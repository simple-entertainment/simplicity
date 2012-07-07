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
#ifndef SIMPLECOMPOSITEENGINE_H_
#define SIMPLECOMPOSITEENGINE_H_

#include <vector>

#include "BaseEngine.h"
#include "CompositeEngine.h"

namespace simplicity
{
	/**
	 * <p>
	 * Manages its sub-engines by running at the lowest common frequency (advancements per second) of these sub-engines
	 * and advancing them at their preferred frequency.
	 * </p>
	 *
	 * @author Gary Buyn
	 */
	class SimpleCompositeEngine : public BaseEngine, public CompositeEngine
	{
		public:
			/**
			 * <p>
			 * Creates an instance of <code>SimpleCompositeEngine</code>.
			 * </p>
			 */
			SimpleCompositeEngine();

			/**
			 * <p>
			 * Disposes of an instance of <code>SimpleCompositeEngine</code>.
			 * </p>
			 */
			virtual ~SimpleCompositeEngine();

			void addEngine(std::shared_ptr<Engine> engine);

			void addEntity(std::shared_ptr<Entity> entity);

			std::shared_ptr<EngineInput> advance(const std::shared_ptr<EngineInput> input);

			void destroy();

			void removeEngine(const std::shared_ptr<Engine> engine);

			void removeEntity(const Entity& entity);

		private:
			/**
			 * <p>
			 * The index of the current advancement.
			 * </p>
			 */
			int advanceIndex;

			/**
			 * <p>
			 * The lowest common frequency (advancements per second) at which this <code>SimpleCompositeEngine</code>
			 * can run that will support the preferred frequencies of its sub-engines.
			 * </p>
			 */
			int compositeFrequency;

			/**
			 * <p>
			 * The sub-engines managed by this <code>SimpleCompositeEngine</code>.
			 * </p>
			 */
			std::vector<std::shared_ptr<Engine> > engines;

			/**
			 * <p>
			 * Calculates the lowest common denominator of the two integer values given.
			 * </p>
			 *
			 * @param a The first of the two integers to calculate the lowest common denominator of.
			 * @param b The second of the two integers to calculate the lowest common denominator of.
			 *
			 * @return The lowest common denominator of the two integer values given.
			 */
			int calculateLCD(int a, int b) const;

			/**
			 * <p>
			 * Retrieves the lowest common frequency (advancements per second) at which this
			 * <code>SimpleCompositeEngine</code> can run that will support the preferred frequencies of its
			 * sub-engines.
			 * </p>
			 *
			 * @return the lowest common frequency (advancements per second) at which this
			 * <code>SimpleCompositeEngine</code> can run that will support the preferred frequencies of its
			 * sub-engines.
			 */
			int getCompositeFrequency() const;

			void onInit();

			void onReset();
	};
}

#endif /* SIMPLECOMPOSITEENGINE_H_ */
