/*
    This file is part of The Simplicity Engine.

    The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
    by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

    The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
package com.se.simplicity.editor.model.scene;

import java.util.Enumeration;
import java.util.Hashtable;

import javax.media.opengl.GL;

import com.se.simplicity.jogl.JOGLComponent;
import com.se.simplicity.rendering.Light;
import com.se.simplicity.rendering.LightingMode;
import com.se.simplicity.scenegraph.Node;
import com.se.simplicity.vector.TransformationMatrixf;

/**
 * <p>
 * Wraps another <code>Light</code> implementation (including JOGL support) and provides the ability to add meta data attributes.
 * </p>
 * 
 * <p>
 * This <code>MetaDataLight</code> will behave exactly as if you were acting on the <code>Light</code> it is wrapping so the caller need not even know
 * that they are calling the <code>MetaDataLight</code>.
 * </p>
 * 
 * @author Gary Buyn
 */
public class MetaDataLight implements Light, JOGLComponent, MetaData
{
    /**
     * <p>
     * The meta data attributes.
     * </p>
     */
    private Hashtable<String, Object> attributes;

    /**
     * <p>
     * The <code>Light</code> that is wrapped by this <code>MetaDataLight</code>.
     * </p>
     */
    private Light light;

    /**
     * <p>
     * Creates an instance of <code>MetaDataLight</code>.
     * </p>
     * 
     * @param newLight The <code>Light</code> that is wrapped by this <code>MetaDataLight</code>.
     */
    public MetaDataLight(final Light newLight)
    {
        light = newLight;

        attributes = new Hashtable<String, Object>();
    }

    @Override
    public void apply()
    {
        light.apply();
    }

    @Override
    public float[] getAmbientLight()
    {
        return (light.getAmbientLight());
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
    public float[] getDiffuseLight()
    {
        return (light.getDiffuseLight());
    }

    @Override
    public GL getGL()
    {
        return (((JOGLComponent) light).getGL());
    }

    @Override
    public LightingMode getLightingMode()
    {
        return (light.getLightingMode());
    }

    @Override
    public Node getNode()
    {
        return (light.getNode());
    }

    @Override
    public float[] getSpecularLight()
    {
        return (light.getSpecularLight());
    }

    @Override
    public TransformationMatrixf getTransformation()
    {
        return (light.getTransformation());
    }

    /**
     * <p>
     * Retrieves the <code>Light</code> that is wrapped by this <code>MetaDataLight</code>.
     * </p>
     * 
     * @return The <code>Light</code> that is wrapped by this <code>MetaDataLight</code>.
     */
    public Light getWrappedLight()
    {
        return (light);
    }

    @Override
    public void init()
    {
        light.init();
    }

    @Override
    public boolean isInitialised()
    {
        return (light.isInitialised());
    }

    @Override
    public void setAmbientLight(final float[] newAmbientLight)
    {
        light.setAmbientLight(newAmbientLight);
    }

    @Override
    public void setAttribute(final String name, final Object value)
    {
        attributes.put(name, value);
    }

    @Override
    public void setDiffuseLight(final float[] newDiffuseLight)
    {
        light.setDiffuseLight(newDiffuseLight);
    }

    @Override
    public void setGL(final GL newGl)
    {
        ((JOGLComponent) light).setGL(newGl);
    }

    @Override
    public void setInitialised(final boolean newInitialised)
    {
        light.setInitialised(newInitialised);
    }

    @Override
    public void setLightingMode(final LightingMode newLightingMode)
    {
        light.setLightingMode(newLightingMode);
    }

    @Override
    public void setNode(final Node newNode)
    {
        light.setNode(newNode);
    }

    @Override
    public void setSpecularLight(final float[] newSpecularLight)
    {
        light.setSpecularLight(newSpecularLight);
    }
}
