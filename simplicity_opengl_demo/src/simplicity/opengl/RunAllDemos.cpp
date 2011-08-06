/*
 This file is part of The Simplicity Engine.

 The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
 by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

 The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

 You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
#include <boost/math/constants/constants.hpp>

#include <GL/glew.h>
#include <GL/glut.h>

#include <simplicity/scene/SimpleScene.h>
#include <simplicity/scenegraph/SimpleNode.h>
#include <simplicity/scenegraph/SimpleSceneGraph.h>
#include <simplicity/vector/SimpleRGBAColourVector4.h>
#include <simplicity/vector/SimpleTranslationVector4.h>

#include <simplicity/opengl/rendering/engine/SimpleOpenGLRenderingEngine.h>
#include <simplicity/opengl/rendering/SimpleOpenGLCamera.h>
#include <simplicity/opengl/rendering/SimpleOpenGLLight.h>

#include "rendering/BlendingOpenGLRendererDemo.h"
#include "rendering/CullFaceOpenGLRendererDemo.h"
#include "rendering/MonoColourOpenGLRendererDemo.h"
#include "rendering/SimpleOpenGLRendererDemo.h"

using namespace boost;
using namespace boost::math::constants;
using namespace simplicity;
using namespace simplicity::opengl;
using namespace std;

vector<shared_ptr<Demo> > demos;
unsigned int demoIndex = 0;

SimpleOpenGLRenderingEngine renderingEngine;
shared_ptr<SimpleNode> cameraRootNode(new SimpleNode);

bool cameraEnabled = false;
int mouseX, mouseY = 0;
float textZ;

/**
 * Renders text.
 */
void
text(void* font, const string text, const float x, const float y)
{
  glDisable(GL_LIGHTING);
  glColor3f(0.05f, 0.05f, 0.05f);
  glRasterPos3f(x, y, -1.0f);
  for (unsigned int index = 0; index < text.length(); index++)
  {
    if (text.at(index) == '\n')
    {
      glRasterPos3f(x, y - 0.025f, -1.0f);
    }
    else
    {
      glutBitmapCharacter(font, text.at(index));
    }
  }
  glEnable(GL_LIGHTING);
}

/**
 * Initialises the set of demos.
 */
void
initDemos()
{
  demos.push_back(shared_ptr<SimpleOpenGLRendererDemo> (new SimpleOpenGLRendererDemo));
  demos.push_back(shared_ptr<MonoColourOpenGLRendererDemo> (new MonoColourOpenGLRendererDemo));
  demos.push_back(shared_ptr<CullFaceOpenGLRendererDemo> (new CullFaceOpenGLRendererDemo));
  demos.push_back(shared_ptr<BlendingOpenGLRendererDemo> (new BlendingOpenGLRendererDemo));
}

/**
 * Moves forward to the next scene.
 */
void
nextDemo()
{
  if (demoIndex < demos.size())
  {
    if (demoIndex > 0)
    {
      demos.at(demoIndex - 1)->dispose(renderingEngine);
    }

    demos.at(demoIndex)->init(renderingEngine);

    demoIndex++;
  }
}

/**
 * Moves back to the previous scene.
 */
void
previousDemo()
{
  if (demoIndex > 1)
  {
    demos.at(demoIndex - 1)->dispose(renderingEngine);
    demoIndex--;
    demos.at(demoIndex - 1)->init(renderingEngine);
  }
}

/**
 * Creates the demo scene.
 */
void
initScene()
{
  renderingEngine.setClearingColour(
      shared_ptr<SimpleRGBAColourVector4<float> > (new SimpleRGBAColourVector4<float> (0.95f, 0.95f, 0.95f, 1.0f)));

  shared_ptr<SimpleSceneGraph> sceneGraph(new SimpleSceneGraph);
  shared_ptr<SimpleScene> scene(new SimpleScene);
  scene->setSceneGraph(sceneGraph);
  renderingEngine.setScene(scene);

  shared_ptr<SimpleOpenGLCamera> camera(new SimpleOpenGLCamera);
  shared_ptr<SimpleNode> cameraNode(new SimpleNode);
  cameraNode->getTransformation().translate(SimpleTranslationVector4<float> (0.0f, 0.0f, -20.0f, 1.0f));
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
  lightNode->getTransformation().translate(SimpleTranslationVector4<float> (0.0f, 0.0f, 20.0f, 1.0f));
  light->setNode(lightNode);
  sceneGraph->addSubgraph(lightNode);
  scene->addLight(light);
}

/**
 * Processes keyboard events.
 */
void
keyboard(const unsigned char key, const int x, const int y)
{
  if (key == ' ')
  {
    nextDemo();
  }
  else if ('b')
  {
    previousDemo();
  }
}

/**
 * Processes mouse motion events.
 */
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

/**
 * Processes mouse button events.
 */
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

/**
 * The render method called during each iteration of the main loop.
 */
void
render()
{
  renderingEngine.advance(NULL);

  text(GLUT_BITMAP_HELVETICA_18, demos.at(demoIndex - 1)->getTitle(), -0.5f, 0.35f);
  text(GLUT_BITMAP_HELVETICA_18, demos.at(demoIndex - 1)->getDescription(), -0.5f, 0.325f);

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
  glutKeyboardFunc(keyboard);
  glutMouseFunc(mouse);
  glutMotionFunc(motion);

  initScene();
  initDemos();
  nextDemo();
  renderingEngine.init();
  glutMainLoop();
  renderingEngine.destroy();

  return (0);
}
