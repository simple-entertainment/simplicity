/*
 * Copyright © 2012 Simple Entertainment Limited
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
#ifndef SIMPLEANIMATIONENGINE_H_
#define SIMPLEANIMATIONENGINE_H_

#include "../../engine/RunnableEngine.h"
#include "../Animator.h"

namespace simplicity
{
	/**
	 * <p>
	 * An engine that manages {@link simplicity::Animator Animator}s. The managed <code>Animator</code>s will animate
	 * during every advancement.
	 * </p>
	 *
	 * @author Gary Buyn
	 */
	class SimpleAnimationEngine : public RunnableEngine
	{
		public:
			/**
			 * <p>
			 * Creates an instance of <code>SimpleAnimationEngine</code>.
			 * </p>
			 */
			SimpleAnimationEngine();

			/**
			 * <p>
			 * Disposes of an instance of <code>SimpleAnimationEngine</code>.
			 * </p>
			 */
			virtual ~SimpleAnimationEngine();

			void addEntities(std::vector<std::shared_ptr<Entity> > entities);

			void addEntity(std::shared_ptr<Entity> entity);

			std::shared_ptr<EngineInput> advance(const std::shared_ptr<EngineInput> input);

			void destroy();

			/**
			 * <p>
			 * Retrieves the animators that are managed by this engine.
			 * </p>
			 *
			 * @return The animators that are managed by this engine.
			 */
			const std::vector<std::shared_ptr<Animator> > getAnimators();

		private:
			/**
			 * <p>
			 * The animators that are managed by this engine.
			 * </p>
			 */
			std::vector<std::shared_ptr<Animator> > animators;

			void onInit();

			void onReset();
	};
}

#endif /* SIMPLEANIMATIONENGINE_H_ */
