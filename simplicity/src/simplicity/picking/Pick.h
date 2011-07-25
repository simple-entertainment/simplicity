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
  struct Pick
  {
      /**
       * <p>
       * The height of the area being picked.
       * </p>
       */
      float height;

      /**
       * <p>
       * The width of the area being picked.
       * </p>
       */
      float width;

      /**
       * <p>
       * The position on the <code>x</code> axis being picked.
       * </p>
       */
      float x;

      /**
       * <p>
       * The position on the <code>y</code> axis being picked.
       * </p>
       */
      float y;
  };
}

#endif /* PICK_H_ */
