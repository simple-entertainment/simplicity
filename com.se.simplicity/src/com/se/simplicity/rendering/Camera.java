/*
    This file is part of The Simplicity Engine.

    The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
    by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

    The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
package com.se.simplicity.rendering;

import com.se.simplicity.picking.Pick;
import com.se.simplicity.scenegraph.Node;
import com.se.simplicity.vector.TransformationMatrixf;

/**
 * <p>
 * A viewpoint within a {@link com.se.simplicity.scene.Scene Scene}.
 * </p>
 * 
 * @author Gary Buyn
 */
public interface Camera
{
    /**
     * <p>
     * Applies this <code>Camera</code> to the rendering environment.
     * </p>
     */
    void apply();

    /**
     * <p>
     * Retrieves the distance from the eye past which components of the {@link com.se.simplicity.scenegraph.SceneGraph SceneGraph} will be clipped
     * (not drawn).
     * </p>
     * 
     * @return The distance from the eye past which components of the <code>SceneGraph</code> will be clipped (not drawn).
     */
    float getFarClippingDistance();

    /**
     * <p>
     * Retrieves the aspect ratio of the frame.
     * </p>
     * 
     * @return The aspect ratio of the frame.
     */
    float getFrameAspectRatio();

    /**
     * <p>
     * Retrieves the height of the frame.
     * </p>
     * 
     * @return The height of the frame.
     */
    float getFrameHeight();

    /**
     * <p>
     * Retrieves the width of the frame.
     * </p>
     * 
     * @return The width of the frame.
     */
    float getFrameWidth();

    /**
     * <p>
     * Retrieves the location of the frame on the <code>x</code> axis relative to the location and orientation of this <code>Camera</code>.
     * </p>
     * 
     * @return The location of the frame on the <code>x</code> axis relative to the location and orientation of this <code>Camera</code>.
     */
    float getFrameX();

    /**
     * <p>
     * Retrieves the location of the frame on the <code>y</code> axis relative to the location and orientation of this <code>Camera</code>.
     * </p>
     * 
     * @return The location of the frame on the <code>y</code> axis relative to the location and orientation of this <code>Camera</code>.
     */
    float getFrameY();

    /**
     * <p>
     * Retrieves the distance from the eye before which components of the {@link com.se.simplicity.scenegraph.SceneGraph SceneGraph} will be clipped
     * (not drawn).
     * </p>
     * 
     * @return The distance from the eye before which components of the <code>SceneGraph</code> will be clipped (not drawn).
     */
    float getNearClippingDistance();

    /**
     * <p>
     * Retrieves the {@link com.se.simplicity.scenegraph.Node Node} that represents this <code>Camera</code>'s location and orientation.
     * </p>
     * 
     * @return The <code>Node</code> that represents this <code>Camera</code>'s location and orientation.
     */
    Node getNode();

    /**
     * <p>
     * Retrieves a picking viewpoint adapted from this <code>Camera</code>'s viewpoint.
     * </p>
     * 
     * @param pick The pick to create the viewpoint for.
     * 
     * @return The picking viewpoint.
     */
    Camera getPickCamera(Pick pick);

    /**
     * <p>
     * Retrieves the projection mode used to render a {@link com.se.simplicity.scene.Scene Scene}.
     * </p>
     * 
     * @return The projection mode used to render a <code>Scene</code>.
     */
    ProjectionMode getProjectionMode();

    /**
     * <p>
     * Retrieves the inverted absolute transformation for the {@link com.se.simplicity.scenegraph.Node Node} of this <code>Camera</code>.
     * </p>
     * 
     * @return The inverted absolute transformation for the <code>Node</code> of this <code>Camera</code>, or null if the <code>Node</code> does not
     * exist.
     */
    TransformationMatrixf getTransformation();

    /**
     * <p>
     * Initialises this <code>Camera</code>.
     * </p>
     */
    void init();

    /**
     * <p>
     * Determines if this <code>Camera</code> is initialised.
     * </p>
     * 
     * @return True if this <code>Camera</code> is initialised, false otherwise.
     */
    boolean isInitialised();

    /**
     * <p>
     * Sets the distance from the eye past which components of the {@link com.se.simplicity.scenegraph.SceneGraph SceneGraph} will be clipped (not
     * drawn).
     * </p>
     * 
     * @param farClippingDistance The distance from the eye past which components of the <code>SceneGraph</code> will be clipped (not drawn).
     */
    void setFarClippingDistance(float farClippingDistance);

    /**
     * <p>
     * Sets the aspect ratio of the frame.
     * </p>
     * 
     * @param frameAspectRatio The aspect ratio of the frame.
     */
    void setFrameAspectRatio(float frameAspectRatio);

    /**
     * <p>
     * Sets the height of the frame.
     * </p>
     * 
     * @param frameHeight The height of the frame.
     */
    void setFrameHeight(float frameHeight);

    /**
     * <p>
     * Sets the width of the frame.
     * </p>
     * 
     * @param frameWidth The width of the frame.
     */
    void setFrameWidth(float frameWidth);

    /**
     * <p>
     * Sets the location of the frame on the <code>x</code> axis relative to the location and orientation of this <code>Camera</code>.
     * </p>
     * 
     * @param frameX The location of the frame on the <code>x</code> axis relative to the location and orientation of this <code>Camera</code>.
     */
    void setFrameX(float frameX);

    /**
     * <p>
     * Sets the location of the frame on the <code>y</code> axis relative to the location and orientation of this <code>Camera</code>.
     * </p>
     * 
     * @param frameY The location of the frame on the <code>y</code> axis relative to the location and orientation of this <code>Camera</code>.
     */
    void setFrameY(float frameY);

    /**
     * <p>
     * Sets the initialisation status.
     * </p>
     * 
     * @param isInitialised Determines if this <code>Camera</code> is initialised.
     */
    void setInitialised(boolean isInitialised);

    /**
     * <p>
     * Sets the distance from the eye before which components of the {@link com.se.simplicity.scenegraph.SceneGraph SceneGraph} will be clipped (not
     * drawn).
     * </p>
     * 
     * @param nearClippingDistance The distance from the eye before which components of the <code>SceneGraph</code> will be clipped (not drawn).
     */
    void setNearClippingDistance(float nearClippingDistance);

    /**
     * <p>
     * Sets the {@link com.se.simplicity.scenegraph.Node Node} that represents this <code>Camera</code>'s location and orientation.
     * </p>
     * 
     * @param node The <code>Node</code> that represents this <code>Camera</code>'s location and orientation.
     */
    void setNode(Node node);

    /**
     * <p>
     * Sets the projection mode used to render a {@link com.se.simplicity.scene.Scene Scene}.
     * </p>
     * 
     * @param projectionMode The projection mode used to render a <code>Scene</code>.
     */
    void setProjectionMode(ProjectionMode projectionMode);
}
