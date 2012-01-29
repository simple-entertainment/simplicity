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
			SimpleScene();

			/**
			 * Disposes of an instance of <code>SimpleScene</code>.
			 */
			virtual ~SimpleScene();

			void addCamera(std::shared_ptr<Camera> camera);

			void addLight(std::shared_ptr<Light> light);

			void addNode(std::shared_ptr<Node> node);

			void addNode(std::shared_ptr<Node> node, Node& parent);

			std::vector<std::shared_ptr<Camera> > getCameras() const;

			std::vector<std::shared_ptr<Light> > getLights() const;

			std::shared_ptr<Node> getNode(const int id) const;

			std::shared_ptr<Node> getRoot() const;

			std::vector<std::shared_ptr<Node> > getTopLevelNodes() const;

			void removeNode(Node& node);

			void resetIds();

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
			 * The unique identifier that was assigned to the last {@link com.se.simplicity.scenegraph.Node Node} added
			 * to the <code>SimpleScene</code>.
			 */
			int nextNodeId;

			/**
			 * <p>
			 * The {@link simplicity::Light Light}s that can be used to illuminate this <code>SimpleScene</code>.
			 * </p>
			 */
			std::vector<std::shared_ptr<Light> > lights;

			/**
			 * <p>
			 * The {@link simplicity::Node Node}s within this <code>SimpleScene</code>.
			 * </p>
			 */
			std::map<int, std::shared_ptr<Node> > nodes;

			/**
			 * <p>
			 * The root {@link simplicity::Node Node} of this <code>SimpleScene</code>.
			 * </p>
			 */
			std::shared_ptr<Node> root;

			/**
			 * <p>
			 * Retrieves a unique identifier to assign to the next {@link com.se.simplicity.scenegraph.Node Node} added
			 * to the <code>SimpleScene</code>.
			 * </p>
			 *
			 * @return A unique identifier to assign to the next <code>Node</code> added to the
			 * <code>SimpleScene</code>.
			 */
			int
			getNextNodeId();
	};
}

#endif /* SIMPLESCENE_H_ */
