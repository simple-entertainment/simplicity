/*
 This file is part of The Simplicity Engine.

 The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
 by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

 The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

 You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef SIMPLEPATHFINDERDEMO_H_
#define SIMPLEPATHFINDERDEMO_H_

#include <simplicity/ai/pathfinding/SimplePathFinder.h>

#include <simplicity/Demo.h>

#include <simplicity/opengl/rendering/engine/SimpleOpenGLRenderingEngine.h>

namespace simplicity
{
  /**
   * <p>
   * A small demonstration of the {@link simplicity::SimplePathFinder SimplePathFinder}.
   * </p>
   *
   * @author Gary Buyn
   */
  class SimplePathFinderDemo : public Demo
  {
    public:
      /**
       * <p>
       * Creates an instance of <code>SimplePathFinderDemo</code>.
       * </p>
       */
      SimplePathFinderDemo();

      /**
       * <p>
       * Disposes of an instance of <code>SimplePathFinderDemo</code>.
       * </p>
       */
      virtual
      ~SimplePathFinderDemo();

      void
      advance();

      void
      dispose();

      std::string
      getDescription();

      boost::shared_ptr<Node>
      getCameraRootNode();

      std::string
      getTitle();

      void
      init();

      void
      mouseClick(const int x, const int y);

    private:
      /**
       * <p>
       * The full path from which the shortest path is to be found.
       * </p>
       */
      vector<shared_ptr<Node> > fullPath;

      /**
       * <p>
       * The path finder for the demo.
       * </p>
       */
      boost::shared_ptr<PathFinder> pathFinder;

      /**
       * <p>
       * The rendering engine for the demo.
       * </p>
       */
      simplicity::opengl::SimpleOpenGLRenderingEngine renderingEngine;

      /**
       * <p>
       * Adds the background scene to the given node.
       * </p>
       *
       * @parentNode The node under which the background scene is to be added.
       */
      void
      addBackground(shared_ptr<Node> parentNode);

      /**
       * <p>
       * Adds the camera scene to the given node.
       * </p>
       *
       * @param parentNode The node under which the camera scene is to be added.
       *
       * @return The camera that has been added.
       */
      shared_ptr<Camera>
      addCamera(shared_ptr<Node> parentNode);

      /**
       * <p>
       * Adds the light scene to the given node.
       * </p>
       *
       * @param parentNode The node under which the light scene is to be added.
       *
       * @return The light that has been added.
       */
      shared_ptr<Light>
      addLight(shared_ptr<Node> parentNode);

      /**
       * <p>
       * Creates a light or dark grey square on the XZ plane with dimensions 1x1 centered on the origin.
       * </p>
       *
       * @param dark Determines whether a light or dark square should be created.
       *
       * @return A node containing the light or dark grey square.
       */
      boost::shared_ptr<Node>
      createGreySquareOnXZPlane(const bool dark);

      /**
       * <p>
       * Creates obstacle entities and removes the location of these obstacles from the full path.
       * </p>
       *
       * @return The obstacle entities.
       */
      std::vector<boost::shared_ptr<Entity> >
      createObstacles();

      /**
       * <p>
       * Creates a square on the XZ plane with dimensions 1x1 centered on the origin.
       * </p>
       *
       * @param colour The colour of the square.
       *
       * @return A node containing the square.
       */
      boost::shared_ptr<Node>
      createSquareOnXZPlane(const RGBAColourVector<float>& colour);

      /**
       * <p>
       * Populates the full path.
       * </p>
       */
      void
      populateFullPath();
  };
}

#endif /* SIMPLEPATHFINDERDEMO_H_ */
