/*
    This file is part of The Simplicity Engine.

    The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
    by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

    The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
package com.se.simplicity.test.engine;

import static org.junit.Assert.assertEquals;

import org.junit.Before;
import org.junit.Test;

import com.se.simplicity.engine.SEEngineAdvancementException;
import com.se.simplicity.test.mocks.OverrunningMockRunnableEngine;

/**
 * <p>
 * Unit tests for the class {@link com.se.simplicity.engine.RunnableEngine RunnableEngine}.
 * </p>
 * 
 * @author Gary Buyn
 */
public class RunnableEngineTest
{
    /**
     * An instance of the class being unit tested.
     */
    private OverrunningMockRunnableEngine fTestObject;

    /**
     * <p>
     * Setup to perform before each unit test.
     * </p>
     */
    @Before
    public void before()
    {
        fTestObject = new OverrunningMockRunnableEngine();
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.engine.RunnableEngine#run() run()}.
     * </p>
     * 
     * @throws InterruptedException If the test is interrupted while it is waiting for the {@link com.se.simplicity.engine.RunnableEngine
     * RunnableEngine} to run.
     * @throws SEEngineAdvancementException Thrown if the engine fails to advance.
     */
    @Test
    public void run() throws InterruptedException, SEEngineAdvancementException
    {
        // Initialise test environment.
        fTestObject.setPreferredFrequency(5);

        // Perform test.
        Thread engineThread = new Thread(fTestObject);
        engineThread.start();

        Thread.sleep(2500);

        engineThread.interrupt();
        engineThread.join();

        // Verify test results.
        assertEquals(1, fTestObject.getMethodCallCountIgnoreParams("init"), 0);
        assertEquals(12, fTestObject.getMethodCallCountIgnoreParams("advance"), 0);
        assertEquals(1, fTestObject.getMethodCallCountIgnoreParams("destroy"), 0);
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.engine.RunnableEngine#run() run()} with the special condition that it runs longer than is allowed
     * by its preferred frequency.
     * </p>
     * 
     * @throws InterruptedException If the test is interrupted while it is waiting for the {@link com.se.simplicity.engine.RunnableEngine
     * RunnableEngine} to run.
     */
    @Test
    public void runOverrunFrequency() throws InterruptedException
    {
        // Initialise test environment.
        fTestObject.setPreferredFrequency(5);
        fTestObject.setOverrunIndex(2);

        // Perform test.
        Thread engineThread = new Thread(fTestObject);
        engineThread.start();

        Thread.sleep(2500);

        engineThread.interrupt();
        engineThread.join();

        // Verify test results.
        assertEquals(12, fTestObject.getMethodCallCountIgnoreParams("advance"), 0);
    }
}
