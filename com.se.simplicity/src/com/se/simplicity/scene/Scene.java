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
 * A 3D environment that can be displayed and picked via a {@link com.se.simplicity.viewport.Viewport Viewport}.
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
     * @param newCamera The {@link com.se.simplicity.rendering.Camera Camera}s that can be used to view this <code>Scene</code> from specific angles.
     */
    void addCamera(Camera newCamera);

    /**
     * <p>
     * Adds a {@link com.se.simplicity.rendering.Light Light} that can be used to illuminate this <code>Scene</code>.
     * </p>
     * 
     * @param newLight The {@link com.se.simplicity.rendering.Light Light} that can be used to illuminate this <code>Scene</code>.
     */
    void addLight(Light newLight);

    /**
     * <p>
     * Retrieves the {@link com.se.simplicity.rendering.Camera Camera}s that can be used to view this <code>Scene</code> from specific angles.
     * </p>
     * 
     * @return The {@link com.se.simplicity.rendering.Camera Camera}s that can be used to view this <code>Scene</code> from specific angles.
     */
    List<Camera> getCameras();

    /**
     * <p>
     * Retrieves the {@link com.se.simplicity.rendering.Light Light}s that can be used to illuminate this <code>Scene</code>.
     * </p>
     * 
     * @return The {@link com.se.simplicity.rendering.Light Light}s that can be used to illuminate this <code>Scene</code>.
     */
    List<Light> getLights();

    /**
     * <p>
     * Retrieves the {@link com.se.simplicity.scenegraph.SceneGraph SceneGraph} that describes the relative locations of this <code>Scene</code>'s
     * content.
     * </p>
     * 
     * @return The {@link com.se.simplicity.scenegraph.SceneGraph SceneGraph} that describes the relative locations of this <code>Scene</code>'s
     * content.
     */
    SceneGraph getSceneGraph();

    /**
     * <p>
     * Sets the {@link com.se.simplicity.rendering.Camera Camera}s that can be used to view this <code>Scene</code> from specific angles.
     * </p>
     * 
     * @param newCameras The {@link com.se.simplicity.rendering.Camera Camera}s that can be used to view this <code>Scene</code> from specific angles.
     */
    void setCameras(List<Camera> newCameras);

    /**
     * <p>
     * Sets the {@link com.se.simplicity.rendering.Light Light}s that can be used to illuminate this <code>Scene</code>.
     * </p>
     * 
     * @param newLights The {@link com.se.simplicity.rendering.Light Light}s that can be used to illuminate this <code>Scene</code>.
     */
    void setLights(List<Light> newLights);

    /**
     * <p>
     * Sets the {@link com.se.simplicity.scenegraph.SceneGraph SceneGraph} that describes the relative locations of this <code>Scene</code>'s content.
     * </p>
     * 
     * @param newSceneGraph The {@link com.se.simplicity.scenegraph.SceneGraph SceneGraph} that describes the relative locations of this
     * <code>Scene</code>'s content.
     */
    void setSceneGraph(SceneGraph newSceneGraph);
}
