/*
 This file is part of The Simplicity Engine.

 The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
 by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

 The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

 You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
#include "SimpleScene.h"

namespace simplicity
{
  SimpleScene::SimpleScene() :
    fCameras(vector<Camera *> ()), fLights(vector<Light *> ()), fSceneGraph(0)
  {
  }

  SimpleScene::~SimpleScene()
  {
    delete fSceneGraph;
  }

  void
  SimpleScene::addCamera(Camera * const camera)
  {
    fCameras.push_back(camera);
  }

  void
  SimpleScene::addLight(Light * const light)
  {
    fLights.push_back(light);
  }

  vector<Camera *>
  SimpleScene::getCameras() const
  {
    return (fCameras);
  }

  vector<Light *>
  SimpleScene::getLights() const
  {
    return (fLights);
  }

  SceneGraph *
  SimpleScene::getSceneGraph() const
  {
    return (fSceneGraph);
  }

  void
  SimpleScene::setCameras(vector<Camera *> const cameras)
  {
    fCameras = cameras;
  }

  void
  SimpleScene::setLights(vector<Light *> const lights)
  {
    fLights = lights;
  }

  void
  SimpleScene::setSceneGraph(SceneGraph * const sceneGraph)
  {
    delete fSceneGraph;

    fSceneGraph = sceneGraph;
  }
}
