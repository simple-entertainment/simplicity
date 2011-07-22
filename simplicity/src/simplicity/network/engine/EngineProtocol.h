/*
 This file is part of The Simplicity Engine.

 The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
 by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

 The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

 You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef ENGINEPROTOCOL_H_
#define ENGINEPROTOCOL_H_

#include <string.h>
#include <vector>

namespace simplicity
{
  /**
   * <p>
   * A protocol used for communication between two or more engines across a network.
   * </p>
   *
   * @author Gary Buyn
   */
  class EngineProtocol
  {
    public:
      /**
       * <p>
       * Disposes of an instance of <code>EngineProtocol</code> (included to allow polymorphic deletion).
       * </p>
       */
      virtual
      ~EngineProtocol()
      {
      }

      /**
       * <p>
       * Retrieves the time a connection can stay idle before it is considered disconnected.
       * </p>
       *
       * @return The time a connection can stay idle before it is considered disconnected.
       */
      boost::posix_time::time_duration
      getDisconnectionTimeout() const;

      /**
       * <p>
       * Retrieves the host names of all the remote endpoints this protocol communicates with.
       * </p>
       *
       * @return The host names of all the remote endpoints this protocol communicates with.
       */
      std::vector<std::string> &
      getEndpointHostNames();

      /**
       * <p>
       * Retrieves the port this protocol is bound to locally.
       * </p>
       *
       * @return The port this protocol is bound to locally.
       */
      unsigned int
      getLocalPort() const;

      /**
       * <p>
       * Retrieves the maximum amount of data that can be sent or received in a single message.
       * </p>
       *
       * @return The maximum amount of data that can be sent or received in a single message.
       */
      unsigned int
      getMaxDataLength() const;

      /**
       * <p>
       * Retrieves the port this protocol sends messages to.
       * </p>
       *
       * @return The port this protocol sends messages to.
       */
      unsigned int
      getRemotePort() const;

      /**
       * <p>
       * Initialises this protocol.
       * </p>
       */
      void
      init();

      /**
       * <p>
       * Determines if this protocol is currently connected to a remote endpoint with the given host name.
       * </p>
       *
       * @param endpointHostName The host name of the remote endpoint whose connection status is to be checked.
       *
       * @return True if this protocol is currently connected to a remote endpoint with the given host name, false otherwise.
       */
      bool
      isConnectedTo(std::string const endpointHostName) const;

      bool
      isConnectionFlooded(std::string const endpointHostName) const;

      /**
       * <p>
       * Receives a message.
       * </p>
       *
       * @param data The address to write the received data to.
       *
       * @return The length of the message received.
       */
      unsigned int
      receive(unsigned char * const data);

      bool
      receivedMessage(std::string const endpointHostName, unsigned int const sequenceNumber) const;

      /**
       * <p>
       * Sends a message.
       * </p>
       *
       * @param data The address of the data to be sent.
       * @param dataLength The length of the data to be sent (in bytes).
       */
      void
      send(unsigned char * const data, unsigned int const dataLength);

      /**
       * <p>
       * Sets the time a connection can stay idle before it is considered disconnected.
       * </p>
       *
       * @param disconnectionTimeout The time a connection can stay idle before it is considered disconnected.
       */
      boost::posix_time::time_duration
      setDisconnectionTimeout(long const disconnectionTimeout);

      /**
       * <p>
       * Sets the port this protocol is bound to locally.
       * </p>
       *
       * @param port The port this protocol is bound to locally.
       */
      void
      setLocalPort(unsigned int const port);

      /**
       * <p>
       * Sets the maximum amount of data that can be sent or received in a single message.
       * </p>
       *
       * @param maxDataLength The maximum amount of data that can be sent or received in a single message.
       */
      void
      setMaxDataLength(unsigned int const maxDataLength);

      /**
       * <p>
       * Sets the port this protocol sends messages to.
       * </p>
       *
       * @param port The port this protocol sends messages to.
       */
      void
      setRemotePort(unsigned int const port);

      /**
       * <p>
       * Sets whether if this protocol supports communication to and from multiple remote endpoints.
       * </p>
       *
       * @param supportMultipleEndpoints Determines if this protocol supports communication to and from multiple remote endpoints.
       */
      void
      setSupportsMultipleEndpoints(bool const supportMultipleEndpoints);

      /**
       * <p>
       * Determines if this protocol supports communication to and from multiple remote endpoints.
       * </p>
       *
       * @return True if this protocol supports communication to and from multiple remote endpoints, false otherwise.
       */
      bool
      supportsMultipleEndpoints();
  };
}

#endif /* ENGINEPROTOCOL_H_ */
