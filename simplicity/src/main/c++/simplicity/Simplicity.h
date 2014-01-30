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
#ifndef SIMPLICITY_H_
#define SIMPLICITY_H_

#include "engine/Engine.h"
#include "graph/Graph.h"

namespace simplicity
{
	namespace Simplicity
	{
		void addEngine(std::unique_ptr<Engine> engine);

		void addEntity(std::unique_ptr<Entity> entity);

        void addWorldRepresentation(std::unique_ptr<Graph> graph);

		float getDeltaTime();

        std::vector<Entity*> getEntities(unsigned short category = Categories::ALL_CATEGORIES);

		unsigned short getMaxFrameRate();

		float getTotalTime();

		void pause();

		void play();

		void removeEngine(const Engine& engine);

		void removeEntity(const Entity& entity);

		void setMaxFrameRate(unsigned short maxFrameRate);

		void stop();
	}
}

#endif /* SIMPLICITY_H_ */
