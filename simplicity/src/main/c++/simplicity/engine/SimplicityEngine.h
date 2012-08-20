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
#ifndef SIMPLICITYENGINE_H_
#define SIMPLICITYENGINE_H_

#include "BaseEngine.h"
#include "../scene/Scene.h"

namespace simplicity
{
	class SimplicityEngine : public BaseEngine
	{
		public:
			SimplicityEngine();

			virtual ~SimplicityEngine();

			void addEntity(std::shared_ptr<Entity> entity);

			void addEntity(std::shared_ptr<Entity> entity, std::shared_ptr<TreeNode> node);

			void addEntity(std::shared_ptr<Entity> entity, std::shared_ptr<TreeNode> node, TreeNode& parent);

			std::shared_ptr<EngineInput> advance(const std::shared_ptr<EngineInput> input);

			void destroy();

			Engine* getEngine() const;

			Entity& getEntity(const std::string name);

			Scene* getScene() const;

			void onInit();

			void onReset();

			void removeEntity(const Entity& entity);

			void removeEntity(const string& name);

			void setEngine(std::shared_ptr<Engine> engine);

			void setScene(std::shared_ptr<Scene> scene);

		private:
			std::shared_ptr<Engine> engine;

			std::map<const string, std::shared_ptr<Entity> > entities;

			std::vector<std::shared_ptr<Entity> > newEntities;

			std::map<std::shared_ptr<TreeNode>, std::reference_wrapper<TreeNode> > newNodes;

			std::map<const Entity*, std::reference_wrapper<TreeNode> > nodes;

			std::shared_ptr<Scene> scene;
	};
}

#endif /* SIMPLICITYENGINE_H_ */
