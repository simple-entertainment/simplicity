/*
 This file is part of The Simplicity Engine.

 The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
 by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

 The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

 You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef SCENE_H_
#define SCENE_H_

#include <vector>
using namespace std;

#include "../rendering/Camera.h"
#include "../rendering/Light.h"
#include "../scenegraph/SceneGraph.h"

namespace simplicity
{
  /**
   * <p>
   * A 3D environment.
   * </p>
   *
   * @author Gary Buyn
   */
  class Scene
  {
    public:
      /**
       * <p>
       * Disposes of an instance of <code>Scene</code> (included to allow polymorphic deletion).
       * </p>
       */
      virtual
      ~Scene()
      {
      }

      /**
       * <p>
       * Adds a {@link simplicity::Camera Camera}s that can be used to view this <code>Scene</code> from specific angles.
       * </p>
       *
       * @param camera The <code>Camera</code>s that can be used to view this <code>Scene</code> from specific angles.
       */
      virtual void
      addCamera(Camera * const camera) = 0;

      /**
       * <p>
       * Adds a {@link simplicity::Light Light} that can be used to illuminate this <code>Scene</code>.
       * </p>
       *
       * @param light The <code>Light</code> that can be used to illuminate this <code>Scene</code>.
       */
      virtual void
      addLight(Light * const light) = 0;

      /**
       * <p>
       * Retrieves the {@link simplicity::Camera Camera}s that can be used to view this <code>Scene</code> from specific angles.
       * </p>
       *
       * @return The <code>Camera</code>s that can be used to view this <code>Scene</code> from specific angles.
       */
      virtual vector<Camera *>
      getCameras() const = 0;

      /**
       * <p>
       * Retrieves the {@link simplicity::Light Light}s that can be used to illuminate this <code>Scene</code>.
       * </p>
       *
       * @return The <code>Light</code>s that can be used to illuminate this <code>Scene</code>.
       */
      virtual vector<Light *>
      getLights() const = 0;

      /**
       * <p>
       * Retrieves the {@link simplicity::SceneGraph SceneGraph} that describes the relative locations of this <code>Scene</code>'s
       * content.
       * </p>
       *
       * @return The <code>SceneGraph</code> that describes the relative locations of this <code>Scene</code>'s content.
       */
      virtual SceneGraph *
      getSceneGraph() const = 0;

      /**
       * <p>
       * Sets the {@link simplicity::Camera Camera}s that can be used to view this <code>Scene</code> from specific angles.
       * </p>
       *
       * @param cameras The <code>Camera</code>s that can be used to view this <code>Scene</code> from specific angles.
       */
      virtual void
      setCameras(vector<Camera *> const cameras) = 0;

      /**
       * <p>
       * Sets the {@link simplicity::Light Light}s that can be used to illuminate this <code>Scene</code>.
       * </p>
       *
       * @param lights The <code>Light</code>s that can be used to illuminate this <code>Scene</code>.
       */
      virtual void
      setLights(vector<Light *> const lights) = 0;

      /**
       * <p>
       * Sets the {@link simplicity::SceneGraph SceneGraph} that describes the relative locations of this <code>Scene</code>'s content.
       * </p>
       *
       * @param sceneGraph The <code>SceneGraph</code> that describes the relative locations of this <code>Scene</code>'s content.
       */
      virtual void
      setSceneGraph(SceneGraph * const sceneGraph) = 0;
  };
}

#endif /* SCENE_H_ */
