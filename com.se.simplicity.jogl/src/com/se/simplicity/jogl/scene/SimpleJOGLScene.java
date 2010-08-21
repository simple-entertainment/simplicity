/*
    This file is part of The Simplicity Engine.

    The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
    by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

    The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
package com.se.simplicity.jogl.scene;

import java.util.List;

import javax.media.opengl.GL;

import com.se.simplicity.jogl.JOGLComponent;
import com.se.simplicity.rendering.Camera;
import com.se.simplicity.rendering.Light;
import com.se.simplicity.scene.SimpleScene;

/**
 * <p>
 * A simple implementation of a {@link com.se.simplicity.scene.Scene Scene}.
 * </p>
 * 
 * @author Gary Buyn
 */
public class SimpleJOGLScene extends SimpleScene implements JOGLComponent
{
    /**
     * <p>
     * The JOGL rendering environment.
     * </p>
     */
    private GL gl;

    @Override
    public void addCamera(final Camera newCamera)
    {
        super.addCamera(newCamera);

        ((JOGLComponent) newCamera).setGL(getGL());
    }

    @Override
    public void addLight(final Light newLight)
    {
        super.addLight(newLight);

        ((JOGLComponent) newLight).setGL(getGL());
    }

    @Override
    public GL getGL()
    {
        return (gl);
    }

    @Override
    public void setCameras(final List<Camera> newCameras)
    {
        super.setCameras(newCameras);

        for (Camera camera : newCameras)
        {
            ((JOGLComponent) camera).setGL(getGL());
        }
    }

    @Override
    public void setGL(final GL newGl)
    {
        gl = newGl;

        for (Camera camera : getCameras())
        {
            ((JOGLComponent) camera).setGL(getGL());
        }

        for (Light light : getLights())
        {
            ((JOGLComponent) light).setGL(getGL());
        }
    }

    @Override
    public void setLights(final List<Light> newLights)
    {
        super.setLights(newLights);

        for (Light light : newLights)
        {
            ((JOGLComponent) light).setGL(getGL());
        }
    }
}
