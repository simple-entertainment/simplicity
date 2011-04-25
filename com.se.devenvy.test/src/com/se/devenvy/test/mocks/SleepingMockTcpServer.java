package com.se.devenvy.test.mocks;

import java.net.ServerSocket;
import java.net.Socket;

import com.se.devenvy.net.Client;
import com.se.devenvy.net.TcpServer;

/**
 * <p>
 * A mock implementation of a {@link com.se.devenvy.net.TcpServer TcpServer}. This implementation creates instances of {@link SleepingMockTcpClient}s.
 * </p>
 * 
 * @author Gary Buyn
 */
public class SleepingMockTcpServer extends TcpServer
{
    /**
     * <p>
     * Creates an instance of <code>SleepingMockTcpServer</code>.
     * </p>
     * 
     * @param serverSocket The {@link java.net.ServerSocket ServerSocket} listening for new connections.
     */
    public SleepingMockTcpServer(final ServerSocket serverSocket)
    {
        super(serverSocket);
    }

    @Override
    protected Client getClientInstance(final Socket socket)
    {
        return (new SleepingMockTcpClient(socket));
    }
}
