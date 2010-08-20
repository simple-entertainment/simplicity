/*
    This file is part of The Simplicity Engine.

    The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
    by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

    The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
package com.se.simplicity.jogl.rendering;

import javax.media.opengl.GL;

import org.apache.log4j.Logger;

import com.se.simplicity.SEInvalidOperationException;
import com.se.simplicity.jogl.JOGLComponent;
import com.se.simplicity.picking.Pick;
import com.se.simplicity.rendering.Camera;
import com.se.simplicity.rendering.ProjectionMode;
import com.se.simplicity.scenegraph.Node;
import com.se.simplicity.vector.SimpleTransformationMatrixf44;
import com.se.simplicity.vector.TransformationMatrixf;

/**
 * <p>
 * A viewpoint within a <code>SceneGraph</code> rendered by a JOGL rendering environment. This implementation uses only simple camera techniques and
 * properties.
 * </p>
 * 
 * <p>
 * The viewing frustrum is the shape that contains all components of the <code>SceneGraph</code> displayed when viewing through a
 * <code>SimpleJOGLCamera</code>. The following diagram shows the 'side' and 'front' views of a viewing frustrum.
 * </p>
 * 
 * <pre>
 *              _______
 *       /|    |\     /|
 *      / |    | \___/ |
 * _\  |  |    | |   | |
 *  /  |  |    | |___| |
 *      \ |    | /   \ |
 *       \|    |/_____\|
 *   
 *   side        front
 * </pre>
 * 
 * <p>
 * <b>Eye</b>
 * </p>
 * 
 * <p>
 * The eye is the position of the viewer. The 'front' of the frustrum in the context of this explanation is the side of the frustrum that is closest
 * to the eye. In the 'side' view the eye is shown as the arrow to the left of the frustrum.
 * </p>
 * 
 * <p>
 * <b>Near Clipping Plane</b>
 * </p>
 * 
 * <p>
 * The near clipping plane is a plane in the <code>SceneGraph</code> a distance from the eye in front of which the viewer cannot see i.e. all
 * components of the <code>SceneGraph</code> nearer to the eye than the near clipping plane will be clipped (not drawn). The area on the near clipping
 * plane that constitutes a face of the frustrum is shown as the short vertical line in the 'side' view and the smaller rectangle in the 'front' view.
 * This face can be thought of as analogous to the screen and is referred to as the frame.
 * </p>
 * 
 * <p>
 * <b>Far Clipping Plane</b>
 * </p>
 * 
 * <p>
 * The far clipping plane is a plane in the <code>SceneGraph</code> a distance from the eye past which the viewer cannot see i.e. all components of
 * the <code>SceneGraph</code> further from the eye than the far clipping plane will be clipped (not drawn). The area on the far clipping plane that
 * constitutes a face of the frustrum is shown as the long vertical line in the 'side' view and the larger rectangle in the 'front' view.
 * </p>
 * 
 * <p>
 * <b>Frame Position and Dimensions</b>
 * </p>
 * 
 * <p>
 * The dimensions of the areas of the clipping planes that are used as faces of the frustrum are calculated automatically by the
 * <code>SimpleJOGLCamera</code>. The diagonal lines in the diagram extend from the four corners of the far clipping plane to the four corners of the
 * near clipping plane and finally (by default) converge at the eye. The frame can be moved on the <code>x</code> and <code>y</code> axis so that the
 * eye no longer resides at this convergence. Also, the aspect ratio of the frame (4:3 by default) can be changed.
 * </p>
 * 
 * @author Gary Buyn
 */
public class SimpleJOGLCamera implements Camera, JOGLComponent
{
    /**
     * <p>
     * The default far clipping plane.
     * </p>
     */
    private static final float DEFAULT_FAR_CLIPPING_PLANE = 1000.0f;

    /**
     * <p>
     * The default frame aspect ratio.
     * </p>
     */
    private static final float DEFAULT_FRAME_ASPECT_RATIO = 0.75f; // 3:4

    /**
     * <p>
     * The default frame width.
     * </p>
     */
    private static final float DEFAULT_FRAME_WIDTH = 0.1f;

    /**
     * <p>
     * The default near clipping plane.
     * </p>
     */
    private static final float DEFAULT_NEAR_CLIPPING_PLANE = 0.1f;

    /**
     * <p>
     * The distance from the eye past which components of the <code>SceneGraph</code> will be clipped (not drawn).
     * </p>
     */
    private float farClippingDistance;

    /**
     * <p>
     * The aspect ratio of the frame. An aspect ratio of 3:4 is stored as 3 / 4 (0.75).
     * </p>
     */
    private float frameAspectRatio;

    /**
     * <p>
     * The width of the frame.
     * </p>
     */
    private float frameWidth;

    /**
     * <p>
     * The location of the frame on the <code>x</code> axis relative to the location and orientation of this <code>SimpleJOGLCamera</code>.
     * </p>
     */
    private float frameX;

    /**
     * <p>
     * The location of the frame on the <code>y</code> axis relative to the location and orientation of this <code>SimpleJOGLCamera</code>.
     * </p>
     */
    private float frameY;

    /**
     * <p>
     * The JOGL rendering environment.
     * </p>
     */
    private GL gl;

    /**
     * The initialisation status. Determines if this <code>SimpleJOGLCamera</code> is initialised.
     */
    private boolean isInitialised;

    /**
     * <p>
     * Logs messages associated with this class.
     * </p>
     */
    private Logger logger;

    /**
     * <p>
     * The distance from the eye before which components of the <code>SceneGraph</code> will be clipped (not drawn).
     * </p>
     */
    private float nearClippingDistance;

    /**
     * <p>
     * The <code>Node</code> that represents this <code>SimpleJOGLCamera</code>'s location and orientation.
     * </p>
     */
    private Node node;

    /**
     * <p>
     * The projection mode used to render a <code>SceneGraph</code>.
     * </p>
     */
    private ProjectionMode projectionMode;

    /**
     * <p>
     * Creates an instance of <code>SimpleJOGLCamera</code>.
     * </p>
     */
    public SimpleJOGLCamera()
    {
        farClippingDistance = DEFAULT_FAR_CLIPPING_PLANE;
        frameAspectRatio = DEFAULT_FRAME_ASPECT_RATIO;
        frameWidth = DEFAULT_FRAME_WIDTH;
        frameX = 0.0f;
        frameY = 0.0f;
        isInitialised = false;
        logger = Logger.getLogger(getClass().getName());
        nearClippingDistance = DEFAULT_NEAR_CLIPPING_PLANE;
        node = null;
        projectionMode = ProjectionMode.PERSPECTIVE;
    }

    @Override
    public void apply()
    {
        if (!isInitialised)
        {
            init();
        }

        gl.glMultMatrixf(((SimpleTransformationMatrixf44) getTransformation()).getArray(), 0);
    }

    /**
     * <p>
     * Retrieves the distance from the eye past which components of the <code>SceneGraph</code> will be clipped (not drawn).
     * </p>
     * 
     * @return The distance from the eye past which components of the <code>SceneGraph</code> will be clipped (not drawn).
     */
    public float getFarClippingDistance()
    {
        return (farClippingDistance);
    }

    /**
     * <p>
     * Retrieves the aspect ratio of the frame.
     * </p>
     * 
     * @return The aspect ratio of the frame.
     */
    public float getFrameAspectRatio()
    {
        return (frameAspectRatio);
    }

    /**
     * <p>
     * Retrieves the width of the frame.
     * </p>
     * 
     * @return The width of the frame.
     */
    public float getFrameWidth()
    {
        return (frameWidth);
    }

    /**
     * <p>
     * Retrieves the location of the frame on the <code>x</code> axis relative to the location and orientation of this <code>SimpleJOGLCamera</code>.
     * </p>
     * 
     * @return The location of the frame on the <code>x</code> axis relative to the location and orientation of this <code>SimpleJOGLCamera</code>.
     */
    public float getFrameX()
    {
        return (frameX);
    }

    /**
     * <p>
     * Retrieves the location of the frame on the <code>y</code> axis relative to the location and orientation of this <code>SimpleJOGLCamera</code>.
     * </p>
     * 
     * @return The location of the frame on the <code>y</code> axis relative to the location and orientation of this <code>SimpleJOGLCamera</code>.
     */
    public float getFrameY()
    {
        return (frameY);
    }

    @Override
    public GL getGL()
    {
        return (gl);
    }

    /**
     * <p>
     * Retrieves the distance from the eye before which components of the <code>SceneGraph</code> will be clipped (not drawn).
     * </p>
     * 
     * @return The distance from the eye before which components of the <code>SceneGraph</code> will be clipped (not drawn).
     */
    public float getNearClippingDistance()
    {
        return (nearClippingDistance);
    }

    @Override
    public Node getNode()
    {
        return (node);
    }

    @Override
    public Camera getPickCamera(final Pick pick)
    {
        // Create the Camera to pick with.
        SimpleJOGLCamera pickCamera = new SimpleJOGLCamera();
        pickCamera.setFarClippingDistance(getFarClippingDistance());
        pickCamera.setFrameAspectRatio(getFrameAspectRatio());
        pickCamera.setFrameWidth(pick.getWidth());
        pickCamera.setFrameX(pick.getX() - (getFrameWidth() / 2) + getFrameX());
        pickCamera.setFrameY((getFrameWidth() * getFrameAspectRatio() / 2) - pick.getY() + getFrameY());
        pickCamera.setGL(getGL());
        pickCamera.setNearClippingDistance(getNearClippingDistance());
        pickCamera.setNode(getNode());

        return (pickCamera);
    }

    /**
     * <p>
     * Retrieves the projection mode used to render a <code>SceneGraph</code>.
     * </p>
     * 
     * @return The projection mode used to render a <code>SceneGraph</code>.
     */
    public ProjectionMode getProjectionMode()
    {
        return (projectionMode);
    }

    @Override
    public TransformationMatrixf getTransformation()
    {
        if (node == null)
        {
            return (null);
        }

        TransformationMatrixf transformation = new SimpleTransformationMatrixf44();
        Node currentNode = node;

        while (currentNode != null)
        {
            transformation.multiplyRight(currentNode.getTransformation());

            currentNode = currentNode.getParent();
        }

        try
        {
            transformation.invert();
        }
        catch (SEInvalidOperationException e)
        {
            logger.error("Failed to invert the transformation.", e);
        }

        return (transformation);
    }

    @Override
    public void init()
    {
        if (projectionMode == null)
        {
            throw new IllegalStateException("This Camera must have a projection mode to be initialised.");
        }

        gl.glMatrixMode(GL.GL_PROJECTION);

        gl.glLoadIdentity();
        gl.glFrustum(-frameWidth / 2 + frameX, frameWidth / 2 + frameX, -frameWidth * frameAspectRatio / 2 + frameY, frameWidth * frameAspectRatio
                / 2 + frameY, nearClippingDistance, farClippingDistance);

        gl.glMatrixMode(GL.GL_MODELVIEW);

        isInitialised = true;
    }

    @Override
    public boolean isInitialised()
    {
        return (isInitialised);
    }

    /**
     * <p>
     * Sets the distance from the eye past which components of the <code>SceneGraph</code> will be clipped (not drawn).
     * </p>
     * 
     * @param newFarClippingDistance The distance from the eye past which components of the <code>SceneGraph</code> will be clipped (not drawn).
     */
    public void setFarClippingDistance(final float newFarClippingDistance)
    {
        farClippingDistance = newFarClippingDistance;

        isInitialised = false;
    }

    /**
     * <p>
     * Sets the aspect ratio of the frame. An aspect ratio of 3:4 is stored as 3 / 4 (0.75).
     * </p>
     * 
     * @param newFrameAspectRatio The aspect ratio of the frame. An aspect ratio of 3:4 is stored as 3 / 4 (0.75).
     */
    public void setFrameAspectRatio(final float newFrameAspectRatio)
    {
        frameAspectRatio = newFrameAspectRatio;

        isInitialised = false;
    }

    /**
     * <p>
     * Sets the width of the frame.
     * </p>
     * 
     * @param newFrameWidth The width of the frame.
     */
    public void setFrameWidth(final float newFrameWidth)
    {
        frameWidth = newFrameWidth;

        isInitialised = false;
    }

    /**
     * <p>
     * Sets the location of the frame on the <code>x</code> axis relative to the location and orientation of this <code>SimpleJOGLCamera</code>.
     * </p>
     * 
     * @param newFrameX The location of the frame on the <code>x</code> axis relative to the location and orientation of this
     * <code>SimpleJOGLCamera</code>.
     */
    public void setFrameX(final float newFrameX)
    {
        frameX = newFrameX;

        isInitialised = false;
    }

    /**
     * <p>
     * Sets the location of the frame on the <code>y</code> axis relative to the location and orientation of this <code>SimpleJOGLCamera</code>.
     * </p>
     * 
     * @param newFrameY The location of the frame on the <code>y</code> axis relative to the location and orientation of this
     * <code>SimpleJOGLCamera</code>.
     */
    public void setFrameY(final float newFrameY)
    {
        frameY = newFrameY;

        isInitialised = false;
    }

    @Override
    public void setGL(final GL newGl)
    {
        gl = newGl;

        isInitialised = false;
    }

    @Override
    public void setInitialised(final boolean newIsInitialised)
    {
        isInitialised = newIsInitialised;
    }

    /**
     * <p>
     * Sets the distance from the eye before which components of the <code>SceneGraph</code> will be clipped (not drawn).
     * </p>
     * 
     * @param newNearClippingDistance The distance from the eye before which components of the <code>SceneGraph</code> will be clipped (not drawn).
     */
    public void setNearClippingDistance(final float newNearClippingDistance)
    {
        nearClippingDistance = newNearClippingDistance;

        isInitialised = false;
    }

    @Override
    public void setNode(final Node newNode)
    {
        node = newNode;
    }

    /**
     * <p>
     * Sets the projection mode used to render a <code>SceneGraph</code>.
     * </p>
     * 
     * @param newProjectionMode The projection mode used to render a <code>SceneGraph</code>.
     */
    public void setProjectionMode(final ProjectionMode newProjectionMode)
    {
        projectionMode = newProjectionMode;
    }
}
