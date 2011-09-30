/*
 This file is part of The Simplicity Engine.

 The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
 by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

 The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

 You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef GLUSHAPE_H_
#define GLUSHAPE_H_

#include <simplicity/model/shape/Shape.h>

namespace simplicity
{
  namespace opengl
  {
    /**
     * <p>
     * A {@link simplicity::Shape Shape} implemented by the OpenGL Utilities.
     * </p>
     *
     * @author Gary Buyn
     */
    class GLUShape : public virtual Shape
    {
      public:
        /**
         * <p>
         * Retrieves the number of slices this <code>GLUShape</code> is comprised of. For information on how the slices effect the rendering of the
         * <code>GLUShape</code>, see the specification documentation for OpenGL Utility functions that render shapes e.g. <code>gluSphere</code>,
         * <code>gluCylinder</code> etc.
         * </p>
         *
         * @return The number of slices this <code>GLUShape</code> is comprised of.
         */
        virtual int
        getSlices() const = 0;

        /**
         * <p>
         * Retrieves the number of stacks this <code>GLUShape</code> is comprised of. For information on how the stacks effect the rendering of the
         * <code>GLUShape</code>, see the specification documentation for OpenGL Utility functions that render shapes e.g. <code>gluSphere</code>,
         * <code>gluCylinder</code> etc.
         * </p>
         *
         * @return The number of stacks this <code>GLUShape</code> is comprised of.
         */
        virtual int
        getStacks() const = 0;

        /**
         * <p>
         * Retrieves the number of slices this <code>GLUShape</code> is comprised of. For information on how the slices effect the rendering of the
         * <code>GLUShape</code>, see the specification documentation for OpenGL Utility functions that render shapes e.g. <code>gluSphere</code>,
         * <code>gluCylinder</code> etc.
         * </p>
         *
         * @param slices The number of slices this <code>GLUShape</code> is comprised of.
         */
        virtual void
        setSlices(int slices) = 0;

        /**
         * <p>
         * Retrieves the number of stacks this <code>GLUShape</code> is comprised of. For information on how the stacks effect the rendering of the
         * <code>GLUShape</code>, see the specification documentation for OpenGL Utility functions that render shapes e.g. <code>gluSphere</code>,
         * <code>gluCylinder</code> etc.
         * </p>
         *
         * @param stacks The number of stacks this <code>GLUShape</code> is comprised of.
         */
        virtual void
        setStacks(int stacks) = 0;
    };
  }
}

#endif /* GLUSHAPE_H_ */
