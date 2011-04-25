/*
    This file is part of Dev Envy.

    Dev Envy is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
    by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

    Dev Envy is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along with Dev Envy. If not, see <http://www.gnu.org/licenses/>.
 */
package com.se.devenvy.net;

import java.io.IOException;

/**
 * <p>
 * A client that can receive and send data to and from another <code>Client</code> over an IP network. It also implements a 'keep alive' system
 * whereby it sends 'heartbeats' periodically to ensure the connection is still 'alive'.
 * </p>
 * 
 * @author Gary Buyn
 */
public interface Client
{
    /**
     * <p>
     * Closes the connection to the client.
     * </p>
     * 
     * @throws IOException Thrown if the client connection closure fails.
     */
    void dispose() throws IOException;

    /**
     * <p>
     * The data that is sent periodically to ensure the connection is still 'alive'. The default is a single byte with the value -1. It is recommended
     * that this value is changed if it could ever be construed as a valid communication.
     * </p>
     * 
     * @return The data that is sent periodically to ensure the connection is still 'alive'.
     */
    byte[] getHeartbeatData();

    /**
     * <p>
     * The time interval between heartbeats (in milliseconds). The default is 1000 (one second).
     * </p>
     * 
     * @return The time interval between heartbeats (in milliseconds).
     */
    int getHeartbeatInterval();

    /**
     * <p>
     * The maximum number of bytes that can be received during a single call to {@link #receiveData()}. The default is 1024 bytes.
     * </p>
     * 
     * @return The maximum number of bytes that can be received during a single call to <code>receiveData()</code>.
     */
    int getMaxDataReceivable();

    /**
     * <p>
     * Determines whether this <code>Client</code> is connected to a 'living' connection. Unlike {@link java.net.Socket Socket}s, a
     * <code>Client</code> is only said to be connected as if the connection is 'alive'. Once the connection is closed by either party, or due to a
     * lack of response to a 'heartbeat', this <code>Client</code> is said to be disconnected.
     * </p>
     * 
     * @return Determines whether this <code>Client</code> is connected to a 'living' connection.
     */
    boolean isConnected();

    /**
     * <p>
     * Determines whether this <code>Client</code> sends 'heartbeats' periodically to ensure the connection is still 'alive'.
     * </p>
     * 
     * @param maintainHeartbeat Determines whether this <code>Client</code> sends 'heartbeats' periodically to ensure the connection is still 'alive'.
     */
    void maintainHeartbeat(boolean maintainHeartbeat);

    /**
     * <p>
     * Receives data from the <code>Client</code> at the other end of the connection. Blocks until data is received or the connection 'dies'.
     * </p>
     * 
     * @throws IOException Thrown if the underlying socket fails to receive the data.
     */
    void receiveData() throws IOException;

    /**
     * <p>
     * Sends data to the <code>Client</code> at the other end of the connection.
     * </p>
     * 
     * @param data The data to send.
     * 
     * @throws IOException Thrown if the underlying socket fails to send the data.
     */
    void sendData(byte[] data) throws IOException;

    /**
     * <p>
     * The data that is sent periodically to ensure the connection is still 'alive'. The default is a single byte with the value -1. It is recommended
     * that this value is changed if it could ever be construed as a valid communication.
     * </p>
     * 
     * @param heartbeatData The data that is sent periodically to ensure the connection is still 'alive'.
     */
    void setHeartbeatData(byte[] heartbeatData);

    /**
     * <p>
     * The time interval between heartbeats (in milliseconds). The default is 1000 (one second).
     * </p>
     * 
     * @param heartbeatInterval The time interval between heartbeats (in milliseconds).
     */
    void setHeartbeatInterval(int heartbeatInterval);

    /**
     * <p>
     * The maximum number of bytes that can be received during a single call to {@link #receiveData()}. The default is 1024 bytes.
     * </p>
     * 
     * @param maxDataReceivable The maximum number of bytes that can be received during a single call to <code>receiveData()</code>.
     */
    void setMaxDataReceivable(int maxDataReceivable);
}
