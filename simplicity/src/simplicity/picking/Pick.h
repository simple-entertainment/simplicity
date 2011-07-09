/*
 This file is part of The Simplicity Engine.

 The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
 by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

 The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

 You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef PICK_H_
#define PICK_H_

namespace simplicity
{
  /**
   * <p>
   * The position and area for a {@link simplicity::Picker Picker} to pick. A <code>Pick</code> generally represents a subset of a
   * {@link simplicity::Camera Camera}'s frame.
   * </p>
   *
   * @author Gary Buyn
   */
  class Pick
  {
    public:
      /**
       * <p>
       * Creates an instance of <code>Pick</code>.
       * </p>
       */
      Pick();

      /**
       * <p>
       * Disposes of an instance of <code>Pick</code>.
       * </p>
       */
      virtual
      ~Pick();

      /**
       * <p>
       * Retrieves the height of the area being picked.
       * </p>
       *
       * @return The height of the area being picked.
       */
      float
      getHeight() const;

      /**
       * <p>
       * Retrieves the width of the area being picked.
       * </p>
       *
       * @return The width of the area being picked.
       */
      float
      getWidth() const;

      /**
       * <p>
       * Retrieves the position on the <code>x</code> axis being picked.
       * </p>
       *
       * @return The position on the <code>x</code> axis being picked.
       */
      float
      getX() const;

      /**
       * <p>
       * Retrieves the position on the <code>y</code> axis being picked.
       * </p>
       *
       * @return The position on the <code>y</code> axis being picked.
       */
      float
      getY() const;

      /**
       * <p>
       * Sets the height of the area being picked.
       * </p>
       *
       * @param height The height of the area being picked.
       */
      void
      setHeight(float const height);

      /**
       * <p>
       * Sets the width of the area being picked.
       * </p>
       *
       * @param width The height of the area being picked.
       */
      void
      setWidth(float const width);

      /**
       * <p>
       * Sets the position on the <code>x</code> axis being picked.
       * </p>
       *
       * @param x The position on the <code>x</code> axis being picked.
       */
      void
      setX(float const x);

      /**
       * <p>
       * Sets the position on the <code>y</code> axis being picked.
       * </p>
       *
       * @param y The position on the <code>y</code> axis being picked.
       */
      void
      setY(float const y);

    private:
      /**
       * <p>
       * The height of the area being picked.
       * </p>
       */
      float fHeight;

      /**
       * <p>
       * The width of the area being picked.
       * </p>
       */
      float fWidth;

      /**
       * <p>
       * The position on the <code>x</code> axis being picked.
       * </p>
       */
      float fX;

      /**
       * <p>
       * The position on the <code>y</code> axis being picked.
       * </p>
       */
      float fY;
  };
}

#endif /* PICK_H_ */
