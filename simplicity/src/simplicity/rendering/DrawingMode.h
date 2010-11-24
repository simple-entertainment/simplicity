/*
 This file is part of The Simplicity Engine.

 The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
 by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

 The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

 You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef DRAWINGMODE_H_
#define DRAWINGMODE_H_

namespace simplicity
{
    /**
     * <p>
     * The drawing mode used to render a {@link simplicity::SceneGraph SceneGraph}. The modes are as follows:
     * </p>
     *
     * @author Gary Buyn
     */
    enum DrawingMode
    {
        /**
         * <p>
         * Renders only the edges of the models.
         * </p>
         */
        EDGES,

        /**
         * <p>
         * Renders only the faces of the models.
         * </p>
         */
        FACES,

        /**
         * <p>
         * Renders only the vertices of the models.
         * </p>
         */
        VERTICES
    };
}

#endif /* DRAWINGMODE_H_ */
