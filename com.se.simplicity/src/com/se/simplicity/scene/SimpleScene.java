/*
    This file is part of The Simplicity Engine.

    The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
    by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

    The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
package com.se.simplicity.scene;

import java.util.ArrayList;
import java.util.List;

import com.se.simplicity.rendering.Camera;
import com.se.simplicity.rendering.Light;
import com.se.simplicity.scenegraph.SceneGraph;

/**
 * <p>
 * A simple implementation of a {@link com.se.simplicity.scene.Scene Scene}.
 * </p>
 * 
 * @author Gary Buyn
 */
public class SimpleScene implements Scene
{
    /**
     * <p>
     * The {@link com.se.simplicity.rendering.Camera Camera}s that can be used to view this <code>Scene</code> from specific angles.
     * </p>
     */
    private List<Camera> fCameras;

    /**
     * <p>
     * The {@link com.se.simplicity.rendering.Light Light}s that can be used to illuminate this <code>Scene</code>.
     * </p>
     */
    private List<Light> fLights;

    /**
     * <p>
     * The {@link com.se.simplicity.scenegraph.SceneGraph SceneGraph} that describes the relative locations of this <code>Scene</code>'s content.
     * </p>
     */
    private SceneGraph fSceneGraph;

    /**
     * Creates an instance of <code>SimpleScene</code>.
     */
    public SimpleScene()
    {
        fCameras = new ArrayList<Camera>();
        fLights = new ArrayList<Light>();
        fSceneGraph = null;
    }

    @Override
    public void addCamera(final Camera camera)
    {
        fCameras.add(camera);
    }

    @Override
    public void addLight(final Light light)
    {
        fLights.add(light);
    }

    @Override
    public List<Camera> getCameras()
    {
        return (fCameras);
    }

    @Override
    public List<Light> getLights()
    {
        return (fLights);
    }

    @Override
    public SceneGraph getSceneGraph()
    {
        return (fSceneGraph);
    }

    @Override
    public void setCameras(final List<Camera> cameras)
    {
        fCameras = cameras;
    }

    @Override
    public void setLights(final List<Light> lights)
    {
        fLights = lights;
    }

    @Override
    public void setSceneGraph(final SceneGraph sceneGraph)
    {
        fSceneGraph = sceneGraph;
    }
}
