/*
 This file is part of The Simplicity Engine.

 The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
 by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

 The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

 You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef SIMPLERGBCOLOURVECTOR4_H_
#define SIMPLERGBCOLOURVECTOR4_H_

#include "RGBColourVector.h"
#include "SimpleVector4.h"

namespace simplicity
{
  /**
   * <p>
   * A 4 dimensional RGB colour vector that stores its data in a array.
   * </p>
   *
   * @author Gary Buyn
   */
  template<class Data>
    class SimpleRGBColourVector4 : public SimpleVector4<Data> , public RGBColourVector<Data>
    {
      public:
        /**
         * <p>
         * Creates an instance of <code>SimpleRGBColourVector4</code>.
         * </p>
         *
         * <p>
         * The <code>SimpleRGBColourVector4</code> is initialised to <code>(0.0, 0.0, 0.0, 1.0)</code>.
         * </p>
         */
        SimpleRGBColourVector4();

        /**
         * <p>
         * Creates an instance of <code>SimpleRGBColourVector4</code>.
         * </p>
         *
         * @param r The red element of this <code>SimpleRGBColourVector4</code>.
         * @param g The green element of this <code>SimpleRGBColourVector4</code>.
         * @param b The blue element of this <code>SimpleRGBColourVector4</code>.
         * @param a The alpha element of this <code>SimpleRGBColourVector4</code>.
         */
        SimpleRGBColourVector4(const Data r, const Data g, const Data b, const Data a);

        /**
         * <p>
         * Creates an instance of <code>SimpleRGBColourVector4</code>.
         * </p>
         *
         * @param data An array containing the initial elements of this <code>SimpleRGBColourVector4</code>.
         */
        SimpleRGBColourVector4(boost::array<Data, SimpleVector4<Data>::CELLS_IN_VECTOR> data);

        Data
        getBlue() const;

        Data
        getGreen() const;

        Data
        getRed() const;

        void
        setBlue(const Data blue);

        void
        setGreen(const Data green);

        void
        setRed(const Data red);
    };
}

#include "SimpleRGBColourVector4.tpp"

#endif /* SIMPLERGBCOLOURVECTOR4_H_ */
