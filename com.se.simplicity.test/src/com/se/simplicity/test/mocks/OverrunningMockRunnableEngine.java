/*
    This file is part of The Simplicity Engine.

    The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
    by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

    The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
package com.se.simplicity.test.mocks;

import org.apache.log4j.Logger;

import com.se.devenvy.mocks.MethodCall;
import com.se.devenvy.mocks.MockObject;
import com.se.devenvy.mocks.SimpleMockObject;
import com.se.simplicity.engine.EngineInput;
import com.se.simplicity.engine.RunnableEngine;
import com.se.simplicity.engine.SEEngineAdvancementException;

/**
 * <p>
 * A mock engine that does not perform any work except to sleep for 1.5 during the advancement specified by {@link #setOverrunIndex(int)}. Used to
 * test the behaviour of a {@link com.se.engine.RunnableEngine RunnableEngine} when it 'overruns'.
 * </p>
 * 
 * @author Gary Buyn
 */
public class OverrunningMockRunnableEngine extends RunnableEngine implements MockObject
{
    /**
     * <p>
     * The fraction of the preferred frequency this <code>MockEngine</code> should wait. This should be above 1 to test over-running the frequency.
     * </p>
     */
    private static final double FRACTION_OF_FREQUENCY_TO_WAIT = 1.5;

    /**
     * <p>
     * Logs messages associated with this class.
     * </p>
     */
    private static Logger fLogger = Logger.getLogger(RunnableEngine.class);

    /**
     * <p>
     * The number of milliseconds in a second.
     * </p>
     */
    private static final double MILLISECONDS_IN_A_SECOND = 1000.0;

    /**
     * <p>
     * The index of the current advancement.
     * </p>
     */
    private int fAdvanceIndex;

    /**
     * <p>
     * Performs actual mocking.
     * </p>
     */
    private SimpleMockObject fMockObject;

    /**
     * <p>
     * The index of the advancement in which this engine will overrun.
     * </p>
     */
    private int fOverrunIndex;

    /**
     * <p>
     * Creates an instance of <code>OverrunningMockRunnableEngine</code>.
     * </p>
     */
    public OverrunningMockRunnableEngine()
    {
        fAdvanceIndex = 0;
        fOverrunIndex = -1;
        fMockObject = new SimpleMockObject();
    }

    @Override
    public EngineInput advance(final EngineInput input) throws SEEngineAdvancementException
    {
        fMockObject.addMethodCall("advance", new Object[] {input});

        if (++fAdvanceIndex == fOverrunIndex)
        {
            try
            {
                Thread.sleep((long) (MILLISECONDS_IN_A_SECOND / getPreferredFrequency() * FRACTION_OF_FREQUENCY_TO_WAIT));
            }
            catch (InterruptedException e)
            {
                fLogger.error("The engine was interrupted while advancing.", e);
            }
        }

        return (null);
    }

    @Override
    public void destroy()
    {
        fMockObject.addMethodCall("destroy", null);

        super.destroy();
    }

    @Override
    public MethodCall getMethodCall(final int callIndex, final String name, final Object[] parameters)
    {
        return (fMockObject.getMethodCall(callIndex, name, parameters));
    }

    @Override
    public int getMethodCallCount(final String name, final Object[] parameters)
    {
        return (fMockObject.getMethodCallCount(name, parameters));
    }

    @Override
    public int getMethodCallCountIgnoreParams(final String name)
    {
        return (fMockObject.getMethodCallCountIgnoreParams(name));
    }

    @Override
    public MethodCall getMethodCallIgnoreParams(final int callIndex, final String name)
    {
        return (fMockObject.getMethodCallIgnoreParams(callIndex, name));
    }

    /**
     * <p>
     * Retrieves the index of the advancement in which this engine will overrun.
     * </p>
     * 
     * @return The index of the advancement in which this engine will overrun.
     */
    public int getOverrunIndex()
    {
        return (fOverrunIndex);
    }

    @Override
    public int getPreferredFrequency()
    {
        fMockObject.addMethodCall("getPreferredFrequency", null);

        return super.getPreferredFrequency();
    }

    @Override
    public void init()
    {
        fMockObject.addMethodCall("init", null);

        super.init();
    }

    @Override
    public boolean methodCallOrderCheck(final int beforeCallIndex, final String beforeMethodName, final Object[] beforeMethodParameters,
            final int afterCallIndex, final String afterMethodName, final Object[] afterMethodParameters)
    {
        return (fMockObject.methodCallOrderCheck(beforeCallIndex, beforeMethodName, beforeMethodParameters, afterCallIndex, afterMethodName,
                afterMethodParameters));
    }

    @Override
    public boolean methodCallOrderCheckIgnoreParams(final int beforeCallIndex, final String beforeMethodName, final int afterCallIndex,
            final String afterMethodName)
    {
        return (fMockObject.methodCallOrderCheckIgnoreParams(beforeCallIndex, beforeMethodName, afterCallIndex, afterMethodName));
    }

    @Override
    public void reset()
    {
        fMockObject.addMethodCall("reset", null);
    }

    @Override
    public void run()
    {
        fMockObject.addMethodCall("run", null);

        super.run();
    }

    /**
     * <p>
     * Sets the index of the advancement in which this engine will overrun.
     * </p>
     * 
     * @param overrunIndex The index of the advancement in which this engine will overrun.
     */
    public void setOverrunIndex(final int overrunIndex)
    {
        fOverrunIndex = overrunIndex;
    }

    @Override
    public void setPreferredFrequency(final int preferredFrequency)
    {
        fMockObject.addMethodCall("setPreferredFrequency", new Object[] {preferredFrequency});

        super.setPreferredFrequency(preferredFrequency);
    }
}
