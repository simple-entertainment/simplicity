package com.se.devenvy.net;

import java.io.IOException;

import org.apache.log4j.Logger;

/**
 * <p>
 * Continually listens for data.
 * </p>
 * 
 * @author Gary Buyn
 */
public class UdpServer implements Runnable, Server
{
    /**
     * <p>
     * Logs messages associated with this class.
     * </p>
     */
    private Logger fLogger;

    /**
     * <p>
     * The {@link UdpClient} used to listen for the data.
     * </p>
     */
    private UdpClient fServerClient;

    /**
     * <p>
     * Creates an instance of <code>UdpServer</code>.
     * </p>
     * 
     * @param serverClient The {@link UdpClient} used to listen for the data.
     */
    public UdpServer(final UdpClient serverClient)
    {
        fServerClient = serverClient;

        fLogger = Logger.getLogger(getClass());
    }

    @Override
    public void dispose() throws IOException
    {
        fServerClient.dispose();
    }

    @Override
    public void run()
    {
        try
        {
            // While the server's client is connected.
            while (fServerClient.isConnected())
            {
                fServerClient.receiveData();
            }
        }
        catch (Exception e)
        {
            fLogger.fatal("The connection to the client has been unexpectedly terminated.", e);
        }
    }
}
