/*
 This file is part of The Simplicity Engine.

 The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
 by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

 The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

 You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef BOUNDINGVOLUME_H_
#define BOUNDINGVOLUME_H_

namespace simplicity
{
    /**
     * <p>
     * A simple geometric shape that contains the geometry of a subgraph of a {@link simplicity::SceneGraph SceneGraph}.
     * <code>BoundingVolume</code>s can be used in many processes to enhance performance and reduce un-needed calculations.
     * </p>
     *
     * <p>
     * An example where <code>BoundingVolume</code>s are used is collision detection. Collision of the two <code>BoundingVolume</code>s can be tested
     * before collision of the actual geometry contained in them. If the <code>BoundingVolume</code>s do not collide the (possibly very complex)
     * calculations required to test for collisions between the actual geometry is avoided.
     * </p>
     *
     * @author Gary Buyn
     */
    class BoundingVolume
    {
        public:
            /**
             * <p>
             * Determines if this <code>BoundingVolume</code> intersects with the given <code>BoundingVolume</code>.
             * </p>
             *
             * @param otherBoundingVolume The <code>BoundingVolume</code> to test for intersection with this <code>BoundingVolume</code>.
             *
             * @return True if the this <code>BoundingVolume</code> intersects with the given <code>BoundingVolume</code>, false otherwise.
             */
            virtual bool
            intersectsWith(BoundingVolume* const otherBoundingVolume) = 0;

            /**
             * <p>
             * Updates this <code>BoundingVolume</code> to ensure it includes the entire subgraph's geometry.
             * </p>
             */
            virtual void
            update() = 0;
    };
}

#endif /* BOUNDINGVOLUME_H_ */
