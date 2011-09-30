/*
 This file is part of The Simplicity Engine.

 The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
 by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

 The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

 You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef GLUSPHERE_H_
#define GLUSPHERE_H_

#include <simplicity/model/shape/Sphere.h>

#include "GLUShape.h"

namespace simplicity
{
  namespace opengl
  {
    /**
     * <p>
     * A {@link simplicity::Sphere Sphere} implemented by the OpenGL Utilities.
     * </p>
     *
     * @author Gary Buyn
     */
    class GLUSphere : public GLUShape, public Sphere
    {
      public:
        /**
         * <p>
         * Creates an instance of <code>GLUSphere</code>.
         * </p>
         */
        GLUSphere();

        /**
         * <p>
         * Disposes of an instance of <code>GLUSphere</code>.
         * </p>
         */
        virtual
        ~GLUSphere();

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
         * The default number of slices this <code>GLUSphere</code> is comprised of.
         * </p>
         */
        static const int DEFALUT_SLICES = 10;

        /**
         * <p>
         * The default number of stacks this <code>GLUSphere</code> is comprised of.
         * </p>
         */
        static const int DEFALUT_STACKS = 10;

        /**
         * <p>
         * The number of slices this <code>GLUSphere</code> is comprised of.
         * </p>
         */
        int fSlices;

        /**
         * <p>
         * The number of stacks this <code>GLUSphere</code> is comprised of.
         * </p>
         */
        int fStacks;
    };
  }
}

#endif /* GLUSPHERE_H_ */
