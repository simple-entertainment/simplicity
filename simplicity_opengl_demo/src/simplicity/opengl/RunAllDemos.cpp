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

#include <simplicity/vector/SimpleTranslationVector4.h>

#include "picking/SimpleOpenGLPickerDemo.h"
#include "rendering/AlwaysAndNotEqualStencilOpenGLRenderersDemo.h"
#include "rendering/BlendingOpenGLRendererDemo.h"
#include "rendering/CullFaceOpenGLRendererDemo.h"
#include "rendering/DepthClearingOpenGLRendererDemo.h"
#include "rendering/MonoColourOpenGLRendererDemo.h"
#include "rendering/OutlineOpenGLRendererDemo.h"
#include "rendering/SimpleOpenGLRendererDemo.h"
#include "rendering/StencilClearingOpenGLRendererDemo.h"

using namespace boost;
using namespace boost::math::constants;
using namespace simplicity;
using namespace simplicity::opengl;
using namespace std;

vector<shared_ptr<Demo> > demos;
unsigned int demoIndex = 0;

bool cameraEnabled = false;
int mouseX, mouseY = 0;
float textZ;

/**
 * Renders text.
 */
void
text(void* font, const string text, const float x, const float y)
{
  float currentY = y;

  glDisable(GL_LIGHTING);
  glColor3f(0.05f, 0.05f, 0.05f);
  glRasterPos3f(x, currentY, -1.0f);
  for (unsigned int index = 0; index < text.length(); index++)
  {
    if (text.at(index) == '\n')
    {
      currentY -= 0.025f;
      glRasterPos3f(x, currentY, -1.0f);
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
  demos.push_back(shared_ptr < SimpleOpenGLRendererDemo > (new SimpleOpenGLRendererDemo));
  demos.push_back(shared_ptr < MonoColourOpenGLRendererDemo > (new MonoColourOpenGLRendererDemo));
  demos.push_back(shared_ptr < CullFaceOpenGLRendererDemo > (new CullFaceOpenGLRendererDemo));
  demos.push_back(shared_ptr < BlendingOpenGLRendererDemo > (new BlendingOpenGLRendererDemo));
  demos.push_back(shared_ptr < AlwaysAndNotEqualStencilOpenGLRenderersDemo > (new AlwaysAndNotEqualStencilOpenGLRenderersDemo));
  demos.push_back(shared_ptr < StencilClearingOpenGLRendererDemo > (new StencilClearingOpenGLRendererDemo));
  demos.push_back(shared_ptr < DepthClearingOpenGLRendererDemo > (new DepthClearingOpenGLRendererDemo));
  demos.push_back(shared_ptr < OutlineOpenGLRendererDemo > (new OutlineOpenGLRendererDemo));
  demos.push_back(shared_ptr < SimpleOpenGLPickerDemo > (new SimpleOpenGLPickerDemo));
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
      demos.at(demoIndex - 1)->dispose();
    }

    demos.at(demoIndex)->init();

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
    demos.at(demoIndex - 1)->dispose();
    demoIndex--;
    demos.at(demoIndex - 1)->init();
  }
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
  else if (key == 8) // backspace
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

  demos.at(demoIndex - 1)->getCameraRootNode()->getTransformation().rotate(angleX / pi<float>(),
      SimpleTranslationVector4<float>(0.0f, 1.0f, 0.0f, 1.0f));
  demos.at(demoIndex - 1)->getCameraRootNode()->getTransformation().rotate(angleY / pi<float>(),
      SimpleTranslationVector4<float>(1.0f, 0.0f, 0.0f, 1.0f));
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
  else if (button == GLUT_RIGHT_BUTTON && state == GLUT_UP)
  {
    demos.at(demoIndex - 1)->mouseClick(x, y);
  }
}

/**
 * The render method called during each iteration of the main loop.
 */
void
render()
{
  demos.at(demoIndex - 1)->advance();

  text(GLUT_BITMAP_HELVETICA_18, demos.at(demoIndex - 1)->getTitle(), -0.5f, 0.35f);
  text(GLUT_BITMAP_HELVETICA_12, demos.at(demoIndex - 1)->getDescription(), -0.5f, 0.325f);
  text(GLUT_BITMAP_HELVETICA_18, "<< Previous [backspace]", -0.5f, -0.36f);
  text(GLUT_BITMAP_HELVETICA_18, "[space] Next >>", 0.34f, -0.36f);

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

  initDemos();
  nextDemo();
  glutMainLoop();

  return (0);
}
