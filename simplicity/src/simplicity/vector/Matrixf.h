/*
 This file is part of The Simplicity Engine.

 The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
 by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

 The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

 You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef MATRIXF_H_
#define MATRIXF_H_

#include "../SEInvalidOperationException.h"

namespace simplicity
{
    /**
     * <p>
     * A matrix that stores its data in a <code>float</code> array.
     * </p>
     *
     * @author Gary Buyn
     */
    class Matrixf
    {
        public:
            /**
             * <p>
             * Disposes of an instance of <code>Matrixf</code> (included to allow polymorphic deletion).
             * </p>
             */
            virtual
            ~Matrixf()
            {
            }

            /**
             * <p>
             * Retrieves the determinant of this <code>Matrixf</code>.
             * </p>
             *
             * @return The determinant of this <code>Matrixf</code>.
             */
            virtual float
            getDeterminant() = 0;

            /**
             * <p>
             * Attempts to set this <code>Matrixf</code> to the inverse of this <code>Matrixf</code>.
             * </p>
             *
             * @throw SEInvalidOperationException If this <code>SimpleMatrixf44</code> has a determinant of 0.
             */
            virtual void
            invert() throw (SEInvalidOperationException) = 0;

            /**
             * <p>
             * Multiplies this <code>Matrixf</code> with the <code>Matrixf</code> given. The <code>Matrixf</code> given is placed on the left hand side of the
             * equation.
             * </p>
             *
             * <p>
             * This <code>Matrixf</code> becomes the result of the multiplication.
             * </p>
             *
             * @param leftMatrix The <code>Matrixf</code> to be placed on the left hand side of the multiplication with this <code>Matrixf</code>.
             */
            virtual void
            multiplyLeft(Matrixf* const leftMatrix) = 0;

            /**
             * <p>
             * Multiplies this <code>Matrixf</code> with the <code>Matrixf</code> given. The <code>Matrixf</code> given is placed on the left hand side of the
             * equation.
             * </p>
             *
             * <p>
             * A new <code>Matrixf</code> is created as the result of the multiplication.
             * </p>
             *
             * <p>
             * The caller must assume ownership of the returned <code>Matrixf</code>.
             * </p>
             *
             * @param leftMatrix The <code>Matrixf</code> to be placed on the left hand side of the multiplication with this <code>Matrixf</code>.
             *
             * @return The result of the multiplication.
             */
            virtual Matrixf*
            multiplyLeftCopy(Matrixf* const leftMatrix) = 0;

            /**
             * <p>
             * Multiplies this <code>Matrixf</code> with the <code>Matrixf</code> given. The <code>Matrixf</code> given is placed on the right hand side of
             * the equation.
             * </p>
             *
             * <p>
             * This <code>Matrixf</code> becomes the result of the multiplication.
             * </p>
             *
             * @param rightMatrix The <code>Matrixf</code> to be placed on the right hand side of the multiplication with this <code>Matrixf</code>.
             */
            virtual void
            multiplyRight(Matrixf* const rightMatrix) = 0;

            /**
             * <p>
             * Multiplies this <code>Matrixf</code> with the <code>Matrixf</code> given. The <code>Matrixf</code> given is placed on the right hand side of
             * the equation.
             * </p>
             *
             * <p>
             * A new <code>Matrixf</code> is created as the result of the multiplication.
             * </p>
             *
             * <p>
             * The caller must assume ownership of the returned <code>Matrixf</code>.
             * </p>
             *
             * @param rightMatrix The <code>Matrixf</code> to be placed on the right hand side of the multiplication with this <code>Matrixf</code>.
             *
             * @return The result of the multiplication.
             */
            virtual Matrixf*
            multiplyRightCopy(Matrixf* const rightMatrix) = 0;

            /**
             * <p>
             * Sets this <code>Matrixf</code> to the identity matrix.
             * </p>
             */
            virtual void
            setIdentity() = 0;

            /**
             * <p>
             * Sets this <code>Matrixf</code> to the transpose of this <code>Matrixf</code>.
             * </p>
             */
            virtual void
            transpose() = 0;
    };

}

#endif /* MATRIXF_H_ */
