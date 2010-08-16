package com.se.simplicity;

/**
 * <p>
 * A general exception thrown by a simple enterprises project.
 * </p>
 * 
 * @author simple
 */
public class SEException extends Exception
{
	/**
	 * The serialisation version of this class.
	 */
	private static final long serialVersionUID = 1L;

	/**
	 * <p>
	 * Creates an instance of <code>SEException</code>.
	 * </p>
	 */
	public SEException()
	{
		super();
	}

	/**
	 * <p>
	 * Creates an instance of <code>SEException</code>.
	 * </p>
	 * 
	 * @param message The message for this <code>SEException</code>.
	 */
	public SEException(final String message)
	{
		super(message);
	}

	/**
	 * <p>
	 * Creates an instance of <code>SEException</code>.
	 * </p>
	 * 
	 * @param message The message for this <code>SEException</code>.
	 * @param cause The underlying cause of this <code>SEException</code>.
	 */
	public SEException(final String message, final Throwable cause)
	{
		super(message, cause);
	}

	/**
	 * <p>
	 * Creates an instance of <code>SEException</code>.
	 * </p>
	 * 
	 * @param cause The underlying cause of this <code>SEException</code>.
	 */
	public SEException(final Throwable cause)
	{
		super(cause);
	}
}
