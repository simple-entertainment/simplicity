/*
 This file is part of The Simplicity Engine.

 The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
 by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

 The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

 You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
#include <boost/date_time.hpp>
#include <boost/thread.hpp>

#include <simplicity/SEInvalidOperationException.h>

#include "SimpleEngineProtocolTest.h"

using namespace boost;
using namespace boost::asio;
using namespace boost::asio::ip;
using namespace boost::posix_time;
using namespace std;

namespace simplicity
{
  /**
   * <p>
   * Unit test the method {@link simplicity::SimpleEngineProtocol#init() init()} with ths special condition that multiple endpoints have been
   * configured but multiple endpoints are not supported.
   * </p>
   */
  TEST_F(SimpleEngineProtocolTest, initMultipleEndpointsNotSupported)
  {
    // Initialise test environment.
    fTestObject.getEndpointHostNames().push_back("host_1");
    fTestObject.getEndpointHostNames().push_back("host_2");

    // Perform test - Verify test results.
    ASSERT_THROW(fTestObject.init(), SEInvalidOperationException);
  }

  /**
   * <p>
   * Unit test the method {@link simplicity::SimpleEngineProtocol#isConnectedTo(string const) isConnectedTo(string const)}.
   * </p>
   */
  TEST_F(SimpleEngineProtocolTest, isConnectedTo)
  {
    // Initialise test environment.
    fTestObject.getEndpointHostNames().push_back("localhost");
    fTestObject.init();

    // Perform test - Verify test results.
    ASSERT_TRUE(fTestObject.isConnectedTo("localhost"));
  }

  /**
   * <p>
   * Unit test the method {@link simplicity::SimpleEngineProtocol#isConnectedTo(string const) isConnectedTo(string const)} with the special condition
   * that the connection is only open due to messages received from the endpoint.
   * </p>
   */
  TEST_F(SimpleEngineProtocolTest, isConnectedToConnectionSustained)
  {
    // Create dependencies.
    io_service io_service;
    udp::resolver resolver(io_service);
    udp::socket socket(io_service);
    udp::endpoint receivingEndpoint = *resolver.resolve(udp::resolver::query(udp::v4(), "localhost", lexical_cast<string> (fTestObject.getLocalPort())));
    udp::endpoint sendingEndpoint = *resolver.resolve(udp::resolver::query(udp::v4(), "localhost", lexical_cast<string> (fTestObject.getRemotePort())));

    unsigned char sendHeaderData[16];
    unsigned int id = SimpleEngineProtocol::ID;
    unsigned int sequenceNumber = 1;
    unsigned int remoteSequenceNumber = 0;
    bitset<32> ackBitfield;
    memcpy(sendHeaderData, &id, sizeof(unsigned int));
    memcpy(sendHeaderData + sizeof(unsigned int), &sequenceNumber, sizeof(unsigned int));
    memcpy(sendHeaderData + 2 * sizeof(unsigned int), &remoteSequenceNumber, sizeof(unsigned int));
    memcpy(sendHeaderData + 3 * sizeof(unsigned int), &ackBitfield, 4);

    vector<unsigned char> sendData(10);
    array<mutable_buffer, 2> buffers;
    buffers.at(0) = buffer(sendHeaderData, 16);
    buffers.at(1) = buffer(sendData, 10);

    vector<unsigned char> receiveData(10);

    // Initialise test environment.
    fTestObject.getEndpointHostNames().push_back("localhost");
    fTestObject.init();
    fTestObject.setDisconnectionTimeout(milliseconds(100));
    this_thread::sleep(milliseconds(50));

    socket.open(udp::v4());
    socket.bind(sendingEndpoint);

    socket.send_to(buffers, receivingEndpoint);

    fTestObject.receive(receiveData);

    this_thread::sleep(milliseconds(75));

    // Perform test - Verify test results.
    ASSERT_TRUE(fTestObject.isConnectedTo("localhost"));
  }

  /**
   * <p>
   * Unit test the method {@link simplicity::SimpleEngineProtocol#isConnectedTo(string const) isConnectedTo(string const)} with the special condition
   * that the connection has been idle for longer than the disconnection timeout.
   * </p>
   */
  TEST_F(SimpleEngineProtocolTest, isConnectedToAfterDisconnectionTimeout)
  {
    // Initialise test environment.
    fTestObject.getEndpointHostNames().push_back("localhost");
    fTestObject.init();
    fTestObject.setDisconnectionTimeout(milliseconds(100));
    this_thread::sleep(milliseconds(150));

    // Perform test - Verify test results.
    ASSERT_FALSE(fTestObject.isConnectedTo("localhost"));
  }

  /**
   * <p>
   * Unit test the method {@link simplicity::SimpleEngineProtocol#isConnectionFlooded(string const) isConnectionFlooded(string const)} with the
   * special condition that the connection has been bad for the duration of its life.
   * </p>
   */
  TEST_F(SimpleEngineProtocolTest, isConnectionFloodedBadConnection)
  {
    // Create dependencies.
    io_service io_service;
    udp::resolver resolver(io_service);
    udp::socket socket(io_service);
    udp::endpoint receivingEndpoint = *resolver.resolve(udp::resolver::query(udp::v4(), "localhost", lexical_cast<string> (fTestObject.getLocalPort())));
    udp::endpoint sendingEndpoint = *resolver.resolve(udp::resolver::query(udp::v4(), "localhost", lexical_cast<string> (fTestObject.getRemotePort())));

    unsigned char sendHeaderData[16];
    unsigned int id = SimpleEngineProtocol::ID;
    unsigned int sequenceNumber = 1;
    unsigned int remoteSequenceNumber = 0;
    bitset<32> ackBitfield;
    memcpy(sendHeaderData, &id, sizeof(unsigned int));
    memcpy(sendHeaderData + sizeof(unsigned int), &sequenceNumber, sizeof(unsigned int));
    memcpy(sendHeaderData + 2 * sizeof(unsigned int), &remoteSequenceNumber, sizeof(unsigned int));
    memcpy(sendHeaderData + 3 * sizeof(unsigned int), &ackBitfield, 4);

    vector<unsigned char> sendData(10);
    array<mutable_buffer, 2> buffers;
    buffers.at(0) = buffer(sendHeaderData, 16);
    buffers.at(1) = buffer(sendData, 10);

    vector<unsigned char> receiveData(10);

    // Initialise test environment.
    fTestObject.getEndpointHostNames().push_back("localhost");
    fTestObject.setFloodModeRoundTripTime(milliseconds(5));
    fTestObject.init();

    socket.open(udp::v4());
    socket.bind(sendingEndpoint);

    // Perform test.
    socket.send_to(buffers, receivingEndpoint);
    fTestObject.receive(receiveData);
    fTestObject.send(sendData);
    this_thread::sleep(milliseconds(10));

    sequenceNumber++;
    remoteSequenceNumber++;
    memcpy(sendHeaderData + sizeof(unsigned int), &sequenceNumber, sizeof(unsigned int));
    memcpy(sendHeaderData + 2 * sizeof(unsigned int), &remoteSequenceNumber, sizeof(unsigned int));
    socket.send_to(buffers, receivingEndpoint);
    fTestObject.receive(receiveData);
    fTestObject.send(sendData);
    this_thread::sleep(milliseconds(10));

    sequenceNumber++;
    remoteSequenceNumber++;
    memcpy(sendHeaderData + sizeof(unsigned int), &sequenceNumber, sizeof(unsigned int));
    memcpy(sendHeaderData + 2 * sizeof(unsigned int), &remoteSequenceNumber, sizeof(unsigned int));
    socket.send_to(buffers, receivingEndpoint);
    fTestObject.receive(receiveData);

    // Verify test results.
    ASSERT_TRUE(fTestObject.isConnectionFlooded("localhost"));

    // Cleanup.
    socket.close();
  }

  /**
   * <p>
   * Unit test the method {@link simplicity::SimpleEngineProtocol#isConnectionFlooded(string const) isConnectionFlooded(string const)} with the
   * special condition that the connection has been good for the duration of its life.
   * </p>
   */
  TEST_F(SimpleEngineProtocolTest, isConnectionFloodedGoodConnection)
  {
    // Create dependencies.
    io_service io_service;
    udp::resolver resolver(io_service);
    udp::socket socket(io_service);
    udp::endpoint receivingEndpoint = *resolver.resolve(udp::resolver::query(udp::v4(), "localhost", lexical_cast<string> (fTestObject.getLocalPort())));
    udp::endpoint sendingEndpoint = *resolver.resolve(udp::resolver::query(udp::v4(), "localhost", lexical_cast<string> (fTestObject.getRemotePort())));

    unsigned char sendHeaderData[16];
    unsigned int id = SimpleEngineProtocol::ID;
    unsigned int sequenceNumber = 1;
    unsigned int remoteSequenceNumber = 0;
    bitset<32> ackBitfield;
    memcpy(sendHeaderData, &id, sizeof(unsigned int));
    memcpy(sendHeaderData + sizeof(unsigned int), &sequenceNumber, sizeof(unsigned int));
    memcpy(sendHeaderData + 2 * sizeof(unsigned int), &remoteSequenceNumber, sizeof(unsigned int));
    memcpy(sendHeaderData + 3 * sizeof(unsigned int), &ackBitfield, 4);

    vector<unsigned char> sendData(10);
    array<mutable_buffer, 2> buffers;
    buffers.at(0) = buffer(sendHeaderData, 16);
    buffers.at(1) = buffer(sendData, 10);

    vector<unsigned char> receiveData(10);

    // Initialise test environment.
    fTestObject.getEndpointHostNames().push_back("localhost");
    fTestObject.init();

    socket.open(udp::v4());
    socket.bind(sendingEndpoint);

    // Perform test.
    socket.send_to(buffers, receivingEndpoint);
    fTestObject.receive(receiveData);
    fTestObject.send(sendData);
    this_thread::sleep(milliseconds(10));

    sequenceNumber++;
    remoteSequenceNumber++;
    memcpy(sendHeaderData + sizeof(unsigned int), &sequenceNumber, sizeof(unsigned int));
    memcpy(sendHeaderData + 2 * sizeof(unsigned int), &remoteSequenceNumber, sizeof(unsigned int));
    socket.send_to(buffers, receivingEndpoint);
    fTestObject.receive(receiveData);
    fTestObject.send(sendData);
    this_thread::sleep(milliseconds(10));

    sequenceNumber++;
    remoteSequenceNumber++;
    memcpy(sendHeaderData + sizeof(unsigned int), &sequenceNumber, sizeof(unsigned int));
    memcpy(sendHeaderData + 2 * sizeof(unsigned int), &remoteSequenceNumber, sizeof(unsigned int));
    socket.send_to(buffers, receivingEndpoint);
    fTestObject.receive(receiveData);

    // Verify test results.
    ASSERT_FALSE(fTestObject.isConnectionFlooded("localhost"));

    // Cleanup.
    socket.close();
  }

  /**
   * <p>
   * Unit test the method {@link simplicity::SimpleEngineProtocol#receive(unsigned char *) receive(unsigned char *)}.
   * </p>
   */
  TEST_F(SimpleEngineProtocolTest, receive)
  {
    // Create dependencies.
    io_service io_service;
    udp::resolver resolver(io_service);
    udp::socket socket(io_service);
    udp::endpoint receivingEndpoint = *resolver.resolve(udp::resolver::query(udp::v4(), "localhost", lexical_cast<string> (fTestObject.getLocalPort())));
    udp::endpoint sendingEndpoint = *resolver.resolve(udp::resolver::query(udp::v4(), "localhost", lexical_cast<string> (fTestObject.getRemotePort())));

    unsigned char sendHeaderData[16];
    unsigned int id = SimpleEngineProtocol::ID;
    unsigned int sequenceNumber = 1;
    unsigned int remoteSequenceNumber = 0;
    bitset<32> ackBitfield;
    memcpy(sendHeaderData, &id, sizeof(unsigned int));
    memcpy(sendHeaderData + sizeof(unsigned int), &sequenceNumber, sizeof(unsigned int));
    memcpy(sendHeaderData + 2 * sizeof(unsigned int), &remoteSequenceNumber, sizeof(unsigned int));
    memcpy(sendHeaderData + 3 * sizeof(unsigned int), &ackBitfield, 4);

    vector<unsigned char> sendData(10);
    sendData.at(0) = 0;
    sendData.at(1) = 1;
    sendData.at(2) = 2;
    sendData.at(3) = 3;
    sendData.at(4) = 4;
    sendData.at(5) = 5;
    sendData.at(6) = 6;
    sendData.at(7) = 7;
    sendData.at(8) = 8;
    sendData.at(9) = 9;
    array<mutable_buffer, 2> buffers;
    buffers.at(0) = buffer(sendHeaderData, 16);
    buffers.at(1) = buffer(sendData, 10);

    vector<unsigned char> receiveData(10);

    // Initialise test environment.
    fTestObject.getEndpointHostNames().push_back("localhost");
    fTestObject.init();

    socket.open(udp::v4());
    socket.bind(sendingEndpoint);

    socket.send_to(buffers, receivingEndpoint);

    // Perform test.
    unsigned int dataLength = fTestObject.receive(receiveData);

    // Verify test results.
    ASSERT_EQ(10u, dataLength);
    ASSERT_EQ(0, receiveData[0]);
    ASSERT_EQ(1, receiveData[1]);
    ASSERT_EQ(2, receiveData[2]);
    ASSERT_EQ(3, receiveData[3]);
    ASSERT_EQ(4, receiveData[4]);
    ASSERT_EQ(5, receiveData[5]);
    ASSERT_EQ(6, receiveData[6]);
    ASSERT_EQ(7, receiveData[7]);
    ASSERT_EQ(8, receiveData[8]);
    ASSERT_EQ(9, receiveData[9]);

    // Cleanup.
    socket.close();
  }

  /**
   * <p>
   * Unit test the method {@link simplicity::SimpleEngineProtocol#receivedMessage(unsigned string const, unsigned int const)
   * receivedMessage(unsigned string const, unsigned int const)}.
   * </p>
   */
  TEST_F(SimpleEngineProtocolTest, receivedMessage)
  {
    // Create dependencies.
    io_service io_service;
    udp::resolver resolver(io_service);
    udp::socket socket(io_service);
    udp::endpoint receivingEndpoint = *resolver.resolve(udp::resolver::query(udp::v4(), "localhost", lexical_cast<string> (fTestObject.getLocalPort())));
    udp::endpoint sendingEndpoint = *resolver.resolve(udp::resolver::query(udp::v4(), "localhost", lexical_cast<string> (fTestObject.getRemotePort())));

    unsigned char sendHeaderData[16];
    unsigned int id = SimpleEngineProtocol::ID;
    unsigned int sequenceNumber = 1;
    unsigned int remoteSequenceNumber = 0;
    bitset<32> ackBitfield;
    memcpy(sendHeaderData, &id, sizeof(unsigned int));
    memcpy(sendHeaderData + sizeof(unsigned int), &sequenceNumber, sizeof(unsigned int));
    memcpy(sendHeaderData + 2 * sizeof(unsigned int), &remoteSequenceNumber, sizeof(unsigned int));
    memcpy(sendHeaderData + 3 * sizeof(unsigned int), &ackBitfield, 4);

    vector<unsigned char> sendData(10);
    array<mutable_buffer, 2> buffers;
    buffers.at(0) = buffer(sendHeaderData, 16);
    buffers.at(1) = buffer(sendData, 10);

    vector<unsigned char> receiveData(10);

    // Initialise test environment.
    fTestObject.getEndpointHostNames().push_back("localhost");
    fTestObject.init();

    socket.open(udp::v4());
    socket.bind(sendingEndpoint);

    socket.send_to(buffers, receivingEndpoint);
    sequenceNumber = 3;
    memcpy(sendHeaderData + sizeof(unsigned int), &sequenceNumber, sizeof(unsigned int));
    socket.send_to(buffers, receivingEndpoint);
    sequenceNumber = 4;
    memcpy(sendHeaderData + sizeof(unsigned int), &sequenceNumber, sizeof(unsigned int));
    socket.send_to(buffers, receivingEndpoint);
    sequenceNumber = 8;
    memcpy(sendHeaderData + sizeof(unsigned int), &sequenceNumber, sizeof(unsigned int));
    socket.send_to(buffers, receivingEndpoint);
    sequenceNumber = 6;
    memcpy(sendHeaderData + sizeof(unsigned int), &sequenceNumber, sizeof(unsigned int));
    socket.send_to(buffers, receivingEndpoint);

    fTestObject.receive(receiveData);
    fTestObject.receive(receiveData);
    fTestObject.receive(receiveData);
    fTestObject.receive(receiveData);
    fTestObject.receive(receiveData);

    // Perform test - Verify test results.
    ASSERT_TRUE(fTestObject.receivedMessage("localhost", 1));
    ASSERT_FALSE(fTestObject.receivedMessage("localhost", 2));
    ASSERT_TRUE(fTestObject.receivedMessage("localhost", 3));
    ASSERT_TRUE(fTestObject.receivedMessage("localhost", 4));
    ASSERT_FALSE(fTestObject.receivedMessage("localhost", 5));
    ASSERT_TRUE(fTestObject.receivedMessage("localhost", 6));
    ASSERT_FALSE(fTestObject.receivedMessage("localhost", 7));
    ASSERT_TRUE(fTestObject.receivedMessage("localhost", 8));
  }

  /**
   * <p>
   * Unit test the method {@link simplicity::SimpleEngineProtocol#receive(unsigned char *) receive(unsigned char *)} with the special condition that
   * the message received was not sent by a recognised endpoint.
   * </p>
   */
  TEST_F(SimpleEngineProtocolTest, receiveInvalidEndpoint)
  {
    // Create dependencies.
    io_service io_service;
    udp::resolver resolver(io_service);
    udp::socket socket(io_service);
    udp::endpoint receivingEndpoint = *resolver.resolve(udp::resolver::query(udp::v4(), "localhost", lexical_cast<string> (fTestObject.getLocalPort())));
    udp::endpoint sendingEndpoint = *resolver.resolve(udp::resolver::query(udp::v4(), "localhost", lexical_cast<string> (fTestObject.getRemotePort())));

    unsigned char sendHeaderData[16];
    unsigned int id = SimpleEngineProtocol::ID;
    unsigned int sequenceNumber = 1;
    unsigned int remoteSequenceNumber = 0;
    bitset<32> ackBitfield;
    memcpy(sendHeaderData, &id, sizeof(unsigned int));
    memcpy(sendHeaderData + sizeof(unsigned int), &sequenceNumber, sizeof(unsigned int));
    memcpy(sendHeaderData + 2 * sizeof(unsigned int), &remoteSequenceNumber, sizeof(unsigned int));
    memcpy(sendHeaderData + 3 * sizeof(unsigned int), &ackBitfield, 4);

    vector<unsigned char> sendData(10);
    array<mutable_buffer, 2> buffers;
    buffers.at(0) = buffer(sendHeaderData, 16);
    buffers.at(1) = buffer(sendData, 10);

    vector<unsigned char> receiveData(10);

    // Initialise test environment.
    fTestObject.getEndpointHostNames().push_back("10.0.0.1");
    fTestObject.init();

    socket.open(udp::v4());
    socket.bind(sendingEndpoint);

    socket.send_to(buffers, receivingEndpoint);

    // Perform test.
    unsigned int dataLength = fTestObject.receive(receiveData);

    // Verify test results.
    ASSERT_EQ(0u, dataLength);

    // Cleanup.
    socket.close();
  }

  /**
   * <p>
   * Unit test the method {@link simplicity::SimpleEngineProtocol#receive(unsigned char *) receive(unsigned char *)} with the special condition that
   * the message received was not sent by the same protocol and version.
   * </p>
   */
  TEST_F(SimpleEngineProtocolTest, receiveInvalidId)
  {
    // Create dependencies.
    io_service io_service;
    udp::resolver resolver(io_service);
    udp::socket socket(io_service);
    udp::endpoint receivingEndpoint = *resolver.resolve(udp::resolver::query(udp::v4(), "localhost", lexical_cast<string> (fTestObject.getLocalPort())));
    udp::endpoint sendingEndpoint = *resolver.resolve(udp::resolver::query(udp::v4(), "localhost", lexical_cast<string> (fTestObject.getRemotePort())));

    unsigned char sendHeaderData[16];
    unsigned int invalidId = SimpleEngineProtocol::ID - 1;
    unsigned int sequenceNumber = 1;
    unsigned int remoteSequenceNumber = 0;
    bitset<32> ackBitfield;
    memcpy(sendHeaderData, &invalidId, sizeof(unsigned int));
    memcpy(sendHeaderData + sizeof(unsigned int), &sequenceNumber, sizeof(unsigned int));
    memcpy(sendHeaderData + 2 * sizeof(unsigned int), &remoteSequenceNumber, sizeof(unsigned int));
    memcpy(sendHeaderData + 3 * sizeof(unsigned int), &ackBitfield, 4);

    vector<unsigned char> sendData(10);
    array<mutable_buffer, 2> buffers;
    buffers.at(0) = buffer(sendHeaderData, 16);
    buffers.at(1) = buffer(sendData, 10);

    vector<unsigned char> receiveData(10);

    // Initialise test environment.
    fTestObject.getEndpointHostNames().push_back("localhost");
    fTestObject.init();

    socket.open(udp::v4());
    socket.bind(sendingEndpoint);

    socket.send_to(buffers, receivingEndpoint);

    // Perform test.
    unsigned int dataLength = fTestObject.receive(receiveData);

    // Verify test results.
    ASSERT_EQ(0u, dataLength);

    // Cleanup.
    socket.close();
  }

  /**
   * <p>
   * Unit test the method {@link simplicity::SimpleEngineProtocol#receive(unsigned char *) receive(unsigned char *)} with the special condition that
   * the first message received was not valid but the second message received was valid.
   * </p>
   */
  TEST_F(SimpleEngineProtocolTest, receiveInvalidMessageThenValidMessage)
  {
    // Create dependencies.
    io_service io_service;
    udp::resolver resolver(io_service);
    udp::socket socket(io_service);
    udp::endpoint receivingEndpoint = *resolver.resolve(udp::resolver::query(udp::v4(), "localhost", lexical_cast<string> (fTestObject.getLocalPort())));
    udp::endpoint sendingEndpoint = *resolver.resolve(udp::resolver::query(udp::v4(), "localhost", lexical_cast<string> (fTestObject.getRemotePort())));

    unsigned char sendHeaderData[16];
    unsigned int invalidId = SimpleEngineProtocol::ID - 1;
    unsigned int sequenceNumber = 1;
    unsigned int remoteSequenceNumber = 0;
    bitset<32> ackBitfield;
    memcpy(sendHeaderData, &invalidId, sizeof(unsigned int));
    memcpy(sendHeaderData + sizeof(unsigned int), &sequenceNumber, sizeof(unsigned int));
    memcpy(sendHeaderData + 2 * sizeof(unsigned int), &remoteSequenceNumber, sizeof(unsigned int));
    memcpy(sendHeaderData + 3 * sizeof(unsigned int), &ackBitfield, 4);

    vector<unsigned char> sendData(10);
    sendData.at(0) = 0;
    sendData.at(1) = 1;
    sendData.at(2) = 2;
    sendData.at(3) = 3;
    sendData.at(4) = 4;
    sendData.at(5) = 5;
    sendData.at(6) = 6;
    sendData.at(7) = 7;
    sendData.at(8) = 8;
    sendData.at(9) = 9;
    array<mutable_buffer, 2> buffers;
    buffers.at(0) = buffer(sendHeaderData, 16);
    buffers.at(1) = buffer(sendData, 10);

    vector<unsigned char> receiveData(10);

    // Initialise test environment.
    fTestObject.getEndpointHostNames().push_back("localhost");
    fTestObject.init();

    socket.open(udp::v4());
    socket.bind(sendingEndpoint);

    socket.send_to(buffers, receivingEndpoint);
    unsigned int id = SimpleEngineProtocol::ID;
    memcpy(sendHeaderData, &id, sizeof(unsigned int));
    sequenceNumber = 2;
    memcpy(sendHeaderData + sizeof(unsigned int), &sequenceNumber, sizeof(unsigned int));
    socket.send_to(buffers, receivingEndpoint);

    // Perform test 1.
    unsigned int dataLength = fTestObject.receive(receiveData);

    // Verify test 1 results.
    ASSERT_EQ(10u, dataLength);
    ASSERT_EQ(0, receiveData[0]);
    ASSERT_EQ(1, receiveData[1]);
    ASSERT_EQ(2, receiveData[2]);
    ASSERT_EQ(3, receiveData[3]);
    ASSERT_EQ(4, receiveData[4]);
    ASSERT_EQ(5, receiveData[5]);
    ASSERT_EQ(6, receiveData[6]);
    ASSERT_EQ(7, receiveData[7]);
    ASSERT_EQ(8, receiveData[8]);
    ASSERT_EQ(9, receiveData[9]);

    // Perform test 2.
    dataLength = fTestObject.receive(receiveData);

    // Verify test 2 results.
    ASSERT_EQ(0u, dataLength);

    // Cleanup.
    socket.close();
  }

  /**
   * <p>
   * Unit test the method {@link simplicity::SimpleEngineProtocol#receive(unsigned char *) receive(unsigned char *)} with the special condition that
   * there is no message to be received.
   * </p>
   */
  TEST_F(SimpleEngineProtocolTest, receiveNoMessage)
  {
    // Create dependencies.
    vector<unsigned char> receiveData(10);

    // Initialise test environment.
    fTestObject.init();

    // Perform test.
    unsigned int dataLength = fTestObject.receive(receiveData);

    // Verify test results.
    ASSERT_EQ(0u, dataLength);
  }

  /**
   * <p>
   * Unit test the method {@link simplicity::SimpleEngineProtocol#receive(unsigned char *) receive(unsigned char *)} with the special condition that
   * the first message received was valid but the second message received was not valid.
   * </p>
   */
  TEST_F(SimpleEngineProtocolTest, receiveValidMessageThenInvalidMessage)
  {
    // Create dependencies.
    io_service io_service;
    udp::resolver resolver(io_service);
    udp::socket socket(io_service);
    udp::endpoint receivingEndpoint = *resolver.resolve(udp::resolver::query(udp::v4(), "localhost", lexical_cast<string> (fTestObject.getLocalPort())));
    udp::endpoint sendingEndpoint = *resolver.resolve(udp::resolver::query(udp::v4(), "localhost", lexical_cast<string> (fTestObject.getRemotePort())));

    unsigned char sendHeaderData[16];
    unsigned int id = SimpleEngineProtocol::ID;
    unsigned int sequenceNumber = 1;
    unsigned int remoteSequenceNumber = 0;
    bitset<32> ackBitfield;
    memcpy(sendHeaderData, &id, sizeof(unsigned int));
    memcpy(sendHeaderData + sizeof(unsigned int), &sequenceNumber, sizeof(unsigned int));
    memcpy(sendHeaderData + 2 * sizeof(unsigned int), &remoteSequenceNumber, sizeof(unsigned int));
    memcpy(sendHeaderData + 3 * sizeof(unsigned int), &ackBitfield, 4);

    vector<unsigned char> sendData(10);
    sendData.at(0) = 0;
    sendData.at(1) = 1;
    sendData.at(2) = 2;
    sendData.at(3) = 3;
    sendData.at(4) = 4;
    sendData.at(5) = 5;
    sendData.at(6) = 6;
    sendData.at(7) = 7;
    sendData.at(8) = 8;
    sendData.at(9) = 9;
    array<mutable_buffer, 2> buffers;
    buffers.at(0) = buffer(sendHeaderData, 16);
    buffers.at(1) = buffer(sendData, 10);

    vector<unsigned char> receiveData(10);

    // Initialise test environment.
    fTestObject.getEndpointHostNames().push_back("localhost");
    fTestObject.init();

    socket.open(udp::v4());
    socket.bind(sendingEndpoint);

    socket.send_to(buffers, receivingEndpoint);
    unsigned int invalidId = SimpleEngineProtocol::ID - 1;
    memcpy(sendHeaderData, &invalidId, sizeof(unsigned int));
    sequenceNumber = 2;
    memcpy(sendHeaderData + sizeof(unsigned int), &sequenceNumber, sizeof(unsigned int));
    socket.send_to(buffers, receivingEndpoint);

    // Perform test 1.
    unsigned int dataLength = fTestObject.receive(receiveData);

    // Verify test 1 results.
    ASSERT_EQ(10u, dataLength);
    ASSERT_EQ(0, receiveData[0]);
    ASSERT_EQ(1, receiveData[1]);
    ASSERT_EQ(2, receiveData[2]);
    ASSERT_EQ(3, receiveData[3]);
    ASSERT_EQ(4, receiveData[4]);
    ASSERT_EQ(5, receiveData[5]);
    ASSERT_EQ(6, receiveData[6]);
    ASSERT_EQ(7, receiveData[7]);
    ASSERT_EQ(8, receiveData[8]);
    ASSERT_EQ(9, receiveData[9]);

    // Perform test 2.
    dataLength = fTestObject.receive(receiveData);

    // Verify test 2 results.
    ASSERT_EQ(0u, dataLength);

    // Cleanup.
    socket.close();
  }

  /**
   * <p>
   * Unit test the method {@link simplicity::SimpleEngineProtocol#send(unsigned char *, unsigned int const) send(unsigned char *, unsigned int const)}.
   * </p>
   */
  TEST_F(SimpleEngineProtocolTest, send)
  {
    // Create dependencies.
    io_service io_service;
    udp::resolver resolver(io_service);
    udp::socket socket(io_service);
    udp::endpoint sendingEndpoint;
    udp::endpoint receivingEndpoint = *resolver.resolve(udp::resolver::query(udp::v4(), "localhost", lexical_cast<string> (fTestObject.getRemotePort())));

    vector<unsigned char> sendData(10);
    sendData.at(0) = 0;
    sendData.at(1) = 1;
    sendData.at(2) = 2;
    sendData.at(3) = 3;
    sendData.at(4) = 4;
    sendData.at(5) = 5;
    sendData.at(6) = 6;
    sendData.at(7) = 7;
    sendData.at(8) = 8;
    sendData.at(9) = 9;

    unsigned char receiveHeaderData[16];

    vector<unsigned char> receiveData(10);
    array<mutable_buffer, 2> buffers;
    buffers.at(0) = buffer(receiveHeaderData, 16);
    buffers.at(1) = buffer(receiveData, 10);

    // Initialise test environment.
    fTestObject.getEndpointHostNames().push_back("localhost");
    fTestObject.init();

    socket.open(udp::v4());
    socket.bind(receivingEndpoint);

    // Perform test.
    fTestObject.send(sendData);

    socket.receive_from(buffers, sendingEndpoint);

    // Verify test results.
    ASSERT_EQ(0, receiveData[0]);
    ASSERT_EQ(1, receiveData[1]);
    ASSERT_EQ(2, receiveData[2]);
    ASSERT_EQ(3, receiveData[3]);
    ASSERT_EQ(4, receiveData[4]);
    ASSERT_EQ(5, receiveData[5]);
    ASSERT_EQ(6, receiveData[6]);
    ASSERT_EQ(7, receiveData[7]);
    ASSERT_EQ(8, receiveData[8]);
    ASSERT_EQ(9, receiveData[9]);

    // Cleanup.
    socket.close();
  }
}
