/*
    This file is part of The Simplicity Engine.

    The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
    by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

    The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
package com.se.simplicity.util.metadata.rendering;

import java.util.Enumeration;
import java.util.Hashtable;

import javax.media.opengl.GL;

import com.se.simplicity.jogl.JOGLComponent;
import com.se.simplicity.picking.Pick;
import com.se.simplicity.rendering.Camera;
import com.se.simplicity.rendering.ProjectionMode;
import com.se.simplicity.scenegraph.Node;
import com.se.simplicity.util.metadata.MetaData;
import com.se.simplicity.vector.TransformationMatrixf;

/**
 * <p>
 * Wraps another <code>Camera</code> implementation (including JOGL support) and provides the ability to add meta data attributes.
 * </p>
 * 
 * <p>
 * This <code>MetaDataCamera</code> will behave exactly as if you were acting on the <code>Camera</code> it is wrapping so the caller need not even
 * know that they are calling the <code>MetaDataCamera</code>.
 * </p>
 * 
 * @author Gary Buyn
 */
public class MetaDataCamera implements Camera, JOGLComponent, MetaData
{
    /**
     * <p>
     * The meta data attributes.
     * </p>
     */
    private Hashtable<String, Object> attributes;

    /**
     * <p>
     * The <code>Camera</code> that is wrapped by this <code>MetaDataCamera</code>.
     * </p>
     */
    private Camera camera;

    /**
     * <p>
     * Creates an instance of <code>MetaDataCamera</code>.
     * </p>
     * 
     * @param newCamera The <code>Camera</code> that is wrapped by this <code>MetaDataCamera</code>.
     */
    public MetaDataCamera(final Camera newCamera)
    {
        camera = newCamera;

        attributes = new Hashtable<String, Object>();
    }

    @Override
    public void apply()
    {
        camera.apply();
    }

    @Override
    public Object getAttribute(final String name)
    {
        return (attributes.get(name));
    }

    @Override
    public Enumeration<String> getAttributeNames()
    {
        return (attributes.keys());
    }

    @Override
    public Enumeration<Object> getAttributes()
    {
        return (attributes.elements());
    }

    @Override
    public float getFarClippingDistance()
    {
        return (camera.getFarClippingDistance());
    }

    @Override
    public float getFrameHeight()
    {
        return (camera.getFrameHeight());
    }

    @Override
    public float getFrameWidth()
    {
        return (camera.getFrameWidth());
    }

    @Override
    public float getFrameX()
    {
        return (camera.getFrameX());
    }

    @Override
    public float getFrameY()
    {
        return (camera.getFrameY());
    }

    @Override
    public GL getGL()
    {
        return (((JOGLComponent) camera).getGL());
    }

    @Override
    public float getNearClippingDistance()
    {
        return (camera.getNearClippingDistance());
    }

    @Override
    public Node getNode()
    {
        return (camera.getNode());
    }

    @Override
    public Camera getPickCamera(final Pick pick)
    {
        return (camera.getPickCamera(pick));
    }

    @Override
    public ProjectionMode getProjectionMode()
    {
        return (camera.getProjectionMode());
    }

    @Override
    public TransformationMatrixf getTransformation()
    {
        return (camera.getTransformation());
    }

    /**
     * <p>
     * Retrieves the <code>Camera</code> that is wrapped by this <code>MetaDataCamera</code>.
     * </p>
     * 
     * @return The <code>Camera</code> that is wrapped by this <code>MetaDataCamera</code>.
     */
    public Camera getWrappedCamera()
    {
        return (camera);
    }

    @Override
    public void init()
    {
        camera.init();
    }

    @Override
    public boolean isInitialised()
    {
        return (camera.isInitialised());
    }

    @Override
    public void setAttribute(final String name, final Object value)
    {
        attributes.put(name, value);
    }

    @Override
    public void setFarClippingDistance(final float farClippingDistance)
    {
        camera.setFarClippingDistance(farClippingDistance);
    }

    @Override
    public void setFrameHeight(final float frameHeight)
    {
        camera.setFrameHeight(frameHeight);
    }

    @Override
    public void setFrameWidth(final float frameWidth)
    {
        camera.setFrameWidth(frameWidth);
    }

    @Override
    public void setFrameX(final float frameX)
    {
        camera.setFrameX(frameX);
    }

    @Override
    public void setFrameY(final float frameY)
    {
        camera.setFrameY(frameY);
    }

    @Override
    public void setGL(final GL gl)
    {
        ((JOGLComponent) camera).setGL(gl);
    }

    @Override
    public void setInitialised(final boolean initialised)
    {
        camera.setInitialised(initialised);
    }

    @Override
    public void setNearClippingDistance(final float nearClippingDistance)
    {
        camera.setNearClippingDistance(nearClippingDistance);
    }

    @Override
    public void setNode(final Node node)
    {
        camera.setNode(node);
    }

    @Override
    public void setProjectionMode(final ProjectionMode projectionMode)
    {
        camera.setProjectionMode(projectionMode);
    }

    @Override
    public float getFrameAspectRatio()
    {
        return (camera.getFrameAspectRatio());
    }

    @Override
    public void setFrameAspectRatio(final float frameAspectRatio)
    {
        camera.setFrameAspectRatio(frameAspectRatio);
    }
}
