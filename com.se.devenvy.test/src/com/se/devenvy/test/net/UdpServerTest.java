/*
    This file is part of Dev Envy.

    Dev Envy is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
    by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

    Dev Envy is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along with Dev Envy. If not, see <http://www.gnu.org/licenses/>.
 */
package com.se.devenvy.test.net;

import static org.easymock.EasyMock.expect;
import static org.easymock.classextension.EasyMock.createMock;
import static org.easymock.classextension.EasyMock.replay;
import static org.easymock.classextension.EasyMock.verify;

import java.io.IOException;

import org.junit.Test;

import com.se.devenvy.net.UdpClient;
import com.se.devenvy.net.UdpServer;

/**
 * <p>
 * Unit tests for the class {@link com.se.devenvy.net.UdpServer UdpServer}.
 * </p>
 * 
 * @author Gary Buyn
 */
public class UdpServerTest
{
    /**
     * An instance of the class being unit tested.
     */
    private UdpServer fTestObject;

    /**
     * <p>
     * Unit test the method {@link com.se.devenvy.net.UdpServer#dispose() dispose()}.
     * </p>
     * 
     * @throws IOException Thrown if an I/O error occurs.
     * @throws InterruptedException Thrown if this thread is interrupted while waiting for the <code>UdpServer</code> to be disposed.
     */
    @Test
    public void dispose() throws IOException, InterruptedException
    {
        // Create dependencies.
        UdpClient mockUdpClient = createMock(UdpClient.class);

        // Dictate correct results.
        mockUdpClient.dispose();
        replay(mockUdpClient);

        // Initialise test environment.
        fTestObject = new UdpServer(mockUdpClient);

        // Perform test.
        fTestObject.dispose();

        // Verify test results.
        verify(mockUdpClient);
    }

    /**
     * <p>
     * Unit test the method {@link com.se.devenvy.net.UdpServer#run() run()}.
     * </p>
     * 
     * @throws IOException Thrown if an I/O error occurs.
     * 
     * @throws InterruptedException Thrown if this test is interrupted.
     */
    @Test
    public void run() throws IOException, InterruptedException
    {
        // Create dependencies.
        UdpClient mockUdpClient = createMock(UdpClient.class);

        // Dictate expected results.
        expect(mockUdpClient.isConnected()).andReturn(true);
        mockUdpClient.receiveData();
        expect(mockUdpClient.isConnected()).andReturn(false);
        mockUdpClient.dispose();
        replay(mockUdpClient);

        // Initialise test environment.
        fTestObject = new UdpServer(mockUdpClient);

        // Perform test.
        fTestObject.run();
        Thread.sleep(500);
        fTestObject.dispose();

        // Verify test results.
        verify(mockUdpClient);
    }
}
