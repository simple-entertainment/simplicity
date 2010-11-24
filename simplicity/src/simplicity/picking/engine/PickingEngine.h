/*
 This file is part of The Simplicity Engine.

 The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
 by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

 The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

 You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef PICKINGENGINE_H_
#define PICKINGENGINE_H_

namespace simplicity
{
    /**
     * <p>
     * Manages the picking of a {@link simplicity::SceneGraph SceneGraph}. Each advance processes the outstanding
     * {@link simplicity::Pick Pick}s, the results are fired to any {@link simplicity::PickListener PickListener}s in
     * the form of a {@link simplicity::PickEvent PickEvent}.
     * </p>
     *
     * @author Gary Buyn
     */
    class PickingEngine : public Engine
    {
        public:
            /**
             * <p>
             * Adds a {@link simplicity::PickListener PickListener} to be invoked when a {@link simplicity::SceneGraph
             * SceneGraph} is picked.
             * </p>
             *
             * @param listener A <code>PickListener</code> to be invoked when a <code>SceneGraph</code> is picked.
             */
            virtual void
            addPickListener(PickListener* const listener) = 0;

            /**
             * <p>
             * Performs the outstanding picks against a {@link simplicity::SceneGraph SceneGraph}.
             * </p>
             */
            virtual void
            advance() = 0;

            /**
             * <p>
             * Fires a {@link simplicity::PickEvent PickEvent} to all {@link simplicity::PickListener PickListener}s
             * for processing.
             * </p>
             *
             * @param event The <code>PickEvent</code> to be fired to all <code>PickListener</code>s.
             */
            virtual void
            firePickEvent(const PickEvent event) = 0;

            /**
             * <p>
             * Retrieves the viewpoint that will be adapted to create the picking viewpoint.
             * </p>
             *
             * @return The viewpoint that will be adapted to create the picking viewpoint.
             */
            virtual Camera
            getCamera() = 0;

            /**
             * <p>
             * Retrieves the {@link simplicity::Picker Picker} that picks the {@link simplicity::SceneGraph SceneGraph} for
             * this <code>PickingEngine</code>.
             * </p>
             *
             * @return The <code>Picker</code> that picks the <code>SceneGraph</code> for this <code>PickingEngine</code>.
             */
            virtual Picker
            getPicker() = 0;

            /**
             * <p>
             * Retrieves the outstanding picks to be performed against this <code>PickingEngine</code>'s {@link simplicity::SceneGraph
             * SceneGraph}.
             * </p>
             *
             * @return The outstanding picks to be performed against this <code>PickingEngine</code>'s <code>SceneGraph</code>.
             */
            virtual vector<Pick>
            getPicks() = 0;

            /**
             * <p>
             * Retrieves the {@link simplicity::Scene Scene} to be picked.
             * </p>
             *
             * @return The <code>Scene</code> to be picked.
             */
            virtual Scene*
            getScene() = 0;

            /**
             * <p>
             * Registers a pick at the given location and area relative to this <code>PickingEngine</code>'s {@link simplicity::Camera Camera}
             * in {@link simplicity::SceneGraph SceneGraph} coordinates.
             * </p>
             *
             * @param x The position on the <code>x</code> axis to pick.
             * @param y The position on the <code>y</code> axis to pick.
             * @param width The width of the area to pick.
             * @param height The height of the area to pick.
             */
            virtual void
            pick(const float x, const float y, const float width, const float height) = 0;

            /**
             * <p>
             * Registers a pick at the given location and area relative to this <code>PickingEngine</code>'s {@link simplicity::Camera Camera}
             * in {@link simplicity::SceneGraph SceneGraph} coordinates.
             * </p>
             *
             * @param pick The position and area to pick.
             */
            virtual void
            pick(const Pick pick) = 0;

            /**
             * <p>
             * Registers a pick at the given location of a viewport with the given dimensions.
             * </p>
             *
             * @param viewportSize The size of the viewport.
             * @param x The position on the <code>x</code> axis of the viewport to pick.
             * @param y The position on the <code>y</code> axis of the viewport to pick.
             * @param width The width of the area on the viewport to pick.
             * @param height The height of the area on the viewport to pick.
             */
            virtual void
            pickViewport(Dimension viewportSize, const int x, const int y, const int width, const int height) = 0;

            /**
             * <p>
             * Registers a pick at the given location and area of a viewport.
             * </p>
             *
             * @param viewportSize The size of the viewport.
             * @param pick The position and area of the viewport to pick.
             */
            virtual void
            pickViewport(Dimension viewportSize, const Pick pick) = 0;

            /**
             * <p>
             * Removes a {@link simplicity::PickListener PickListener} from those to be invoked when a
             * {@link simplicity::SceneGraph SceneGraph} is picked.
             * </p>
             *
             * @param listener A <code>PickListener</code> that was to be invoked when a <code>SceneGraph</code> is picked.
             */
            virtual void
            removePickListener(PickListener* const listener) = 0;

            /**
             * <p>
             * Sets the viewpoint that will be adapted to create the picking viewpoint.
             * </p>
             *
             * @param camera The viewpoint that will be adapted to create the picking viewpoint. The {@link simplicity::Camera Camera}
             * given will not be modified when creating the picking viewpoint.
             */
            virtual void
            setCamera(Camera* const camera) = 0;

            /**
             * <p>
             * Sets the {@link simplicity::Picker Picker} that picks the {@link simplicity::SceneGraph SceneGraph} for this
             * <code>PickingEngine</code>.
             * </p>
             *
             * @param picker The {@link simplicity::Picker Picker} that picks the {@link simplicity::SceneGraph SceneGraph}
             * for this <code>PickingEngine</code>.
             */
            virtual void
            setPicker(Picker* const picker) = 0;

            /**
             * <p>
             * Sets the {@link simplicity::Scene Scene} to be picked.
             * </p>
             *
             * @param scene The <code>Scene</code> to be picked.
             */
            virtual void
            setScene(Scene* const scene) = 0;
    };
}

#endif /* PICKINGENGINE_H_ */
