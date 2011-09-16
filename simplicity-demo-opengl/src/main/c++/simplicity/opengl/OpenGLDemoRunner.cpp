/*
 This file is part of The Simplicity Engine.

 The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
 by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

 The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

 You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
#include <GL/glew.h>
#include <GL/glut.h>

#include <boost/function.hpp>
#include <boost/math/constants/constants.hpp>

#include <simplicity/vector/SimpleTranslationVector4.h>

#include "OpenGLDemoRunner.h"

using namespace std;
using namespace boost::math::constants;

namespace simplicity
{
  OpenGLDemoRunner* runner;

  void
  keyboard(const unsigned char key, const int x, const int y)
  {
    runner->keyboard(key, x, y);
  }

  void
  motion(const int x, const int y)
  {
    runner->motion(x, y);
  }

  void
  mouse(const int button, const int state, const int x, const int y)
  {
    runner->mouse(button, state, x, y);
  }

  void
  render()
  {
    runner->render();
  }

  void
  initStandalone(OpenGLDemoRunner* runner)
  {
    simplicity::runner = runner;

    glutDisplayFunc(render);
    glutIdleFunc(render);
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
    glutMotionFunc(motion);
  }

  OpenGLDemoRunner::OpenGLDemoRunner(string title) :
      cameraEnabled(false), demoIndex(0), mouseX(0), mouseY(0), title(title)
  {
  }

  OpenGLDemoRunner::~OpenGLDemoRunner()
  {
  }

  void
  OpenGLDemoRunner::addDemo(boost::shared_ptr<Demo> demo)
  {
    demos.push_back(demo);
  }

  void
  OpenGLDemoRunner::dispose()
  {
    demos.at(demoIndex - 1)->dispose();
  }

  void
  OpenGLDemoRunner::init(int argc, char **argv)
  {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Where's my title???");

    initStandalone(this);

    nextDemo();
  }

  /**
   * Processes keyboard events.
   */
  void
  OpenGLDemoRunner::keyboard(const unsigned char key, const int x, const int y)
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
  OpenGLDemoRunner::motion(const int x, const int y)
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
  OpenGLDemoRunner::mouse(const int button, const int state, const int x, const int y)
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
   * Moves forward to the next scene.
   */
  void
  OpenGLDemoRunner::nextDemo()
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
  OpenGLDemoRunner::previousDemo()
  {
    if (demoIndex > 1)
    {
      demos.at(demoIndex - 1)->dispose();
      demoIndex--;
      demos.at(demoIndex - 1)->init();
    }
  }

  /**
   * The render method called during each iteration of the main loop.
   */
  void
  OpenGLDemoRunner::render()
  {
    demos.at(demoIndex - 1)->advance();

    text(GLUT_BITMAP_HELVETICA_18, demos.at(demoIndex - 1)->getTitle(), -0.5f, 0.35f);
    text(GLUT_BITMAP_HELVETICA_12, demos.at(demoIndex - 1)->getDescription(), -0.5f, 0.325f);
    text(GLUT_BITMAP_HELVETICA_18, "<< Previous [backspace]", -0.5f, -0.36f);
    text(GLUT_BITMAP_HELVETICA_18, "[space] Next >>", 0.34f, -0.36f);

    glutSwapBuffers();
  }

  void
  OpenGLDemoRunner::run()
  {
    glutMainLoop();
  }

  /**
   * Renders text.
   */
  void
  OpenGLDemoRunner::text(void* font, const string text, const float x, const float y)
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
}
