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
#include "engine/SimplicityEngine.h"
#include "Simplicity.h"

using namespace std;

namespace simplicity
{
	namespace Simplicity
	{
		/**
		 * <p>
		 * The {@link simplicity::Engine Engine} that does the actual work for simplicity.
		 * </p>
		 */
		unique_ptr<SimplicityEngine> engine(new SimplicityEngine);

		void addEntities(vector<shared_ptr<Entity> > entities)
		{
			for (shared_ptr<Entity> entity : entities)
			{
				addEntity(entity);
			}
		}

		void addEntity(shared_ptr<Entity> entity)
		{
			engine->addEntity(entity);
		}

		void addEntity(shared_ptr<Entity> entity, shared_ptr<TreeNode> node)
		{
			engine->addEntity(entity, node);
		}

		void addEntity(shared_ptr<Entity> entity, shared_ptr<TreeNode> node, TreeNode& parent)
		{
			engine->addEntity(entity, node, parent);
		}

		Entity& getEntity(const string name)
		{
			return engine->getEntity(name);
		}

		Scene* getScene()
		{
			return engine->getScene();
		}

		void removeEntity(const string name)
		{
			engine->removeEntity(name);
		}

		void reset()
		{
			engine.reset();
		}

		void setEngine(std::shared_ptr<Engine> engine)
		{
			Simplicity::engine->setEngine(engine);
		}

		void setScene(std::shared_ptr<Scene> scene)
		{
			engine->setScene(scene);
		}

		void start()
		{
			engine->run();
		}

		void stop()
		{
			engine->destroy();
		}
	}
}
