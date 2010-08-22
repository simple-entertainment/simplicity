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
import java.util.List;

import javax.media.opengl.GL;

import com.se.simplicity.jogl.JOGLComponent;
import com.se.simplicity.rendering.Camera;
import com.se.simplicity.rendering.Light;
import com.se.simplicity.scene.Scene;
import com.se.simplicity.scenegraph.SceneGraph;

/**
 * <p>
 * Wraps another <code>Scene</code> implementation (including JOGL support) and provides the ability to add meta data attributes.
 * </p>
 * 
 * <p>
 * This <code>MetaDataScene</code> will behave exactly as if you were acting on the <code>Scene</code> it is wrapping so the caller need not even know
 * that they are calling the <code>MetaDataScene</code>.
 * </p>
 * 
 * @author Gary Buyn
 */
public class MetaDataScene implements Scene, JOGLComponent, MetaData
{
    /**
     * <p>
     * The meta data attributes.
     * </p>
     */
    private Hashtable<String, Object> attributes;

    /**
     * <p>
     * The <code>Scene</code> that is wrapped by this <code>MetaDataScene</code>.
     * </p>
     */
    private Scene scene;

    /**
     * <p>
     * Creates an instance of <code>MetaDataScene</code>.
     * </p>
     * 
     * @param newScene The <code>Scene</code> that is wrapped by this <code>MetaDataScene</code>.
     */
    public MetaDataScene(final Scene newScene)
    {
        scene = newScene;

        attributes = new Hashtable<String, Object>();
    }

    @Override
    public void addCamera(final Camera newCamera)
    {
        scene.addCamera(newCamera);
    }

    @Override
    public void addLight(final Light newLight)
    {
        scene.addLight(newLight);
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
    public List<Camera> getCameras()
    {
        return (scene.getCameras());
    }

    @Override
    public GL getGL()
    {
        return (((JOGLComponent) scene).getGL());
    }

    @Override
    public List<Light> getLights()
    {
        return (scene.getLights());
    }

    @Override
    public SceneGraph getSceneGraph()
    {
        return (scene.getSceneGraph());
    }

    /**
     * <p>
     * Retrieves the <code>Scene</code> that is wrapped by this <code>MetaDataScene</code>.
     * </p>
     * 
     * @return The <code>Scene</code> that is wrapped by this <code>MetaDataScene</code>.
     */
    public Scene getWrappedScene()
    {
        return (scene);
    }

    @Override
    public void setAttribute(final String name, final Object value)
    {
        attributes.put(name, value);
    }

    @Override
    public void setCameras(final List<Camera> newCameras)
    {
        scene.setCameras(newCameras);
    }

    @Override
    public void setGL(final GL newGl)
    {
        ((JOGLComponent) scene).setGL(newGl);
    }

    @Override
    public void setLights(final List<Light> newLights)
    {
        scene.setLights(newLights);
    }

    @Override
    public void setSceneGraph(final SceneGraph newSceneGraph)
    {
        scene.setSceneGraph(newSceneGraph);
    }
}
