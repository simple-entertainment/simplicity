package com.se.devenvy.mocks;

import java.util.ArrayList;

/**
 * <p>
 * A mock object that can be used in situations where EasyMock cannot provide a suitable mock. Can count method calls and assert the number of calls
 * made.
 * </p>
 * 
 * @author simple
 */
public abstract class MockObject
{
    /**
     * <p>
     * A method call that hass been made to this <code>MockObject</code>.
     * </p>
     * 
     * @author simple
     */
    public class MethodCall
    {
        public String name;
        public Object[] parameters;
    }

    /**
     * <p>
     * The method calls that have been made on this <code>MockObject</code>.
     * </p>
     */
    private ArrayList<MethodCall> methodCalls;

    /**
     * <p>
     * Creates an instance of <code>MockObject</code>.
     * </p>
     */
    public MockObject()
    {
        methodCalls = new ArrayList<MethodCall>();
    }

    /**
     * <p>
     * Adds a method call that has been made on this <code>MockObject</code>.
     * </p>
     * 
     * @param name The name of the method that has been called on this <code>MockObject</code>.
     * @param parameters The parameters passed to this <code>MockObject</code> when the method was called, or <code>null</code> if no parameters were
     *            given.
     */
    protected void addMethodCall(final String name, final Object[] parameters)
    {
        MethodCall methodCall = new MethodCall();

        methodCall.name = name;
        methodCall.parameters = parameters;

        methodCalls.add(methodCall);
    }

    /**
     * <p>
     * Retrieves the nth call made to the given method with the given parameters on this <code>MockObject</code>.
     * </p>
     * 
     * @param callIndex The index of the call to return.
     * @param name The name of the method to check the method calls for.
     * @param parameters The parameters to check the method calls for.
     * 
     * @return The nth call made to the given method with the given parameters on this <code>MockObject</code>.
     */
    public MethodCall getMethodCall(final int callIndex, final String name, final Object[] parameters)
    {
        int calls = 0;

        for (MethodCall methodCall : methodCalls)
        {
            if (methodCall.name.equals(name) && parametersEqual(methodCall.parameters, parameters))
            {
                if (calls == callIndex)
                {
                    return (methodCall);
                }

                calls++;
            }
        }

        return (null);
    }

    /**
     * <p>
     * Retrieves the number of calls made to the given method with the given parameters on this <code>MockObject</code>.
     * </p>
     * 
     * @param name The name of the method to check the number of method calls for.
     * @param parameters The parameters to check the number of method calls for.
     * 
     * @return The number of calls made to the given method with the given parameters on this <code>MockObject</code>.
     */
    public int getMethodCallCount(String name, Object[] parameters)
    {
        int methodCallCount = 0;

        for (MethodCall methodCall : methodCalls)
        {
            if (methodCall.name.equals(name) && parametersEqual(methodCall.parameters, parameters))
            {
                methodCallCount++;
            }
        }

        return (methodCallCount);
    }

    /**
     * <p>
     * Retrieves the number of calls made to the given method on this <code>MockObject</code>.
     * </p>
     * 
     * @param name The name of the method to check the number of method calls for.
     * 
     * @return The number of calls made to the given method on this <code>MockObject</code>.
     */
    public int getMethodCallCountIgnoreParams(String name)
    {
        int methodCallCount = 0;

        for (MethodCall methodCall : methodCalls)
        {
            if (methodCall.name.equals(name))
            {
                methodCallCount++;
            }
        }

        return (methodCallCount);
    }

    /**
     * <p>
     * Retrieves the nth call made to the given method on this <code>MockObject</code>.
     * </p>
     * 
     * @param callIndex The index of the call to return.
     * @param name The name of the method to check the method calls for.
     * 
     * @return The nth call made to the given method on this <code>MockObject</code>.
     */
    public MethodCall getMethodCallIgnoreParams(final int callIndex, final String name)
    {
        int calls = 0;

        for (MethodCall methodCall : methodCalls)
        {
            if (methodCall.name.equals(name))
            {
                if (calls == callIndex)
                {
                    return (methodCall);
                }

                calls++;
            }
        }

        return (null);
    }

    /**
     * <p>
     * Determines whether the nth call to one method with the given parameters was made before the mth call to another method with the given
     * parameters.
     * </p>
     * 
     * @param beforeCallIndex The index of the call to the method that is expected to have come before (the nth call). The first call is index 0.
     * @param beforeMethodName The method that is expected to have been called before.
     * @param beforeMethodParameters The parameters of the method that is expected to have been called before.
     * @param afterCallIndex The index of the call to the method that is expected to have come after (the mth call). The first call is index 0.
     * @param afterMethodName The method that is expected to have been called after.
     * @param afterMethodParameters The parameters of the method that is expected to have been called after.
     * 
     * @return True if the <code>n</code>th call to one method was made before the <code>m</code>th call to another.
     */
    public boolean methodCallOrderCheck(int beforeCallIndex, String beforeMethodName, Object[] beforeMethodParameters, int afterCallIndex,
            String afterMethodName, Object[] afterMethodParameters)
    {
        int beforeCalls = 0;
        int afterCalls = 0;
        boolean beforeMethodFound = false;

        for (MethodCall methodCall : methodCalls)
        {
            if (methodCall.name.equals(beforeMethodName) && parametersEqual(methodCall.parameters, beforeMethodParameters))
            {
                if (beforeCalls == beforeCallIndex)
                {
                    beforeMethodFound = true;
                }

                beforeCalls++;
            }

            if (methodCall.name.equals(afterMethodName) && parametersEqual(methodCall.parameters, afterMethodParameters))
            {
                if (afterCalls == afterCallIndex)
                {
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
     * Determines whether the nth call to one method was made before the mth call to another method.
     * </p>
     * 
     * @param beforeCallIndex The index of the call to the method that is expected to have come before (the nth call). The first call is index 0.
     * @param beforeMethodName The method that is expected to have been called before.
     * @param afterCallIndex The index of the call to the method that is expected to have come after (the mth call). The first call is index 0.
     * @param afterMethodName The method that is expected to have been called after.
     * 
     * @return True if the <code>n</code>th call to one method was made before the <code>m</code>th call to another.
     */
    public boolean methodCallOrderCheckIgnoreParams(int beforeCallIndex, String beforeMethodName, int afterCallIndex, String afterMethodName)
    {
        int beforeCalls = 0;
        int afterCalls = 0;

        for (MethodCall methodCall : methodCalls)
        {
            if (methodCall.name.equals(beforeMethodName))
            {
                if (beforeCalls == beforeCallIndex)
                {
                    return (true);
                }

                beforeCalls++;
            }
            else if (methodCall.name.equals(afterMethodName))
            {
                if (afterCalls == afterCallIndex)
                {
                    return (false);
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
    protected boolean parametersEqual(Object[] parameterSetA, Object[] parameterSetB)
    {
        if (parameterSetA == null && parameterSetB == null)
        {
            return (true);
        }

        if (parameterSetA == null || parameterSetB == null)
        {
            return (false);
        }

        if (parameterSetA.length != parameterSetB.length)
        {
            return (false);
        }

        for (int index = 0; index < parameterSetA.length; index++)
        {
            if (parameterSetA[index].getClass().isEnum() && parameterSetB[index].getClass().isEnum())
            {
                if (((Enum) parameterSetA[index]) != ((Enum) parameterSetB[index]))
                {
                    return (false);
                }
            }
            else if (parameterSetA[index] instanceof Number && parameterSetB[index] instanceof Number)
            {
                if (Math.abs(((Number) parameterSetA[index]).doubleValue() - ((Number) parameterSetB[index]).doubleValue()) > 0.0001)
                {
                    return (false);
                }
            }
            else if (!parameterSetA[index].equals(parameterSetB[index]))
            {
                return (false);
            }
        }

        return (true);
    }

    /**
     * <p>
     * Resets this <code>MockObject<code>.
     * </p>
     */
    public void reset()
    {
        methodCalls.clear();
    }
}
