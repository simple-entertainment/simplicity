/*
    This file is part of Dev Envy.

    Dev Envy is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
    by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

    Dev Envy is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along with Dev Envy. If not, see <http://www.gnu.org/licenses/>.
 */
package com.se.devenvy.test.net;

import java.net.ServerSocket;
import java.net.Socket;

import com.se.devenvy.net.Client;
import com.se.devenvy.net.TcpServer;

/**
 * <p>
 * A mock implementation of a {@link com.se.devenvy.net.TcpServer TcpServer}. This implementation creates instances of {@link MockTcpClient}s.
 * </p>
 * 
 * @author Gary Buyn
 */
public class MockTcpServer extends TcpServer
{
    /**
     * <p>
     * Creates an instance of <code>MockTcpServer</code>.
     * </p>
     * 
     * @param serverSocket The {@link java.net.ServerSocket ServerSocket} listening for new connections.
     */
    public MockTcpServer(final ServerSocket serverSocket)
    {
        super(serverSocket);
    }

    @Override
    protected Client getClientInstance(final Socket socket)
    {
        return (new MockTcpClient(socket));
    }
}
