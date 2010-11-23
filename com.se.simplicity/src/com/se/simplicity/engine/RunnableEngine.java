package com.se.simplicity.engine;

import org.apache.log4j.Logger;

/**
 * <p>
 * An engine that can be run at the preferred frequency provided to it. If an advancement takes longer than the time allowed by the preferred
 * frequency, this <code>RunnableEngine</code> will attempt to 'catch up' by advancing continuously until the correct number of advancements have been
 * made for the time this <code>RunnableEngine</code> has been running.
 * </p>
 * 
 * <p>
 * <code>RunnableEngine</code> is designed to be run in a new thread. It implements {@link java.lang.Runnable Runnable} and is cleanly interruptible.
 * For more information on Java threading see the tutorials on the Java web site.
 * </p>
 * 
 * @author Gary Buyn
 */
public abstract class RunnableEngine implements Engine, Runnable
{
    /**
     * <p>
     * Logs messages associated with this class.
     * </p>
     */
    private static Logger fLogger = Logger.getLogger(RunnableEngine.class);

    /**
     * <p>
     * The preferred frequency (advancements per second) of this <code>RunnableEngine</code>.
     * </p>
     */
    private int fPreferredFrequency;

    /**
     * <p>
     * The unadjusted time for this <code>RunnableEngine</code> to sleep between advancements. This <code>RunnableEngine</code> would only sleep this
     * long if the previous advancement was instantaneous.
     * </p>
     */
    private long fSleepTime;

    /**
     * <p>
     * Creates an instance of <code>RunnableEngine</code>.
     * </p>
     */
    public RunnableEngine()
    {
        fPreferredFrequency = 1;
        fSleepTime = 0L;
    }

    @Override
    public void destroy()
    {}

    @Override
    public int getPreferredFrequency()
    {
        return (fPreferredFrequency);
    }

    @Override
    public void init()
    {
        fSleepTime = (long) (MILLISECONDS_IN_A_SECOND / fPreferredFrequency);
    }

    @Override
    public void run()
    {
        init();

        // Start by sleeping.
        long beforeAdvanceTime = 0;
        long adjustedSleepTime = sleep(fSleepTime);

        // While the engine has not been interrupted.
        while (!Thread.interrupted())
        {
            beforeAdvanceTime = System.currentTimeMillis();

            try
            {
                advance(null);
            }
            catch (Exception e)
            {
             // Interrupt the engine.
                Thread.currentThread().interrupt();
                fLogger.error("Failed to advance the engine.", e);
            }

            // Subtract the time taken to advance the engine from the time it needs to sleep for.
            adjustedSleepTime -= System.currentTimeMillis() - beforeAdvanceTime;

            // Sleep until the next advancement is due.
            adjustedSleepTime = sleep(adjustedSleepTime);
        }

        destroy();
    }

    @Override
    public void setPreferredFrequency(final int preferredFrequency)
    {
        fPreferredFrequency = preferredFrequency;
    }

    /**
     * <p>
     * Causes this <code>RunnableEngine</code> to sleep for the adjusted time given (assuming it is it's own thread). The adjusted sleep time is then
     * updated to account due to the fact that this <code>RunnableEngine</code> has just slept.
     * </p>
     * 
     * <p>
     * In the case that the adjusted sleep time was positive, it is simply reset to the regular sleep time. In the case that it was negative (or
     * zero), the regular sleep time is added to it (and no delay is actually effected).
     * </p>
     * 
     * @param adjustedSleepTime The adjusted time this <code>RunnableEngine</code> is required to sleep. The 'adjusted time' is the time taken to
     * execute the previous advancement subtracted from the 'regular time' (the time between advancements).
     * 
     * @return The updated adjusted sleep time.
     */
    private long sleep(final long adjustedSleepTime)
    {
        // If the engine needs to sleep.
        if (adjustedSleepTime > 0)
        {
            try
            {
                Thread.sleep(adjustedSleepTime);
            }
            catch (InterruptedException e)
            {
                // Interrupt the engine.
                Thread.currentThread().interrupt();
                fLogger.debug("The engine was interrupted while sleeping.");
            }

            // Return the standard sleep duration.
            return (fSleepTime);
        }
        else
        {
            fLogger.warn("The engine ran over time.");

            // The engine has not slept as a result it has 'caught up' by the standard sleep duration.
            return (adjustedSleepTime + fSleepTime);
        }
    }
}
