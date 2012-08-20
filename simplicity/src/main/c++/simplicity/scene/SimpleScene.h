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
#ifndef SIMPLESCENE_H_
#define SIMPLESCENE_H_

#include <map>

#include "Scene.h"
#include "../graph/TreeNode.h"

namespace simplicity
{
	/**
	 * <p>
	 * A simple implementation of a {@link simplicity::Scene Scene}.
	 * </p>
	 *
	 * @author Gary Buyn
	 */
	class SimpleScene : public Scene
	{
		public:
			/**
			 * Creates an instance of <code>SimpleScene</code>.
			 */
			SimpleScene(std::shared_ptr<Tree<TreeNode> > tree);

			/**
			 * Disposes of an instance of <code>SimpleScene</code>.
			 */
			virtual ~SimpleScene();

			void addCamera(std::shared_ptr<Camera> camera);

			void addLight(std::shared_ptr<Light> light);

			std::vector<std::shared_ptr<Camera> > getCameras() const;

			std::vector<std::shared_ptr<Light> > getLights() const;

			Tree<TreeNode>& getTree();

			const Tree<TreeNode>& getTree() const;

			void setCameras(std::vector<std::shared_ptr<Camera> > cameras);

			void setLights(std::vector<std::shared_ptr<Light> > lights);

		private:
			/**
			 * <p>
			 * The {@link simplicity::Camera Camera}s that can be used to view this <code>SimpleScene</code> from
			 * specific angles.
			 * </p>
			 */
			std::vector<std::shared_ptr<Camera> > cameras;

			/**
			 * <p>
			 * The {@link simplicity::Light Light}s that can be used to illuminate this <code>SimpleScene</code>.
			 * </p>
			 */
			std::vector<std::shared_ptr<Light> > lights;

			std::shared_ptr<Tree<TreeNode> > tree;
	};
}

#endif /* SIMPLESCENE_H_ */
