/*
 This file is part of The Simplicity Engine.

 The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
 by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

 The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

 You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef OPENGLDEMO_H_
#define OPENGLDEMO_H_

#include <simplicity/rendering/Camera.h>
#include <simplicity/rendering/Light.h>
#include <simplicity/scenegraph/SceneGraph.h>

#include <simplicity/Demo.h>

namespace simplicity
{
  namespace opengl
  {
    /**
     * <p>
     * Provides common elements required by OpenGL demos.
     * </p>
     */
    class OpenGLDemo : public Demo
    {
      public:
        virtual void
        mouseClick(const int x, const int y);

      protected:
        /**
         * <p>
         * Creates a standard OpenGL camera in the standard location for use with demos.
         * </p>
         *
         * @param parentNode The node under which the camera should be added.
         *
         * @return The standard camera.
         */
        boost::shared_ptr<Camera>
        addStandardCamera(boost::shared_ptr<Node> parentNode);

        /**
         * <p>
         * Creates a standard OpenGL capsule in the standard location for use with demos.
         * </p>
         *
         * @param parentNode The node under which the capsule should be added.
         */
        void
        addStandardCapsule(boost::shared_ptr<Node> parentNode);

        /**
         * <p>
         * Creates a standard OpenGL cylinder in the standard location for use with demos.
         * </p>
         *
         * @param parentNode The node under which the cylinder should be added.
         */
        void
        addStandardCylinder(boost::shared_ptr<Node> parentNode);

        /**
         * <p>
         * Creates a standard OpenGL light in the standard location for use with demos.
         * </p>
         *
         * @param parentNode The node under which the light should be added.
         *
         * @return The standard light.
         */
        boost::shared_ptr<Light>
        addStandardLight(boost::shared_ptr<Node> parentNode);

        /**
         * <p>
         * Creates a standard OpenGL sphere in the standard location for use with demos.
         * </p>
         *
         * @param parentNode The node under which the sphere should be added.
         */
        void
        addStandardSphere(boost::shared_ptr<Node> parentNode);

        /**
         * <p>
         * Creates a standard OpenGL torus in the standard location for use with demos.
         * </p>
         *
         * @param parentNode The node under which the torus should be added.
         */
        void
        addStandardTorus(boost::shared_ptr<Node> parentNode);
    };
  }
}

#endif /* OPENGLDEMO_H_ */
