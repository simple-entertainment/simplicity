package com.se.devenvy.test.mocks;

import java.net.Socket;

import com.se.devenvy.net.TcpClient;

/**
 * <p>
 * A mock implementation of a {@link com.se.devenvy.net.TcpClient TcpClient}. This implementation sleeps for one second every time
 * {@link #receiveData()} is called.
 * </p>
 * 
 * @author Gary Buyn
 */
public class SleepingMockTcpClient extends TcpClient
{
    /**
     * <p>
     * Creates an instance of <code>SleepingMockTcpClient</code>.
     * </p>
     * 
     * @param socket The socket over which the TCP connection is made.
     */
    public SleepingMockTcpClient(final Socket socket)
    {
        super(socket);
    }

    @Override
    protected void onReceiveData(final byte[] data)
    {
        try
        {
            Thread.sleep(1000);
        }
        catch (InterruptedException e)
        {
            e.printStackTrace();
        }
    }
}
