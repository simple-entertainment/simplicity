/*
 This file is part of The Simplicity Engine.

 The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
 by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

 The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

 You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef SPHERE_H_
#define SPHERE_H_

#include "Shape.h"

namespace simplicity
{
  /**
   * <p>
   * A spherical {@link simplicity::Model Model}.
   * </p>
   *
   * @author Gary Buyn
   */
  class Sphere : public Shape
  {
    public:
      /**
       * <p>
       * Creates an instance of <code>Sphere</code>.
       * </p>
       */
      Sphere();

      /**
       * <p>
       * Disposes of an instance of <code>Sphere</code>.
       * </p>
       */
      ~Sphere();

      const TranslationVector<float>&
      getCenter() const;

      RGBColourVector<float>&
      getColour() const;

      /**
       * <p>
       * Retrieves the radius. The default is 1.0.
       * </p>
       *
       * @return The radius.
       */
      float
      getRadius() const;

      void
      setColour(boost::shared_ptr<RGBColourVector<float> > colour);

      /**
       * <p>
       * Sets the radius. The default is 1.0.
       * </p>
       *
       * @param radius The radius.
       */
      void
      setRadius(const float radius);

    private:
      /**
       * <p>
       * The point at the center of this <code>Sphere</code>.
       * </p>
       */
      boost::shared_ptr<TranslationVector<float> > fCenter;

      /**
       * <p>
       * The colour to render this <code>Sphere</code> as.
       * </p>
       */
      boost::shared_ptr<RGBColourVector<float> > fColour;

      /**
       * <p>
       * The radius.
       * </p>
       */
      float fRadius;
  };
}

#endif /* SPHERE_H_ */
