/*
 This file is part of The Simplicity Engine.

 The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
 by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

 The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

 You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef SIMPLEENGINEPROTOCOL_H_
#define SIMPLEENGINEPROTOCOL_H_

#include <bitset>
#include <map>

#include <log4cpp/Category.hh>

#include <boost/array.hpp>
#include <boost/asio.hpp>
#include <boost/date_time.hpp>

#include "EngineProtocol.h"

namespace simplicity
{
  /**
   * <p>
   * This is a basic real-time protocol built on top of UDP and Boost.Asio. It is based on the Gaffer on Games 'Networking for Game Programmers'
   * articles (http://gafferongames.com/networking-for-game-programmers/).
   * </p>
   *
   * <p>
   * The protocol includes these features:
   * </p>
   *
   * <ul>
   * <li>Non-Blocking I/O - If there is no message to be received, the {@link #receive(unsigned char * const data)} method returns immediately and
   * returns 0.</li>
   * <li>Protocol Filter - Only messages received that are identified as having been sent by the same version of the same protocol are accepted and
   * passed to the application. All other messages are ignored and their existence is not made visible to the application.</li>
   * <li>Remote Endpoint Filter - Only messages received that are identified as having been sent from an endpoint known to this protocol are accepted
   * and passed to the application. All other messages are ignored and their existence is not made visible to the application.</li>
   * <li>Disconnection Detection - A connection is assumed to be disconnected after no messages have been received on it for the disconnection
   * timeout period.</li>
   * <li>Connection Flooding Detection - A connection is considered flooded when it exceeds a predetermined round trip time. The flooding is resolved
   * after a period of time during which the connection's round trip time is lower than the predetermined round trip time.</li>
   * <ul>
   */
  class SimpleEngineProtocol : public EngineProtocol
  {
    public:
      /**
       * <p>
       * The version of this protocol.
       * </p>
       */
      static unsigned int const VERSION = 0;

      /**
       * <p>
       * The ID of this protocol.
       * </p>
       */
      static unsigned int const ID = 5551 + VERSION;

      /**
       * <p>
       * Creates of an instance of <code>SimpleEngineProtocol</code>.
       * </p>
       */
      SimpleEngineProtocol();

      virtual
      ~SimpleEngineProtocol();

      boost::posix_time::time_duration
      getDisconnectionTimeout() const;

      std::vector<std::string> &
      getEndpointHostNames();

      /**
       * <p>
       * Retrieves the round trip time that is so slow that the connection is considered flooded if it is reached.
       * </p>
       *
       * @return The round trip time that is so slow that the connection is considered flooded if it is reached.
       */
      boost::posix_time::time_duration
      getFloodModeRoundTripTime() const;

      unsigned int
      getLocalPort() const;

      unsigned int
      getMaxDataLength() const;

      unsigned int
      getRemotePort() const;

      void
      init();

      bool
      isConnectedTo(std::string const endpointHostName) const;

      bool
      isConnectionFlooded(std::string const endpointHostName) const;

      unsigned int
      receive(unsigned char * const data);

      bool
      receivedMessage(std::string const endpointHostName, unsigned int const sequenceNumber) const;

      void
      send(unsigned char * const data, unsigned int const dataLength);

      void
      setDisconnectionTimeout(boost::posix_time::time_duration const disconnectionTimeout);

      /**
       * <p>
       * Sets the round trip time that is so slow that the connection is considered flooded if it is reached.
       * </p>
       *
       * @param floodModeRoundTripTime The round trip time that is so slow that the connection is considered flooded if it is reached.
       */
      void
      setFloodModeRoundTripTime(boost::posix_time::time_duration const floodModeRoundTripTime);

      void
      setLocalPort(unsigned int const port);

      void
      setMaxDataLength(unsigned int const maxDataLength);

      void
      setRemotePort(unsigned int const port);

      void
      setSupportsMultipleEndpoints(bool const supportMultipleEndpoints);

      bool
      supportsMultipleEndpoints();

    private:
      /**
       * <p>
       * The number of previous messages to acknowledge in each message.
       * </p>
       */
      static long const ACK_BACKLOG = 32;

      /**
       * <p>
       * The default time a connection can stay idle before it is considered disconnected.
       * </p>
       */
      static boost::posix_time::time_duration const DEFAULT_DISCONNECTION_TIMEOUT;

      /**
       * <p>
       * The default round trip time that is so slow that the connection is considered flooded if it is reached.
       * </p>
       */
      static boost::posix_time::time_duration const FLOOD_MODE_DEFAULT_ROUND_TRIP_TIME;

      /**
       * <p>
       * The default period of time a connection must stay 'good' (not flooded) for before exiting flood mode.
       * </p>
       */
      static boost::posix_time::time_duration const FLOOD_MODE_DEFAULT_TIME_PERIOD;

      /**
       * <p>
       * The maximum period of time a connection must stay 'good' (not flooded) for before exiting flood mode. This maximum may be reached after
       * prolonged 'bad' communication to prevent a premature exit from flood mode.
       * </p>
       */
      static boost::posix_time::time_duration const FLOOD_MODE_MAX_TIME_PERIOD;

      /**
       * <p>
       * The minimum period of time a connection must stay 'good' (not flooded) for before exiting flood mode. This minimum may be reached after
       * prolonged 'good' communication to prevent an unwarranted extended flood mode.
       * </p>
       */
      static boost::posix_time::time_duration const FLOOD_MODE_MIN_TIME_PERIOD;

      /**
       * <p>
       * The time period of 'good' communication after which the 'flood mode time period' is reduced if the minimum has not yet been reached.
       * </p>
       */
      static boost::posix_time::time_duration const FLOOD_MODE_REVIEW_TIME_PERIOD;

      /**
       * <p>
       * The length of the header (in bytes).
       * </p>
       */
      static unsigned int const HEADER_LENGTH = 12 + ACK_BACKLOG / 8;

      /**
       * <p>
       * The received status of the previous messages from each remote endpoint.
       * </p>
       */
      std::map<boost::asio::ip::udp::endpoint, std::bitset<ACK_BACKLOG> > fAckBitfields;

      /**
       * <p>
       * The time a connection can stay idle before it is considered disconnected.
       * </p>
       */
      boost::posix_time::time_duration fDisconnectionTimeout;

      /**
       * <p>
       * The host names of all the remote endpoints this protocol communicates with.
       * </p>
       */
      std::vector<std::string> fEndpointHostNames;

      /**
       * <p>
       * The remote endpoints this protocol communicates with.
       * </p>
       */
      std::vector<boost::asio::ip::udp::endpoint> fEndpoints;

      /**
       * <p>
       * The times at which each connection last exited flood mode.
       * </p>
       */
      std::map<boost::asio::ip::udp::endpoint, boost::posix_time::ptime> fFloodModeExitTimes;

      /**
       * <p>
       * The times at which each connection's 'flood mode time period' was last 'reviewed' (reduced for good behaviour).
       * </p>
       */
      std::map<boost::asio::ip::udp::endpoint, boost::posix_time::ptime> fFloodModeReviewTimes;

      /**
       * <p>
       * The round trip time that is so slow that the connection is considered flooded if it is reached.
       * </p>
       */
      boost::posix_time::time_duration fFloodModeRoundTripTime;

      /**
       * <p>
       * The periods of time the connections must stay 'good' (not flooded) for before exiting flood mode.
       * </p>
       */
      std::map<boost::asio::ip::udp::endpoint, boost::posix_time::time_duration> fFloodModeTimePeriods;

      /**
       * <p>
       * Determines which connections are in flood mode. Flood mode can be used by the application to limit the data sent top a remote endpoint.
       * </p>
       */
      std::map<boost::asio::ip::udp::endpoint, bool> fFloodModes;

      /**
       * <p>
       * The header data.
       * </p>
       */
      boost::array<unsigned char, HEADER_LENGTH> fHeaderData;

      /**
       * <p>
       * The service used to provide communications.
       * </p>
       */
      boost::asio::io_service fIoService;

      /**
       * <p>
       * The port this protocol is bound to locally.
       * </p>
       */
      unsigned int fLocalPort;

      /**
       * <p>
       * Logs messages associated with this class.
       * </p>
       */
      static log4cpp::Category * fLogger;

      /**
       * <p>
       * The maximum amount of data that can be sent or received in a single message.
       * </p>
       */
      unsigned int fMaxDataLength;

      /**
       * <p>
       * The port this protocol sends messages to.
       * </p>
       */
      unsigned int fRemotePort;

      /**
       * <p>
       * The sequence numbers of the last messages received from each remote endpoint.
       * </p>
       */
      std::map<boost::asio::ip::udp::endpoint, unsigned int> fRemoteSequenceNumbers;

      /**
       * <p>
       * Resolves the remote host names to endpoints.
       * </p>
       */
      boost::scoped_ptr<boost::asio::ip::udp::resolver> fResolver;

      /**
       * <p>
       * The sequence numbers of the next messages to be sent to each remote endpoint.
       * </p>
       */
      std::map<boost::asio::ip::udp::endpoint, boost::posix_time::time_duration> fRoundTripTimes;

      /**
       * <p>
       * The times that messages were sent.
       * </p>
       */
      std::map<boost::asio::ip::udp::endpoint, std::map<unsigned int, boost::posix_time::ptime> > fSendTimes;

      /**
       * <p>
       * The sequence numbers of the next messages to be sent to each remote endpoint.
       * </p>
       */
      std::map<boost::asio::ip::udp::endpoint, unsigned int> fSequenceNumbers;

      /**
       * <p>
       * The socket over which the communication is performed.
       * </p>
       */
      boost::scoped_ptr<boost::asio::ip::udp::socket> fSocket;

      /**
       * <p>
       * Determines if this protocol supports communication to and from multiple remote endpoints.
       * </p>
       */
      bool fSupportMultipleEndpoints;

      /**
       * <p>
       * The times when the last message was received from each remote endpoint.
       * </p>
       */
      std::map<boost::asio::ip::udp::endpoint, boost::posix_time::ptime> fLastReceiptTimes;

      /**
       * <p>
       * Establishes a virtual connection to the remote endpoint with the given host name.
       * </p>
       *
       * @param endpointHostName The host name of the remote endpoint to establish a virtual connection with.
       */
      void
      connectTo(std::string const & endpointHostName);

      /**
       * <p>
       * Handles the event fired when the receipt of a message has completed.
       * </p>
       */
      void
      onReceiveComplete(boost::asio::ip::udp::endpoint const & endpoint);

      /**
       * <p>
       * Handles the event fired when the sending of a message has completed.
       * </p>
       */
      void
      onSendComplete(boost::asio::ip::udp::endpoint const & endpoint);

      /**
       * <p>
       * Prepares the header for the next message to be sent.
       * </p>
       */
      void
      prepareHeader(boost::asio::ip::udp::endpoint const & endpoint);

      /**
       * <p>
       * Updates the round trip time for the given remote endpoint and enters/exits/manages flood mode as a result of the changes in round trip time.
       * </p>
       *
       * @param endpoint The remote endpoint to update the round trip time for.
       * @param lastRoundTripTime The round trip time of the message just acknowledged.
       */
      void
      updateRoundTripTime(boost::asio::ip::udp::endpoint const & endpoint, boost::posix_time::time_duration const & lastRoundTripTime);

      /**
       * <p>
       * Validates the last message received.
       * </p>
       */
      bool
      validateMessage(boost::asio::ip::udp::endpoint const & endpoint);
  };
}

#endif /* SIMPLEENGINEPROTOCOL_H_ */
