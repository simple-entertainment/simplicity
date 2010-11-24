/*
    This file is part of The Simplicity Engine.

    The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
    by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

    The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
package com.se.simplicity.scene;

import java.util.List;

import com.se.simplicity.rendering.Camera;
import com.se.simplicity.rendering.Light;
import com.se.simplicity.scenegraph.SceneGraph;

/**
 * <p>
 * A 3D environment.
 * </p>
 * 
 * @author Gary Buyn
 */
public interface Scene
{
    /**
     * <p>
     * Adds a {@link com.se.simplicity.rendering.Camera Camera}s that can be used to view this <code>Scene</code> from specific angles.
     * </p>
     * 
     * @param camera The <code>Camera</code>s that can be used to view this <code>Scene</code> from specific angles.
     */
    void addCamera(Camera camera);

    /**
     * <p>
     * Adds a {@link com.se.simplicity.rendering.Light Light} that can be used to illuminate this <code>Scene</code>.
     * </p>
     * 
     * @param light The <code>Light</code> that can be used to illuminate this <code>Scene</code>.
     */
    void addLight(Light light);

    /**
     * <p>
     * Retrieves the {@link com.se.simplicity.rendering.Camera Camera}s that can be used to view this <code>Scene</code> from specific angles.
     * </p>
     * 
     * @return The <code>Camera</code>s that can be used to view this <code>Scene</code> from specific angles.
     */
    List<Camera> getCameras();

    /**
     * <p>
     * Retrieves the {@link com.se.simplicity.rendering.Light Light}s that can be used to illuminate this <code>Scene</code>.
     * </p>
     * 
     * @return The <code>Light</code>s that can be used to illuminate this <code>Scene</code>.
     */
    List<Light> getLights();

    /**
     * <p>
     * Retrieves the {@link com.se.simplicity.scenegraph.SceneGraph SceneGraph} that describes the relative locations of this <code>Scene</code>'s
     * content.
     * </p>
     * 
     * @return The <code>SceneGraph</code> that describes the relative locations of this <code>Scene</code>'s content.
     */
    SceneGraph getSceneGraph();

    /**
     * <p>
     * Sets the {@link com.se.simplicity.rendering.Camera Camera}s that can be used to view this <code>Scene</code> from specific angles.
     * </p>
     * 
     * @param cameras The <code>Camera</code>s that can be used to view this <code>Scene</code> from specific angles.
     */
    void setCameras(List<Camera> cameras);

    /**
     * <p>
     * Sets the {@link com.se.simplicity.rendering.Light Light}s that can be used to illuminate this <code>Scene</code>.
     * </p>
     * 
     * @param lights The <code>Light</code>s that can be used to illuminate this <code>Scene</code>.
     */
    void setLights(List<Light> lights);

    /**
     * <p>
     * Sets the {@link com.se.simplicity.scenegraph.SceneGraph SceneGraph} that describes the relative locations of this <code>Scene</code>'s content.
     * </p>
     * 
     * @param sceneGraph The <code>SceneGraph</code> that describes the relative locations of this <code>Scene</code>'s content.
     */
    void setSceneGraph(SceneGraph sceneGraph);
}
