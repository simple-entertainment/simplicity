/*
 This file is part of The Simplicity Engine.

 The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
 by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

 The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

 You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef PICKADAPTER_H_
#define PICKADAPTER_H_

#include "PickListener.h"

namespace simplicity
{
    /**
     * <p>
     * An empty implementation of a {@link simplicity::PickListener PickListener} for convenience to facilitate extension.
     * </p>
     *
     * @author Gary Buyn
     */
    class PickAdapter : public PickListener
    {
        public:
            /**
             * <p>
             * Creates an instance of <code>PickAdapter</code>.
             * </p>
             */
            PickAdapter();

            /**
             * <p>
             * Disposes of an instance of <code>PickAdapter</code>.
             * </p>
             */
            virtual
            ~PickAdapter();

            void
            scenePicked(const PickEvent event);
    };
}

#endif /* PICKADAPTER_H_ */
