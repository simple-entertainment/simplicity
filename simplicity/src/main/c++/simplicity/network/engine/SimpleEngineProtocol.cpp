/*
 This file is part of The Simplicity Engine.

 The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
 by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

 The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

 You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
#include <stdio.h>

#include <boost/bind.hpp>
#include <boost/lexical_cast.hpp>

#include "../../SEInvalidOperationException.h"
#include "../../SENotSupportedException.h"
#include "SimpleEngineProtocol.h"

using namespace boost;
using namespace boost::asio;
using namespace boost::asio::ip;
using namespace boost::posix_time;
using namespace std;

namespace simplicity
{
  const time_duration SimpleEngineProtocol::DEFAULT_DISCONNECTION_TIMEOUT = milliseconds(10000);

  const time_duration SimpleEngineProtocol::FLOOD_MODE_DEFAULT_ROUND_TRIP_TIME = milliseconds(250);

  const time_duration SimpleEngineProtocol::FLOOD_MODE_DEFAULT_TIME_PERIOD = milliseconds(10000);

  const time_duration SimpleEngineProtocol::FLOOD_MODE_MAX_TIME_PERIOD = milliseconds(60000);

  const time_duration SimpleEngineProtocol::FLOOD_MODE_MIN_TIME_PERIOD = milliseconds(1000);

  const time_duration SimpleEngineProtocol::FLOOD_MODE_REVIEW_TIME_PERIOD = milliseconds(10000);

  log4cpp::Category& SimpleEngineProtocol::fLogger = log4cpp::Category::getInstance("simplicity::SimpleEngineProtocol");

  SimpleEngineProtocol::SimpleEngineProtocol() :
    fDisconnectionTimeout(DEFAULT_DISCONNECTION_TIMEOUT), fFloodModeRoundTripTime(FLOOD_MODE_DEFAULT_ROUND_TRIP_TIME),
        fLocalPort(10111), fMaxDataLength(1024), fRemotePort(10222), fResolver(new udp::resolver(fIoService)),
        fSocket(new udp::socket(fIoService)), fSupportMultipleEndpoints(false)
  {
  }

  SimpleEngineProtocol::~SimpleEngineProtocol()
  {
    fSocket->close();
  }

  void
  SimpleEngineProtocol::connectTo(const string& endpointHostName)
  {
    fEndpoints.push_back(
        *fResolver->resolve(udp::resolver::query(udp::v4(), endpointHostName, lexical_cast<string> (fRemotePort))));

    fAckBitfields.insert(pair<udp::endpoint, bitset<ACK_BACKLOG> > (fEndpoints.back(), bitset<ACK_BACKLOG> ()));
    fFloodModeExitTimes.insert(pair<udp::endpoint, ptime> (fEndpoints.back(), ptime(microsec_clock::universal_time())));
    fFloodModeReviewTimes.insert(pair<udp::endpoint, ptime> (fEndpoints.back(), ptime(microsec_clock::universal_time())));
    fFloodModes.insert(pair<udp::endpoint, bool> (fEndpoints.back(), false));
    fFloodModeTimePeriods.insert(pair<udp::endpoint, time_duration> (fEndpoints.back(), FLOOD_MODE_DEFAULT_TIME_PERIOD));
    fLastReceiptTimes.insert(pair<udp::endpoint, ptime> (fEndpoints.back(), ptime(microsec_clock::universal_time())));
    fRemoteSequenceNumbers.insert(pair<udp::endpoint, unsigned int> (fEndpoints.back(), 0));
    fRoundTripTimes.insert(pair<udp::endpoint, time_duration> (fEndpoints.back(), milliseconds(0)));
    fSendTimes.insert(pair<udp::endpoint, map<unsigned int, ptime> > (fEndpoints.back(), map<unsigned int, ptime> ()));
    fSequenceNumbers.insert(pair<udp::endpoint, unsigned int> (fEndpoints.back(), 1));
  }

  time_duration
  SimpleEngineProtocol::getDisconnectionTimeout() const
  {
    return (fDisconnectionTimeout);
  }

  vector<string>&
  SimpleEngineProtocol::getEndpointHostNames()
  {
    return (fEndpointHostNames);
  }

  time_duration
  SimpleEngineProtocol::getFloodModeRoundTripTime() const
  {
    return (fFloodModeRoundTripTime);
  }

  unsigned int
  SimpleEngineProtocol::getLocalPort() const
  {
    return (fLocalPort);
  }

  unsigned int
  SimpleEngineProtocol::getMaxDataLength() const
  {
    return (fMaxDataLength);
  }

  unsigned int
  SimpleEngineProtocol::getRemotePort() const
  {
    return (fRemotePort);
  }

  void
  SimpleEngineProtocol::init()
  {
    // Prepare the socket.
    fSocket->open(udp::v4());
    udp::socket::non_blocking_io non_blocking(true);
    fSocket->io_control(non_blocking);
    fSocket->bind(*fResolver->resolve(udp::resolver::query(udp::v4(), "localhost", lexical_cast<string> (fLocalPort))));

    // Add the ID of the protocol to the header.
    unsigned int id = ID;
    memcpy(fHeaderData.begin(), (unsigned char *) &id, sizeof(unsigned int));

    // Ensure only one endpoint is present for 1-1 connections.
    if (!fSupportMultipleEndpoints && fEndpointHostNames.size() > 1)
    {
      throw SEInvalidOperationException();
    }

    // Create remote endpoints.
    for (unsigned int index = 0; index < fEndpointHostNames.size(); index++)
    {
      connectTo(fEndpointHostNames.at(index));
    }
  }

  bool
  SimpleEngineProtocol::isConnectedTo(const string endpointHostName) const
  {
    bool connected = true;
    udp::endpoint endpoint = *fResolver->resolve(
        udp::resolver::query(udp::v4(), endpointHostName, lexical_cast<string> (fRemotePort)));

    time_duration timeSinceLastReceipt = ptime(microsec_clock::universal_time()) - fLastReceiptTimes.at(endpoint);
    if (timeSinceLastReceipt > fDisconnectionTimeout)
    {
      connected = false;
    }

    return (connected);
  }

  bool
  SimpleEngineProtocol::isConnectionFlooded(const string endpointHostName) const
  {
    udp::endpoint endpoint = *fResolver->resolve(
        udp::resolver::query(udp::v4(), endpointHostName, lexical_cast<string> (fRemotePort)));

    return (fFloodModes.at(endpoint));
  }

  void
  SimpleEngineProtocol::onReceiveComplete(const udp::endpoint& endpoint)
  {
    // Record the time the message was received.
    fLastReceiptTimes.at(endpoint) = ptime(microsec_clock::universal_time());

    unsigned int sequenceNumber = (unsigned int) *(fHeaderData.begin() + 2 * sizeof(unsigned int));
    unsigned int newRemoteSequenceNumber = (unsigned int) *(fHeaderData.begin() + sizeof(unsigned int));
    unsigned int oldRemoteSequenceNumber = fRemoteSequenceNumbers.at(endpoint);
    int relativeSequenceNumber = newRemoteSequenceNumber - oldRemoteSequenceNumber;

    // If the message received was sent after all messages already received.
    if (relativeSequenceNumber > 0)
    {
      fRemoteSequenceNumbers.at(endpoint) = newRemoteSequenceNumber;
      fAckBitfields.at(endpoint) <<= relativeSequenceNumber;
    }

    if (oldRemoteSequenceNumber != 0)
    {
      fAckBitfields.at(endpoint).set(abs(relativeSequenceNumber) - 1);
    }

    if (sequenceNumber > 0)
    {
      time_duration roundTripTime = ptime(microsec_clock::universal_time()) - fSendTimes.at(endpoint).at(sequenceNumber);
      updateRoundTripTime(endpoint, roundTripTime);
    }
  }

  void
  SimpleEngineProtocol::onSendComplete(const udp::endpoint& endpoint)
  {
    // Record the time the message was sent.
    fSendTimes.at(endpoint).insert(
        pair<unsigned int, ptime> (fSequenceNumbers.at(endpoint) - 1, ptime(microsec_clock::universal_time())));
  }

  void
  SimpleEngineProtocol::prepareHeader(const udp::endpoint& endpoint)
  {
    // The protocol ID has already been added.

    // Add the sequence number.
    memcpy(fHeaderData.begin() + sizeof(unsigned int), &fSequenceNumbers.at(endpoint), sizeof(unsigned int));
    fSequenceNumbers.at(endpoint)++;

    // Add the remote sequence number.
    memcpy(fHeaderData.begin() + 2 * sizeof(unsigned int), &fRemoteSequenceNumbers.at(endpoint), sizeof(unsigned int));

    // Add the acknowledgement backlog.
    memcpy(fHeaderData.begin() + 3 * sizeof(unsigned int), &fAckBitfields.at(endpoint), ACK_BACKLOG / 8);
  }

  unsigned int
  SimpleEngineProtocol::receive(vector<unsigned char>& data)
  {
    unsigned int dataLength = 0;
    array<mutable_buffer, 2> buffers;
    buffers.at(0) = buffer(fHeaderData);
    buffers.at(1) = buffer(data);
    udp::endpoint endpoint;

    while (fSocket->available() > 0)
    {
      dataLength = fSocket->receive_from(buffers, endpoint) - HEADER_LENGTH;

      if (validateMessage(endpoint))
      {
        onReceiveComplete(endpoint);
        break;
      }

      dataLength = 0;
    }

    return (dataLength);
  }

  bool
  SimpleEngineProtocol::receivedMessage(const string endpointHostName, const unsigned int sequenceNumber) const
  {
    bool received = false;
    udp::endpoint endpoint = *fResolver->resolve(
        udp::resolver::query(udp::v4(), endpointHostName, lexical_cast<string> (fRemotePort)));

    if (sequenceNumber == fRemoteSequenceNumbers.at(endpoint))
    {
      received = true;
    }
    else if (sequenceNumber < fRemoteSequenceNumbers.at(endpoint))
    {
      received = fAckBitfields.at(endpoint).test(fRemoteSequenceNumbers.at(endpoint) - sequenceNumber - 1);
    }

    return (received);
  }

  void
  SimpleEngineProtocol::send(const vector<unsigned char>& data)
  {
    array<const_buffer, 2> buffers;
    buffers.at(0) = buffer(fHeaderData);
    buffers.at(1) = buffer(data);

    for (unsigned int index = 0; index < fEndpoints.size(); index++)
    {
      prepareHeader(fEndpoints.at(index));
      fSocket->send_to(buffers, fEndpoints.at(index));
      onSendComplete(fEndpoints.at(index));
    }
  }

  void
  SimpleEngineProtocol::setDisconnectionTimeout(const time_duration disconnectionTimeout)
  {
    fDisconnectionTimeout = disconnectionTimeout;
  }

  void
  SimpleEngineProtocol::setFloodModeRoundTripTime(const time_duration floodModeRoundTripTime)
  {
    fFloodModeRoundTripTime = floodModeRoundTripTime;
  }

  void
  SimpleEngineProtocol::setLocalPort(const unsigned int port)
  {
    fLocalPort = port;
  }

  void
  SimpleEngineProtocol::setMaxDataLength(const unsigned int maxDataLength)
  {
    fMaxDataLength = maxDataLength;
  }

  void
  SimpleEngineProtocol::setRemotePort(const unsigned int port)
  {
    fRemotePort = port;
  }

  void
  SimpleEngineProtocol::setSupportsMultipleEndpoints(const bool supportMultipleEndpoints)
  {
    if (supportMultipleEndpoints)
    {
      throw SENotSupportedException();
    }
  }

  bool
  SimpleEngineProtocol::supportsMultipleEndpoints()
  {
    return (fSupportMultipleEndpoints);
  }

  void
  SimpleEngineProtocol::updateRoundTripTime(const udp::endpoint& endpoint, const time_duration& lastRoundTripTime)
  {
    time_duration timeSinceExitingFloodMode = ptime(microsec_clock::universal_time()) - fFloodModeExitTimes.at(endpoint);
    time_duration oldRoundTripTime = fRoundTripTimes.at(endpoint);
    time_duration newRoundTripTime = lastRoundTripTime;
    if (oldRoundTripTime > milliseconds(0))
    {
      time_duration difference = fRoundTripTimes.at(endpoint) - lastRoundTripTime;
      newRoundTripTime = oldRoundTripTime + difference * 0.1;
    }

    fRoundTripTimes.at(endpoint) = newRoundTripTime;

    // The round trip time has raised above the threshold.
    if (oldRoundTripTime < fFloodModeRoundTripTime && newRoundTripTime > fFloodModeRoundTripTime)
    {
      fLogger.warn("Connection flooded!");
      fFloodModes.at(endpoint) = true;

      // If it has not been very long since the last time we were in flood mode, stay in flood mode longer this time.
      if (timeSinceExitingFloodMode < fFloodModeTimePeriods.at(endpoint))
      {
        fLogger.debug("Extending flood mode duration.");
        fFloodModeTimePeriods.at(endpoint) = min(fFloodModeTimePeriods.at(endpoint) * 2, FLOOD_MODE_MAX_TIME_PERIOD);
      }
    }
    // The round trip time has returned under the threshold.
    else if (oldRoundTripTime > fFloodModeRoundTripTime && newRoundTripTime < fFloodModeRoundTripTime)
    {
      fLogger.debug("The round trip time has returned to 'normal'.");
      fFloodModeExitTimes.at(endpoint) = ptime(microsec_clock::universal_time());
      fFloodModeReviewTimes.at(endpoint) = ptime(microsec_clock::universal_time());
    }
    // The round trip time has been under the threshold for a while.
    else if (newRoundTripTime < fFloodModeRoundTripTime && timeSinceExitingFloodMode > fFloodModeTimePeriods.at(endpoint))
    {
      fLogger.debug("Connection cleared!");
      fFloodModes.at(endpoint) = false;
      time_duration timeSinceReviewingFloodMode = ptime(microsec_clock::universal_time()) - fFloodModeReviewTimes.at(endpoint);

      // If it has been very long since the last time we were in flood mode, make flood mode shorter next time.
      if (timeSinceReviewingFloodMode > FLOOD_MODE_REVIEW_TIME_PERIOD)
      {
        fLogger.debug("Shortening flood mode duration.");
        fFloodModeReviewTimes.at(endpoint) = ptime(microsec_clock::universal_time());
        fFloodModeTimePeriods.at(endpoint) = max(fFloodModeTimePeriods.at(endpoint) / 2, FLOOD_MODE_MIN_TIME_PERIOD);
      }
    }
  }

  bool
  SimpleEngineProtocol::validateMessage(const udp::endpoint& endpoint)
  {
    bool valid = true;

    // Only accept messages from the correct protocol.
    if (*((unsigned int *) fHeaderData.begin()) != ID)
    {
      valid = false;
    }

    // Only accept messages from recognised endpoints.
    if (valid)
    {
      if (find(fEndpoints.begin(), fEndpoints.end(), endpoint) == fEndpoints.end())
      {
        valid = false;
      }
    }

    return (valid);
  }
}
