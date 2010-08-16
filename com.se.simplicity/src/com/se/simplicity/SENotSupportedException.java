package com.se.simplicity;

/**
 * <p>
 * A runtime exception thrown by a simple enterprises project. Signifies that the functionality being invoked is not supported.
 * </p>
 * 
 * @author simple
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
