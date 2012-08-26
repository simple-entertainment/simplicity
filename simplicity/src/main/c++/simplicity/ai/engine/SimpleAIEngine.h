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
#ifndef SIMPLEAIENGINE_H_
#define SIMPLEAIENGINE_H_

#include "../../engine/BaseEngine.h"
#include "../Agent.h"

namespace simplicity
{
	/**
	 * <p>
	 * An engine that manages {@link simplicity::Agent Agent}s. The managed <code>Agent</code>s will think during every
	 * advancement.
	 * </p>
	 *
	 * @author Gary Buyn
	 */
	class SimpleAIEngine : public BaseEngine
	{
		public:
			/**
			 * <p>
			 * Creates an instance of <code>SimpleAIEngine</code>.
			 * </p>
			 */
			SimpleAIEngine();

			/**
			 * <p>
			 * Disposes of an instance of <code>SimpleAIEngine</code>.
			 * </p>
			 */
			virtual ~SimpleAIEngine();

			void addEntity(std::shared_ptr<Entity> entity);

			std::vector<std::shared_ptr<Action> > advance(std::vector<std::shared_ptr<Action> > actions);

			void destroy();

			/**
			 * <p>
			 * Retrieves the agents that are managed by this engine.
			 * </p>
			 *
			 * @return The agents that are managed by this engine.
			 */
			const std::vector<std::shared_ptr<Agent> > getAgents();

			void removeEntity(const Entity& entity);

		private:
			/**
			 * <p>
			 * The agents that are managed by this engine.
			 * </p>
			 */
			std::vector<std::shared_ptr<Agent> > agents;

			void onInit();

			void onReset();
	};
}

#endif /* SIMPLEAIENGINE_H_ */
