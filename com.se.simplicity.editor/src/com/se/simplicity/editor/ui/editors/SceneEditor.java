/*
    This file is part of The Simplicity Engine.

    The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
    by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

    The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
package com.se.simplicity.editor.ui.editors;

import java.util.List;

import com.se.simplicity.picking.engine.PickingEngine;
import com.se.simplicity.rendering.engine.RenderingEngine;
import com.se.simplicity.scene.Scene;
import com.se.simplicity.scenegraph.Node;

/**
 * <p>
 * An editor capable of displaying a <code>Scene</code> visually.
 * </p>
 * 
 * @author Gary Buyn
 */
public interface SceneEditor
{
    /**
     * <p>
     * Retrieves the root <code>Node</code>s for the subgraphs that contain the 3D widgets used to manipulate <code>Model</code>s.
     * </p>
     * 
     * @return The root <code>Node</code>s for the subgraphs that contain the 3D widgets used to manipulate <code>Model</code>s.
     */
    List<Node> get3DWidgetsRootNodes();

    /**
     * <p>
     * Retrieves the <code>PickingEngine</code> used to select items in the <code>Scene</code>.
     * </p>
     * 
     * @return The <code>PickingEngine</code> used to select items in the <code>Scene</code>.
     */
    PickingEngine getPickingEngine();

    /**
     * <p>
     * Retrieves the <code>RenderingEngine</code> that will render the <code>Scene</code>.
     * </p>
     * 
     * @return The <code>RenderingEngine</code> that will render the <code>Scene</code>.
     */
    RenderingEngine getRenderingEngine();

    /**
     * <p>
     * Retrieves the <code>Scene</code> displayed by this editor.
     * </p>
     * 
     * @return The <code>Scene</code> displayed by this editor.
     */
    Scene getScene();
}
