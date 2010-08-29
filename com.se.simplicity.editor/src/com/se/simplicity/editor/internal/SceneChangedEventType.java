/*
    This file is part of The Simplicity Engine.

    The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
    by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

    The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
package com.se.simplicity.editor.internal;

/**
 * <p>
 * The type of a {@link com.se.simplicity.editor.internal.SceneChangedEvent SceneChangedEvent}.
 * </p>
 * 
 * @author Gary Buyn
 */
public enum SceneChangedEventType
{
    /**
     * <p>
     * A <code>Camera</code> has been modified.
     * </p>
     */
    CAMERA_ACTIVATED,

    /**
     * <p>
     * A <code>Light</code> has been modified.
     * </p>
     */
    LIGHT_ACTIVATED,

    /**
     * <p>
     * A <code>Node</code> has been modified.
     * </p>
     */
    NODE_MODIFIED,

    /**
     * <p>
     * A <code>Node</code> has been made active.
     * </p>
     */
    NODE_ACTIVATED,

    /**
     * <p>
     * The <code>Scene</code> has been modified.
     * </p>
     */
    SCENE_MODIFIED,

    /**
     * <p>
     * The <code>Scene</code> has been made active.
     * </p>
     */
    SCENE_ACTIVATED
}
