/*
 This file is part of The Simplicity Engine.

 The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
 by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

 The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

 You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef PICKER_H_
#define PICKER_H_

namespace simplicity
{
    /**
     * <p>
     * Picks {@link simplicity::Scene Scene}s. The <code>Scene</code> is picked based on a {@link simplicity::Camera Camera}
     * and a {@link simplicity::Pick Pick} that generally represents a subset of the <code>Camera</code>'s frame.
     * </p>
     *
     * @author Gary Buyn
     */
    class Picker
    {
        public:
            /**
             * <p>
             * Reverts the picking environment.
             * </p>
             */
            virtual void
            dispose() = 0;

            /**
             * <p>
             * Retrieves the {@link simplicity::DrawingMode DrawingMode} used to create {@link simplicity::PickEvent
             * PickEvent}s from the {@link simplicity::Scene Scene}.
             * </p>
             *
             * @return The <code>DrawingMode</code> used to create <code>PickEvent</code>s from the <code>Scene</code>.
             */
            virtual DrawingMode
            getDrawingMode() = 0;

            /**
             * <p>
             * Initialises the picking environment.
             * </p>
             */
            virtual void
            init() = 0;

            /**
             * <p>
             * Picks a {@link simplicity::Scene Scene} using the given {@link simplicity::Pick Pick} and basing the
             * <code>Pick</code> on the given {@link simplicity::Camera Camera}.
             * </p>
             *
             * @param scene The <code>Scene</code> to pick.
             * @param camera The <code>Camera</code> to base the pick on.
             * @param pick The <code>Pick</code> to apply to the <code>Scene</code>.
             *
             * @return An event containing any picked components of the <code>Scene</code>.
             */
            virtual PickEvent
            pickScene(Scene* const scene, Camera* const camera, const Pick pick) = 0;

            /**
             * <p>
             * Sets the drawing mode used to pick the {@link simplicity::Scene Scene}.
             * </p>
             *
             * @param mode The drawing mode used to pick the {@link simplicity::Scene Scene}.
             */
            virtual void
            setDrawingMode(const DrawingMode mode) = 0;
    };
}

#endif /* PICKER_H_ */
