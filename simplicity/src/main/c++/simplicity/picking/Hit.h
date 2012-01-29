/*
 This file is part of The Simplicity Engine.

 The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
 by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

 The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

 You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef HIT_H_
#define HIT_H_

#include "../model/Model.h"
#include "../scene/Node.h"

namespace simplicity
{
  /**
   * <p>
   * A hit made as a result of a pick.
   * </p>
   *
   * @author Gary Buyn
   */
  struct Hit
  {
      /**
       * <p>
       * The maximum distance of the primitive(s) that intersected the pick on the Z axis in relation to the {@link simplicity::Camera Camera}.
       * </p>
       */
      int maximumDistance;

      /**
       * <p>
       * The minimum distance of the primitive(s) that intersected the pick on the Z axis in relation to the {@link simplicity::Camera Camera}.
       * </p>
       */
      int minimumDistance;

      /**
       * <p>
       * The {@link simplicity::Node Node} that most directly contains the primitive(s) that intersected the pick.
       * </p>
       */
      std::shared_ptr<Node> node;

      /**
       * <p>
       * The primitive that intersected the pick. In the case that multiple primitives were drawn with the same name, this primitive stored in this
       * value is undefined.
       * </p>
       */
      std::shared_ptr<Model> primitive;
  };
}

#endif /* HIT_H_ */
