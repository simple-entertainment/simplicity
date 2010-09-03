/*
    This file is part of The Simplicity Engine.

    The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
    by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

    The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
package com.se.simplicity.editor.ui.editors;

import com.se.simplicity.editor.internal.SceneManager;
import com.se.simplicity.picking.event.PickEvent;
import com.se.simplicity.picking.event.PickListener;
import com.se.simplicity.rendering.Renderer;
import com.se.simplicity.rendering.engine.RenderingEngine;
import com.se.simplicity.scenegraph.Node;

/**
 * <p>
 * Listens for pick events on a 3D canvas and draws an outline around the selected object (if any). If no object is selected, any previously selected
 * object will no longer be highlighted.
 * </p>
 * 
 * @author Gary Buyn
 */
public class VisualScenePickListener implements PickListener
{
    /**
     * <p>
     * The {@link com.se.simplicity.rendering.engine.RenderingEngine RenderingEngine} containing the
     * {@link com.se.simplicity.jogl.rendering.OutlineJOGLRenderer OutlineJOGLRenderer} used to outline the selected object.
     * </p>
     */
    private RenderingEngine fRenderingEngine;

    /**
     * <p>
     * Creates an instance of <code>VisualScenePickListener</code>.
     * </p>
     * 
     * @param renderingEngine The {@link com.se.simplicity.rendering.engine.RenderingEngine RenderingEngine} containing the
     * {@link com.se.simplicity.jogl.rendering.OutlineJOGLRenderer OutlineJOGLRenderer} used to outline the selected object.
     */
    public VisualScenePickListener(final RenderingEngine renderingEngine)
    {
        fRenderingEngine = renderingEngine;
    }

    @Override
    public void scenePicked(final PickEvent event)
    {
        Renderer outlineRenderer = fRenderingEngine.getRenderers().get(1);

        if (event.getHitCount() > 0)
        {
            // TODO should be getting closest hit.
            Node selectedNode = (Node) event.getHit(0)[0];

            fRenderingEngine.setRendererRoot(outlineRenderer, selectedNode);
            SceneManager.getSceneManager().setActiveNode(selectedNode);
        }
        else
        {
            fRenderingEngine.setRendererRoot(outlineRenderer, null);
            SceneManager.getSceneManager().setActiveNode(null);
        }
    }
}
