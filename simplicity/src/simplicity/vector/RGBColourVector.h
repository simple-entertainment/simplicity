/*
 This file is part of The Simplicity Engine.

 The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
 by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

 The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

 You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef RGBCOLOURVECTOR_H_
#define RGBCOLOURVECTOR_H_

#include "Vector.h"

namespace simplicity
{
  /**
   * <p>
   * An RGB colour vector.
   * </p>
   *
   * @author Gary Buyn
   */
  template<class Data>
    class RGBColourVector : public virtual Vector<Data>
    {
      public:
        /**
         * <p>
         * Retrieves the blue component of this <code>RGBColourVector</code>.
         * </p>
         *
         * @return The blue component of this <code>RGBColourVector</code>.
         */
        virtual Data
        getBlue() const = 0;

        /**
         * <p>
         * Retrieves the green component of this <code>RGBColourVector</code>.
         * </p>
         *
         * @return The green component of this <code>RGBColourVector</code>.
         */
        virtual Data
        getGreen() const = 0;

        /**
         * <p>
         * Retrieves the red component of this <code>RGBColourVector</code>.
         * </p>
         *
         * @return The red component of this <code>RGBColourVector</code>.
         */
        virtual Data
        getRed() const = 0;

        /**
         * <p>
         * Sets the blue component of this <code>RGBColourVector</code>.
         * </p>
         *
         * @param blue The blue component of this <code>RGBColourVector</code>.
         */
        virtual void
        setBlue(const Data blue) = 0;

        /**
         * <p>
         * Sets the green component of this <code>RGBColourVector</code>.
         * </p>
         *
         * @param green The green component of this <code>RGBColourVector</code>.
         */
        virtual void
        setGreen(const Data green) = 0;

        /**
         * <p>
         * Sets the red component of this <code>RGBColourVector</code>.
         * </p>
         *
         * @param red The red component of this <code>RGBColourVector</code>.
         */
        virtual void
        setRed(const Data red) = 0;
    };

}

#endif /* RGBCOLOURVECTOR_H_ */
