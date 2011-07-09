/*
 This file is part of The Simplicity Engine.

 The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
 by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

 The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

 You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef SHAPE_H_
#define SHAPE_H_

#include "../Model.h"
#include "../../vector/RGBColourVector.h"

namespace simplicity
{
  /**
   * <p>
   * A {@link simplicity::Model Model} described by a single atomic shape.
   * </p>
   *
   * @author Gary Buyn
   */
  class Shape : public Model
  {
    public:
      /**
       * <p>
       * Retrieves the colour to render this <code>Shape</code> as.
       * </p>
       *
       * @return The colour to render this <code>Shape</code> as.
       */
      virtual RGBColourVector<float> *
      getColour() const = 0;

      /**
       * <p>
       * Sets the colour to render this <code>Shape</code> as.
       * </p>
       *
       * <p>
       * This <code>Shape</code> will assume ownership of the given <code>RGBColourVector</code>.
       * </p>
       *
       * @param colour The colour to render this <code>Shape</code> as.
       */
      virtual void
      setColour(RGBColourVector<float> * const colour) = 0;
  };
}

#endif /* SHAPE_H_ */
