/*
    This file is part of The Simplicity Engine.

    The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
    by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

    The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
package com.se.simplicity;

/**
 * <p>
 * A runtime exception thrown by a simple enterprises project. Signifies that the functionality being invoked is not supported.
 * </p>
 * 
 * @author Gary Buyn
 */
public class SENotSupportedException extends SERuntimeException
{
    /**
     * The serialisation version of this class.
     */
    private static final long serialVersionUID = 1L;

    /**
     * <p>
     * Creates an instance of <code>SENotSupportedException</code>.
     * </p>
     */
    public SENotSupportedException()
    {
        super();
    }

    /**
     * <p>
     * Creates an instance of <code>SENotSupportedException</code>.
     * </p>
     * 
     * @param message The message for this <code>SENotSupportedException</code>.
     */
    public SENotSupportedException(final String message)
    {
        super(message);
    }

    /**
     * <p>
     * Creates an instance of <code>SENotSupportedException</code>.
     * </p>
     * 
     * @param message The message for this <code>SENotSupportedException</code>.
     * @param cause The underlying cause of this <code>SENotSupportedException</code>.
     */
    public SENotSupportedException(final String message, final Throwable cause)
    {
        super(message, cause);
    }

    /**
     * <p>
     * Creates an instance of <code>SENotSupportedException</code>.
     * </p>
     * 
     * @param cause The underlying cause of this <code>SENotSupportedException</code>.
     */
    public SENotSupportedException(final Throwable cause)
    {
        super(cause);
    }
}
