/*
    This file is part of The Simplicity Engine.

    The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
    by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

    The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
package com.se.simplicity.test.engine;

import static org.easymock.EasyMock.*;
import static org.junit.Assert.*;

import org.easymock.EasyMock;
import org.easymock.IMocksControl;
import org.junit.Before;
import org.junit.Test;

import com.se.simplicity.engine.Engine;
import com.se.simplicity.engine.SimpleCompositeEngine;
import com.se.simplicity.test.mocks.MockEngine;

/**
 * <p>
 * Unit tests for the class {@link com.se.simplicity.engine.SimpleCompositeEngine SimpleCompositeEngine}.
 * </p>
 * 
 * @author Gary Buyn
 */
public class SimpleCompositeEngineTest
{
    /**
     * An instance of the class being unit tested.
     */
    private SimpleCompositeEngine testObject;

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.engine.SimpleCompositeEngine.advance advance()}.
     * </p>
     */
    @Test
    public void advance()
    {
        IMocksControl mockControl = createStrictControl();
        Engine mockEngine1 = (Engine) mockControl.createMock(Engine.class);
        Engine mockEngine2 = (Engine) mockControl.createMock(Engine.class);
        Engine mockEngine3 = (Engine) mockControl.createMock(Engine.class);

        testObject.addEngine(mockEngine1);
        testObject.addEngine(mockEngine2);
        testObject.addEngine(mockEngine3);

        mockControl.reset();
        expect(mockEngine1.getPreferredFrequency()).andReturn(3);
        expect(mockEngine2.getPreferredFrequency()).andReturn(4);
        expect(mockEngine3.getPreferredFrequency()).andReturn(6);
        mockEngine1.init();
        mockEngine2.init();
        mockEngine3.init();

        // First advance.
        expect(mockEngine1.getPreferredFrequency()).andReturn(3);
        expect(mockEngine2.getPreferredFrequency()).andReturn(4);
        expect(mockEngine3.getPreferredFrequency()).andReturn(6);

        // Second advance.
        expect(mockEngine1.getPreferredFrequency()).andReturn(3);
        expect(mockEngine2.getPreferredFrequency()).andReturn(4);
        expect(mockEngine3.getPreferredFrequency()).andReturn(6);
        mockEngine3.advance();

        // Third advance.
        expect(mockEngine1.getPreferredFrequency()).andReturn(3);
        expect(mockEngine2.getPreferredFrequency()).andReturn(4);
        mockEngine2.advance();
        expect(mockEngine3.getPreferredFrequency()).andReturn(6);

        // Fourth advance.
        expect(mockEngine1.getPreferredFrequency()).andReturn(3);
        mockEngine1.advance();
        expect(mockEngine2.getPreferredFrequency()).andReturn(4);
        expect(mockEngine3.getPreferredFrequency()).andReturn(6);
        mockEngine3.advance();

        // Fifth advance.
        expect(mockEngine1.getPreferredFrequency()).andReturn(3);
        expect(mockEngine2.getPreferredFrequency()).andReturn(4);
        expect(mockEngine3.getPreferredFrequency()).andReturn(6);

        // Sixth advance.
        expect(mockEngine1.getPreferredFrequency()).andReturn(3);
        expect(mockEngine2.getPreferredFrequency()).andReturn(4);
        mockEngine2.advance();
        expect(mockEngine3.getPreferredFrequency()).andReturn(6);
        mockEngine3.advance();

        // Seventh advance.
        expect(mockEngine1.getPreferredFrequency()).andReturn(3);
        expect(mockEngine2.getPreferredFrequency()).andReturn(4);
        expect(mockEngine3.getPreferredFrequency()).andReturn(6);

        // Eighth advance.
        expect(mockEngine1.getPreferredFrequency()).andReturn(3);
        mockEngine1.advance();
        expect(mockEngine2.getPreferredFrequency()).andReturn(4);
        expect(mockEngine3.getPreferredFrequency()).andReturn(6);
        mockEngine3.advance();

        // Ninth advance.
        expect(mockEngine1.getPreferredFrequency()).andReturn(3);
        expect(mockEngine2.getPreferredFrequency()).andReturn(4);
        mockEngine2.advance();
        expect(mockEngine3.getPreferredFrequency()).andReturn(6);

        // Tenth advance.
        expect(mockEngine1.getPreferredFrequency()).andReturn(3);
        expect(mockEngine2.getPreferredFrequency()).andReturn(4);
        expect(mockEngine3.getPreferredFrequency()).andReturn(6);
        mockEngine3.advance();

        // Eleventh advance.
        expect(mockEngine1.getPreferredFrequency()).andReturn(3);
        expect(mockEngine2.getPreferredFrequency()).andReturn(4);
        expect(mockEngine3.getPreferredFrequency()).andReturn(6);

        // Twelfth advance.
        expect(mockEngine1.getPreferredFrequency()).andReturn(3);
        mockEngine1.advance();
        expect(mockEngine2.getPreferredFrequency()).andReturn(4);
        mockEngine2.advance();
        expect(mockEngine3.getPreferredFrequency()).andReturn(6);
        mockEngine3.advance();

        // Thirteenth advance.
        expect(mockEngine1.getPreferredFrequency()).andReturn(3);
        expect(mockEngine2.getPreferredFrequency()).andReturn(4);
        expect(mockEngine3.getPreferredFrequency()).andReturn(6);

        // Fourteenth advance.
        expect(mockEngine1.getPreferredFrequency()).andReturn(3);
        expect(mockEngine2.getPreferredFrequency()).andReturn(4);
        expect(mockEngine3.getPreferredFrequency()).andReturn(6);
        mockEngine3.advance();

        // Fifteenth advance.
        expect(mockEngine1.getPreferredFrequency()).andReturn(3);
        expect(mockEngine2.getPreferredFrequency()).andReturn(4);
        mockEngine2.advance();
        expect(mockEngine3.getPreferredFrequency()).andReturn(6);

        // Sixteenth advance.
        expect(mockEngine1.getPreferredFrequency()).andReturn(3);
        mockEngine1.advance();
        expect(mockEngine2.getPreferredFrequency()).andReturn(4);
        expect(mockEngine3.getPreferredFrequency()).andReturn(6);
        mockEngine3.advance();

        // Seventeenth advance.
        expect(mockEngine1.getPreferredFrequency()).andReturn(3);
        expect(mockEngine2.getPreferredFrequency()).andReturn(4);
        expect(mockEngine3.getPreferredFrequency()).andReturn(6);

        // Eighteenth advance.
        expect(mockEngine1.getPreferredFrequency()).andReturn(3);
        expect(mockEngine2.getPreferredFrequency()).andReturn(4);
        mockEngine2.advance();
        expect(mockEngine3.getPreferredFrequency()).andReturn(6);
        mockEngine3.advance();

        // Nineteenth advance.
        expect(mockEngine1.getPreferredFrequency()).andReturn(3);
        expect(mockEngine2.getPreferredFrequency()).andReturn(4);
        expect(mockEngine3.getPreferredFrequency()).andReturn(6);

        // Twentieth advance.
        expect(mockEngine1.getPreferredFrequency()).andReturn(3);
        mockEngine1.advance();
        expect(mockEngine2.getPreferredFrequency()).andReturn(4);
        expect(mockEngine3.getPreferredFrequency()).andReturn(6);
        mockEngine3.advance();

        // Twenty First advance.
        expect(mockEngine1.getPreferredFrequency()).andReturn(3);
        expect(mockEngine2.getPreferredFrequency()).andReturn(4);
        mockEngine2.advance();
        expect(mockEngine3.getPreferredFrequency()).andReturn(6);

        // Twenty Second advance.
        expect(mockEngine1.getPreferredFrequency()).andReturn(3);
        expect(mockEngine2.getPreferredFrequency()).andReturn(4);
        expect(mockEngine3.getPreferredFrequency()).andReturn(6);
        mockEngine3.advance();

        // Twenty Third advance.
        expect(mockEngine1.getPreferredFrequency()).andReturn(3);
        expect(mockEngine2.getPreferredFrequency()).andReturn(4);
        expect(mockEngine3.getPreferredFrequency()).andReturn(6);

        // Twenty Fourth advance.
        expect(mockEngine1.getPreferredFrequency()).andReturn(3);
        mockEngine1.advance();
        expect(mockEngine2.getPreferredFrequency()).andReturn(4);
        mockEngine2.advance();
        expect(mockEngine3.getPreferredFrequency()).andReturn(6);
        mockEngine3.advance();
        mockControl.replay();

        testObject.init();

        for (int index = 0; index < 24; index++)
        {
            testObject.advance();
        }

        mockControl.verify();
    }

    /**
     * <p>
     * Setup to perform before each unit test.
     * </p>
     */
    @Before
    public void before()
    {
        testObject = new SimpleCompositeEngine();
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.engine.SimpleCompositeEngine.getCompositeFrequency getCompositeFrequency()}.
     * </p>
     */
    @Test
    public void getCompositeFrequency()
    {
        Engine mockEngine1 = (Engine) createMock(Engine.class);
        Engine mockEngine2 = (Engine) createMock(Engine.class);
        Engine mockEngine3 = (Engine) createMock(Engine.class);

        testObject.addEngine(mockEngine1);
        testObject.addEngine(mockEngine2);
        testObject.addEngine(mockEngine3);

        EasyMock.reset(mockEngine1, mockEngine2, mockEngine3);
        expect(mockEngine1.getPreferredFrequency()).andReturn(3);
        expect(mockEngine2.getPreferredFrequency()).andReturn(4);
        expect(mockEngine3.getPreferredFrequency()).andReturn(6);
        replay(mockEngine1, mockEngine2, mockEngine3);

        assertEquals(testObject.getCompositeFrequency(), 12, 0);
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.engine.SimpleCompositeEngine.getCompositeFrequency getCompositeFrequency()} with the special
     * condition that the {@link com.se.simplicity.engine.SimpleCompositeEngine SimpleCompositeEngine} being tested does not have any sub-engines.
     * </p>
     */
    @Test
    public void getCompositeFrequencyNoEngines()
    {
        assertEquals(testObject.getCompositeFrequency(), 1, 0);
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.engine.SimpleCompositeEngine.reset reset()}.
     * </p>
     */
    @Test
    public void reset()
    {
        IMocksControl mockControl = createStrictControl();
        Engine mockEngine1 = (Engine) mockControl.createMock(Engine.class);
        Engine mockEngine2 = (Engine) mockControl.createMock(Engine.class);
        Engine mockEngine3 = (Engine) mockControl.createMock(Engine.class);

        testObject.addEngine(mockEngine1);
        testObject.addEngine(mockEngine2);
        testObject.addEngine(mockEngine3);

        mockControl.reset();
        expect(mockEngine1.getPreferredFrequency()).andReturn(3);
        expect(mockEngine2.getPreferredFrequency()).andReturn(4);
        expect(mockEngine3.getPreferredFrequency()).andReturn(6);
        mockEngine1.init();
        mockEngine2.init();
        mockEngine3.init();

        // First advance.
        expect(mockEngine1.getPreferredFrequency()).andReturn(3);
        expect(mockEngine2.getPreferredFrequency()).andReturn(4);
        expect(mockEngine3.getPreferredFrequency()).andReturn(6);

        // Second advance.
        expect(mockEngine1.getPreferredFrequency()).andReturn(3);
        expect(mockEngine2.getPreferredFrequency()).andReturn(4);
        expect(mockEngine3.getPreferredFrequency()).andReturn(6);
        mockEngine3.advance();

        // Third advance.
        expect(mockEngine1.getPreferredFrequency()).andReturn(3);
        expect(mockEngine2.getPreferredFrequency()).andReturn(4);
        mockEngine2.advance();
        expect(mockEngine3.getPreferredFrequency()).andReturn(6);

        // Fourth advance.
        expect(mockEngine1.getPreferredFrequency()).andReturn(3);
        mockEngine1.advance();
        expect(mockEngine2.getPreferredFrequency()).andReturn(4);
        expect(mockEngine3.getPreferredFrequency()).andReturn(6);
        mockEngine3.advance();

        // Fifth advance.
        expect(mockEngine1.getPreferredFrequency()).andReturn(3);
        expect(mockEngine2.getPreferredFrequency()).andReturn(4);
        expect(mockEngine3.getPreferredFrequency()).andReturn(6);

        // Reset.
        expect(mockEngine1.getPreferredFrequency()).andReturn(3);
        expect(mockEngine2.getPreferredFrequency()).andReturn(4);
        expect(mockEngine3.getPreferredFrequency()).andReturn(6);
        mockEngine1.reset();
        mockEngine2.reset();
        mockEngine3.reset();

        // First advance.
        expect(mockEngine1.getPreferredFrequency()).andReturn(3);
        expect(mockEngine2.getPreferredFrequency()).andReturn(4);
        expect(mockEngine3.getPreferredFrequency()).andReturn(6);

        // Second advance.
        expect(mockEngine1.getPreferredFrequency()).andReturn(3);
        expect(mockEngine2.getPreferredFrequency()).andReturn(4);
        expect(mockEngine3.getPreferredFrequency()).andReturn(6);
        mockEngine3.advance();

        // Third advance.
        expect(mockEngine1.getPreferredFrequency()).andReturn(3);
        expect(mockEngine2.getPreferredFrequency()).andReturn(4);
        mockEngine2.advance();
        expect(mockEngine3.getPreferredFrequency()).andReturn(6);

        // Fourth advance.
        expect(mockEngine1.getPreferredFrequency()).andReturn(3);
        mockEngine1.advance();
        expect(mockEngine2.getPreferredFrequency()).andReturn(4);
        expect(mockEngine3.getPreferredFrequency()).andReturn(6);
        mockEngine3.advance();

        // Fifth advance.
        expect(mockEngine1.getPreferredFrequency()).andReturn(3);
        expect(mockEngine2.getPreferredFrequency()).andReturn(4);
        expect(mockEngine3.getPreferredFrequency()).andReturn(6);

        // Sixth advance.
        expect(mockEngine1.getPreferredFrequency()).andReturn(3);
        expect(mockEngine2.getPreferredFrequency()).andReturn(4);
        mockEngine2.advance();
        expect(mockEngine3.getPreferredFrequency()).andReturn(6);
        mockEngine3.advance();

        // Seventh advance.
        expect(mockEngine1.getPreferredFrequency()).andReturn(3);
        expect(mockEngine2.getPreferredFrequency()).andReturn(4);
        expect(mockEngine3.getPreferredFrequency()).andReturn(6);

        // Eighth advance.
        expect(mockEngine1.getPreferredFrequency()).andReturn(3);
        mockEngine1.advance();
        expect(mockEngine2.getPreferredFrequency()).andReturn(4);
        expect(mockEngine3.getPreferredFrequency()).andReturn(6);
        mockEngine3.advance();

        // Ninth advance.
        expect(mockEngine1.getPreferredFrequency()).andReturn(3);
        expect(mockEngine2.getPreferredFrequency()).andReturn(4);
        mockEngine2.advance();
        expect(mockEngine3.getPreferredFrequency()).andReturn(6);

        // Tenth advance.
        expect(mockEngine1.getPreferredFrequency()).andReturn(3);
        expect(mockEngine2.getPreferredFrequency()).andReturn(4);
        expect(mockEngine3.getPreferredFrequency()).andReturn(6);
        mockEngine3.advance();

        // Eleventh advance.
        expect(mockEngine1.getPreferredFrequency()).andReturn(3);
        expect(mockEngine2.getPreferredFrequency()).andReturn(4);
        expect(mockEngine3.getPreferredFrequency()).andReturn(6);

        // Twelfth advance.
        expect(mockEngine1.getPreferredFrequency()).andReturn(3);
        mockEngine1.advance();
        expect(mockEngine2.getPreferredFrequency()).andReturn(4);
        mockEngine2.advance();
        expect(mockEngine3.getPreferredFrequency()).andReturn(6);
        mockEngine3.advance();
        mockControl.replay();

        testObject.init();

        for (int index = 0; index < 5; index++)
        {
            testObject.advance();
        }

        testObject.reset();

        for (int index = 0; index < 12; index++)
        {
            testObject.advance();
        }

        mockControl.verify();
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.engine.SimpleCompositeEngine.run run()}.
     * </p>
     * 
     * @throws InterruptedException If the test is interrupted while it is waiting for the {@link com.se.simplicity.engine.SimpleCompositeEngine
     * SimpleCompositeEngine} to run.
     */
    @Test
    public void run() throws InterruptedException
    {
        Engine mockEngine1 = (Engine) createMock(Engine.class);
        Engine mockEngine2 = (Engine) createMock(Engine.class);
        Engine mockEngine3 = (Engine) createMock(Engine.class);

        testObject.addEngine(mockEngine1);
        testObject.addEngine(mockEngine2);
        testObject.addEngine(mockEngine3);

        org.easymock.EasyMock.reset(mockEngine1, mockEngine2, mockEngine3);
        expect(mockEngine1.getPreferredFrequency()).andReturn(3).anyTimes();
        expect(mockEngine2.getPreferredFrequency()).andReturn(4).anyTimes();
        expect(mockEngine3.getPreferredFrequency()).andReturn(6).anyTimes();
        mockEngine1.init();
        mockEngine2.init();
        mockEngine3.init();
        mockEngine1.advance();
        mockEngine1.advance();
        mockEngine1.advance();
        mockEngine1.advance();
        mockEngine1.advance();
        mockEngine1.advance();
        mockEngine1.advance();
        mockEngine2.advance();
        mockEngine2.advance();
        mockEngine2.advance();
        mockEngine2.advance();
        mockEngine2.advance();
        mockEngine2.advance();
        mockEngine2.advance();
        mockEngine2.advance();
        mockEngine2.advance();
        mockEngine3.advance();
        mockEngine3.advance();
        mockEngine3.advance();
        mockEngine3.advance();
        mockEngine3.advance();
        mockEngine3.advance();
        mockEngine3.advance();
        mockEngine3.advance();
        mockEngine3.advance();
        mockEngine3.advance();
        mockEngine3.advance();
        mockEngine3.advance();
        mockEngine3.advance();
        mockEngine3.advance();
        mockEngine1.destroy();
        mockEngine2.destroy();
        mockEngine3.destroy();
        replay(mockEngine1, mockEngine2, mockEngine3);

        Thread engineThread = new Thread(testObject);
        engineThread.start();

        Thread.sleep(2400);

        engineThread.interrupt();
        engineThread.join();

        verify(mockEngine1, mockEngine2, mockEngine3);
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.engine.SimpleCompositeEngine.run run()} with the special condition that one of the sub-engines
     * runs longer than is allowed by its preferred frequency.
     * </p>
     * 
     * @throws InterruptedException If the test is interrupted while it is waiting for the {@link com.se.simplicity.engine.SimpleCompositeEngine
     * SimpleCompositeEngine} to run.
     */
    @Test
    public void runSubEngineOverrunFrequency() throws InterruptedException
    {
        MockEngine mockEngine = new MockEngine();
        mockEngine.setPreferredFrequency(5);

        testObject.addEngine(mockEngine);

        Thread engineThread = new Thread(testObject);
        engineThread.start();

        Thread.sleep(2500);

        engineThread.interrupt();
        engineThread.join();

        assertEquals(12, mockEngine.getMethodCallCountIgnoreParams("advance"), 0);
    }
}
