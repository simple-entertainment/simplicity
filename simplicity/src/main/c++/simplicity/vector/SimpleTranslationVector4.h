/*
 This file is part of The Simplicity Engine.

 The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
 by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

 The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

 You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef SIMPLETRANSLATIONVECTOR4_H_
#define SIMPLETRANSLATIONVECTOR4_H_

#include "SimpleVector4.h"
#include "TranslationVector.h"

namespace simplicity
{
  /**
   * <p>
   * A 4 dimensional translation vector that stores its data in an array.
   * </p>
   *
   * <p>
   * This <code>SimpleVector4</code> uses a 3D homogeneous coordinate system. It is of the following format:
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
  template<class Data>
    class SimpleTranslationVector4 : public SimpleVector4<Data> , public TranslationVector<Data>
    {
      public:
        /**
         * <p>
         * Creates an instance of <code>SimpleTranslationVector4</code>.
         * </p>
         */
        SimpleTranslationVector4();

        /**
         * <p>
         * Creates an instance of <code>SimpleTranslationVector4</code>.
         * </p>
         *
         * @param x The x element of this <code>SimpleTranslationVector4</code>.
         * @param y The y element of this <code>SimpleTranslationVector4</code>.
         * @param z The z element of this <code>SimpleTranslationVector4</code>.
         * @param w The w element of this <code>SimpleTranslationVector4</code>.
         */
        SimpleTranslationVector4(const Data x, const Data y, const Data z, const Data w);

        /**
         * <p>
         * Creates an instance of <code>SimpleTranslationVector4</code>.
         * </p>
         *
         * @param data An array containing the initial elements of this <code>SimpleTranslationVector4</code>.
         */
        SimpleTranslationVector4(boost::array<Data, SimpleVector4<Data>::CELLS_IN_VECTOR> data);

        Data
        getW() const;

        Data
        getX() const;

        Data
        getY() const;

        Data
        getZ() const;

        void
        setX(const Data x);

        void
        setY(const Data y);

        void
        setZ(const Data z);

        void
        translateX(const Data x);

        void
        translateY(const Data y);

        void
        translateZ(const Data z);
    };
}

#include "SimpleTranslationVector4.tpp"

#endif /* SIMPLETRANSLATIONVECTOR4_H_ */
