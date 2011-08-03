/*
 This file is part of The Simplicity Engine.

 The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
 by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

 The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

 You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
#include <boost/math/constants/constants.hpp>
#include <boost/smart_ptr.hpp>

#include <GL/glew.h>
#include <GL/glut.h>

#include <simplicity/scene/SimpleScene.h>
#include <simplicity/scenegraph/SimpleSceneGraph.h>
#include <simplicity/scenegraph/model/SimpleModelNode.h>
#include <simplicity/vector/SimpleRGBAColourVector4.h>
#include <simplicity/vector/SimpleTranslationVector4.h>

#include <simplicity/opengl/model/shape/GLUCapsule.h>
#include <simplicity/opengl/model/shape/GLUCylinder.h>
#include <simplicity/opengl/model/shape/GLUSphere.h>
#include <simplicity/opengl/model/shape/GLUTorus.h>
#include <simplicity/opengl/rendering/engine/SimpleOpenGLRenderingEngine.h>
#include <simplicity/opengl/rendering/SimpleOpenGLCamera.h>
#include <simplicity/opengl/rendering/SimpleOpenGLLight.h>
#include <simplicity/opengl/rendering/SimpleOpenGLRenderer.h>

using namespace boost;
using namespace boost::math::constants;
using namespace simplicity;
using namespace simplicity::opengl;
using namespace std;

shared_ptr<SimpleOpenGLRenderer> renderer(new SimpleOpenGLRenderer());
SimpleOpenGLRenderingEngine renderingEngine;
shared_ptr<SimpleNode> cameraRootNode(new SimpleNode);

bool cameraEnabled = false;
int mouseX, mouseY = 0;

void
init()
{
  shared_ptr<SimpleSceneGraph> sceneGraph(new SimpleSceneGraph);
  shared_ptr<SimpleScene> scene(new SimpleScene);
  scene->setSceneGraph(sceneGraph);
  renderingEngine.setScene(scene);
  renderingEngine.addRenderer(renderer);

  shared_ptr<SimpleOpenGLCamera> camera(new SimpleOpenGLCamera);
  shared_ptr<SimpleNode> cameraNode(new SimpleNode);
  cameraNode->getTransformation().translate(SimpleTranslationVector4<float> (0.0f, 0.0f, -15.0f, 1.0f));
  cameraNode->getTransformation().rotate(pi<float> (), SimpleTranslationVector4<float> (0.0f, 1.0f, 0.0f, 1.0f));
  camera->setNode(cameraNode);
  cameraRootNode->getTransformation().rotate(pi<float> () / 8.0f, SimpleTranslationVector4<float> (-0.5f, -0.5f, 0.0f, 1.0f));
  cameraRootNode->addChild(cameraNode);
  sceneGraph->addSubgraph(cameraRootNode);
  scene->addCamera(camera);
  renderingEngine.setCamera(camera);

  shared_ptr<SimpleOpenGLLight> light(new SimpleOpenGLLight);
  light->setAmbientLight(
      shared_ptr<SimpleRGBAColourVector4<float> > (new SimpleRGBAColourVector4<float> (0.25f, 0.25f, 0.25f, 1.0f)));
  light->setDiffuseLight(
      shared_ptr<SimpleRGBAColourVector4<float> > (new SimpleRGBAColourVector4<float> (0.25f, 0.25f, 0.25f, 1.0f)));
  light->setSpecularLight(
      shared_ptr<SimpleRGBAColourVector4<float> > (new SimpleRGBAColourVector4<float> (0.1f, 0.1f, 0.1f, 1.0f)));
  shared_ptr<SimpleNode> lightNode(new SimpleNode);
  lightNode->getTransformation().translate(SimpleTranslationVector4<float> (0.0f, 0.0f, 15.0f, 1.0f));
  light->setNode(lightNode);
  sceneGraph->addSubgraph(lightNode);
  scene->addLight(light);

  shared_ptr<SimpleModelNode> capsuleNode(new SimpleModelNode);
  capsuleNode->getTransformation().translate(SimpleTranslationVector4<float> (-3.0f, 3.0f, 0.0f, 1.0f));
  shared_ptr<GLUCapsule> capsule(new GLUCapsule);
  capsule->setColour(shared_ptr<SimpleRGBAColourVector4<float> > (new SimpleRGBAColourVector4<float> (0.75f, 0.0f, 0.0f, 1.0f)));
  capsuleNode->setModel(capsule);
  sceneGraph->addSubgraph(capsuleNode);
  shared_ptr<SimpleModelNode> cylinderNode(new SimpleModelNode);
  cylinderNode->getTransformation().translate(SimpleTranslationVector4<float> (0.0f, 3.0f, 0.0f, 1.0f));
  shared_ptr<GLUCylinder> cylinder(new GLUCylinder);
  cylinder->setColour(shared_ptr<SimpleRGBAColourVector4<float> > (new SimpleRGBAColourVector4<float> (0.0f, 0.75f, 0.0f, 1.0f)));
  cylinderNode->setModel(cylinder);
  sceneGraph->addSubgraph(cylinderNode);
  shared_ptr<SimpleModelNode> sphereNode(new SimpleModelNode);
  sphereNode->getTransformation().translate(SimpleTranslationVector4<float> (3.0f, 3.0f, 0.0f, 1.0f));
  shared_ptr<GLUSphere> sphere(new GLUSphere);
  sphere->setColour(shared_ptr<SimpleRGBAColourVector4<float> > (new SimpleRGBAColourVector4<float> (0.0f, 0.0f, 0.75f, 1.0f)));
  sphereNode->setModel(sphere);
  sceneGraph->addSubgraph(sphereNode);
  shared_ptr<SimpleModelNode> torusNode(new SimpleModelNode);
  torusNode->getTransformation().translate(SimpleTranslationVector4<float> (0.0f, -2.0f, 0.0f, 1.0f));
  torusNode->setModel(shared_ptr<GLUTorus> (new GLUTorus));
  sceneGraph->addSubgraph(torusNode);
}

void
mouse(const int button, const int state, const int x, const int y)
{
  if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
  {
    cameraEnabled = true;
    mouseX = x;
    mouseY = y;
  }
}

void
motion(const int x, const int y)
{
  float angleX = (mouseX - x) / 10.0f;
  float angleY = (y - mouseY) / 10.0f;
  mouseX = x;
  mouseY = y;

  cameraRootNode->getTransformation().rotate(angleX / pi<float> (), SimpleTranslationVector4<float> (0.0f, 1.0f, 0.0f, 1.0f));
  cameraRootNode->getTransformation().rotate(angleY / pi<float> (), SimpleTranslationVector4<float> (1.0f, 0.0f, 0.0f, 1.0f));
}

void
render()
{
  renderingEngine.advance(NULL);

  glutSwapBuffers();
}

int
main(int argc, char** argv)
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
  glutInitWindowSize(800, 600);
  glutCreateWindow("Simplicity OpenGL Demo");

  glutDisplayFunc(render);
  glutIdleFunc(render);
  glutMouseFunc(mouse);
  glutMotionFunc(motion);

  init();
  renderingEngine.init();
  glutMainLoop();
  renderingEngine.destroy();

  return (0);
}
