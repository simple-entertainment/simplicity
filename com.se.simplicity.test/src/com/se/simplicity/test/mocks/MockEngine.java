package com.se.simplicity.test.mocks;

import com.se.devenvy.mocks.MockObject;
import com.se.simplicity.engine.Engine;

/**
 * <p>
 * A mock engine that does not perform any work except to sleep for 1.5 times its preferred frequency the third time it advances.
 * Used to test the behaviour of composite engines when one or more of their sub-engines runs over time.
 * </p>
 * 
 * @author simple
 */
public class MockEngine extends MockObject implements Engine
{
	/**
	 * <p>
	 * The index of the current advancement.
	 * </p>
	 */
	private int advanceIndex;

	/**
	 * <p>
	 * The preferred frequency (advancements per second) of this <code>MockEngine</code>.
	 * </p>
	 */
	private int preferredFrequency;

	@Override
	public void advance()
	{
		addMethodCall("advance", null);

		if (++advanceIndex == 2)
		{
			try
			{
				Thread.sleep((long) (1000.0 / preferredFrequency * 1.5));
			}
			catch (InterruptedException e)
			{
				e.printStackTrace();
			}
		}
	}

	@Override
	public void destroy()
	{
		addMethodCall("destroy", null);
	}

	@Override
	public int getPreferredFrequency()
	{
		addMethodCall("getPreferredFrequency", null);

		return (preferredFrequency);
	}

	@Override
	public void init()
	{
		addMethodCall("init", null);

		advanceIndex = 0;
	}

	@Override
	public void reset()
	{
		addMethodCall("reset", null);

		advanceIndex = 0;
	}

	@Override
	public void setPreferredFrequency(int preferredFrequency)
	{
		addMethodCall("setPreferredFrequency", new Object[] {preferredFrequency});

		this.preferredFrequency = preferredFrequency;
	}

	@Override
	public void run()
	{
		addMethodCall("run", null);
	}
}
