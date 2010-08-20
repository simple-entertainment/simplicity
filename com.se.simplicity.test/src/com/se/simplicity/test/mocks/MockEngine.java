/*
    This file is part of The Simplicity Engine.

    The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
    by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

    The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
package com.se.simplicity.test.mocks;

import com.se.devenvy.mocks.MockObject;
import com.se.simplicity.engine.Engine;

/**
 * <p>
 * A mock engine that does not perform any work except to sleep for 1.5 times its preferred frequency the third time it advances. Used to test the
 * behaviour of composite engines when one or more of their sub-engines runs over time.
 * </p>
 * 
 * @author Gary Buyn
 */
public class MockEngine extends MockObject implements Engine
{
    /**
     * <p>
     * The number of milliseconds in a second.
     * </p>
     */
    private static final double MILLISECONDS_IN_A_SECOND = 1000.0;

    /**
     * <p>
     * The fraction of the preferred frequency this <code>MockEngine</code> should wait. This should be above 1 to test over-running the frequency.
     * </p>
     */
    private static final double FRACTION_OF_FREQUENCY_TO_WAIT = 1.5;

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
                Thread.sleep((long) (MILLISECONDS_IN_A_SECOND / preferredFrequency * FRACTION_OF_FREQUENCY_TO_WAIT));
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
    public void setPreferredFrequency(final int newPreferredFrequency)
    {
        addMethodCall("setPreferredFrequency", new Object[] {newPreferredFrequency});

        this.preferredFrequency = newPreferredFrequency;
    }

    @Override
    public void run()
    {
        addMethodCall("run", null);
    }
}
