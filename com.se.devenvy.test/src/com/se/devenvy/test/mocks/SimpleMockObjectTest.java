/*
    This file is part of The Simplicity Engine.

    The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
    by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

    The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
package com.se.devenvy.test.mocks;

import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertFalse;
import static org.junit.Assert.assertNotNull;
import static org.junit.Assert.assertNotSame;
import static org.junit.Assert.assertNull;
import static org.junit.Assert.assertTrue;

import org.junit.Before;
import org.junit.Test;

import com.se.devenvy.mocks.SimpleMockObject;

/**
 * <p>
 * Unit tests for the class {@link com.se.devenvy.mocks.SimpleMockObject SimpleMockObject}.
 * </p>
 * 
 * @author Gary Buyn
 */
public class SimpleMockObjectTest
{
    /**
     * An instance of the class being unit tested.
     */
    private SimpleMockObject fTestObject;

    /**
     * <p>
     * Unit test the method {@link com.se.devenvy.mocks.SimpleMockObject#addMethodCall(String, Object[]) addMethodCall(String, Object[])}.
     * </p>
     */
    @Test
    public void addMethodCall()
    {
        // Create dependencies.
        Object[] parameters = new Object[] {new Object()};

        // Perform test.
        fTestObject.addMethodCall("test", parameters);

        // Verify test results.
        assertNotNull(fTestObject.getMethodCall(0, "test", parameters));
    }

    /**
     * <p>
     * Setup to perform before each unit test.
     * </p>
     */
    @Before
    public void before()
    {
        fTestObject = new SimpleMockObject();
    }

    /**
     * <p>
     * Unit test the method {@link com.se.devenvy.mocks.SimpleMockObject#getMethodCall(int, String, Object[]) getMethodCall(int, String, Object[])}.
     * </p>
     */
    @Test
    public void getMethodCall()
    {
        // Create dependencies.
        Object[] parameters = new Object[] {new Object()};

        // Initialise test environment.
        fTestObject.addMethodCall("test", parameters);

        // Perform test - Verify test results.
        assertNotNull(fTestObject.getMethodCall(0, "test", parameters));
    }

    /**
     * <p>
     * Unit test the method {@link com.se.devenvy.mocks.SimpleMockObject#getMethodCallCount(String, Object[]) getMethodCallCount(String, Object[])}.
     * </p>
     */
    @Test
    public void getMethodCallCount()
    {
        // Create dependencies.
        Object[] parameters = new Object[] {new Object()};

        // Perform test 1 - Verify test 1 results.
        assertEquals(0, fTestObject.getMethodCallCount("test", parameters), 0);

        // Initialise test environment.
        fTestObject.addMethodCall("test", parameters);

        // Perform test 2 - Verify test 2 results.
        assertEquals(1, fTestObject.getMethodCallCount("test", parameters), 0);

        // Initialise test environment.
        fTestObject.addMethodCall("test", parameters);

        // Perform test 3 - Verify test 3 results.
        assertEquals(2, fTestObject.getMethodCallCount("test", parameters), 0);
    }

    /**
     * <p>
     * Unit test the method {@link com.se.devenvy.mocks.SimpleMockObject#getMethodCallCountIgnoreParams(String)
     * getMethodCallCountIgnoreParams(String)}.
     * </p>
     */
    @Test
    public void getMethodCallCountIgnoreParams()
    {
        // Create dependencies.
        Object[] parameters0 = new Object[] {};
        Object[] parameters1 = new Object[] {new Object()};
        Object[] parameters2 = new Object[] {new Object()};

        // Perform test 1 - Verify test 1 results.
        assertEquals(0, fTestObject.getMethodCallCountIgnoreParams("test"), 0);

        // Initialise test environment.
        fTestObject.addMethodCall("test", parameters0);

        // Perform test 2 - Verify test 2 results.
        assertEquals(1, fTestObject.getMethodCallCountIgnoreParams("test"), 0);

        // Initialise test environment.
        fTestObject.addMethodCall("test", parameters1);

        // Perform test 3 - Verify test 3 results.
        assertEquals(2, fTestObject.getMethodCallCountIgnoreParams("test"), 0);

        // Initialise test environment.
        fTestObject.addMethodCall("test", parameters2);

        // Perform test 4 - Verify test 4 results.
        assertEquals(3, fTestObject.getMethodCallCountIgnoreParams("test"), 0);
    }

    /**
     * <p>
     * Unit test the method {@link com.se.devenvy.mocks.SimpleMockObject#getMethodCallIgnoreParams(int, String) getMethodCallIgnoreParams(int,
     * String)}.
     * </p>
     */
    @Test
    public void getMethodCallIgnoreParams()
    {
        // Create dependencies.
        Object[] parameters = new Object[] {new Object()};

        // Initialise test environment.
        fTestObject.addMethodCall("test", parameters);

        // Perform test - Verify test results.
        assertNotNull(fTestObject.getMethodCallIgnoreParams(0, "test"));
    }

    /**
     * <p>
     * Unit test the method {@link com.se.devenvy.mocks.SimpleMockObject#getMethodCallIgnoreParams(int, String) getMethodCallIgnoreParams(int,
     * String)} with the special condition that there are multiple identical {@link com.se.devenvy.mocks.MethodCall MethodCall}s.
     * </p>
     */
    @Test
    public void getMethodCallIgnoreParamsMultiple()
    {
        // Initialise test environment.
        fTestObject.addMethodCall("test", null);
        fTestObject.addMethodCall("test", null);

        // Perform test - Verify test results.
        assertNotNull(fTestObject.getMethodCallIgnoreParams(0, "test"));
        assertNotNull(fTestObject.getMethodCallIgnoreParams(1, "test"));
        assertNotSame(fTestObject.getMethodCallIgnoreParams(0, "test"), fTestObject.getMethodCallIgnoreParams(1, "test"));
    }

    /**
     * <p>
     * Unit test the method {@link com.se.devenvy.mocks.SimpleMockObject#getMethodCallIgnoreParams(int, String) getMethodCallIgnoreParams(int,
     * String)} with the special condition that a matching {@link com.se.devenvy.mocks.MethodCall MethodCall} does not exist.
     * </p>
     */
    @Test
    public void getMethodCallIgnoreParamsNoneExists()
    {
        // Perform test - Verify test results.
        assertNull(fTestObject.getMethodCallIgnoreParams(0, "test"));
    }

    /**
     * <p>
     * Unit test the method {@link com.se.devenvy.mocks.SimpleMockObject#getMethodCall(int, String, Object[]) getMethodCall(int, String, Object[])}
     * with the special condition that there are multiple identical {@link com.se.devenvy.mocks.MethodCall MethodCall}s.
     * </p>
     */
    @Test
    public void getMethodCallMultiple()
    {
        // Initialise test environment.
        fTestObject.addMethodCall("test", null);
        fTestObject.addMethodCall("test", null);

        // Perform test - Verify test results.
        assertNotNull(fTestObject.getMethodCall(0, "test", null));
        assertNotNull(fTestObject.getMethodCall(1, "test", null));
        assertNotSame(fTestObject.getMethodCall(0, "test", null), fTestObject.getMethodCall(1, "test", null));
    }

    /**
     * <p>
     * Unit test the method {@link com.se.devenvy.mocks.SimpleMockObject#getMethodCall(int, String, Object[]) getMethodCall(int, String, Object[])}
     * with the special condition that a matching {@link com.se.devenvy.mocks.MethodCall MethodCall} does not exist.
     * </p>
     */
    @Test
    public void getMethodCallNoneExists()
    {
        // Perform test - Verify test results.
        assertNull(fTestObject.getMethodCall(0, "test", null));
    }

    /**
     * <p>
     * Unit test the method {@link com.se.devenvy.mocks.SimpleMockObject#methodCallOrderCheck(int, String, Object[], int, String, Object[])
     * methodCallOrderCheck(int, String, Object[], int, String, Object[])}.
     * </p>
     */
    @Test
    public void methodCallOrderCheck()
    {
        // Initialise test environment.
        Object[] parameters0 = new Object[] {new Object()};
        Object[] parameters1 = new Object[] {new Object()};

        fTestObject.addMethodCall("test0", parameters0);
        fTestObject.addMethodCall("test1", parameters1);

        // Perform test - Verify test results.
        assertFalse(fTestObject.methodCallOrderCheck(0, "test1", parameters1, 0, "test0", parameters0));
        assertTrue(fTestObject.methodCallOrderCheck(0, "test0", parameters0, 0, "test1", parameters1));
    }

    /**
     * <p>
     * Unit test the method {@link com.se.devenvy.mocks.SimpleMockObject#methodCallOrderCheck(int, String, Object[], int, String, Object[])
     * methodCallOrderCheck(int, String, Object[], int, String, Object[])} with the special condition that the after method was never called.
     * </p>
     */
    @Test
    public void methodCallOrderCheckAfterNotExists()
    {
        // Initialise test environment.
        Object[] parameters0 = new Object[] {new Object()};
        Object[] parameters1 = new Object[] {new Object()};

        fTestObject.addMethodCall("test0", parameters0);

        // Perform test - Verify test results.
        assertFalse(fTestObject.methodCallOrderCheck(0, "test1", parameters1, 0, "test0", parameters0));
        assertFalse(fTestObject.methodCallOrderCheck(0, "test0", parameters0, 0, "test1", parameters1));
    }

    /**
     * <p>
     * Unit test the method {@link com.se.devenvy.mocks.SimpleMockObject#methodCallOrderCheck(int, String, Object[], int, String, Object[])
     * methodCallOrderCheck(int, String, Object[], int, String, Object[])} with the special condition that the before method was never called.
     * </p>
     */
    @Test
    public void methodCallOrderCheckBeforeNotExists()
    {
        // Initialise test environment.
        Object[] parameters0 = new Object[] {new Object()};
        Object[] parameters1 = new Object[] {new Object()};

        fTestObject.addMethodCall("test1", parameters1);

        // Perform test - Verify test results.
        assertFalse(fTestObject.methodCallOrderCheck(0, "test1", parameters1, 0, "test0", parameters0));
        assertFalse(fTestObject.methodCallOrderCheck(0, "test0", parameters0, 0, "test1", parameters1));
    }

    /**
     * <p>
     * Unit test the method {@link com.se.devenvy.mocks.SimpleMockObject#methodCallOrderCheckIgnoreParams(int, String, int, String)
     * methodCallOrderCheckIgnoreParams(int, String, int, String)}.
     * </p>
     */
    @Test
    public void methodCallOrderCheckIgnoreParams()
    {
        fTestObject.addMethodCall("test0", null);
        fTestObject.addMethodCall("test1", null);

        // Perform test - Verify test results.
        assertFalse(fTestObject.methodCallOrderCheckIgnoreParams(0, "test1", 0, "test0"));
        assertTrue(fTestObject.methodCallOrderCheckIgnoreParams(0, "test0", 0, "test1"));
    }

    /**
     * <p>
     * Unit test the method {@link com.se.devenvy.mocks.SimpleMockObject#methodCallOrderCheckIgnoreParams(int, String, int, String)
     * methodCallOrderCheckIgnoreParams(int, String, int, String)} with the special condition that the after method was never called.
     * </p>
     */
    @Test
    public void methodCallOrderCheckIgnoreParamsAfterNotExists()
    {
        fTestObject.addMethodCall("test0", null);

        // Perform test - Verify test results.
        assertFalse(fTestObject.methodCallOrderCheckIgnoreParams(0, "test1", 0, "test0"));
        assertFalse(fTestObject.methodCallOrderCheckIgnoreParams(0, "test0", 0, "test1"));
    }

    /**
     * <p>
     * Unit test the method {@link com.se.devenvy.mocks.SimpleMockObject#methodCallOrderCheckIgnoreParams(int, String, int, String)
     * methodCallOrderCheckIgnoreParams(int, String, int, String)} with the special condition that the before method was never called.
     * </p>
     */
    @Test
    public void methodCallOrderCheckIgnoreParamsBeforeNotExists()
    {
        fTestObject.addMethodCall("test1", null);

        // Perform test - Verify test results.
        assertFalse(fTestObject.methodCallOrderCheckIgnoreParams(0, "test1", 0, "test0"));
        assertFalse(fTestObject.methodCallOrderCheckIgnoreParams(0, "test0", 0, "test1"));
    }

    /**
     * <p>
     * Unit test the method {@link com.se.devenvy.mocks.SimpleMockObject#methodCallOrderCheckIgnoreParams(int, String, int, String)
     * methodCallOrderCheckIgnoreParams(int, String, int, String)} with the special condition that the before and after methods were never called.
     * </p>
     */
    @Test
    public void methodCallOrderCheckIgnoreParamsNoneExists()
    {
        // Perform test - Verify test results.
        assertFalse(fTestObject.methodCallOrderCheckIgnoreParams(0, "test1", 0, "test0"));
        assertFalse(fTestObject.methodCallOrderCheckIgnoreParams(0, "test0", 0, "test1"));
    }

    /**
     * <p>
     * Unit test the method {@link com.se.devenvy.mocks.SimpleMockObject#methodCallOrderCheckIgnoreParams(int, String, int, String)
     * methodCallOrderCheckIgnoreParams(int, String, int, String)} with the special condition that the two method calls are the same.
     * </p>
     */
    @Test
    public void methodCallOrderCheckIgnoreParamsSame()
    {
        fTestObject.addMethodCall("test", null);
        fTestObject.addMethodCall("test", null);

        // Perform test - Verify test results.
        assertFalse(fTestObject.methodCallOrderCheckIgnoreParams(1, "test", 0, "test"));
        assertTrue(fTestObject.methodCallOrderCheckIgnoreParams(0, "test", 1, "test"));
    }

    /**
     * <p>
     * Unit test the method {@link com.se.devenvy.mocks.SimpleMockObject#methodCallOrderCheck(int, String, Object[], int, String, Object[])
     * methodCallOrderCheck(int, String, Object[], int, String, Object[])} with the special condition that the before and after methods were never
     * called.
     * </p>
     */
    @Test
    public void methodCallOrderCheckNoneExists()
    {
        // Initialise test environment.
        Object[] parameters0 = new Object[] {new Object()};
        Object[] parameters1 = new Object[] {new Object()};

        // Perform test - Verify test results.
        assertFalse(fTestObject.methodCallOrderCheck(0, "test1", parameters1, 0, "test0", parameters0));
        assertFalse(fTestObject.methodCallOrderCheck(0, "test0", parameters0, 0, "test1", parameters1));
    }

    /**
     * <p>
     * Unit test the method {@link com.se.devenvy.mocks.SimpleMockObject#methodCallOrderCheck(int, String, Object[], int, String, Object[])
     * methodCallOrderCheck(int, String, Object[], int, String, Object[])} with the special condition that the two method calls are the same.
     * </p>
     */
    @Test
    public void methodCallOrderCheckSame()
    {
        // Initialise test environment.
        Object[] parameters0 = new Object[] {new Object()};

        fTestObject.addMethodCall("test", parameters0);
        fTestObject.addMethodCall("test", parameters0);

        // Perform test - Verify test results.
        assertFalse(fTestObject.methodCallOrderCheck(1, "test", parameters0, 0, "test", parameters0));
        assertTrue(fTestObject.methodCallOrderCheck(0, "test", parameters0, 1, "test", parameters0));
    }

    /**
     * <p>
     * Unit test the method {@link com.se.devenvy.mocks.SimpleMockObject#parametersEqual(Object[], Object[]) parametersEqual(Object[], Object[])} with
     * the special condition that one of the arrays is empty.
     * </p>
     */
    @Test
    public void parametersEqualEmpty()
    {
        // Create dependencies.
        Object[] parameters0 = new Object[] {};
        Object[] parameters1 = new Object[] {new Object()};

        // Initialise test environment.
        fTestObject.addMethodCall("test", parameters0);

        // Perform test - Verify test results.
        assertNull(fTestObject.getMethodCall(0, "test", parameters1));
        assertNotNull(fTestObject.getMethodCall(0, "test", parameters0));
        assertNotNull(fTestObject.getMethodCall(0, "test", null));
    }

    /**
     * <p>
     * Unit test the method {@link com.se.devenvy.mocks.SimpleMockObject#parametersEqual(Object[], Object[]) parametersEqual(Object[], Object[])} with
     * the special condition that the arrays have different sizes.
     * </p>
     */
    @Test
    public void parametersEqualDifferentSizes()
    {
        // Create dependencies.
        Object[] parameters0 = new Object[] {new Object()};
        Object[] parameters1 = new Object[] {new Object(), new Object()};

        // Initialise test environment.
        fTestObject.addMethodCall("test", parameters0);

        // Perform test - Verify test results.
        assertNull(fTestObject.getMethodCall(0, "test", parameters1));
        assertNotNull(fTestObject.getMethodCall(0, "test", parameters0));
    }

    /**
     * <p>
     * Unit test the method {@link com.se.devenvy.mocks.SimpleMockObject#parametersEqual(Object[], Object[]) parametersEqual(Object[], Object[])} with
     * the special condition that one of the arrays contains an Enum type.
     * </p>
     */
    @Test
    public void parametersEqualEnum()
    {
        // Create dependencies.
        Object[] parameters0 = new Object[] {};
        Object[] parameters1 = new Object[] {new Object()};
        Object[] parameters2 = new Object[] {MockEnum.TEST0};
        Object[] parameters3 = new Object[] {MockEnum.TEST1};

        // Initialise test environment.
        fTestObject.addMethodCall("test", parameters2);

        // Perform test - Verify test results.
        assertNull(fTestObject.getMethodCall(0, "test", parameters0));
        assertNull(fTestObject.getMethodCall(0, "test", parameters1));
        assertNull(fTestObject.getMethodCall(0, "test", parameters3));
        assertNull(fTestObject.getMethodCall(0, "test", null));
        assertNotNull(fTestObject.getMethodCall(0, "test", parameters2));
    }

    /**
     * <p>
     * Unit test the method {@link com.se.devenvy.mocks.SimpleMockObject#parametersEqual(Object[], Object[]) parametersEqual(Object[], Object[])} with
     * the special condition that one of the arrays is null.
     * </p>
     */
    @Test
    public void parametersEqualNull()
    {
        // Create dependencies.
        Object[] parameters0 = new Object[] {};
        Object[] parameters1 = new Object[] {new Object()};

        // Initialise test environment.
        fTestObject.addMethodCall("test", null);

        // Perform test - Verify test results.
        assertNull(fTestObject.getMethodCall(0, "test", parameters1));
        assertNotNull(fTestObject.getMethodCall(0, "test", parameters0));
        assertNotNull(fTestObject.getMethodCall(0, "test", null));
    }

    /**
     * <p>
     * Unit test the method {@link com.se.devenvy.mocks.SimpleMockObject#parametersEqual(Object[], Object[]) parametersEqual(Object[], Object[])} with
     * the special condition that one of the arrays contains a Number type.
     * </p>
     */
    @Test
    public void parametersEqualNumber()
    {
        // Create dependencies.
        Object[] parameters0 = new Object[] {};
        Object[] parameters1 = new Object[] {new Object()};
        Object[] parameters2 = new Object[] {1.1};
        Object[] parameters3 = new Object[] {2.2};

        // Initialise test environment.
        fTestObject.addMethodCall("test", parameters2);

        // Perform test - Verify test results.
        assertNull(fTestObject.getMethodCall(0, "test", parameters0));
        assertNull(fTestObject.getMethodCall(0, "test", parameters1));
        assertNull(fTestObject.getMethodCall(0, "test", parameters3));
        assertNull(fTestObject.getMethodCall(0, "test", null));
        assertNotNull(fTestObject.getMethodCall(0, "test", parameters2));
    }

    /**
     * <p>
     * Unit test the method {@link com.se.devenvy.mocks.SimpleMockObject#parametersEqual(Object[], Object[]) parametersEqual(Object[], Object[])} with
     * the special condition that one of the arrays contains a non Number and non Enum type.
     * </p>
     */
    @Test
    public void parametersEqualObject()
    {
        // Create dependencies.
        Object[] parameters0 = new Object[] {};
        Object[] parameters1 = new Object[] {new Object()};
        Object[] parameters2 = new Object[] {new Object()};

        // Initialise test environment.
        fTestObject.addMethodCall("test", parameters1);

        // Perform test - Verify test results.
        assertNull(fTestObject.getMethodCall(0, "test", parameters0));
        assertNull(fTestObject.getMethodCall(0, "test", parameters2));
        assertNull(fTestObject.getMethodCall(0, "test", null));
        assertNotNull(fTestObject.getMethodCall(0, "test", parameters1));
    }

    /**
     * <p>
     * Unit test the method {@link com.se.devenvy.mocks.SimpleMockObject#reset() reset()}.
     * </p>
     */
    @Test
    public void reset()
    {
        // Initialise test environment.
        fTestObject.addMethodCall("test", null);

        // Perform test.
        fTestObject.reset();

        // Verify test results.
        assertEquals(0, fTestObject.getMethodCallCount("test", null), 0);
    }
}
