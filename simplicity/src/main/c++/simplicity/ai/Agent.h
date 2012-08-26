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
#ifndef AGENT_H_
#define AGENT_H_

#include "../action/Action.h"
#include "../Component.h"

namespace simplicity
{
	/**
	 * <p>
	 * An intelligent agent.
	 * </p>
	 *
	 * @author Gary Buyn
	 */
	class Agent : public virtual Component
	{
		public:
			/**
			 * <p>
			 * Disposes of an instance of <code>Agent</code> (included to allow polymorphic deletion).
			 * </p>
			 */
			virtual ~Agent()
			{
			}

			/**
			 * <p>
			 * Make decisions.
			 * </p>
			 *
			 * @return The actions that were decided.
			 */
			virtual std::vector<std::shared_ptr<Action> > think() = 0;
	};
}

#endif /* AGENT_H_ */
