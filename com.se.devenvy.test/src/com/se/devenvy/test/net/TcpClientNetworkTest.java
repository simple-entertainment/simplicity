package com.se.devenvy.test.net;

import static org.junit.Assert.assertArrayEquals;
import static org.junit.Assert.assertFalse;
import static org.junit.Assert.assertTrue;

import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;
import java.net.SocketException;

import org.junit.After;
import org.junit.Before;
import org.junit.Test;

/**
 * <p>
 * Tests for the class {@link com.se.devenvy.net.TcpClient TcpClient} with actual network communication.
 * </p>
 * 
 * @author Gary Buyn
 */
public class TcpClientNetworkTest
{
    /**
     * <p>
     * The {@link java.net.ServerSocket ServerSocket} used to retrieve the receiver's {@link java.net.Socket Socket}.
     * </p>
     */
    private ServerSocket fReceiverServer;

    /**
     * <p>
     * The receiver's {@link java.net.Socket Socket}.
     * </p>
     */
    private Socket fReceiverSocket;

    /**
     * <p>
     * The sender's {@link java.net.Socket Socket}.
     * </p>
     */
    private Socket fSenderSocket;

    /**
     * <p>
     * Tear-down to perform after each unit test.
     * </p>
     * 
     * @throws IOException Thrown if an I/O error occurs.
     */
    @After
    public void after() throws IOException
    {
        fSenderSocket.close();
        fReceiverSocket.close();
        fReceiverServer.close();
    }

    /**
     * <p>
     * Setup to perform before each unit test.
     * </p>
     * 
     * @throws IOException Thrown if an I/O error occurs.
     */
    @Before
    public void before() throws IOException
    {
        fReceiverServer = new ServerSocket(10999);
        fSenderSocket = new Socket("localhost", 10999);
        fReceiverSocket = fReceiverServer.accept();
    }

    /**
     * <p>
     * Test receiving data after the receiver's {@link java.net.Socket Socket} has been closed.
     * </p>
     * 
     * @throws IOException Thrown if an I/O error occurs.
     */
    @Test(expected = SocketException.class)
    public void receiveClosedByReceiver() throws IOException
    {
        // Initialise test environment.
        MockTcpClient client1 = new MockTcpClient(fSenderSocket);
        MockTcpClient client2 = new MockTcpClient(fReceiverSocket);

        // Perform test - verify test results.
        client1.sendData("XYZ".getBytes());
        client2.dispose();
        client2.receiveData();
    }

    /**
     * <p>
     * Test receiving data after the sender's {@link java.net.Socket Socket} has been closed.
     * </p>
     * 
     * @throws IOException Thrown if an I/O error occurs.
     */
    @Test
    public void receiveClosedBySender() throws IOException
    {
        // Initialise test environment.
        MockTcpClient client1 = new MockTcpClient(fSenderSocket);
        MockTcpClient client2 = new MockTcpClient(fReceiverSocket);

        assertTrue(client2.isConnected());

        // Perform test.
        client1.dispose();
        client2.receiveData();

        // Verify test results.
        assertFalse(client2.isConnected());
    }

    /**
     * <p>
     * Test sending and receiving data.
     * </p>
     * 
     * @throws IOException Thrown if an I/O error occurs.
     */
    @Test
    public void sendAndReceive() throws IOException
    {
        // Initialise test environment.
        MockTcpClient client1 = new MockTcpClient(fSenderSocket);
        MockTcpClient client2 = new MockTcpClient(fReceiverSocket);

        // Perform test.
        client1.sendData("XYZ".getBytes());
        client2.receiveData();

        // Verify test results.
        byte[] expected = new byte[1024];
        expected[0] = 'X';
        expected[1] = 'Y';
        expected[2] = 'Z';
        assertArrayEquals(expected, client2.getReceivedData());
    }

    /**
     * <p>
     * Test sending data after the receiver's {@link java.net.Socket Socket} has been closed.
     * </p>
     * 
     * @throws IOException Thrown if an I/O error occurs.
     */
    @Test
    public void sendClosedByReceiver() throws IOException
    {
        // Initialise test environment.
        MockTcpClient client1 = new MockTcpClient(fSenderSocket);
        MockTcpClient client2 = new MockTcpClient(fReceiverSocket);

        assertTrue(client1.isConnected());

        // Perform test.
        client2.dispose();
        client1.sendData("XYZ".getBytes());
        client1.sendData("XYZ".getBytes());

        // Verify test results.
        assertFalse(client1.isConnected());
    }

    /**
     * <p>
     * Test sending data after the sender's {@link java.net.Socket Socket} has been closed.
     * </p>
     * 
     * @throws IOException Thrown if an I/O error occurs.
     */
    @Test(expected = SocketException.class)
    public void sendClosedBySender() throws IOException
    {
        // Initialise test environment.
        MockTcpClient client1 = new MockTcpClient(fSenderSocket);

        // Perform test - verify test results.
        client1.dispose();
        client1.sendData("XYZ".getBytes());
    }
}
