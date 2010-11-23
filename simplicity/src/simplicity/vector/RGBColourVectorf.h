/*
 This file is part of The Simplicity Engine.

 The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
 by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

 The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

 You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef RGBCOLOURVECTORF_H_
#define RGBCOLOURVECTORF_H_

#include "Vectorf.h"

namespace simplicity
{
    /**
     * <p>
     * A colour vector that stores its data in a <code>float</code> array.
     * </p>
     *
     * @author Gary Buyn
     */
    class RGBColourVectorf : public virtual Vectorf
    {
        public:
            /**
             * <p>
             * Retrieves the blue component of this <code>RGBColourVectorf</code>.
             * </p>
             *
             * @return The blue component of this <code>RGBColourVectorf</code>.
             */
            virtual float
            getBlue() = 0;

            /**
             * <p>
             * Retrieves the green component of this <code>RGBColourVectorf</code>.
             * </p>
             *
             * @return The green component of this <code>RGBColourVectorf</code>.
             */
            virtual float
            getGreen() = 0;

            /**
             * <p>
             * Retrieves the red component of this <code>RGBColourVectorf</code>.
             * </p>
             *
             * @return The red component of this <code>RGBColourVectorf</code>.
             */
            virtual float
            getRed() = 0;

            /**
             * <p>
             * Sets the blue component of this <code>RGBColourVectorf</code>.
             * </p>
             *
             * @param blue The blue component of this <code>RGBColourVectorf</code>.
             */
            virtual void
            setBlue(const float blue) = 0;

            /**
             * <p>
             * Sets the green component of this <code>RGBColourVectorf</code>.
             * </p>
             *
             * @param green The green component of this <code>RGBColourVectorf</code>.
             */
            virtual void
            setGreen(const float green) = 0;

            /**
             * <p>
             * Sets the red component of this <code>RGBColourVectorf</code>.
             * </p>
             *
             * @param red The red component of this <code>RGBColourVectorf</code>.
             */
            virtual void
            setRed(const float red) = 0;
    };

}

#endif /* RGBCOLOURVECTORF_H_ */
