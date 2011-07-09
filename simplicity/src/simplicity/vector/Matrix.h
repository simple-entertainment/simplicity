/*
 This file is part of The Simplicity Engine.

 The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
 by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

 The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

 You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef MATRIX_H_
#define MATRIX_H_

#include "../SEInvalidOperationException.h"

namespace simplicity
{
  /**
   * <p>
   * A matrix.
   * </p>
   *
   * @author Gary Buyn
   */
  template<class Data = float>
    class Matrix
    {
      public:
        /**
         * <p>
         * Disposes of an instance of <code>Matrix</code> (included to allow polymorphic deletion).
         * </p>
         */
        virtual
        ~Matrix()
        {
        }

        /**
         * <p>
         * Retrieves the determinant of this <code>Matrix</code>.
         * </p>
         *
         * @return The determinant of this <code>Matrix</code>.
         */
        virtual Data
        getDeterminant() const = 0;

        /**
         * <p>
         * Attempts to set this <code>Matrix</code> to the inverse of this <code>Matrix</code>.
         * </p>
         *
         * @throw SEInvalidOperationException If this <code>SimpleMatrix44</code> has a determinant of 0.
         */
        virtual void
        invert() throw (SEInvalidOperationException) = 0;

        /**
         * <p>
         * Multiplies this <code>Matrix</code> with the <code>Matrix</code> given. The <code>Matrix</code> given is placed on the left hand side of the
         * equation.
         * </p>
         *
         * <p>
         * This <code>Matrix</code> becomes the result of the multiplication.
         * </p>
         *
         * @param leftMatrix The <code>Matrix</code> to be placed on the left hand side of the multiplication with this <code>Matrix</code>.
         */
        virtual void
        multiplyLeft(Matrix<Data> const * const leftMatrix) = 0;

        /**
         * <p>
         * Multiplies this <code>Matrix</code> with the <code>Matrix</code> given. The <code>Matrix</code> given is placed on the left hand side of the
         * equation.
         * </p>
         *
         * <p>
         * A new <code>Matrix</code> is created as the result of the multiplication.
         * </p>
         *
         * <p>
         * The caller must assume ownership of the returned <code>Matrix</code>.
         * </p>
         *
         * @param leftMatrix The <code>Matrix</code> to be placed on the left hand side of the multiplication with this <code>Matrix</code>.
         *
         * @return The result of the multiplication.
         */
        virtual Matrix<Data> *
        multiplyLeftCopy(Matrix<Data> const * const leftMatrix) const = 0;

        /**
         * <p>
         * Multiplies this <code>Matrix</code> with the <code>Matrix</code> given. The <code>Matrix</code> given is placed on the right hand side of
         * the equation.
         * </p>
         *
         * <p>
         * This <code>Matrix</code> becomes the result of the multiplication.
         * </p>
         *
         * @param rightMatrix The <code>Matrix</code> to be placed on the right hand side of the multiplication with this <code>Matrix</code>.
         */
        virtual void
        multiplyRight(Matrix<Data> const * const rightMatrix) = 0;

        /**
         * <p>
         * Multiplies this <code>Matrix</code> with the <code>Matrix</code> given. The <code>Matrix</code> given is placed on the right hand side of
         * the equation.
         * </p>
         *
         * <p>
         * A new <code>Matrix</code> is created as the result of the multiplication.
         * </p>
         *
         * <p>
         * The caller must assume ownership of the returned <code>Matrix</code>.
         * </p>
         *
         * @param rightMatrix The <code>Matrix</code> to be placed on the right hand side of the multiplication with this <code>Matrix</code>.
         *
         * @return The result of the multiplication.
         */
        virtual Matrix<Data> *
        multiplyRightCopy(Matrix<Data> const * const rightMatrix) const = 0;

        /**
         * <p>
         * Sets this <code>Matrix</code> to the identity matrix.
         * </p>
         */
        virtual void
        setIdentity() = 0;

        /**
         * <p>
         * Sets this <code>Matrix</code> to the transpose of this <code>Matrix</code>.
         * </p>
         */
        virtual void
        transpose() = 0;
    };

}

#endif /* MATRIX_H_ */
