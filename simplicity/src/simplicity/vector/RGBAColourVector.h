/*
 This file is part of The Simplicity Engine.

 The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
 by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

 The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

 You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef RGBACOLOURVECTOR_H_
#define RGBACOLOURVECTOR_H_

#include "Vector.h"

namespace simplicity
{
  /**
   * <p>
   * An RGBA colour vector.
   * </p>
   *
   * @author Gary Buyn
   */
  template<class Data>
    class RGBAColourVector : public virtual Vector<Data>
    {
      public:
        /**
         * <p>
         * Retrieves the alpha component.
         * </p>
         *
         * @return The alpha component.
         */
        virtual Data
        getAlpha() const = 0;

        /**
         * <p>
         * Retrieves the blue component.
         * </p>
         *
         * @return The blue component.
         */
        virtual Data
        getBlue() const = 0;

        /**
         * <p>
         * Retrieves the green component.
         * </p>
         *
         * @return The green component.
         */
        virtual Data
        getGreen() const = 0;

        /**
         * <p>
         * Retrieves the red component.
         * </p>
         *
         * @return The red component.
         */
        virtual Data
        getRed() const = 0;

        /**
         * <p>
         * Sets the alpha component.
         * </p>
         *
         * @param alpha The alpha component.
         */
        virtual void
        setAlpha(const Data alpha) = 0;

        /**
         * <p>
         * Sets the blue component.
         * </p>
         *
         * @param blue The blue component.
         */
        virtual void
        setBlue(const Data blue) = 0;

        /**
         * <p>
         * Sets the green component.
         * </p>
         *
         * @param green The green component.
         */
        virtual void
        setGreen(const Data green) = 0;

        /**
         * <p>
         * Sets the red component.
         * </p>
         *
         * @param red The red component.
         */
        virtual void
        setRed(const Data red) = 0;
    };
}

#endif /* RGBACOLOURVECTOR_H_ */
