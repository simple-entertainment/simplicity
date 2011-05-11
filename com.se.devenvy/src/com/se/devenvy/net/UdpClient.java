package com.se.devenvy.net;

import java.io.IOException;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;

import org.apache.log4j.Logger;

/**
 * <p>
 * A client that can receive and send data to and from another <code>UdpClient</code> over an IP network using the UDP protocol.
 * </p>
 * 
 * @author Gary Buyn
 */
public abstract class UdpClient implements Client
{
    /**
     * <p>
     * Sends 'heartbeats' periodically to ensure the connection is still 'alive'.
     * </p>
     * 
     * @author Gary Buyn
     */
    public class Heartbeat implements Runnable
    {
        @Override
        public void run()
        {
            fLogger.debug("Heartbeat started.");

            try
            {
                do
                {
                    try
                    {
                        Thread.sleep(fHeartbeatInterval);

                        if (isConnected())
                        {
                            sendHeartbeat();
                        }
                    }
                    catch (InterruptedException e)
                    {
                        Thread.currentThread().interrupt();
                    }
                }
                while (isConnected() && !Thread.interrupted());
            }
            catch (Exception e)
            {
                fLogger.error("Failed to maintain heartbeat.");
            }

            fLogger.debug("Heartbeat stopped.");
        }
    }

    /**
     * <p>
     * The default data that is sent periodically to ensure the connection is still 'alive'.
     * </p>
     */
    private static final byte[] DEFAULT_HEARTBEAT_DATA = new byte[] {-1};

    /**
     * <p>
     * The default time interval between heartbeats (in milliseconds).
     * </p>
     */
    private static final int DEFAULT_HEARTBEAT_INTERVAL = 10000;

    /**
     * <p>
     * The default maximum number of bytes that can be received during a single call to {@link #receiveData()}.
     * </p>
     */
    private static final int DEFAULT_MAX_DATA_RECEIVABLE = 1024;

    /**
     * <p>
     * The bytes that have been received during the last call to {@link #receiveData()}.
     * </p>
     */
    private byte[] fData;

    /**
     * <p>
     * The socket over which the UDP data is sent and received.
     * </p>
     */
    private DatagramSocket fDatagramSocket;

    /**
     * <p>
     * The data that is sent periodically to ensure the connection is still 'alive'.
     * </p>
     */
    private byte[] fHeartbeatData;

    /**
     * <p>
     * The time interval between heartbeats (in milliseconds).
     * </p>
     */
    private int fHeartbeatInterval;

    /**
     * <p>
     * The thread on which the {@link Heartbeat} is running.
     * </p>
     */
    private Thread fHeartbeatThread;

    /**
     * <p>
     * Logs messages associated with this class.
     * </p>
     */
    private Logger fLogger;

    /**
     * <p>
     * The maximum number of bytes that can be received during a single call to {@link #receiveData()}.
     * </p>
     */
    private int fMaxDataReceivable;

    /**
     * <p>
     * The remote host with which this <code>UdpClient</code> is communicating.
     * </p>
     */
    private InetAddress fRemoteHost;

    /**
     * <p>
     * The remote port with which this <code>UdpClient</code> is communicating.
     * </p>
     */
    private int fRemotePort;

    /**
     * <p>
     * Creates an instance of <code>UdpClient</code>.
     * </p>
     * 
     * @param datagramSocket The socket over which the UDP data is sent and received.
     */
    public UdpClient(final DatagramSocket datagramSocket)
    {
        fData = null;
        fDatagramSocket = datagramSocket;
        fHeartbeatData = DEFAULT_HEARTBEAT_DATA;
        fHeartbeatInterval = DEFAULT_HEARTBEAT_INTERVAL;
        fHeartbeatThread = null;
        fLogger = Logger.getLogger(getClass());
        fMaxDataReceivable = DEFAULT_MAX_DATA_RECEIVABLE;
        fRemoteHost = null;
        fRemotePort = -1;
    }

    /**
     * <p>
     * Creates an instance of <code>UdpClient</code>.
     * </p>
     * 
     * @param datagramSocket The socket over which the UDP data is sent and received.
     * @param remoteHost The remote host with which this <code>UdpClient</code> is communicating.
     * @param remotePort The remote port with which this <code>UdpClient</code> is communicating.
     */
    public UdpClient(final DatagramSocket datagramSocket, final InetAddress remoteHost, final int remotePort)
    {
        fData = null;
        fDatagramSocket = datagramSocket;
        fHeartbeatData = DEFAULT_HEARTBEAT_DATA;
        fHeartbeatInterval = DEFAULT_HEARTBEAT_INTERVAL;
        fHeartbeatThread = null;
        fLogger = Logger.getLogger(getClass());
        fMaxDataReceivable = DEFAULT_MAX_DATA_RECEIVABLE;
        fRemoteHost = remoteHost;
        fRemotePort = remotePort;
    }

    @Override
    public void dispose() throws IOException
    {
        fDatagramSocket.close();
        maintainHeartbeat(false);
    }

    @Override
    public byte[] getHeartbeatData()
    {
        return (fHeartbeatData);
    }

    @Override
    public int getHeartbeatInterval()
    {
        return (fHeartbeatInterval);
    }

    @Override
    public int getMaxDataReceivable()
    {
        return (fMaxDataReceivable);
    }

    @Override
    public boolean isConnected()
    {
        return (!fDatagramSocket.isClosed());
    }

    /**
     * <p>
     * Determines whether the given data represents a 'heartbeat' sent to this <code>UdpClient</code>.
     * </p>
     * 
     * @param packet The data to compare against the 'heartbeat' data.
     * 
     * @return True if the given data represents a 'heartbeat' sent to this <code>UdpClient</code>, false otherwise.
     */
    private boolean isHeartbeat(final DatagramPacket packet)
    {
        boolean heartbeat = true;

        if (packet.getLength() != fHeartbeatData.length)
        {
            heartbeat = false;
        }
        else
        {
            for (int index = 0; index < fHeartbeatData.length; index++)
            {
                if (packet.getData()[index] != fHeartbeatData[index])
                {
                    heartbeat = false;
                    break;
                }
            }
        }

        return (heartbeat);
    }

    @Override
    public void maintainHeartbeat(final boolean maintainHeartbeat)
    {
        if (maintainHeartbeat)
        {
            // Start the heartbeat if it is not running.
            if (fHeartbeatThread == null || !fHeartbeatThread.isAlive())
            {
                fHeartbeatThread = new Thread(new Heartbeat());
                fHeartbeatThread.start();
            }
        }
        else
        {
            // Stop the heartbeat if it is running.
            if (fHeartbeatThread != null && fHeartbeatThread.isAlive())
            {
                fHeartbeatThread.interrupt();
            }
        }
    }

    /**
     * <p>
     * A callback that must be implemented by subclasses to process the data received.
     * </p>
     * 
     * @param packet The data received.
     */
    protected abstract void onReceiveData(final DatagramPacket packet);

    @Override
    public void receiveData() throws IOException
    {
        // Ensure the correct amount of data can be received.
        if (fData == null || fData.length != fMaxDataReceivable)
        {
            fData = new byte[fMaxDataReceivable];
        }

        try
        {
            DatagramPacket packet = new DatagramPacket(fData, fData.length);
            fDatagramSocket.receive(packet);

            if (isHeartbeat(packet))
            {
                fLogger.debug("Heartbeat received.");
            }
            else
            {
                onReceiveData(packet);
            }
        }
        catch (IOException e)
        {
            dispose();
        }
    }

    @Override
    public void sendData(final byte[] data) throws IOException
    {
        try
        {
            fDatagramSocket.send(new DatagramPacket(data, data.length, fRemoteHost, fRemotePort));
        }
        catch (IOException e)
        {
            dispose();
        }
    }

    /**
     * <p>
     * Sends a 'heartbeat'.
     * </p>
     * 
     * @throws IOException Thrown if the underlying datagram socket fails to send the 'heartbeat' data.
     */
    private void sendHeartbeat() throws IOException
    {
        sendData(fHeartbeatData);
    }

    @Override
    public void setHeartbeatData(final byte[] heartbeatData)
    {
        fHeartbeatData = heartbeatData;
    }

    @Override
    public void setHeartbeatInterval(final int heartbeatInterval)
    {
        fHeartbeatInterval = heartbeatInterval;
    }

    @Override
    public void setMaxDataReceivable(final int maxDataReceivable)
    {
        fMaxDataReceivable = maxDataReceivable;
    }

}
