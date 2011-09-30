/*
 This file is part of The Simplicity Engine.

 The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
 by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

 The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

 You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef GLUCAPSULE_H_
#define GLUCAPSULE_H_

#include <simplicity/model/shape/Capsule.h>

#include "GLUShape.h"

namespace simplicity
{
  namespace opengl
  {
    /**
     * <p>
     * A {@link simplicity::Capsule Capsule} implemented by the OpenGL Utilities.
     * </p>
     *
     * @author Gary Buyn
     */
    class GLUCapsule : public GLUShape, public Capsule
    {
      public:
        /**
         * <p>
         * Creates an instance of <code>GLUCapsule</code>.
         * </p>
         */
        GLUCapsule();

        /**
         * <p>
         * Disposes of an instance of <code>GLUCapsule</code>.
         * </p>
         */
        virtual
        ~GLUCapsule();

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
         * The default number of slices this <code>GLUCapsule</code> is comprised of.
         * </p>
         */
        static const int DEFALUT_SLICES = 10;

        /**
         * <p>
         * The default number of stacks this <code>GLUCapsule</code> is comprised of.
         * </p>
         */
        static const int DEFALUT_STACKS = 1;

        /**
         * <p>
         * The number of slices this <code>GLUCapsule</code> is comprised of.
         * </p>
         */
        int fSlices;

        /**
         * <p>
         * The number of stacks this <code>GLUCapsule</code> is comprised of.
         * </p>
         */
        int fStacks;
    };
  }
}

#endif /* GLUCAPSULE_H_ */
