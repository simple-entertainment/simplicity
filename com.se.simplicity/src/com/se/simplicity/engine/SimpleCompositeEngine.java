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

/**
 * <p>
 * Manages its sub-engines by running at the lowest common frequency (advancements per second) of these sub-engines and advancing them at their
 * preferred frequency.
 * </p>
 * 
 * @author Gary Buyn
 */
public class SimpleCompositeEngine extends RunnableEngine implements CompositeEngine
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
     * Creates an instance of <code>SimpleCompositeEngine</code>.
     * </p>
     */
    public SimpleCompositeEngine()
    {
        super();

        fAdvanceIndex = 0;
        fCompositeFrequency = 1;
        fEngines = new ArrayList<Engine>();
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

        // For every sub-engine.
        for (Engine engine : fEngines)
        {
            // If the sub-engine should be advanced at this time (if it's preferred frequency is a multiple of the composite frequency).
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
     * @param big The largest of the two integers to calculate the lowest common denominator of.
     * @param small The smallest of the two integers to calculate the lowest common denominator of.
     * 
     * @return The lowest common denominator of the two integer values given.
     */
    private int calculateLCD(final int big, final int small)
    {
        int gcd = big;

        if (small != 0)
        {
            gcd = big % small;
        }

        if (gcd == 0)
        {
            return (big);
        }

        return (big * small / gcd);
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
    private int getCompositeFrequency()
    {
        int newCompositeFrequency = 1;

        // If there is at least 1 sub-engine.
        if (!fEngines.isEmpty())
        {
            newCompositeFrequency = fEngines.get(0).getPreferredFrequency();

            // For every sub-engine (except for the first one).
            for (int index = 1; index < fEngines.size(); index++)
            {
                int preferredFrequency = fEngines.get(index).getPreferredFrequency();

                // Ensure that preferreFrequency contains the smaller of the two frequencies (required for the calculateLCD method).
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

        super.setPreferredFrequency(fCompositeFrequency);
        super.init();
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
}
