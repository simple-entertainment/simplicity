package com.se.simplicity;

/**
 * <p>
 * An exception thrown by a simple enterprises project. Signifies that an invalid operation was attempted.
 * </p>
 * 
 * @author simple
 */
public class SEInvalidOperationException extends SEException
{
	/**
	 * The serialisation version of this class.
	 */
	private static final long serialVersionUID = 1L;

	/**
	 * <p>
	 * Creates an instance of <code>SEInvalidOperationException</code>.
	 * </p>
	 */
	public SEInvalidOperationException()
	{
		super();
	}

	/**
	 * <p>
	 * Creates an instance of <code>SEInvalidOperationException</code>.
	 * </p>
	 * 
	 * @param message The message for this <code>SEInvalidOperationException</code>.
	 */
	public SEInvalidOperationException(final String message)
	{
		super(message);
	}

	/**
	 * <p>
	 * Creates an instance of <code>SEInvalidOperationException</code>.
	 * </p>
	 * 
	 * @param message The message for this <code>SEInvalidOperationException</code>.
	 * @param cause The underlying cause of this <code>SEInvalidOperationException</code>.
	 */
	public SEInvalidOperationException(final String message, final Throwable cause)
	{
		super(message, cause);
	}

	/**
	 * <p>
	 * Creates an instance of <code>SEInvalidOperationException</code>.
	 * </p>
	 * 
	 * @param cause The underlying cause of this <code>SEInvalidOperationException</code>.
	 */
	public SEInvalidOperationException(final Throwable cause)
	{
		super(cause);
	}
}
