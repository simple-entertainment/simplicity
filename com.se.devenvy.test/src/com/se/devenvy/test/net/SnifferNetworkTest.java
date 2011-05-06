/*
    This file is part of Dev Envy.

    Dev Envy is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
    by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

    Dev Envy is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along with Dev Envy. If not, see <http://www.gnu.org/licenses/>.
 */
package com.se.devenvy.test.net;

import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertTrue;

import java.io.IOException;
import java.net.InetAddress;
import java.net.ServerSocket;
import java.net.UnknownHostException;
import java.util.List;

import org.junit.Before;
import org.junit.Test;

import com.se.devenvy.net.Sniffer;

/**
 * <p>
 * Tests for the class {@link com.se.devenvy.net.Sniffer Sniffer} with actual network communication.
 * </p>
 * 
 * @author Gary Buyn
 */
public class SnifferNetworkTest
{
    /**
     * An instance of the class being unit tested.
     */
    private Sniffer fTestObject;

    /**
     * <p>
     * Setup to perform before each unit test.
     * </p>
     */
    @Before
    public void before()
    {
        fTestObject = new Sniffer();
    }

    /**
     * <p>
     * Test sniffing for devices in the subnet.
     * </p>
     * 
     * @throws UnknownHostException Thrown upon failure to retrieve the localhost address.
     */
    @Test
    public void sniffSubnet() throws UnknownHostException
    {
        // Initialise test environment.
        fTestObject.setTimeout(100);

        // Perform test.
        List<InetAddress> serverAddresses = fTestObject.sniffSubnet(InetAddress.getByName(InetAddress.getLocalHost().getHostName() + ".local"));

        // Verify test results.
        assertTrue(serverAddresses.size() >= 1);
    }

    /**
     * <p>
     * Test sniffing for devices for which TCP connections can be made in the subnet.
     * </p>
     * 
     * @throws IOException Thrown if an I/O error occurs.
     */
    @Test
    public void sniffSubnetForTcpConnection() throws IOException
    {
        // Create dependencies.
        final ServerSocket server = new ServerSocket(10999);

        // Initialise test environment.
        fTestObject.setTimeout(100);
        Thread acceptThread = new Thread()
        {
            @Override
            public void run()
            {
                try
                {
                    server.accept();
                }
                catch (IOException e)
                {}
            }
        };
        acceptThread.start();

        // Perform test.
        List<InetAddress> serverAddresses = fTestObject.sniffSubnetForTcpConnection(10999,
                InetAddress.getByName(InetAddress.getLocalHost().getHostName() + ".local"));

        // Verify test results.
        assertEquals(1, serverAddresses.size());

        // Cleanup.
        server.close();
    }
}
