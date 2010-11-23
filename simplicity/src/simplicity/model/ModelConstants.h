/*
 This file is part of The Simplicity Engine.

 The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
 by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

 The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

 You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef MODELCONSTANTS_H_
#define MODELCONSTANTS_H_

namespace simplicity
{
    /**
     * <p>
     * Constants often used by objects that manipulate {@link simplicity::Model Model}s.
     * </p>
     *
     * @author Gary Buyn
     */
    class ModelConstants
    {
        public:
            /**
             * <p>
             * The number of data items in a colour, normal or vertex array required to represent one vertex.
             * </p>
             */
            static const int ITEMS_IN_CNV = 3;

            /**
             * <p>
             * The number of vertices in a face.
             * </p>
             */
            static const int VERTICES_IN_A_FACE = 3;

            /**
             * <p>
             * The number of data items in a colour, normal or vertex array required to represent one face.
             * </p>
             */
            static const int CNV_ITEMS_IN_FACE = VERTICES_IN_A_FACE * ITEMS_IN_CNV;
    };
}

#endif /* MODELCONSTANTS_H_ */
