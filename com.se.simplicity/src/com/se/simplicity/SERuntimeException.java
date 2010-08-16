package com.se.simplicity;

/**
 * <p>
 * A general runtime exception thrown by a simple enterprises project.
 * </p>
 * 
 * @author simple
 */
public class SERuntimeException extends RuntimeException
{
	/**
	 * The serialisation version of this class.
	 */
	private static final long serialVersionUID = 1L;

	/**
	 * <p>
	 * Creates an instance of <code>SERuntimeException</code>.
	 * </p>
	 */
	public SERuntimeException()
	{
		super();
	}

	/**
	 * <p>
	 * Creates an instance of <code>SERuntimeException</code>.
	 * </p>
	 * 
	 * @param message The message for this <code>SERuntimeException</code>.
	 */
	public SERuntimeException(final String message)
	{
		super(message);
	}

	/**
	 * <p>
	 * Creates an instance of <code>SERuntimeException</code>.
	 * </p>
	 * 
	 * @param message The message for this <code>SERuntimeException</code>.
	 * @param cause The underlying cause of this <code>SERuntimeException</code>.
	 */
	public SERuntimeException(final String message, final Throwable cause)
	{
		super(message, cause);
	}

	/**
	 * <p>
	 * Creates an instance of <code>SERuntimeException</code>.
	 * </p>
	 * 
	 * @param cause The underlying cause of this <code>SERuntimeException</code>.
	 */
	public SERuntimeException(final Throwable cause)
	{
		super(cause);
	}
}
