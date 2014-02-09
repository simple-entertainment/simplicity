/*
 * Copyright © 2014 Simple Entertainment Limited
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
#include "Simplicity.h"

namespace simplicity
{
	namespace Simplicity
	{
		extern std::unique_ptr<CompositeEngine> compositeEngine;
		extern std::vector<std::unique_ptr<Graph>> worldRepresentations;

		template<typename EngineType>
		EngineType* getEngine()
		{
			for (unsigned int index = 0; index < compositeEngine->getEngines().size(); index++)
			{
				EngineType* engine = dynamic_cast<EngineType*>(compositeEngine->getEngines()[index].get());
				if (engine != NULL)
				{
					return engine;
				}
			}

			return NULL;
		}

		template<typename EngineType>
		std::vector<EngineType*> getEngines()
		{
			std::vector<EngineType*> typedEngines;

			for (unsigned int index = 0; index < compositeEngine->getEngines().size(); index++)
			{
				EngineType* engine = dynamic_cast<EngineType*>(compositeEngine->getEngines()[index].get());
				if (engine != NULL)
				{
					typedEngines.push_back(engine);
				}
			}

			return typedEngines;
		}

		template<typename GraphType>
		GraphType* getWorldRepresentation()
		{
			for (unsigned int index = 0; index < worldRepresentations.size(); index++)
			{
				GraphType* worldRepresentation = dynamic_cast<GraphType*>(worldRepresentations[index].get());
				if (worldRepresentation != NULL)
				{
					return worldRepresentation;
				}
			}

			return NULL;
		}

		template<typename GraphType>
		std::vector<GraphType*> getWorldRepresentations()
		{
			std::vector<GraphType*> typedWorldRepresentations;

			for (unsigned int index = 0; index < worldRepresentations.size(); index++)
			{
				GraphType* worldRepresentation = dynamic_cast<GraphType*>(worldRepresentations[index].get());
				if (worldRepresentation != NULL)
				{
					typedWorldRepresentations.push_back(worldRepresentation);
				}
			}

			return typedWorldRepresentations;
		}
	}
}
