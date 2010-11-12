/*
 This file is part of The Simplicity Engine.

 The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
 by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

 The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

 You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef RUNNABLEENGINE_H_
#define RUNNABLEENGINE_H_

#include <log4cpp/Category.hh>
using namespace log4cpp;

#include "Engine.h"

namespace simplicity
{
    /**
     * <p>
     * An engine that can be run at the preferred frequency provided to it. If an advancement takes longer than the time allowed by the preferred
     * frequency, this <code>RunnableEngine</code> will attempt to 'catch up' by advancing continuously until the correct number of advancements have been
     * made for the time this <code>RunnableEngine</code> has been running.
     * </p>
     *
     * <p>
     * <code>RunnableEngine</code> is designed to be run in a new Boost thread. It is cleanly interruptible.
     * For more information on Boost threading see the documentation at {@link www.boost.org}.
     * </p>
     *
     * @author Gary Buyn
     */
    class RunnableEngine : public virtual Engine
    {
        public:
            /**
             * <p>
             * Creates an instance of <code>RunnableEngine</code>.
             * </p>
             */
            RunnableEngine();

            /**
             * <p>
             * Disposes of an instance of <code>RunnableEngine</code>.
             * </p>
             */
            virtual
            ~RunnableEngine();

            int
            getPreferredFrequency();

            void
            init();

            /**
             * <p>
             * Runs the <code>RunnableEngine</code> at the preferred frequency. To stop the <code>RunnableEngine</code> interrupt the Boost thread it is running on.
             * </p>
             */
            void
            run();

            void
            setPreferredFrequency(const int preferredFrequency);

        protected:
            /**
             * <p>
             * Initialises the internal components of this <code>RunnableEngine</code> only. Does not initialise the sub-engines.
             * </p>
             */
            virtual void
            initInternal();

        private:
            /**
             * <p>
             * Determines if this <code>RunnableEngine</code> has been interrupted.
             * </p>
             */
            bool fInterrupted;

            /**
             * <p>
             * Logs messages associated with this class.
             * </p>
             */
            static Category* fLogger;

            /**
             * <p>
             * The preferred frequency (advancements per second) of this <code>RunnableEngine</code>.
             * </p>
             */
            int fPreferredFrequency;

            /**
             * <p>
             * The unadjusted time for this <code>RunnableEngine</code> to sleep between advancements. This <code>RunnableEngine</code> would
             * only sleep this long if the previous advancement was instantaneous.
             * </p>
             */
            long fSleepTime;

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
            long
            sleep(const long adjustedSleepTime);
    };
}

#endif /* RUNNABLEENGINE_H_ */
