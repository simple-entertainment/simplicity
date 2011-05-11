package com.se.devenvy.test.net;

import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;

import com.se.devenvy.net.UdpClient;

/**
 * <p>
 * A mock implementation of a {@link com.se.devenvy.net.UdpClient UdpClient}.
 * </p>
 * 
 * @author Gary Buyn
 */
public class MockUdpClient extends UdpClient
{
    /**
     * <p>
     * The data received during the last call to {@link #receiveData()}.
     * </p>
     */
    private DatagramPacket fReceivedData;

    /**
     * <p>
     * Creates an instance of <code>MockUdpClient</code>.
     * </p>
     * 
     * @param datagramSocket The socket over which the UDP data is sent and received.
     */
    public MockUdpClient(final DatagramSocket datagramSocket)
    {
        super(datagramSocket);

        fReceivedData = null;
    }

    /**
     * <p>
     * Creates an instance of <code>MockUdpClient</code>.
     * </p>
     * 
     * @param datagramSocket The socket over which the UDP data is sent and received.
     * @param remoteHost The remote host with which this <code>UdpClient</code> is communicating.
     * @param remotePort The remote port with which this <code>UdpClient</code> is communicating.
     */
    public MockUdpClient(final DatagramSocket datagramSocket, final InetAddress remoteHost, final int remotePort)
    {
        super(datagramSocket, remoteHost, remotePort);

        fReceivedData = null;
    }

    /**
     * <p>
     * Retrieves the data received during the last call to {@link #receiveData()}.
     * </p>
     * 
     * @return The data received during the last call to <code>receiveData()</code>.
     */
    public DatagramPacket getReceivedData()
    {
        return (fReceivedData);
    }

    @Override
    protected void onReceiveData(final DatagramPacket packet)
    {
        fReceivedData = packet;
    }
}
