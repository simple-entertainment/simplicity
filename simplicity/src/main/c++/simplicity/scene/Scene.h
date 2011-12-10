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
#ifndef SCENE_H_
#define SCENE_H_

#include <vector>

#include <boost/enable_shared_from_this.hpp>

#include "../rendering/Camera.h"
#include "../rendering/Light.h"

namespace simplicity
{
	/**
	 * <p>
	 * A 3D environment.
	 * </p>
	 *
	 * @author Gary Buyn
	 */
	class Scene : public boost::enable_shared_from_this<Scene>
	{
		public:
			/**
			 * <p>
			 * Disposes of an instance of <code>Scene</code> (included to allow polymorphic deletion).
			 * </p>
			 */
			virtual ~Scene()
			{
			}

			/**
			 * <p>
			 * Adds a {@link simplicity::Camera Camera}s that can be used to view this <code>Scene</code> from specific
			 * angles.
			 * </p>
			 *
			 * @param camera The <code>Camera</code>s that can be used to view this <code>Scene</code> from specific
			 * angles.
			 */
			virtual void addCamera(boost::shared_ptr<Camera> camera) = 0;

			/**
			 * <p>
			 * Adds a {@link simplicity::Light Light} that can be used to illuminate this <code>Scene</code>.
			 * </p>
			 *
			 * @param light The <code>Light</code> that can be used to illuminate this <code>Scene</code>.
			 */
			virtual void addLight(boost::shared_ptr<Light> light) = 0;

			/**
			 * <p>
			 * Adds a {@link simplicity::Node Node}. This <code>Scene</code> will determine where to add the node
			 * depending on the internal structure it maintains.
			 * </p>
			 *
			 * <p>
			 * This method should be called instead of retrieving the root <code>Node</code> of the <code>Scene</code>
			 * and manually adding a child to maintain the integrity of the <code>Scene</code>.
			 * </p>
			 *
			 * @param node The <code>Node</code> to add.
			 */
			virtual void addNode(boost::shared_ptr<Node> node) = 0;

			/**
			 * <p>
			 * Adds a {@link simplicity::Node Node}.
			 * </p>
			 *
			 * <p>
			 * This method should be called instead of retrieving the root <code>Node</code> of the <code>Scene</code>
			 * and manually adding a child to maintain the integrity of the <code>Scene</code>. <code>Node</code>s
			 * should never be added as direct children of the root <code>Node</code>.
			 * </p>
			 *
			 * @param node The <code>Node</code> to add.
			 * @param parent The <code>Node</code> within the <code>Scene</code> to add the <code>Node</code> under.
			 */
			virtual void addNode(boost::shared_ptr<Node> node, Node& parent) = 0;

			/**
			 * <p>
			 * Retrieves the {@link simplicity::Camera Camera}s that can be used to view this <code>Scene</code> from
			 * specific angles.
			 * </p>
			 *
			 * @return The <code>Camera</code>s that can be used to view this <code>Scene</code> from specific angles.
			 */
			virtual std::vector<boost::shared_ptr<Camera> > getCameras() const = 0;

			/**
			 * <p>
			 * Retrieves the {@link simplicity::Light Light}s that can be used to illuminate this <code>Scene</code>.
			 * </p>
			 *
			 * @return The <code>Light</code>s that can be used to illuminate this <code>Scene</code>.
			 */
			virtual std::vector<boost::shared_ptr<Light> > getLights() const = 0;

			/**
			 * <p>
			 * Retrieves the {@link simplicity.scenegraph.Node Node} with the given ID.
			 * </p>
			 *
			 * @param id The ID of the <code>Node</code> to retrieve.
			 *
			 * @return The <code>Node</code> with the given ID.
			 */
			virtual boost::shared_ptr<Node> getNode(const int id) const = 0;

			/**
			 * Retrieves the root {@link simplicity::Node Node} of this <code>Scene</code>.
			 *
			 * @return The root <code>Node</code> of this <code>Scene</code>.
			 */
			virtual boost::shared_ptr<Node> getRoot() const = 0;

			/**
			 * <p>
			 * Obtain a shared pointer to this <code>Scene</code>.
			 * </p>
			 */
			boost::shared_ptr<Scene> getThisShared()
			{
				return (shared_from_this());
			}
			boost::shared_ptr<const Scene> getThisShared() const
			{
				return (shared_from_this());
			}

			/**
			 * <p>
			 * Retrieves the {@link simplicity::Node Node}s that were added to this <code>Scene</code> using the
			 * {@link #addNode(boost::shared_ptr<Node>)} method.
			 * </p>
			 *
			 * @return The <code>Node</code>s that were added to this <code>Scene</code> using the
			 * {@link #addNode(boost::shared_ptr<Node>)} method.
			 */
			virtual std::vector<boost::shared_ptr<Node> > getTopLevelNodes() const = 0;

			/**
			 * <p>
			 * Removes a {@link simplicity::Node Node} from the <code>Scene</code>.
			 * </p>
			 *
			 * <p>
			 * This method should be called instead of retrieving the <code>Node</code> and manually removing it from
			 * its parent to maintain the integrity of the <code>Scene</code>.
			 * </p>
			 *
			 * @param node The root <code>Node</code> to remove.
			 */
			virtual void removeNode(Node& node) = 0;

			/**
			 * <p>
			 * Resets the IDs of all the {@link simplicity::Node Node}s in this <code>SceneGraph</code>.
			 * </p>
			 */
			virtual void resetIds() = 0;

			/**
			 * <p>
			 * Sets the {@link simplicity::Camera Camera}s that can be used to view this <code>Scene</code> from
			 * specific angles.
			 * </p>
			 *
			 * @param cameras The <code>Camera</code>s that can be used to view this <code>Scene</code> from specific
			 * angles.
			 */
			virtual void setCameras(std::vector<boost::shared_ptr<Camera> > cameras) = 0;

			/**
			 * <p>
			 * Sets the {@link simplicity::Light Light}s that can be used to illuminate this <code>Scene</code>.
			 * </p>
			 *
			 * @param lights The <code>Light</code>s that can be used to illuminate this <code>Scene</code>.
			 */
			virtual void setLights(std::vector<boost::shared_ptr<Light> > const lights) = 0;
	};
}

#endif /* SCENE_H_ */
