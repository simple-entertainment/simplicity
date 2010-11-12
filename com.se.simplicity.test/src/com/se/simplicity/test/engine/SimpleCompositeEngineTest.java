/*
    This file is part of The Simplicity Engine.

    The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
    by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

    The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
package com.se.simplicity.test.engine;

import static org.easymock.EasyMock.createMock;
import static org.easymock.EasyMock.createStrictControl;
import static org.easymock.EasyMock.expect;
import static org.easymock.EasyMock.replay;
import static org.junit.Assert.assertEquals;

import org.easymock.IMocksControl;
import org.junit.Before;
import org.junit.Test;

import com.se.simplicity.engine.Engine;
import com.se.simplicity.engine.EngineInput;
import com.se.simplicity.engine.SEEngineAdvancementException;
import com.se.simplicity.engine.SimpleCompositeEngine;

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
    private SimpleCompositeEngine fTestObject;

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.engine.SimpleCompositeEngine#advance(EngineInput) advance(EngineInput)}.
     * </p>
     * 
     * @throws SEEngineAdvancementException Thrown if the engine fails to advance.
     */
    @Test
    public void advance() throws SEEngineAdvancementException
    {
        // Create dependencies.
        IMocksControl mockControl = createStrictControl();
        Engine mockEngine1 = (Engine) mockControl.createMock(Engine.class);
        Engine mockEngine2 = (Engine) mockControl.createMock(Engine.class);
        Engine mockEngine3 = (Engine) mockControl.createMock(Engine.class);

        // Initialise test environment.
        fTestObject.addEngine(mockEngine1);
        fTestObject.addEngine(mockEngine2);
        fTestObject.addEngine(mockEngine3);

        // Dictate correct behaviour.
        mockControl.reset();
        expect(mockEngine1.getPreferredFrequency()).andStubReturn(3);
        expect(mockEngine2.getPreferredFrequency()).andStubReturn(4);
        expect(mockEngine3.getPreferredFrequency()).andStubReturn(6);
        mockEngine1.init();
        mockEngine2.init();
        mockEngine3.init();

        // Dictate expected results.
        // First advance.
        // No engines advance.

        // Second advance.
        expect(mockEngine3.advance(null)).andReturn(null);

        // Third advance.
        expect(mockEngine2.advance(null)).andReturn(null);

        // Fourth advance.
        expect(mockEngine1.advance(null)).andReturn(null);
        expect(mockEngine3.advance(null)).andReturn(null);

        // Fifth advance.
        // No engines advance.

        // Sixth advance.
        expect(mockEngine2.advance(null)).andReturn(null);
        expect(mockEngine3.advance(null)).andReturn(null);

        // Seventh advance.
        // No engines advance.

        // Eighth advance.
        expect(mockEngine1.advance(null)).andReturn(null);
        expect(mockEngine3.advance(null)).andReturn(null);

        // Ninth advance.
        expect(mockEngine2.advance(null)).andReturn(null);

        // Tenth advance.
        expect(mockEngine3.advance(null)).andReturn(null);

        // Eleventh advance.
        // No engines advance.

        // Twelfth advance.
        expect(mockEngine1.advance(null)).andReturn(null);
        expect(mockEngine2.advance(null)).andReturn(null);
        expect(mockEngine3.advance(null)).andReturn(null);

        // Thirteenth advance.
        // No engines advance.

        // Fourteenth advance.
        expect(mockEngine3.advance(null)).andReturn(null);

        // Fifteenth advance.
        expect(mockEngine2.advance(null)).andReturn(null);

        // Sixteenth advance.
        expect(mockEngine1.advance(null)).andReturn(null);
        expect(mockEngine3.advance(null)).andReturn(null);

        // Seventeenth advance.
        // No engines advance.

        // Eighteenth advance.
        expect(mockEngine2.advance(null)).andReturn(null);
        expect(mockEngine3.advance(null)).andReturn(null);

        // Nineteenth advance.
        // No engines advance.

        // Twentieth advance.
        expect(mockEngine1.advance(null)).andReturn(null);
        expect(mockEngine3.advance(null)).andReturn(null);

        // Twenty First advance.
        expect(mockEngine2.advance(null)).andReturn(null);

        // Twenty Second advance.
        expect(mockEngine3.advance(null)).andReturn(null);

        // Twenty Third advance.
        // No engines advance.

        // Twenty Fourth advance.
        expect(mockEngine1.advance(null)).andReturn(null);
        expect(mockEngine2.advance(null)).andReturn(null);
        expect(mockEngine3.advance(null)).andReturn(null);

        mockControl.replay();

        // Perform test.
        fTestObject.init();

        for (int index = 0; index < 24; index++)
        {
            fTestObject.advance(null);
        }

        // Verify test results.
        mockControl.verify();
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.engine.SimpleCompositeEngine#advance(EngineInput) advance(EngineInput)}, specifically the
     * functionality that passes the {@link com.se.simplicity.engine.EngineInput EngineInput} from one {@link com.se.simplicity.engine.Engine Engine}
     * to the next.
     * </p>
     * 
     * @throws SEEngineAdvancementException Thrown if the engine fails to advance.
     */
    @Test
    public void advancePassEngineInput() throws SEEngineAdvancementException
    {
        // Create dependencies.
        IMocksControl mockControl = createStrictControl();
        Engine mockEngine1 = mockControl.createMock(Engine.class);
        Engine mockEngine2 = mockControl.createMock(Engine.class);
        Engine mockEngine3 = mockControl.createMock(Engine.class);
        EngineInput mockInput0 = createMock(EngineInput.class);
        EngineInput mockInput1 = createMock(EngineInput.class);
        EngineInput mockInput2 = createMock(EngineInput.class);
        EngineInput mockInput3 = createMock(EngineInput.class);

        // Dictate correct behaviour.
        expect(mockEngine1.getPreferredFrequency()).andStubReturn(1);
        expect(mockEngine2.getPreferredFrequency()).andStubReturn(1);
        expect(mockEngine3.getPreferredFrequency()).andStubReturn(1);
        mockEngine1.init();
        mockEngine2.init();
        mockEngine3.init();
        mockControl.replay();

        // Initialise test environment.
        fTestObject.addEngine(mockEngine1);
        fTestObject.addEngine(mockEngine2);
        fTestObject.addEngine(mockEngine3);
        fTestObject.init();

        // Dictate expected results.
        mockControl.reset();
        expect(mockEngine1.getPreferredFrequency()).andStubReturn(1);
        expect(mockEngine2.getPreferredFrequency()).andStubReturn(1);
        expect(mockEngine3.getPreferredFrequency()).andStubReturn(1);
        expect(mockEngine1.advance(mockInput0)).andReturn(mockInput1);
        expect(mockEngine2.advance(mockInput1)).andReturn(mockInput2);
        expect(mockEngine3.advance(mockInput2)).andReturn(mockInput3);
        mockControl.replay();

        // Perform test.
        fTestObject.advance(mockInput0);

        // Verify test results.
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
        fTestObject = new SimpleCompositeEngine();
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.engine.SimpleCompositeEngine#getCompositeFrequency() getCompositeFrequency()}.
     * </p>
     */
    @Test
    public void getCompositeFrequency()
    {
        // Create dependencies.
        Engine mockEngine1 = (Engine) createMock(Engine.class);
        Engine mockEngine2 = (Engine) createMock(Engine.class);
        Engine mockEngine3 = (Engine) createMock(Engine.class);

        // Dictate correct behaviour.
        expect(mockEngine1.getPreferredFrequency()).andStubReturn(3);
        expect(mockEngine2.getPreferredFrequency()).andStubReturn(4);
        expect(mockEngine3.getPreferredFrequency()).andStubReturn(6);
        mockEngine1.init();
        mockEngine2.init();
        mockEngine3.init();
        replay(mockEngine1, mockEngine2, mockEngine3);

        // Initialise test environment.
        fTestObject.addEngine(mockEngine1);
        fTestObject.addEngine(mockEngine2);
        fTestObject.addEngine(mockEngine3);
        fTestObject.init();

        // Perform test - Verify test results.
        assertEquals(fTestObject.getPreferredFrequency(), 12, 0);
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.engine.SimpleCompositeEngine#getCompositeFrequency() getCompositeFrequency()} with the special
     * condition that the {@link com.se.simplicity.engine.SimpleCompositeEngine SimpleCompositeEngine} being tested does not have any sub-engines.
     * </p>
     */
    @Test
    public void getCompositeFrequencyNoEngines()
    {
        // Perform test - Verify test results.
        assertEquals(fTestObject.getPreferredFrequency(), 1, 0);
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.engine.SimpleCompositeEngine#reset() reset()}.
     * </p>
     * 
     * @throws SEEngineAdvancementException Thrown if the engine fails to advance.
     */
    @Test
    public void reset() throws SEEngineAdvancementException
    {
        // Create dependencies.
        IMocksControl mockControl = createStrictControl();
        Engine mockEngine1 = (Engine) mockControl.createMock(Engine.class);
        Engine mockEngine2 = (Engine) mockControl.createMock(Engine.class);
        Engine mockEngine3 = (Engine) mockControl.createMock(Engine.class);

        // Initialise test environment.
        fTestObject.addEngine(mockEngine1);
        fTestObject.addEngine(mockEngine2);
        fTestObject.addEngine(mockEngine3);

        // Dictate correct behaviour.
        mockControl.reset();
        expect(mockEngine1.getPreferredFrequency()).andStubReturn(3);
        expect(mockEngine2.getPreferredFrequency()).andStubReturn(4);
        expect(mockEngine3.getPreferredFrequency()).andStubReturn(6);
        mockEngine1.init();
        mockEngine2.init();
        mockEngine3.init();

        // Dictate expected results.
        // First advance.
        // No engines advance.

        // Second advance.
        expect(mockEngine3.advance(null)).andReturn(null);

        // Third advance.
        expect(mockEngine2.advance(null)).andReturn(null);

        // Fourth advance.
        expect(mockEngine1.advance(null)).andReturn(null);
        expect(mockEngine3.advance(null)).andReturn(null);

        // Fifth advance.
        // No engines advance.

        // Reset.
        mockEngine1.reset();
        mockEngine2.reset();
        mockEngine3.reset();

        // First advance.
        // No engines advance.

        // Second advance.
        expect(mockEngine3.advance(null)).andReturn(null);

        // Third advance.
        expect(mockEngine2.advance(null)).andReturn(null);

        // Fourth advance.
        expect(mockEngine1.advance(null)).andReturn(null);
        expect(mockEngine3.advance(null)).andReturn(null);

        // Fifth advance.
        // No engines advance.

        // Sixth advance.
        expect(mockEngine2.advance(null)).andReturn(null);
        expect(mockEngine3.advance(null)).andReturn(null);

        // Seventh advance.
        // No engines advance.

        // Eighth advance.
        expect(mockEngine1.advance(null)).andReturn(null);
        expect(mockEngine3.advance(null)).andReturn(null);

        // Ninth advance.
        expect(mockEngine2.advance(null)).andReturn(null);

        // Tenth advance.
        expect(mockEngine3.advance(null)).andReturn(null);

        // Eleventh advance.
        // No engines advance.

        // Twelfth advance.
        expect(mockEngine1.advance(null)).andReturn(null);
        expect(mockEngine2.advance(null)).andReturn(null);
        expect(mockEngine3.advance(null)).andReturn(null);

        mockControl.replay();

        // Perform test.
        fTestObject.init();

        for (int index = 0; index < 5; index++)
        {
            fTestObject.advance(null);
        }

        fTestObject.reset();

        for (int index = 0; index < 12; index++)
        {
            fTestObject.advance(null);
        }

        // Verify test results.
        mockControl.verify();
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.engine.SimpleCompositeEngine#setPreferredFrequency(int) setPreferredFrequency(int)}.
     * </p>
     */
    @Test
    public void setPreferredFrequency()
    {
        // Perform test - Verify test results.
        fTestObject.setPreferredFrequency(5);
    }
}
