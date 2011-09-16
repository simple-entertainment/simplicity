/*
 This file is part of The Simplicity Engine.

 The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
 by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

 The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

 You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef OPENGLDEMORUNNER_H_
#define OPENGLDEMORUNNER_H_

#include <string>
#include <vector>

#include <simplicity/DemoRunner.h>

namespace simplicity
{
  class OpenGLDemoRunner
  {
    public:
      OpenGLDemoRunner(std::string title);

      virtual
      ~OpenGLDemoRunner();

      void
      addDemo(boost::shared_ptr<Demo> demo);

      void
      dispose();

      void
      init(int argc, char** argv);

      void
      keyboard(const unsigned char key, const int x, const int y);

      void
      motion(const int x, const int y);

      void
      mouse(const int button, const int state, const int x, const int y);

      void
      render();

      void
      run();

    private:
      bool cameraEnabled;

      unsigned int demoIndex;

      std::vector<boost::shared_ptr<Demo> > demos;

      int mouseX;

      int mouseY;

      std::string title;

      float textZ;

      void
      nextDemo();

      void
      previousDemo();

      void
      text(void* font, const std::string text, const float x, const float y);
  };
}

#endif /* OPENGLDEMORUNNER_H_ */
