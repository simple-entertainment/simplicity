/*
 This file is part of The Simplicity Engine.

 The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
 by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

 The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

 You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef SIMPLERGBCOLOURVECTORF4_H_
#define SIMPLERGBCOLOURVECTORF4_H_

#include "RGBColourVectorf.h"
#include "SimpleVectorf4.h"

namespace simplicity
{
    /**
     * <p>
     * A 4 dimensional colour vector that stores its data in a <code>float</code> array.
     * </p>
     *
     * @author Gary Buyn
     */
    class SimpleRGBColourVectorf4 : public SimpleVectorf4, public RGBColourVectorf
    {
        public:
            /**
             * <p>
             * Creates an instance of <code>SimpleRGBColourVectorf4</code>.
             * </p>
             *
             * <p>
             * The <code>SimpleRGBColourVectorf4</code> is initialised to <code>(0.0f, 0.0f, 0.0f, 1.0f)</code>.
             * </p>
             */
            SimpleRGBColourVectorf4();

            /**
             * <p>
             * Creates an instance of <code>SimpleRGBColourVectorf4</code>.
             * </p>
             *
             * @param f0 The red element of this <code>SimpleRGBColourVectorf4</code>.
             * @param f1 The green element of this <code>SimpleRGBColourVectorf4</code>.
             * @param f2 The blue element of this <code>SimpleRGBColourVectorf4</code>.
             * @param f3 The alpha element of this <code>SimpleRGBColourVectorf4</code>.
             */
            SimpleRGBColourVectorf4(const float f0, const float f1, const float f2, const float f3);

            /**
             * <p>
             * Creates an instance of <code>SimpleRGBColourVectorf4</code>.
             * </p>
             *
             * @param array An array containing the initial elements of this <code>SimpleRGBColourVectorf4</code>.
             */
            SimpleRGBColourVectorf4(float* array);

            /**
             * <p>
             * Disposes of an instance of <code>SimpleRGBColourVectorf4</code>.
             * </p>
             */
            virtual
            ~SimpleRGBColourVectorf4();

            float
            getBlue();

            float
            getGreen();

            float
            getRed();

            void
            setBlue(const float blue);

            void
            setGreen(const float green);

            void
            setRed(const float red);
    };
}

#endif /* SIMPLERGBCOLOURVECTORF4_H_ */
