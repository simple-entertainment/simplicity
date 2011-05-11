/*
    This file is part of Dev Envy.

    Dev Envy is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
    by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

    Dev Envy is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along with Dev Envy. If not, see <http://www.gnu.org/licenses/>.
 */
package com.se.devenvy.test.net;

import static org.easymock.EasyMock.anyObject;
import static org.easymock.EasyMock.eq;
import static org.easymock.EasyMock.expect;
import static org.easymock.EasyMock.expectLastCall;
import static org.easymock.classextension.EasyMock.createMock;
import static org.easymock.classextension.EasyMock.makeThreadSafe;
import static org.easymock.classextension.EasyMock.replay;
import static org.easymock.classextension.EasyMock.verify;
import static org.junit.Assert.assertArrayEquals;

import java.io.IOException;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;
import java.net.SocketException;

import org.junit.Test;

/**
 * <p>
 * Unit tests for the class {@link com.se.devenvy.net.UdpClient UdpClient}.
 * </p>
 * 
 * @author Gary Buyn
 */
public class UdpClientTest
{
    /**
     * An instance of the class being unit tested.
     */
    private MockUdpClient fTestObject;

    /**
     * <p>
     * Unit test the method {@link com.se.devenvy.net.UdpClient#dispose() dispose()}.
     * </p>
     * 
     * @throws IOException Thrown if an I/O error occurs.
     */
    @Test
    public void dispose() throws IOException
    {
        // Create dependencies.
        DatagramSocket mockDatagramSocket = createMock(DatagramSocket.class);

        // Dictate correct results.
        mockDatagramSocket.close();
        replay(mockDatagramSocket);

        // Initialise test environment.
        fTestObject = new MockUdpClient(mockDatagramSocket);

        // Perform test.
        fTestObject.dispose();

        // Verify test results.
        verify(mockDatagramSocket);
    }

    /**
     * <p>
     * Unit test the method {@link com.se.devenvy.net.UdpClient.Heartbeat#run() run()}.
     * </p>
     * 
     * @throws IOException Thrown if an I/O error occurs.
     * @throws InterruptedException Thrown if this test is interrupted.
     */
    @Test
    public void heartbeatRun() throws IOException, InterruptedException
    {
        // Create dependencies.
        DatagramSocket mockDatagramSocket = createMock(DatagramSocket.class);

        // Initialise test environment.
        fTestObject = new MockUdpClient(mockDatagramSocket, InetAddress.getLocalHost(), 10998);
        fTestObject.setHeartbeatInterval(500);

        // Dictate correct behaviour.
        expect(mockDatagramSocket.isConnected()).andStubReturn(true);
        expect(mockDatagramSocket.isClosed()).andStubReturn(false);
        expect(mockDatagramSocket.getRemoteSocketAddress()).andStubReturn(null);
        makeThreadSafe(mockDatagramSocket, true);

        // Dictate expected results.
        mockDatagramSocket.send((DatagramPacket) anyObject());
        expectLastCall().times(2);
        mockDatagramSocket.close();
        replay(mockDatagramSocket);

        // Perform test.
        fTestObject.maintainHeartbeat(true);
        Thread.sleep(1250);
        fTestObject.dispose();
    }

    /**
     * <p>
     * Unit test the method {@link com.se.devenvy.net.UdpClient#receiveData() receiveData()} with the special condition that the connection has been
     * closed locally.
     * </p>
     * 
     * @throws IOException Thrown if an I/O error occurs.
     */
    @Test
    public void receiveDataClosedLocally() throws IOException
    {
        // Create dependencies.
        DatagramSocket mockDatagramSocket = createMock(DatagramSocket.class);

        // Initialise test environment.
        fTestObject = new MockUdpClient(mockDatagramSocket);

        // Dictate correct behaviour.
        mockDatagramSocket.receive((DatagramPacket) anyObject());
        expectLastCall().andStubThrow(new SocketException("Socket closed"));
        expect(mockDatagramSocket.getRemoteSocketAddress()).andStubReturn(null);

        // Dictate expected results.
        mockDatagramSocket.close();
        replay(mockDatagramSocket);

        // Perform test.
        fTestObject.receiveData();

        // Verify test results.
        verify(mockDatagramSocket);
    }

    /**
     * <p>
     * Unit test the method {@link com.se.devenvy.net.UdpClient#receiveData() receiveData()} with the special condition that a
     * {@link java.net.SocketException SocketException} other than "Socket closed" occurs.
     * </p>
     * 
     * @throws IOException Thrown if an I/O error occurs.
     */
    public void receiveDataOtherIOException() throws IOException
    {
        // Create dependencies.
        DatagramSocket mockDatagramSocket = createMock(DatagramSocket.class);

        // Dictate correct behaviour.
        mockDatagramSocket.receive((DatagramPacket) anyObject());
        expectLastCall().andStubThrow(new IOException("Unknown"));

        // Dictate expected results.
        mockDatagramSocket.close();
        replay(mockDatagramSocket);

        // Initialise test environment.
        fTestObject = new MockUdpClient(mockDatagramSocket);

        // Perform test.
        fTestObject.receiveData();

        // Verify test results.
        verify(mockDatagramSocket);
    }

    /**
     * <p>
     * Unit test the method {@link com.se.devenvy.net.UdpClient#sendData() sendData()}.
     * </p>
     * 
     * @throws IOException Thrown if an I/O error occurs.
     */
    @Test
    public void sendData() throws IOException
    {
        // Create dependencies.
        DatagramSocket mockDatagramSocket = createMock(DatagramSocket.class);

        // Dictate expected results.
        mockDatagramSocket.send((DatagramPacket) anyObject());
        replay(mockDatagramSocket);

        // Initialise test environment.
        fTestObject = new MockUdpClient(mockDatagramSocket, InetAddress.getLocalHost(), 10998);

        // Perform test.
        fTestObject.sendData("XYZ".getBytes());

        // Verify test results.
        verify(mockDatagramSocket);
    }

    /**
     * <p>
     * Unit test the method {@link com.se.devenvy.net.UdpClient#sendData() sendData()}.
     * </p>
     * 
     * @throws IOException Thrown if an I/O error occurs.
     */
    public void sendDataClosedLocally() throws IOException
    {
        // Create dependencies.
        DatagramSocket mockDatagramSocket = createMock(DatagramSocket.class);

        // Dictate correct behaviour.
        mockDatagramSocket.send((DatagramPacket) anyObject());
        expectLastCall().andStubThrow(new SocketException("Socket is closed"));
        replay(mockDatagramSocket);

        // Dictate expected results.
        mockDatagramSocket.close();
        replay(mockDatagramSocket);

        // Initialise test environment.
        fTestObject = new MockUdpClient(mockDatagramSocket, InetAddress.getLocalHost(), 10998);

        // Perform test.
        fTestObject.sendData("XYZ".getBytes());

        // Verify test results.
        verify(mockDatagramSocket);
    }
}
