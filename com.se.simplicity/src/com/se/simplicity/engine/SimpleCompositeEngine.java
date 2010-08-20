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
     * The number of milliseconds in a second.
     * </p>
     */
    private static final double MILLISECONDS_IN_A_SECOND = 1000.0;

    /**
     * <p>
     * The index of the current advancement.
     * </p>
     */
    private int advanceIndex;

    /**
     * <p>
     * The lowest common frequency (advancements per second) at which this <code>SimpleCompositeEngine</code> can run that will support the preferred
     * frequencies of its sub-engines.
     * </p>
     */
    private int compositeFrequency;

    /**
     * <p>
     * The sub-engines managed by this <code>SimpleCompositeEngine</code>.
     * </p>
     */
    private List<Engine> engines;

    /**
     * <p>
     * Logs messages associated with this class.
     * </p>
     */
    private Logger logger;

    /**
     * <p>
     * The unadjusted time for this <code>SimpleCompositeEngine</code> to sleep between advancements. This <code>SimpleCompositeEngine</code> would
     * only sleep this long if the previous advancement was instantaneous.
     * </p>
     */
    private long sleepTime;

    /**
     * <p>
     * Creates an instance of <code>SimpleCompositeEngine</code>.
     * </p>
     */
    public SimpleCompositeEngine()
    {
        engines = new ArrayList<Engine>();
        logger = Logger.getLogger(getClass().getName());
    }

    @Override
    public void addEngine(final Engine engine)
    {
        engines.add(engine);
    }

    @Override
    public synchronized void advance()
    {
        advanceIndex++;

        for (Engine engine : engines)
        {
            if (advanceIndex % (compositeFrequency / engine.getPreferredFrequency()) == 0)
            {
                engine.advance();
            }
        }
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
        for (Engine engine : engines)
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

        if (!engines.isEmpty())
        {
            newCompositeFrequency = engines.get(0).getPreferredFrequency();

            for (int index = 1; index < engines.size(); index++)
            {
                int preferredFrequency = engines.get(index).getPreferredFrequency();

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

        for (Engine engine : engines)
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
        advanceIndex = 0;
        compositeFrequency = getCompositeFrequency();
        sleepTime = (long) MILLISECONDS_IN_A_SECOND / compositeFrequency;
    }

    @Override
    public void removeEngine(final Engine engine)
    {
        engines.remove(engine);
    }

    @Override
    public void reset()
    {
        initInternal();

        for (Engine engine : engines)
        {
            engine.reset();
        }
    }

    @Override
    public void run()
    {
        init();

        long beforeAdvanceTime = 0;
        long adjustedSleepTime = sleep(sleepTime);

        while (!Thread.interrupted())
        {
            beforeAdvanceTime = System.currentTimeMillis();

            advance();

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

                logger.debug("The engine was interrupted while sleeping.");
            }

            return (sleepTime);
        }

        logger.warn("One or more sub-engines caused the engine to run over time.");

        return (adjustedSleepTime + sleepTime);
    }
}
