/*
 This file is part of The Simplicity Engine.

 The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
 by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

 The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

 You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef SIMPLETRANSLATIONVECTORF4_H_
#define SIMPLETRANSLATIONVECTORF4_H_

#include "SimpleVectorf4.h"
#include "TranslationVectorf.h"

namespace simplicity
{
    /**
     * <p>
     * A 4 dimensional translation vector that stores its data in a <code>float</code> array.
     * </p>
     *
     * <p>
     * This <code>SimpleVectorf4</code> uses a 3D homogeneous coordinate system. It is of the following format:
     * </p>
     *
     * <pre>
     * ----------------
     *  x | y | z | w |
     * ----------------
     * </pre>
     *
     * @author Gary Buyn
     */
    class SimpleTranslationVectorf4 : public SimpleVectorf4, public TranslationVectorf
    {
        public:
            /**
             * <p>
             * Creates an instance of <code>SimpleTranslationVectorf4</code>.
             * </p>
             */
            SimpleTranslationVectorf4();

            /**
             * <p>
             * Creates an instance of <code>SimpleTranslationVectorf4</code>.
             * </p>
             *
             * @param f0 The x element of this <code>SimpleTranslationVectorf4</code>.
             * @param f1 The y element of this <code>SimpleTranslationVectorf4</code>.
             * @param f2 The z element of this <code>SimpleTranslationVectorf4</code>.
             * @param f3 The w element of this <code>SimpleTranslationVectorf4</code>.
             */
            SimpleTranslationVectorf4(const float f0, const float f1, const float f2, const float f3);

            /**
             * <p>
             * Creates an instance of <code>SimpleTranslationVectorf4</code>.
             * </p>
             *
             * @param array An array containing the initial elements of this <code>SimpleTranslationVectorf4</code>.
             */
            SimpleTranslationVectorf4(float* const array);

            /**
             * <p>
             * Disposes of an instance of <code>SimpleTranslationVectorf4</code>.
             * </p>
             */
            virtual
            ~SimpleTranslationVectorf4();

            float
            getW();

            float
            getX();

            float
            getY();

            float
            getZ();

            void
            setX(const float x);

            void
            setY(const float y);

            void
            setZ(const float z);

            void
            translateX(const float x);

            void
            translateY(const float y);

            void
            translateZ(const float z);
    };
}

#endif /* SIMPLETRANSLATIONVECTORF4_H_ */
