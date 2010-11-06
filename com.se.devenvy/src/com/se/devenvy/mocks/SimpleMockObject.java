/*
    This file is part of The Simplicity Engine.

    The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
    by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

    The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
package com.se.devenvy.mocks;

import java.util.ArrayList;

/**
 * <p>
 * Implements a mock object that can be used in situations where EasyMock cannot provide a suitable mock. To create a mock object of a specific class,
 * extend / implement it and call {@link #addMethodCall(String, Object[])} in each method.
 * </p>
 * 
 * @author Gary Buyn
 */
public class SimpleMockObject implements MockObject
{
    /**
     * <p>
     * The threshold of equality for number comparisons.
     * </p>
     */
    private static double NUMBER_COMPARISON_THRESHOLD = 0.0001;

    /**
     * <p>
     * The method calls that have been made on this <code>SimpleMockObject</code>.
     * </p>
     */
    private ArrayList<MethodCall> fMethodCalls;

    /**
     * <p>
     * Creates an instance of <code>SimpleMockObject</code>.
     * </p>
     */
    public SimpleMockObject()
    {
        fMethodCalls = new ArrayList<MethodCall>();
    }

    /**
     * <p>
     * Adds a method call that has been made on this <code>SimpleMockObject</code>.
     * </p>
     * 
     * @param name The name of the method that has been called on this <code>SimpleMockObject</code>.
     * @param parameters The parameters passed to this <code>SimpleMockObject</code> when the method was called, or <code>null</code> if no parameters
     * were given.
     */
    public void addMethodCall(final String name, final Object[] parameters)
    {
        MethodCall methodCall = new MethodCall();

        methodCall.name = name;
        methodCall.parameters = parameters;

        fMethodCalls.add(methodCall);
    }

    @Override
    public MethodCall getMethodCall(final int callIndex, final String name, final Object[] parameters)
    {
        int calls = 0;

        for (MethodCall methodCall : fMethodCalls)
        {
            // If the current Method Call is a match.
            if (methodCall.name.equals(name) && parametersEqual(methodCall.parameters, parameters))
            {
                // If the correct index has been reached.
                if (calls == callIndex)
                {
                    return (methodCall);
                }

                calls++;
            }
        }

        return (null);
    }

    @Override
    public int getMethodCallCount(final String name, final Object[] parameters)
    {
        int methodCallCount = 0;

        for (MethodCall methodCall : fMethodCalls)
        {
            // If the current Method Call is a match.
            if (methodCall.name.equals(name) && parametersEqual(methodCall.parameters, parameters))
            {
                methodCallCount++;
            }
        }

        return (methodCallCount);
    }

    @Override
    public int getMethodCallCountIgnoreParams(final String name)
    {
        int methodCallCount = 0;

        for (MethodCall methodCall : fMethodCalls)
        {
            // If the current Method Call is a match.
            if (methodCall.name.equals(name))
            {
                methodCallCount++;
            }
        }

        return (methodCallCount);
    }

    @Override
    public MethodCall getMethodCallIgnoreParams(final int callIndex, final String name)
    {
        int calls = 0;

        for (MethodCall methodCall : fMethodCalls)
        {
            // If the current Method Call is a match.
            if (methodCall.name.equals(name))
            {
                // If the correct index has been reached.
                if (calls == callIndex)
                {
                    return (methodCall);
                }

                calls++;
            }
        }

        return (null);
    }

    @Override
    public boolean methodCallOrderCheck(final int beforeCallIndex, final String beforeMethodName, final Object[] beforeMethodParameters,
            final int afterCallIndex, final String afterMethodName, final Object[] afterMethodParameters)
    {
        int beforeCalls = 0;
        int afterCalls = 0;
        boolean beforeMethodFound = false;

        for (MethodCall methodCall : fMethodCalls)
        {
            // If the current Method Call is a match for the before method.
            if (methodCall.name.equals(beforeMethodName) && parametersEqual(methodCall.parameters, beforeMethodParameters))
            {
                // If the before index has been reached.
                if (beforeCalls == beforeCallIndex)
                {
                    beforeMethodFound = true;
                }

                beforeCalls++;
            }

            // If the current Method Call is a match for the after method.
            if (methodCall.name.equals(afterMethodName) && parametersEqual(methodCall.parameters, afterMethodParameters))
            {
                // If the after index has been reached.
                if (afterCalls == afterCallIndex)
                {
                    // If the before method has not yet been found.
                    if (!beforeMethodFound)
                    {
                        return (false);
                    }
                    else
                    {
                        return (true);
                    }
                }

                afterCalls++;
            }
        }

        return (false);
    }

    @Override
    public boolean methodCallOrderCheckIgnoreParams(final int beforeCallIndex, final String beforeMethodName, final int afterCallIndex,
            final String afterMethodName)
    {
        int beforeCalls = 0;
        int afterCalls = 0;
        boolean beforeMethodFound = false;

        for (MethodCall methodCall : fMethodCalls)
        {
            // If the current Method Call is a match for the before method.
            if (methodCall.name.equals(beforeMethodName))
            {
                // If the before index has been reached.
                if (beforeCalls == beforeCallIndex)
                {
                    beforeMethodFound = true;
                }

                beforeCalls++;
            }

            // If the current Method Call is a match for the after method.
            if (methodCall.name.equals(afterMethodName))
            {
                // If the after index has been reached.
                if (afterCalls == afterCallIndex)
                {
                    // If the before method has not yet been found.
                    if (!beforeMethodFound)
                    {
                        return (false);
                    }
                    else
                    {
                        return (true);
                    }
                }

                afterCalls++;
            }
        }

        return (false);
    }

    /**
     * <p>
     * Checks the equality of the two given sets of parameters.
     * </p>
     * 
     * @param parameterSetA The first set of parameters to compare.
     * @param parameterSetB The second set of parameters to compare.
     * 
     * @return True if the sets of parameters are equal, false otherwise.
     */
    @SuppressWarnings("unchecked")
    private boolean parametersEqual(final Object[] parameterSetA, final Object[] parameterSetB)
    {
        boolean parameterSetANullEmpty = false;
        boolean parameterSetBNullEmpty = false;

        if (parameterSetA == null || parameterSetA.length == 0)
        {
            parameterSetANullEmpty = true;
        }

        if (parameterSetB == null || parameterSetB.length == 0)
        {
            parameterSetBNullEmpty = true;
        }

        // If the parameter sets are both null/empty, return true.
        if (parameterSetANullEmpty && parameterSetBNullEmpty)
        {
            return (true);
        }

        // If only one parameter set is null/empty, return false.
        if (parameterSetANullEmpty || parameterSetBNullEmpty)
        {
            return (false);
        }

        // If the parameter sets have different lengths, return false.
        if (parameterSetA.length != parameterSetB.length)
        {
            return (false);
        }

        // If the contents of the parameter sets are different, return false.
        for (int index = 0; index < parameterSetA.length; index++)
        {
            // Compare Enum types.
            if (parameterSetA[index].getClass().isEnum() && parameterSetB[index].getClass().isEnum())
            {
                if (((Enum) parameterSetA[index]) != ((Enum) parameterSetB[index]))
                {
                    return (false);
                }
            }
            // Compare Number values.
            else if (parameterSetA[index] instanceof Number && parameterSetB[index] instanceof Number)
            {
                if (Math.abs(((Number) parameterSetA[index]).doubleValue() - ((Number) parameterSetB[index]).doubleValue()) > NUMBER_COMPARISON_THRESHOLD)
                {
                    return (false);
                }
            }
            // Compare Object instances.
            else if (!parameterSetA[index].equals(parameterSetB[index]))
            {
                return (false);
            }
        }

        return (true);
    }

    @Override
    public void reset()
    {
        fMethodCalls.clear();
    }
}
