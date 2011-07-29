/*
 This file is part of The Simplicity Engine.

 The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
 by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

 The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

 You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef GLUCYLINDER_H_
#define GLUCYLINDER_H_

#include <simplicity/model/shape/Cylinder.h>

#include "GLUShape.h"

namespace simplicity
{
  namespace opengl
  {
    /**
     * <p>
     * A {@link simplicity::Cylinder Cylinder} implemented by the OpenGL Utilities.
     * </p>
     *
     * @author Gary Buyn
     */
    class GLUCylinder : public GLUShape, public Cylinder
    {
      public:
        /**
         * <p>
         * Creates an instance of <code>GLUCylinder</code>.
         * </p>
         */
        GLUCylinder();

        /**
         * <p>
         * Disposes of an instance of <code>GLUCylinder</code>.
         * </p>
         */
        virtual
        ~GLUCylinder();

        int
        getSlices() const;

        int
        getStacks() const;

        void
        setSlices(const int slices);

        void
        setStacks(const int stacks);

      private:
        /**
         * <p>
         * The default number of slices this <code>GLUCylinder</code> is comprised of.
         * </p>
         */
        static const int DEFALUT_SLICES = 10;

        /**
         * <p>
         * The default number of stacks this <code>GLUCylinder</code> is comprised of.
         * </p>
         */
        static const int DEFALUT_STACKS = 1;

        /**
         * <p>
         * The number of slices this <code>GLUCylinder</code> is comprised of.
         * </p>
         */
        int fSlices;

        /**
         * <p>
         * The number of stacks this <code>GLUCylinder</code> is comprised of.
         * </p>
         */
        int fStacks;
    };
  }
}

#endif /* GLUCYLINDER_H_ */
