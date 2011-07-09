/*
 This file is part of The Simplicity Engine.

 The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
 by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

 The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

 You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef SIMPLETRANSFORMATIONMATRIX44_H_
#define SIMPLETRANSFORMATIONMATRIX44_H_

#include "SimpleMatrix44.h"
#include "TransformationMatrix.h"
#include "TranslationVector.h"

namespace simplicity
{
  /**
   * <p>
   * A 4x4 transformation matrix that stores its data in a array.
   * </p>
   *
   * <p>
   * This <code>SimpleTransformationMatrix44</code> uses a 3D homogeneous coordinate system. It is of the following format:
   * </p>
   *
   * <pre>
   * --------------------
   *  xx | yx | zx | tx |
   * --------------------
   *  xy | yy | zy | ty |
   * --------------------
   *  xz | yz | zz | tz |
   * --------------------
   *  xw | yw | zw | tw |
   * --------------------
   * </pre>
   *
   * <p>
   * Where the first column is the x axis rotation, the second column is the y axis rotation, the third column is the z axis rotation and the fourth
   * column is the translation.
   * </p>
   *
   * <p>
   * It is stored in column-major format. This means the first four indices of the array represent the first column of the
   * <code>SimpleTransformationMatrix44</code>, the second four represent the second column etc.
   * </p>
   *
   * @author Gary Buyn
   */
  template<class Data>
    class SimpleTransformationMatrix44 : public SimpleMatrix44<Data> , public TransformationMatrix<Data>
    {
      public:
        /**
         * <p>
         * Creates an instance of <code>SimpleTransformationMatrix44</code>.
         * </p>
         */
        SimpleTransformationMatrix44();

        /**
         * <p>
         * Creates an instance of <code>SimpleTransformationMatrix44</code>.
         * </p>
         *
         * @param data A array containing the initial elements for this <code>SimpleMatrix44</code>.
         */
        SimpleTransformationMatrix44(array<Data, 16> data);

        TranslationVector<Data> *
        getTranslation() const;

        Data
        getXAxisTranslation() const;

        Data
        getYAxisTranslation() const;

        Data
        getZAxisTranslation() const;

        void
        rotate(Data const angle, Vector<Data> const * const axis);

        void
        setTranslation(TranslationVector<Data> const * const translation);

        void
        setXAxisTranslation(Data const distance);

        void
        setYAxisTranslation(Data const distance);

        void
        setZAxisTranslation(Data const distance);

        void
        translate(TranslationVector<Data> const * const translation);
    };
}

#include "SimpleTransformationMatrix44.tpp"

#endif /* SIMPLETRANSFORMATIONMATRIX44_H_ */
