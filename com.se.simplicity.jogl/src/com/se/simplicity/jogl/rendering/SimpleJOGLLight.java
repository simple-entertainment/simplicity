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
import com.se.simplicity.rendering.Light;
import com.se.simplicity.rendering.LightingMode;
import com.se.simplicity.scenegraph.Node;
import com.se.simplicity.vector.ArrayBackedObjectf;
import com.se.simplicity.vector.TransformationMatrixf;

/**
 * <p>
 * A light within a <code>SceneGraph</code> rendered by a JOGL rendering environment. This implementation uses only simple lighting techniques and
 * properties.
 * </p>
 * 
 * @author Gary Buyn
 */
public class SimpleJOGLLight implements Light, JOGLComponent
{
    /**
     * <p>
     * The ambient component of this <code>Light</code>.
     * </p>
     */
    private float[] fAmbientLight;

    /**
     * <p>
     * The diffuse component of this <code>Light</code>.
     * </p>
     */
    private float[] fDiffuseLight;

    /**
     * <p>
     * The JOGL rendering environment.
     * </p>
     */
    private GL fGl;

    /**
     * <p>
     * The initialisation status. Determines if this <code>Light</code> is initialised.
     * </p>
     */
    private boolean fIsInitialised;

    /**
     * <p>
     * The lighting mode used to render the {@link com.se.simplicity.scenegraph.SceneGraph SceneGraph}.
     * </p>
     */
    private LightingMode fLightingMode;

    /**
     * <p>
     * Logs messages associated with this class.
     * </p>
     */
    private Logger fLogger;

    /**
     * <p>
     * The node that represents this <code>Light</code>'s location and orientation of this light.
     * </p>
     */
    private Node fNode;

    /**
     * <p>
     * The specular component of this <code>Light</code>.
     * </p>
     */
    private float[] fSpecularLight;

    /**
     * <p>
     * Creates an instance of <code>SimpleJOGLLight</code>.
     * </p>
     */
    public SimpleJOGLLight()
    {
        fAmbientLight = new float[] {0.0f, 0.0f, 0.0f, 1.0f};
        fDiffuseLight = new float[] {0.0f, 0.0f, 0.0f, 1.0f};
        fIsInitialised = false;
        fLightingMode = LightingMode.SCENE;
        fLogger = Logger.getLogger(getClass().getName());
        fNode = null;
        fSpecularLight = new float[] {0.0f, 0.0f, 0.0f, 1.0f};
    }

    @Override
    public void apply()
    {
        if (!fIsInitialised)
        {
            init();
        }

        TransformationMatrixf transformation = getTransformation();

        fGl.glLightfv(GL.GL_LIGHT0, GL.GL_POSITION, ((ArrayBackedObjectf) transformation.getTranslation()).getArray(), 0);
        fGl.glLightfv(GL.GL_LIGHT0, GL.GL_AMBIENT, fAmbientLight, 0);
        fGl.glLightfv(GL.GL_LIGHT0, GL.GL_DIFFUSE, fDiffuseLight, 0);
        fGl.glLightfv(GL.GL_LIGHT0, GL.GL_SPECULAR, fSpecularLight, 0);
    }

    @Override
    public float[] getAmbientLight()
    {
        return (fAmbientLight);
    }

    @Override
    public float[] getDiffuseLight()
    {
        return (fDiffuseLight);
    }

    @Override
    public GL getGL()
    {
        return (fGl);
    }

    @Override
    public LightingMode getLightingMode()
    {
        return (fLightingMode);
    }

    @Override
    public Node getNode()
    {
        return (fNode);
    }

    @Override
    public float[] getSpecularLight()
    {
        return (fSpecularLight);
    }

    @Override
    public TransformationMatrixf getTransformation()
    {
        if (fNode == null)
        {
            return (null);
        }

        TransformationMatrixf transformation = fNode.getAbsoluteTransformation();

        try
        {
            transformation.invert();
        }
        catch (SEInvalidOperationException e)
        {
            fLogger.error("Failed to invert the transformation.", e);
        }

        return (transformation);
    }

    @Override
    public void init()
    {
        if (fLightingMode == LightingMode.SOLID)
        {
            fGl.glDisable(GL.GL_LIGHTING);
            fGl.glDisable(GL.GL_COLOR_MATERIAL);
            fGl.glDisable(GL.GL_LIGHT0);
        }

        if (fLightingMode == LightingMode.SHADED)
        {
            fGl.glEnable(GL.GL_LIGHTING);
            fGl.glEnable(GL.GL_COLOR_MATERIAL);
            fGl.glColorMaterial(GL.GL_FRONT_AND_BACK, GL.GL_AMBIENT_AND_DIFFUSE);
            fGl.glLightfv(GL.GL_LIGHT0, GL.GL_AMBIENT, new float[] {0.1f, 0.1f, 0.1f, 1.0f}, 0);
            fGl.glLightfv(GL.GL_LIGHT0, GL.GL_DIFFUSE, new float[] {0.1f, 0.1f, 0.1f, 1.0f}, 0);
            fGl.glLightfv(GL.GL_LIGHT0, GL.GL_SPECULAR, new float[] {0.1f, 0.1f, 0.1f, 1.0f}, 0);
            fGl.glEnable(GL.GL_LIGHT0);
        }

        if (fLightingMode == LightingMode.SCENE)
        {
            fGl.glEnable(GL.GL_LIGHTING);
            fGl.glEnable(GL.GL_COLOR_MATERIAL);
            fGl.glColorMaterial(GL.GL_FRONT_AND_BACK, GL.GL_AMBIENT_AND_DIFFUSE);
            fGl.glEnable(GL.GL_LIGHT0);
        }

        fIsInitialised = true;
    }

    @Override
    public boolean isInitialised()
    {
        return (fIsInitialised);
    }

    @Override
    public void setAmbientLight(final float[] ambientLight)
    {
        fAmbientLight = ambientLight;
    }

    @Override
    public void setDiffuseLight(final float[] diffuseLight)
    {
        fDiffuseLight = diffuseLight;
    }

    @Override
    public void setGL(final GL newGl)
    {
        fGl = newGl;
    }

    @Override
    public void setInitialised(final boolean isInitialised)
    {
        fIsInitialised = isInitialised;
    }

    @Override
    public void setLightingMode(final LightingMode lightingMode)
    {
        fLightingMode = lightingMode;

        fIsInitialised = false;
    }

    @Override
    public void setNode(final Node newNode)
    {
        fNode = newNode;
    }

    @Override
    public void setSpecularLight(final float[] specularLight)
    {
        fSpecularLight = specularLight;
    }
}
