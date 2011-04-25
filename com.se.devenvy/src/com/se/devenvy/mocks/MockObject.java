/*
    This file is part of Dev Envy.

    Dev Envy is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
    by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

    Dev Envy is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along with Dev Envy. If not, see <http://www.gnu.org/licenses/>.
 */
package com.se.devenvy.mocks;

/**
 * <p>
 * A mock object that can be used in situations where EasyMock cannot provide a suitable mock. Can count method calls and assert the number of calls
 * made.
 * </p>
 * 
 * @author Gary Buyn
 */
public interface MockObject
{
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
    MethodCall getMethodCall(final int callIndex, final String name, final Object[] parameters);

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
    int getMethodCallCount(final String name, final Object[] parameters);

    /**
     * <p>
     * Retrieves the number of calls made to the given method on this <code>MockObject</code>.
     * </p>
     * 
     * @param name The name of the method to check the number of method calls for.
     * 
     * @return The number of calls made to the given method on this <code>MockObject</code>.
     */
    int getMethodCallCountIgnoreParams(final String name);

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
    MethodCall getMethodCallIgnoreParams(final int callIndex, final String name);

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
    boolean methodCallOrderCheck(final int beforeCallIndex, final String beforeMethodName, final Object[] beforeMethodParameters,
            final int afterCallIndex, final String afterMethodName, final Object[] afterMethodParameters);

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
    boolean methodCallOrderCheckIgnoreParams(final int beforeCallIndex, final String beforeMethodName, final int afterCallIndex,
            final String afterMethodName);

    /**
     * <p>
     * Resets this <code>MockObject</code>.
     * </p>
     */
    void reset();
}
