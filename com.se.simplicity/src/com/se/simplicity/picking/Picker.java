/*
    This file is part of The Simplicity Engine.

    The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
    by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

    The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
package com.se.simplicity.picking;

import com.se.simplicity.picking.event.PickEvent;
import com.se.simplicity.rendering.Camera;
import com.se.simplicity.scenegraph.SceneGraph;

/**
 * <p>
 * Picks {@link com.se.simplicity.scenegraph.SceneGraph SceneGraph}s. The {@link com.se.simplicity.scenegraph.SceneGraph SceneGraph} is picked based
 * on a {@link com.se.simplicity.rendering.Camera Camera} and a {@link com.se.simplicity.picking.Pick Pick} that generally represents a subset of the
 * {@link com.se.simplicity.rendering.Camera Camera}'s frame.
 * </p>
 * 
 * @author Gary Buyn
 */
public interface Picker
{
    /**
     * <p>
     * Picks a {@link com.se.simplicity.scenegraph.SceneGraph SceneGraph} using the given {@link com.se.simplicity.picking.Pick Pick} and basing the
     * {@link com.se.simplicity.picking.Pick Pick} on the given {@link com.se.simplicity.rendering.Camera Camera}.
     * </p>
     * 
     * @param sceneGraph The {@link com.se.simplicity.scenegraph.SceneGraph SceneGraph} to pick.
     * @param camera The {@link com.se.simplicity.rendering.Camera Camera} to base the pick on.
     * @param pick The {@link com.se.simplicity.picking.Pick Pick} to apply to the {@link com.se.simplicity.scenegraph.SceneGraph SceneGraph}.
     * 
     * @return An event containing any picked compoonents of the {@link com.se.simplicity.scenegraph.SceneGraph SceneGraph}.
     */
    PickEvent pickSceneGraph(SceneGraph sceneGraph, Camera camera, Pick pick);
}
