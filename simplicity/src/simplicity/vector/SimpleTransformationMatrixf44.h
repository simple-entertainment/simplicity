/*
 This file is part of The Simplicity Engine.

 The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
 by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

 The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

 You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef SIMPLETRANSFORMATIONMATRIXF44_H_
#define SIMPLETRANSFORMATIONMATRIXF44_H_

#include "SimpleMatrixf44.h"
#include "TransformationMatrixf.h"
#include "TranslationVectorf.h"

namespace simplicity
{
    /**
     * <p>
     * A 4x4 transformation matrix that stores its data in a <code>float</code> array.
     * </p>
     *
     * <p>
     * This <code>SimpleTransformationMatrixf44</code> uses a 3D homogeneous coordinate system. It is of the following format:
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
     * <code>SimpleTransformationMatrixf44</code>, the second four represent the second column etc.
     * </p>
     *
     * @author Gary Buyn
     */
    class SimpleTransformationMatrixf44 : public SimpleMatrixf44, public TransformationMatrixf
    {
        public:
            /**
             * <p>
             * Creates an instance of <code>SimpleTransformationMatrixf44</code>.
             * </p>
             */
            SimpleTransformationMatrixf44();

            /**
             * <p>
             * Creates an instance of <code>SimpleTransformationMatrixf44</code>.
             * </p>
             *
             * @param array An array containing the initial elements for this <code>SimpleMatrixf44</code>.
             */
            SimpleTransformationMatrixf44(float* const array);

            /**
             * <p>
             * Disposes of an instance of <code>SimpleTransformationMatrixf44</code>.
             * </p>
             */
            virtual
            ~SimpleTransformationMatrixf44();

            TranslationVectorf*
            getTranslation();

            float
            getXAxisTranslation();

            float
            getYAxisTranslation();

            float
            getZAxisTranslation();

            void
            rotate(const float angle, Vectorf* const axis);

            void
            setTranslation(TranslationVectorf* const translation);

            void
            setXAxisTranslation(const float distance);

            void
            setYAxisTranslation(const float distance);

            void
            setZAxisTranslation(const float distance);

            void
            translate(TranslationVectorf* const translation);
    };
}

#endif /* SIMPLETRANSFORMATIONMATRIXF44_H_ */
