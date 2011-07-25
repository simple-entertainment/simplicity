/*
 This file is part of The Simplicity Engine.

 The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
 by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

 The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

 You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef TRANSFORMATIONMATRIX_H_
#define TRANSFORMATIONMATRIX_H_

#include "Matrix.h"
#include "TranslationVector.h"
#include "Vector.h"

namespace simplicity
{
  /**
   * <p>
   * A transformation matrix that stores its data in a array.
   * </p>
   *
   * @author Gary Buyn
   */
  template<class Data>
    class TransformationMatrix : public virtual Matrix<Data>
    {
      public:
        /**
         * <p>
         * Retrieves the translation portion of this <code>TransformationMatrix</code>.
         * </p>
         *
         * @return The translation portion of this <code>TransformationMatrix</code>.
         */
        virtual boost::shared_ptr<TranslationVector<Data> >
        getTranslation() const = 0;

        /**
         *<p>
         * Retrieves the x axis translation of this <code>TransformationMatrix</code>.
         *</p>
         *
         * @return The x axis translation of this <code>TransformationMatrix</code>.
         */
        virtual Data
        getXAxisTranslation() const = 0;

        /**
         *<p>
         * Retrieves the y axis translation of this <code>TransformationMatrix</code>.
         *</p>
         *
         * @return The y axis translation of this <code>TransformationMatrix</code>.
         */
        virtual Data
        getYAxisTranslation() const = 0;

        /**
         *<p>
         * Retrieves the z axis translation of this <code>TransformationMatrix</code>.
         *</p>
         *
         * @return The z axis translation of this <code>TransformationMatrix</code>.
         */
        virtual Data
        getZAxisTranslation() const = 0;

        /**
         * <p>
         * Rotates this <code>TransformationMatrix</code> by the angle given about the axis given.
         * </p>
         *
         * @param angle The angle to rotate this <code>TransformationMatrix</code>.
         * @param axis The axis to rotate this <code>TransformationMatrix</code> about.
         */
        virtual void
        rotate(const Data angle, const Vector<Data>& axis) = 0;

        /**
         * <p>
         * Sets the translation portion of this <code>TransformationMatrix</code>.
         * </p>
         *
         * @param translation The translation portion of this <code>TransformationMatrix</code>.
         */
        virtual void
        setTranslation(boost::shared_ptr<TranslationVector<Data> > translation) = 0;

        /**
         *<p>
         * Sets the x axis translation of this <code>TransformationMatrix</code>.
         *</p>
         *
         * @param distance The x axis translation of this <code>TransformationMatrix</code>.
         */
        virtual void
        setXAxisTranslation(const Data distance) = 0;

        /**
         *<p>
         * Sets the y axis translation of this <code>TransformationMatrix</code>.
         *</p>
         *
         * @param distance The y axis translation of this <code>TransformationMatrix</code>.
         */
        virtual void
        setYAxisTranslation(const Data distance) = 0;

        /**
         *<p>
         * Sets the z axis translation of this <code>TransformationMatrix</code>.
         *</p>
         *
         * @param distance The z axis translation of this <code>TransformationMatrix</code>.
         */
        virtual void
        setZAxisTranslation(const Data distance) = 0;

        /**
         * <p>
         * Translates this <code>TransformationMatrix</code> by the translation given.
         * </p>
         *
         * @param translation The translation to translate this <code>TransformationMatrix</code> by.
         */
        virtual void
        translate(const TranslationVector<Data>& translation) = 0;
    };
}

#endif /* TRANSFORMATIONMATRIX_H_ */
