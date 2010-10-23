/*
    This file is part of The Simplicity Engine.

    The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
    by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

    The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
package com.se.simplicity.engine;

import java.util.ArrayList;
import java.util.List;

import org.apache.log4j.Logger;

import com.se.simplicity.SENotSupportedException;

/**
 * <p>
 * Manages its sub-engines by running at the lowest common frequency (advancements per second) of these sub-engines and advancing them at their
 * preferred frequency. If the advancement of the sub-engines takes longer than the time allowed by the lowest common frequency, this
 * <code>SimpleCompositeEngine</code> will attempt to 'catch up' by advancing continuously until the correct number of advancements have been made for
 * the time this <code>SimpleCompositeEngine</code> has been running.
 * </p>
 * 
 * @author Gary Buyn
 */
public class SimpleCompositeEngine implements CompositeEngine
{
    /**
     * <p>
     * The index of the current advancement.
     * </p>
     */
    private int fAdvanceIndex;

    /**
     * <p>
     * The lowest common frequency (advancements per second) at which this <code>SimpleCompositeEngine</code> can run that will support the preferred
     * frequencies of its sub-engines.
     * </p>
     */
    private int fCompositeFrequency;

    /**
     * <p>
     * The sub-engines managed by this <code>SimpleCompositeEngine</code>.
     * </p>
     */
    private List<Engine> fEngines;

    /**
     * <p>
     * Logs messages associated with this class.
     * </p>
     */
    private Logger fLogger;

    /**
     * <p>
     * The unadjusted time for this <code>SimpleCompositeEngine</code> to sleep between advancements. This <code>SimpleCompositeEngine</code> would
     * only sleep this long if the previous advancement was instantaneous.
     * </p>
     */
    private long fSleepTime;

    /**
     * <p>
     * Creates an instance of <code>SimpleCompositeEngine</code>.
     * </p>
     */
    public SimpleCompositeEngine()
    {
        fEngines = new ArrayList<Engine>();
        fLogger = Logger.getLogger(getClass().getName());
    }

    @Override
    public void addEngine(final Engine engine)
    {
        fEngines.add(engine);
    }

    @Override
    public synchronized EngineInput advance(final EngineInput input) throws SEEngineAdvancementException
    {
        fAdvanceIndex++;
        EngineInput currentInput = input;

        for (Engine engine : fEngines)
        {
            if (fAdvanceIndex % (fCompositeFrequency / engine.getPreferredFrequency()) == 0)
            {
                currentInput = engine.advance(currentInput);
            }
        }

        return (currentInput);
    }

    /**
     * <p>
     * Calculates the lowest common denominator of the two integer values given.
     * </p>
     * 
     * @param a The largest of the two integers to calculate the lowest common denominator of.
     * @param b The smallest of the two integers to calculate the lowest common denominator of.
     * 
     * @return The lowest common denominator of the two integer values given.
     */
    protected int calculateLCD(final int a, final int b)
    {
        int gcd = a;

        if (b != 0)
        {
            gcd = a % b;
        }

        if (gcd == 0)
        {
            return (a);
        }

        return (a * b / gcd);
    }

    @Override
    public void destroy()
    {
        for (Engine engine : fEngines)
        {
            engine.destroy();
        }

        destroyInternal();
    }

    /**
     * <p>
     * Destroys the internal components of this <code>SimpleCompositeEngine</code> only. Does not destroy the sub-engines.
     * </p>
     */
    protected void destroyInternal()
    {}

    /**
     * <p>
     * Retrieves the lowest common frequency (advancements per second) at which this <code>SimpleCompositeEngine</code> can run that will support the
     * preferred frequencies of its sub-engines.
     * </p>
     * 
     * @return the lowest common frequency (advancements per second) at which this <code>SimpleCompositeEngine</code> can run that will support the
     * preferred frequencies of its sub-engines.
     */
    public int getCompositeFrequency()
    {
        int newCompositeFrequency = 1;

        if (!fEngines.isEmpty())
        {
            newCompositeFrequency = fEngines.get(0).getPreferredFrequency();

            for (int index = 1; index < fEngines.size(); index++)
            {
                int preferredFrequency = fEngines.get(index).getPreferredFrequency();

                if (newCompositeFrequency < preferredFrequency)
                {
                    int temp = newCompositeFrequency;
                    newCompositeFrequency = preferredFrequency;
                    preferredFrequency = temp;
                }

                newCompositeFrequency = calculateLCD(newCompositeFrequency, preferredFrequency);
            }
        }

        return (newCompositeFrequency);
    }

    @Override
    public int getPreferredFrequency()
    {
        return (-1);
    }

    @Override
    public void init()
    {
        initInternal();

        for (Engine engine : fEngines)
        {
            engine.init();
        }
    }

    /**
     * <p>
     * Initialises the internal components of this <code>SimpleCompositeEngine</code> only. Does not initialise the sub-engines.
     * </p>
     */
    protected void initInternal()
    {
        fAdvanceIndex = 0;
        fCompositeFrequency = getCompositeFrequency();
        fSleepTime = (long) MILLISECONDS_IN_A_SECOND / fCompositeFrequency;
    }

    @Override
    public void removeEngine(final Engine engine)
    {
        fEngines.remove(engine);
    }

    @Override
    public void reset()
    {
        initInternal();

        for (Engine engine : fEngines)
        {
            engine.reset();
        }
    }

    @Override
    public void run()
    {
        init();

        long beforeAdvanceTime = 0;
        long adjustedSleepTime = sleep(fSleepTime);

        while (!Thread.interrupted())
        {
            beforeAdvanceTime = System.currentTimeMillis();

            try
            {
                advance(null);
            }
            catch (Exception e)
            {
                Thread.currentThread().interrupt();
                fLogger.error("Failed to advance the engine.", e);
            }

            adjustedSleepTime -= System.currentTimeMillis() - beforeAdvanceTime;

            adjustedSleepTime = sleep(adjustedSleepTime);
        }

        destroy();
    }

    @Override
    public void setPreferredFrequency(final int preferredFrequency)
    {
        throw new SENotSupportedException();
    }

    /**
     * <p>
     * Causes this <code>SimpleCompositeEngine</code> to sleep for the adjusted time given (assuming it is it's own thread). The adjusted sleep time
     * is then updated to account for the fact that this <code>SimpleCompositeEngine</code> has just slept.
     * </p>
     * 
     * <p>
     * In the case that the adjusted sleep time was positive, it is simply reset to the regular sleep time. In the case that it was negative (or
     * zero), the regular sleep time is added to it (and no delay is actually effected).
     * </p>
     * 
     * @param adjustedSleepTime The adjusted time this <code>SimpleCompositeEngine</code> is required to sleep. The 'adjusted time' is the time taken
     * to execute the previous advancement subtracted from the 'regular time' (the time between advancements).
     * 
     * @return The updated adjusted sleep time.
     */
    protected long sleep(final long adjustedSleepTime)
    {
        if (adjustedSleepTime > 0)
        {
            try
            {
                Thread.sleep(adjustedSleepTime);
            }
            catch (InterruptedException e)
            {
                Thread.currentThread().interrupt();
                fLogger.debug("The engine was interrupted while sleeping.");
            }

            return (fSleepTime);
        }

        fLogger.warn("One or more sub-engines caused the engine to run over time.");

        return (adjustedSleepTime + fSleepTime);
    }
}
