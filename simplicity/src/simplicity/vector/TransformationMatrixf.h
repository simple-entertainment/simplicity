/*
 This file is part of The Simplicity Engine.

 The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
 by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

 The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

 You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef TRANSFORMATIONMATRIXF_H_
#define TRANSFORMATIONMATRIXF_H_

#include "Matrixf.h"
#include "TranslationVectorf.h"
#include "Vectorf.h"

namespace simplicity
{
    /**
     * <p>
     * A transformation matrix that stores its data in a <code>float</code> array.
     * </p>
     *
     * @author Gary Buyn
     */
    class TransformationMatrixf : public virtual Matrixf
    {
        public:
            /**
             * <p>
             * Retrieves the translation portion of this <code>TransformationMatrixf</code>.
             * </p>
             *
             * <p>
             * The caller must assume ownership of the returned <code>TranslationVectorf</code>.
             * </p>
             *
             * @return The translation portion of this <code>TransformationMatrixf</code>.
             */
            virtual TranslationVectorf*
            getTranslation() = 0;

            /**
             *<p>
             * Retrieves the x axis translation of this <code>TransformationMatrixf</code>.
             *</p>
             *
             * @return The x axis translation of this <code>TransformationMatrixf</code>.
             */
            virtual float
            getXAxisTranslation() = 0;

            /**
             *<p>
             * Retrieves the y axis translation of this <code>TransformationMatrixf</code>.
             *</p>
             *
             * @return The y axis translation of this <code>TransformationMatrixf</code>.
             */
            virtual float
            getYAxisTranslation() = 0;

            /**
             *<p>
             * Retrieves the z axis translation of this <code>TransformationMatrixf</code>.
             *</p>
             *
             * @return The z axis translation of this <code>TransformationMatrixf</code>.
             */
            virtual float
            getZAxisTranslation() = 0;

            /**
             * <p>
             * Rotates this <code>TransformationMatrixf</code> by the angle given about the axis given.
             * </p>
             *
             * @param angle The angle to rotate this <code>TransformationMatrixf</code>.
             * @param axis The axis to rotate this <code>TransformationMatrixf</code> about.
             */
            virtual void
            rotate(const float angle, Vectorf* const axis) = 0;

            /**
             * <p>
             * Sets the translation portion of this <code>TransformationMatrixf</code>.
             * </p>
             *
             * @param translation The translation portion of this <code>TransformationMatrixf</code>.
             */
            virtual void
            setTranslation(TranslationVectorf* const translation) = 0;

            /**
             *<p>
             * Sets the x axis translation of this <code>TransformationMatrixf</code>.
             *</p>
             *
             * @param distance The x axis translation of this <code>TransformationMatrixf</code>.
             */
            virtual void
            setXAxisTranslation(const float distance) = 0;

            /**
             *<p>
             * Sets the y axis translation of this <code>TransformationMatrixf</code>.
             *</p>
             *
             * @param distance The y axis translation of this <code>TransformationMatrixf</code>.
             */
            virtual void
            setYAxisTranslation(const float distance) = 0;

            /**
             *<p>
             * Sets the z axis translation of this <code>TransformationMatrixf</code>.
             *</p>
             *
             * @param distance The z axis translation of this <code>TransformationMatrixf</code>.
             */
            virtual void
            setZAxisTranslation(const float distance) = 0;

            /**
             * <p>
             * Translates this <code>TransformationMatrixf</code> by the translation given.
             * </p>
             *
             * @param translation The translation to translate this <code>TransformationMatrixf</code> by.
             */
            virtual void
            translate(TranslationVectorf* const translation) = 0;
    };
}

#endif /* TRANSFORMATIONMATRIXF_H_ */
