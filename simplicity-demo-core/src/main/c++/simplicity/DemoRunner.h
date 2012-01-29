/*
 This file is part of The Simplicity Engine.

 The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
 by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

 The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

 You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef DEMORUNNER_H_
#define DEMORUNNER_H_

#include "Demo.h"

namespace simplicity
{
  /**
   * <p>
   * Provides an environment in which {@link simplicity::Demo Demo}s can be run.
   * </p>
   */
  class DemoRunner
  {
    public:
      /**
       * <p>
       * Disposes of an instance of <code>DemoRunner</code> (included to allow polymorphic deletion).
       * </p>
       */
      virtual
      ~DemoRunner()
      {
      }

      /**
       * <p>
       * Adds a {@link simplicity::Demo Demo} to the list of <code>Demo</code>s to be run.
       * </p>
       *
       * @param demo The <code>Demo</code> to be added to the list of <code>Demo</code>s to be run.
       */
      virtual void
      addDemo(std::shared_ptr<Demo> demo) = 0;

      /**
       * <p>
       * Disposes of this <code>DemoRunner</code>.
       * </p>
       */
      virtual void
      dispose() = 0;

      /**
       * <p>
       * Initialises this <code>DemoRunner</code>.
       * </p>
       *
       * @param argc Program arguments.
       * @param argv Program arguments.
       */
      virtual void
      init(int argc, char** argv) = 0;

      /**
       * <p>
       * Runs the {@link simplicity::Demo Demo}s.
       * </p>
       */
      virtual void
      run() = 0;
  };
}

#endif /* DEMORUNNER_H_ */
