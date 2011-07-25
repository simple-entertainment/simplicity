/*
 This file is part of The Simplicity Engine.

 The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
 by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

 The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

 You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
#include "SimpleScene.h"

using namespace boost;
using namespace std;

namespace simplicity
{
  SimpleScene::SimpleScene()
  {
  }

  SimpleScene::~SimpleScene()
  {
  }

  void
  SimpleScene::addCamera(shared_ptr<Camera> camera)
  {
    fCameras.push_back(camera);
  }

  void
  SimpleScene::addLight(shared_ptr<Light> light)
  {
    fLights.push_back(light);
  }

  vector<shared_ptr<Camera> >
  SimpleScene::getCameras() const
  {
    return (fCameras);
  }

  vector<shared_ptr<Light> >
  SimpleScene::getLights() const
  {
    return (fLights);
  }

  shared_ptr<SceneGraph>
  SimpleScene::getSceneGraph() const
  {
    return (fSceneGraph);
  }

  void
  SimpleScene::setCameras(vector<shared_ptr<Camera> > cameras)
  {
    fCameras = cameras;
  }

  void
  SimpleScene::setLights(vector<shared_ptr<Light> > lights)
  {
    fLights = lights;
  }

  void
  SimpleScene::setSceneGraph(shared_ptr<SceneGraph> sceneGraph)
  {
    fSceneGraph = sceneGraph;
  }
}
