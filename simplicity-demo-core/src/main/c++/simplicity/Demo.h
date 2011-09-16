/*
 This file is part of The Simplicity Engine.

 The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
 by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

 The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

 You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef DEMO_H_
#define DEMO_H_

#include <simplicity/scenegraph/Node.h>

namespace simplicity
{
  /**
   * <p>
   * A small demonstration of a function.
   * </p>
   */
  class Demo
  {
    public:
      /**
       * <p>
       * Disposes of an instance of <code>Demo</code> (included to allow polymorphic deletion).
       * </p>
       */
      virtual
      ~Demo()
      {
      }

      /**
       * <p>
       * Advances the demo by one frame.
       * </p>
       */
      virtual void
      advance() = 0;

      /**
       * <p>
       * Reverts the state of the demo environment.
       * </p>
       */
      virtual void
      dispose() = 0;

      /**
       * <p>
       * Retrieves a description of the demo.
       * </p>
       *
       * @return A description of the demo.
       */
      virtual std::string
      getDescription() = 0;

      /**
       * <p>
       * Retrieves the root node of the camera's subgraph.
       * </p>
       *
       * @return The root node of the camera's subgraph.
       */
      virtual boost::shared_ptr<Node>
      getCameraRootNode() = 0;

      /**
       * <p>
       * Retrieves the title of the demo.
       * </p>
       *
       * @return The title of the demo.
       */
      virtual std::string
      getTitle() = 0;

      /**
       * <p>
       * Initialises the state of the demo environment for this demo.
       * </p>
       */
      virtual void
      init() = 0;

      /**
       * <p>
       * Callback used to respond to mouse click events.
       * </p>
       *
       * @param x The x axis of the location in the demo window that was clicked.
       * @param y The y axis of the location in the demo window that was clicked.
       */
      virtual void
      mouseClick(const int x, const int y) = 0;
  };
}

#endif /* DEMO_H_ */
