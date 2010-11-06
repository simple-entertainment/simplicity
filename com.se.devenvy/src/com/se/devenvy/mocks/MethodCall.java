/*
    This file is part of The Simplicity Engine.

    The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
    by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

    The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
package com.se.devenvy.mocks;

/**
 * <p>
 * A method call that has been made to a {@link com.se.devenvy.mocks.MockObject MockObject}.
 * </p>
 * 
 * @author Gary Buyn
 */
public class MethodCall
{
    /**
     * <p>
     * The name of the method called.
     * </p>
     */
    public String name;

    /**
     * <p>
     * The parameters passed to the method.
     * </p>
     */
    public Object[] parameters;

    /**
     * <p>
     * Creates an instance of <code>MethodCall</code>.
     * </p>
     */
    public MethodCall()
    {}
}
