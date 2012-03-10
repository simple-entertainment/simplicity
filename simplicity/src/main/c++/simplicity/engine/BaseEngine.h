/*
 * Copyright © 2011 Simple Entertainment Limited
 *
 * This file is part of The Simplicity Engine.
 *
 * The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General
 * Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option)
 * any later version.
 *
 * The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the
 * implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more
 * details.
 *
 * You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see
 * <http://www.gnu.org/licenses/>.
 */
#ifndef BASEENGINE_H_
#define BASEENGINE_H_

#include <log4cpp/Category.hh>

#include "Engine.h"

namespace simplicity
{
	/**
	 * <p>
	 * An engine that can be run at the preferred frequency provided to it. If an advancement takes longer than the time
	 * allowed by the preferred frequency, this <code>BaseEngine</code> will attempt to 'catch up' by advancing
	 * continuously until the correct number of advancements have been made for the time this <code>BaseEngine</code>
	 * has been running.
	 * </p>
	 *
	 * <p>
	 * <code>BaseEngine</code> is designed to be run in a new Boost thread. It is cleanly interruptible. For more
	 * information on Boost threading see the documentation at {@link www.boost.org}.
	 * </p>
	 *
	 * @author Gary Buyn
	 */
	class BaseEngine : public virtual Engine
	{
		public:
			/**
			 * <p>
			 * The number of milliseconds in a second.
			 * </p>
			 */
			static const double MILLISECONDS_IN_A_SECOND;

			/**
			 * <p>
			 * Creates an instance of <code>BaseEngine</code>.
			 * </p>
			 */
			BaseEngine();

			/**
			 * <p>
			 * Disposes of an instance of <code>BaseEngine</code>.
			 * </p>
			 */
			virtual ~BaseEngine();

			int getPreferredFrequency() const;

			void init();

			void reset();

			void run();

			void setPreferredFrequency(const int preferredFrequency);

		protected:
			/**
			 * <p>
			 * Initialises this <code>BaseEngine</code>.
			 * </p>
			 */
			virtual void onInit() = 0;

			/**
			 * <p>
			 * Resets this <code>Engine</code> to it's initial properties.
			 * </p>
			 */
			virtual void onReset() = 0;

		private:
			/**
			 * <p>
			 * Determines if this <code>BaseEngine</code> has been interrupted.
			 * </p>
			 */
			bool interrupted;

			/**
			 * <p>
			 * Logs messages associated with this class.
			 * </p>
			 */
			static log4cpp::Category& logger;

			/**
			 * <p>
			 * The preferred frequency (advancements per second) of this <code>BaseEngine</code>.
			 * </p>
			 */
			int preferredFrequency;

			/**
			 * <p>
			 * The unadjusted time for this <code>BaseEngine</code> to sleep between advancements. This
			 * <code>BaseEngine</code> would only sleep this long if the previous advancement was instantaneous.
			 * </p>
			 */
			long sleepTime;

			/**
			 * <p>
			 * Causes this <code>BaseEngine</code> to sleep for the adjusted time given (assuming it is it's own
			 * thread). The adjusted sleep time is then updated to account due to the fact that this
			 * <code>BaseEngine</code> has just slept.
			 * </p>
			 *
			 * <p>
			 * In the case that the adjusted sleep time was positive, it is simply reset to the regular sleep time. In
			 * the case that it was negative (or zero), the regular sleep time is added to it (and no delay is actually
			 * effected).
			 * </p>
			 *
			 * @param adjustedSleepTime The adjusted time this <code>BaseEngine</code> is required to sleep. The
			 * 'adjusted time' is the time taken to execute the previous advancement subtracted from the 'regular time'
			 * (the time between advancements).
			 *
			 * @return The updated adjusted sleep time.
			 */
			long sleep(const long adjustedSleepTime);
	};
}

#endif /* BASEENGINE_H_ */
