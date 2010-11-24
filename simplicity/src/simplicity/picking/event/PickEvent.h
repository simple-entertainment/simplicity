/*
 This file is part of The Simplicity Engine.

 The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
 by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

 The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

 You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef PICKEVENT_H_
#define PICKEVENT_H_

#include <vector>
using namespace std;

#include <boost/optional.hpp>
using namespace boost;

#include "../Hit.h"

namespace simplicity
{
    /**
     * <p>
     * An event that indicates a {@link simplicity::Picker Picker} has been invoked against a
     * {@link simplicity::SceneGraph SceneGraph} (a {@link simplicity::SceneGraph SceneGraph} has been picked) and
     * contains the hits made as a result of this pick.
     * </p>
     *
     * @author Gary Buyn
     */
    class PickEvent
    {
        public:
            /**
             * <p>
             * Creates an instance of <code>PickEvent</code>.
             * </p>
             */
            PickEvent();

            /**
             * <p>
             * Disposes of an instance of <code>PickEvent</code>.
             * </p>
             */
            virtual
            ~PickEvent();

            /**
             * <p>
             * Adds a hit made as a result of the pick.
             * </p>
             *
             * @param hit A hit made as a result of the pick.
             */
            void
            addHit(const Hit hit);

            /**
             * <p>
             * Retrieves the closest hit made as a result of the pick.
             * </p>
             *
             * @return The closest hit made as a result of the pick.
             */
            optional<Hit>
            getCloseHit();

            /**
             * <p>
             * Retrieves a hit made as a result of the pick.
             * </p>
             *
             * @param index The index of the hit to retrieve.
             *
             * @return A hit made as a result of the pick.
             */
            Hit
            getHit(const int index);

            /**
             * <p>
             * Retrieves the number of hits made as a result of the pick.
             * </p>
             *
             * @return The number of hits made as a result of the pick.
             */
            int
            getHitCount();

        private:
            /**
             * <p>
             * The hits made as a result of the pick.
             * </p>
             */
            vector<Hit> fHits;
    };
}

#endif /* PICKEVENT_H_ */
