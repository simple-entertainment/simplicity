/*
 This file is part of The Simplicity Engine.

 The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
 by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

 The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

 You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef CAMERA_H_
#define CAMERA_H_

#include "../picking/Pick.h"
#include "../scenegraph/Node.h"
#include "../vector/TransformationMatrixf.h"
#include "ProjectionMode.h"

namespace simplicity
{
    /**
     * <p>
     * A viewpoint within a {@link simplicity::SceneGraph SceneGraph}.
     * </p>
     *
     * @author Gary Buyn
     */
    class Camera
    {
        public:
            /**
             * <p>
             * Applies this <code>Camera</code> to the rendering environment.
             * </p>
             */
            virtual void
            apply() = 0;

            /**
             * <p>
             * Retrieves the distance from the eye past which components of the {@link com.se.simplicity.scenegraph.SceneGraph SceneGraph} will be clipped
             * (not drawn).
             * </p>
             *
             * @return The distance from the eye past which components of the <code>SceneGraph</code> will be clipped (not drawn).
             */
            virtual float
            getFarClippingDistance() = 0;

            /**
             * <p>
             * Retrieves the aspect ratio of the frame.
             * </p>
             *
             * @return The aspect ratio of the frame.
             */
            virtual float
            getFrameAspectRatio() = 0;

            /**
             * <p>
             * Retrieves the height of the frame.
             * </p>
             *
             * @return The height of the frame.
             */
            virtual float
            getFrameHeight() = 0;

            /**
             * <p>
             * Retrieves the width of the frame.
             * </p>
             *
             * @return The width of the frame.
             */
            virtual float
            getFrameWidth() = 0;

            /**
             * <p>
             * Retrieves the location of the frame on the <code>x</code> axis relative to the location and orientation of this <code>Camera</code>.
             * </p>
             *
             * @return The location of the frame on the <code>x</code> axis relative to the location and orientation of this <code>Camera</code>.
             */
            virtual float
            getFrameX() = 0;

            /**
             * <p>
             * Retrieves the location of the frame on the <code>y</code> axis relative to the location and orientation of this <code>Camera</code>.
             * </p>
             *
             * @return The location of the frame on the <code>y</code> axis relative to the location and orientation of this <code>Camera</code>.
             */
            virtual float
            getFrameY() = 0;

            /**
             * <p>
             * Retrieves the distance from the eye before which components of the {@link com.se.simplicity.scenegraph.SceneGraph SceneGraph} will be clipped
             * (not drawn).
             * </p>
             *
             * @return The distance from the eye before which components of the <code>SceneGraph</code> will be clipped (not drawn).
             */
            virtual float
            getNearClippingDistance() = 0;

            /**
             * <p>
             * Retrieves the {@link com.se.simplicity.scenegraph.Node Node} that represents this <code>Camera</code>'s location and orientation.
             * </p>
             *
             * @return The <code>Node</code> that represents this <code>Camera</code>'s location and orientation.
             */
            virtual Node*
            getNode() = 0;

            /**
             * <p>
             * Retrieves a picking viewpoint adapted from this <code>Camera</code>'s viewpoint.
             * </p>
             *
             * @param pick The pick to create the viewpoint for.
             *
             * @return The picking viewpoint.
             */
            virtual Camera*
            getPickCamera(const Pick pick) = 0;

            /**
             * <p>
             * Retrieves the projection mode used to render a {@link com.se.simplicity.scene.Scene Scene}.
             * </p>
             *
             * @return The projection mode used to render a <code>Scene</code>.
             */
            virtual ProjectionMode
            getProjectionMode() = 0;

            /**
             * <p>
             * Retrieves the inverted absolute transformation for the {@link com.se.simplicity.scenegraph.Node Node} of this <code>Camera</code>.
             * </p>
             *
             * @return The inverted absolute transformation for the <code>Node</code> of this <code>Camera</code>, or null if the <code>Node</code> does not
             * exist.
             */
            virtual TransformationMatrixf*
            getTransformation() = 0;

            /**
             * <p>
             * Initialises this <code>Camera</code>.
             * </p>
             */
            virtual void
            init() = 0;

            /**
             * <p>
             * Determines if this <code>Camera</code> is initialised.
             * </p>
             *
             * @return True if this <code>Camera</code> is initialised, false otherwise.
             */
            virtual bool
            isInitialised() = 0;

            /**
             * <p>
             * Sets the distance from the eye past which components of the {@link com.se.simplicity.scenegraph.SceneGraph SceneGraph} will be clipped (not
             * drawn).
             * </p>
             *
             * @param farClippingDistance The distance from the eye past which components of the <code>SceneGraph</code> will be clipped (not drawn).
             */
            virtual void
            setFarClippingDistance(const float farClippingDistance) = 0;

            /**
             * <p>
             * Sets the aspect ratio of the frame.
             * </p>
             *
             * @param frameAspectRatio The aspect ratio of the frame.
             */
            virtual void
            setFrameAspectRatio(const float frameAspectRatio) = 0;

            /**
             * <p>
             * Sets the height of the frame.
             * </p>
             *
             * @param frameHeight The height of the frame.
             */
            virtual void
            setFrameHeight(const float frameHeight) = 0;

            /**
             * <p>
             * Sets the width of the frame.
             * </p>
             *
             * @param frameWidth The width of the frame.
             */
            virtual void
            setFrameWidth(const float frameWidth) = 0;

            /**
             * <p>
             * Sets the location of the frame on the <code>x</code> axis relative to the location and orientation of this <code>Camera</code>.
             * </p>
             *
             * @param frameX The location of the frame on the <code>x</code> axis relative to the location and orientation of this <code>Camera</code>.
             */
            virtual void
            setFrameX(const float frameX) = 0;

            /**
             * <p>
             * Sets the location of the frame on the <code>y</code> axis relative to the location and orientation of this <code>Camera</code>.
             * </p>
             *
             * @param frameY The location of the frame on the <code>y</code> axis relative to the location and orientation of this <code>Camera</code>.
             */
            virtual void
            setFrameY(const float frameY) = 0;

            /**
             * <p>
             * Sets the initialisation status.
             * </p>
             *
             * @param isInitialised Determines if this <code>Camera</code> is initialised.
             */
            virtual void
            setInitialised(const bool isInitialised) = 0;

            /**
             * <p>
             * Sets the distance from the eye before which components of the {@link com.se.simplicity.scenegraph.SceneGraph SceneGraph} will be clipped (not
             * drawn).
             * </p>
             *
             * @param nearClippingDistance The distance from the eye before which components of the <code>SceneGraph</code> will be clipped (not drawn).
             */
            virtual void
            setNearClippingDistance(const float nearClippingDistance) = 0;

            /**
             * <p>
             * Sets the {@link com.se.simplicity.scenegraph.Node Node} that represents this <code>Camera</code>'s location and orientation.
             * </p>
             *
             * @param node The <code>Node</code> that represents this <code>Camera</code>'s location and orientation.
             */
            virtual void
            setNode(Node* const node) = 0;

            /**
             * <p>
             * Sets the projection mode used to render a {@link com.se.simplicity.scene.Scene Scene}.
             * </p>
             *
             * @param projectionMode The projection mode used to render a <code>Scene</code>.
             */
            virtual void
            setProjectionMode(const ProjectionMode projectionMode) = 0;
    };
}

#endif /* CAMERA_H_ */