/*
    This file is part of The Simplicity Engine.

    The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
    by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

    The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
package com.se.simplicity.rendering;

/**
 * <p>
 * The lighting mode used to render a {@link com.se.simplicity.scenegraph.SceneGraph SceneGraph}. The modes are as follows:
 * </p>
 * 
 * @author Gary Buyn
 */
public enum LightingMode
{
    /**
     * <p>
     * Renders the models with shading determined by the Lights within the SceneGraph.
     * </p>
     */
    SCENE,

    /**
     * <p>
     * Renders the models with simple shading. Lights to create the shading effects are added by the SceneGraph and are implementation specific.
     * </p>
     */
    SHADED,

    /**
     * <p>
     * Renders the models with solid shading. Lights to create the shading effects are added by the SceneGraph and are implementation specific.
     * </p>
     */
    SOLID
}
