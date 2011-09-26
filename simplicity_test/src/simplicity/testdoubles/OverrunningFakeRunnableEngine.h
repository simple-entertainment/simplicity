/*
 * Copyright © Simple Entertainment Limited 2011
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
#ifndef OVERRUNNINGFAKERUNNABLEENGINE_H_
#define OVERRUNNINGFAKERUNNABLEENGINE_H_

#include <log4cpp/Category.hh>

#include <simplicity/engine/Engine.h>
#include <simplicity/engine/RunnableEngine.h>

namespace simplicity
{
	/**
	 * <p>
	 * A fake engine that does not perform any work except to sleep for 1.5 times its preferred frequency the third
	 * time it advances. Used to test the behaviour of composite engines when one or more of their sub-engines runs
	 * over time.
	 * </p>
	 *
	 * @author Gary Buyn
	 */
	class OverrunningFakeRunnableEngine: public RunnableEngine
	{
		public:
			/**
			 * <p>
			 * Creates an instance of <code>OverrunningFakeRunnableEngine</code>.
			 * </p>
			 */
			OverrunningFakeRunnableEngine();

			/**
			 * <p>
			 * Disposes of an instance of <code>OverrunningFakeRunnableEngine</code>.
			 * </p>
			 */
			virtual ~OverrunningFakeRunnableEngine();

			void addEntities(std::vector<boost::shared_ptr<Entity> > entities);

			void addEntity(boost::shared_ptr<Entity> entity);

			boost::shared_ptr<EngineInput> advance(const boost::shared_ptr<EngineInput> input);

			void destroy();

			/**
			 * <p>
			 * Retrieve the number of calls made to {@link #advance()}.
			 * </p>
			 *
			 * @return The number of calls made to <code>advance()</code>.
			 */
			int getAdvanceCount();

			/**
			 * <p>
			 * Retrieve the number of calls made to {@link #destroy()}.
			 * </p>
			 *
			 * @return The number of calls made to <code>destroy()</code>.
			 */
			int getDestroyCount();

			/**
			 * <p>
			 * Retrieve the number of calls made to {@link #init()}.
			 * </p>
			 *
			 * @return The number of calls made to <code>init()</code>.
			 */
			int getInitCount();

			/**
			 * <p>
			 * Retrieves the index of the advancement in which this engine will overrun.
			 * </p>
			 *
			 * @return The index of the advancement in which this engine will overrun.
			 */
			int getOverrunIndex() const;

			void init();

			void reset();

			/**
			 * <p>
			 * Sets the index of the advancement in which this engine will overrun.
			 * </p>
			 *
			 * @param overrunIndex The index of the advancement in which this engine will overrun.
			 */
			void setOverrunIndex(const int overrunIndex);

		private:
			/**
			 * <p>
			 * The fraction of the preferred frequency this <code>MockEngine</code> should wait. This should be above 1
			 * to test over-running the frequency.
			 * </p>
			 */
			static const double FRACTION_OF_FREQUENCY_TO_WAIT = 1.5;

			/**
			 * <p>
			 * Logs messages associated with this class.
			 * </p>
			 */
			static log4cpp::Category& logger;

			/**
			 * <p>
			 * The number of milliseconds in a second.
			 * </p>
			 */
			static const double MILLISECONDS_IN_A_SECOND = 1000.0;

			void initInternal();

			/**
			 * <p>
			 * The number of calls made to {@link #advance()}.
			 * </p>
			 */
			int advanceCount;

			/**
			 * <p>
			 * The index of the current advancement.
			 * </p>
			 */
			int advanceIndex;

			/**
			 * <p>
			 * The number of calls made to {@link #destroy()}.
			 * </p>
			 */
			int destroyCount;

			/**
			 * <p>
			 * The number of calls made to {@link #init()}.
			 * </p>
			 */
			int initCount;

			/**
			 * <p>
			 * The index of the advancement in which this engine will overrun.
			 * </p>
			 */
			int overrunIndex;
	};
}

#endif /* OVERRUNNINGFAKERUNNABLEENGINE_H_ */
