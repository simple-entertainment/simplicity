/*
 This file is part of The Simplicity Engine.

 The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
 by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

 The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

 You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef TRANSLATIONVECTORF_H_
#define TRANSLATIONVECTORF_H_

#include "Vectorf.h"

namespace simplicity
{
    /**
     * <p>
     * A translation vector that stores its data in a <code>float</code> array.
     * </p>
     *
     * @author Gary Buyn
     */
    class TranslationVectorf : public virtual Vectorf
    {
        public:
            /**
             * <p>
             * Retrieves the w component of this <code>TranslationVectorf</code>.
             * </p>
             *
             * @return The w component of this <code>TranslationVectorf</code>.
             */
            virtual float
            getW() = 0;

            /**
             * <p>
             * Retrieves the x axis component of this <code>TranslationVectorf</code>.
             * </p>
             *
             * @return The x axis component of this <code>TranslationVectorf</code>.
             */
            virtual float
            getX() = 0;

            /**
             * <p>
             * Retrieves the y axis component of this <code>TranslationVectorf</code>.
             * </p>
             *
             * @return The y axis component of this <code>TranslationVectorf</code>.
             */
            virtual float
            getY() = 0;

            /**
             * <p>
             * Retrieves the z axis component of this <code>TranslationVectorf</code>.
             * </p>
             *
             * @return The z axis component of this <code>TranslationVectorf</code>.
             */
            virtual float
            getZ() = 0;

            /**
             * <p>
             * Sets the x axis component of this <code>TranslationVectorf</code>.
             * </p>
             *
             * @param x The x axis component of this <code>TranslationVectorf</code>.
             */
            virtual void
            setX(const float x) = 0;

            /**
             * <p>
             * Sets the y axis component of this <code>TranslationVectorf</code>.
             * </p>
             *
             * @param y The y axis component of this <code>TranslationVectorf</code>.
             */
            virtual void
            setY(const float y) = 0;

            /**
             * <p>
             * Sets the z axis component of this <code>TranslationVectorf</code>.
             * </p>
             *
             * @param z The z axis component of this <code>TranslationVectorf</code>.
             */
            virtual void
            setZ(const float z) = 0;

            /**
             * <p>
             * Translates this <code>TranslationVectorf</code> by the given distance on the x axis.
             * </p>
             *
             * @param x The distance to translate this <code>TranslationVectorf</code> on the x axis.
             */
            virtual void
            translateX(const float x) = 0;

            /**
             * <p>
             * Translates this <code>TranslationVectorf</code> by the given distance on the y axis.
             * </p>
             *
             * @param y The distance to translate this <code>TranslationVectorf</code> on the y axis.
             */
            virtual void
            translateY(const float y) = 0;

            /**
             * <p>
             * Translates this <code>TranslationVectorf</code> by the given distance on the z axis.
             * </p>
             *
             * @param z The distance to translate this <code>TranslationVectorf</code> on the z axis.
             */
            virtual void
            translateZ(const float z) = 0;
    };
}

#endif /* TRANSLATIONVECTORF_H_ */
