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
import java.net.InetAddress;
import java.net.InetSocketAddress;
import java.net.NetworkInterface;
import java.net.Socket;
import java.net.SocketException;
import java.util.ArrayList;
import java.util.Date;
import java.util.Enumeration;
import java.util.List;

import org.apache.log4j.Logger;

/**
 * <p>
 * Sniffs the network for devices.
 * </p>
 * 
 * @author Gary Buyn
 */
public class Sniffer
{
    /**
     * <p>
     * The number of bytes in an IPv4 address.
     * </p>
     */
    private static final int BYTES_IN_IPV4 = 4;

    /**
     * <p>
     * The default amount of time to wait for a device to be found at an address.
     * </p>
     */
    private static final int DEFAULT_TIMEOUT = 1000;

    /**
     * <p>
     * Logs messages associated with this class.
     * </p>
     */
    private Logger fLogger;

    /**
     * <p>
     * The listeners for {@link Sniffer} events.
     * </p>
     */
    private List<SnifferListener> fSnifferListeners;

    /**
     * <p>
     * The amount of time to wait for a device to be found at an address.
     * </p>
     */
    private int fTimeout;

    /**
     * <p>
     * Creates an instance of <code>Sniffer</code>.
     * </p>
     */
    public Sniffer()
    {
        fLogger = Logger.getLogger(getClass());
        fSnifferListeners = new ArrayList<SnifferListener>();
        fTimeout = DEFAULT_TIMEOUT;
    }

    /**
     * <p>
     * Adds a listener for <code>Sniffer</code> events.
     * </p>
     * 
     * @param snifferListener The listener to add.
     */
    public void addSnifferListener(final SnifferListener snifferListener)
    {
        fSnifferListeners.add(snifferListener);
    }

    /**
     * <p>
     * Fires a 'device found' {@link Sniffer} event.
     * </p>
     * 
     * @param address The address of the device that was found.
     */
    private void fireConnectionFoundEvent(final InetAddress address)
    {
        for (SnifferListener snifferListener : fSnifferListeners)
        {
            snifferListener.deviceFound(address);
        }
    }

    /**
     * <p>
     * Retrieves the amount of time to wait for a device to be found at an address.
     * </p>
     * 
     * @return The amount of time to wait for a device to be found at an address.
     */
    public int getTimeout()
    {
        return (fTimeout);
    }

    /**
     * <p>
     * Removes a listener for <code>Sniffer</code> events.
     * </p>
     * 
     * @param snifferListener The listener to remove.
     */
    public void removeSnifferListener(final SnifferListener snifferListener)
    {
        fSnifferListeners.remove(snifferListener);
    }

    /**
     * <p>
     * Sets the amount of time to wait for a device to be found at an address.
     * </p>
     * 
     * @param timeout The amount of time to wait for a device to be found at an address.
     */
    public void setTimeout(final int timeout)
    {
        fTimeout = timeout;
    }

    /**
     * <p>
     * Scans all the IP addresses in the same subnet as the localhost address (assuming a subnet mask of 255.255.255.0) for devices.
     * </p>
     * 
     * @return The addresses of the devices found.
     * @throws SocketException Thrown upon failure to retrieve the localhost address.
     */
    public List<InetAddress> sniffSubnet() throws SocketException
    {
        Enumeration<NetworkInterface> networkInterfaces = NetworkInterface.getNetworkInterfaces();
        while (networkInterfaces.hasMoreElements())
        {
            Enumeration<InetAddress> addresses = networkInterfaces.nextElement().getInetAddresses();
            while (addresses.hasMoreElements())
            {
                InetAddress address = addresses.nextElement();
                if (!address.isLoopbackAddress())
                {
                    return (sniffSubnet(address));
                }
            }
        }

        return (null);
    }

    /**
     * <p>
     * Scans all the IP addresses in the same subnet as the given address (assuming a subnet mask of 255.255.255.0) for devices.
     * </p>
     * 
     * @param localAddress The address whose subnet will be scanned.
     * 
     * @return The addresses of the devices found.
     */
    public List<InetAddress> sniffSubnet(final InetAddress localAddress)
    {
        List<InetAddress> deviceAddresses = new ArrayList<InetAddress>();
        InetAddress deviceAddress = null;
        Date startTime = new Date();

        fLogger.debug("Searching for devices.");

        byte[] remoteIp = new byte[BYTES_IN_IPV4];
        System.arraycopy(localAddress.getAddress(), 0, remoteIp, 0, BYTES_IN_IPV4 - 1);

        // For every IP address in the subnet (assuming a subnet mask of 255.255.255.0).
        for (int ipByte4 = 1; ipByte4 < Math.pow(2, Byte.SIZE) && !Thread.interrupted(); ipByte4++)
        {
            try
            {
                // Get the address.
                remoteIp[BYTES_IN_IPV4 - 1] = (byte) ipByte4;
                deviceAddress = InetAddress.getByAddress(remoteIp);

                // Attempt to reach a device.
                if (deviceAddress.isReachable(fTimeout))
                {
                    fLogger.debug("Detected a device at address " + deviceAddress.getHostAddress());
                    deviceAddresses.add(deviceAddress);
                    fireConnectionFoundEvent(deviceAddress);
                }
            }
            catch (IOException e)
            {}
        }

        fLogger.debug("Found " + deviceAddresses.size() + " devices (took " + (new Date().getTime() - startTime.getTime()) + " milliseconds).");

        return (deviceAddresses);
    }

    /**
     * <p>
     * Scans all the IP addresses in the same subnet as the localhost address (assuming a subnet mask of 255.255.255.0) for devices for which TCP
     * connections can be made on the given port.
     * </p>
     * 
     * @param port The port to attempt a TCP connection on.
     * 
     * @return The addresses of the devices found.
     * @throws SocketException Thrown upon failure to retrieve the localhost address.
     */
    public List<InetAddress> sniffSubnetForTcpConnection(final int port) throws SocketException
    {
        Enumeration<NetworkInterface> networkInterfaces = NetworkInterface.getNetworkInterfaces();
        while (networkInterfaces.hasMoreElements())
        {
            Enumeration<InetAddress> addresses = networkInterfaces.nextElement().getInetAddresses();
            while (addresses.hasMoreElements())
            {
                InetAddress address = addresses.nextElement();
                if (!address.isLoopbackAddress())
                {
                    return (sniffSubnetForTcpConnection(port, address));
                }
            }
        }

        return (null);
    }

    /**
     * <p>
     * Scans all the IP addresses in the same subnet as the given address (assuming a subnet mask of 255.255.255.0) for devices for which TCP
     * connections can be made on the given port.
     * </p>
     * 
     * @param port The port to attempt a TCP connection on. *
     * @param localAddress The address whose subnet will be scanned.
     * 
     * @return The addresses of the devices found.
     */
    public List<InetAddress> sniffSubnetForTcpConnection(final int port, final InetAddress localAddress)
    {
        List<InetAddress> deviceAddresses = new ArrayList<InetAddress>();
        InetAddress deviceAddress = null;
        Date startTime = new Date();
        Socket socket = null;

        fLogger.debug("Searching for devices with TCP listening on port " + port + ".");

        byte[] remoteIp = new byte[BYTES_IN_IPV4];
        System.arraycopy(localAddress.getAddress(), 0, remoteIp, 0, BYTES_IN_IPV4 - 1);

        // For every IP address in the subnet (assuming a subnet mask of 255.255.255.0).
        for (int ipByte4 = 1; ipByte4 < Math.pow(2, Byte.SIZE) && !Thread.interrupted(); ipByte4++)
        {
            try
            {
                // Get the address.
                remoteIp[BYTES_IN_IPV4 - 1] = (byte) ipByte4;
                deviceAddress = InetAddress.getByAddress(remoteIp);

                // Attempt to connect to a device.
                socket = new Socket();
                socket.connect(new InetSocketAddress(deviceAddress, port), fTimeout);

                // If an exception was not thrown, the connection was successful. This confirms the presence of a server.
                fLogger.debug("Detected a device at address " + deviceAddress.getHostAddress());
                deviceAddresses.add(deviceAddress);
                fireConnectionFoundEvent(deviceAddress);
            }
            catch (IOException e)
            {}
            finally
            {
                if (socket != null)
                {
                    try
                    {
                        socket.close();
                    }
                    catch (IOException e)
                    {}
                }
            }
        }

        fLogger.debug("Found " + deviceAddresses.size() + " devices with TCP listening on port " + port + " (took "
                + (new Date().getTime() - startTime.getTime()) + " milliseconds).");

        return (deviceAddresses);
    }
}
