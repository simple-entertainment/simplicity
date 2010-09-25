/*
    This file is part of The Simplicity Engine.

    The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
    by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

    The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
package com.se.simplicity.editor.internal.picking;

import java.nio.IntBuffer;

import com.se.simplicity.editor.internal.Widget;
import com.se.simplicity.jogl.picking.SimpleJOGLPicker;
import com.se.simplicity.model.Model;
import com.se.simplicity.model.VertexGroup;
import com.se.simplicity.model.shape.Shape;
import com.se.simplicity.picking.Hit;
import com.se.simplicity.picking.event.PickEvent;
import com.se.simplicity.scene.Scene;
import com.se.simplicity.scenegraph.SceneGraph;
import com.se.simplicity.scenegraph.SimpleSceneGraph;
import com.se.simplicity.scenegraph.model.ModelNode;

/**
 * <p>
 * This {@link com.se.simplicity.picking.Picker Picker} is designed specifically for use with the
 * {@link com.se.simplicity.editor.internal.rendering.WidgetJOGLRenderer WidgetJOGLRenderer}. It is able to selectively pick the
 * {@link com.se.simplicity.scene.Scene Scene} or the actual {@link com.se.simplicit.editor.internal.Widget Widget}s depending on the
 * <code>hittable</code> property of the <code>Widget</code>.
 * </p>
 * 
 * @author Gary Buyn
 */
public class WidgetJOGLPicker extends SimpleJOGLPicker
{
    /**
     * <p>
     * The number of names in the selection buffer relating to the {@link com.se.simplicity.scene.Scene Scene}.
     * </p>
     */
    private static final int SCENE_NAMES = 2;

    /**
     * <p>
     * The {@link com.se.simplicit.editor.internal.Widget Widget} to pick for.
     * </p>
     */
    private Widget fWidget;

    /**
     * <p>
     * A {@link com.se.simplicity.scenegraph.SceneGraph SceneGraph} containing the {@link com.se.simplicity.scenegraph.Node Node}s of the
     * <code>Widget</code>.
     * </p>
     */
    private SceneGraph fWidgetSceneGraph;

    /**
     * <p>
     * Creates an instance of <code>WidgetJOGLPicker</code>.
     * </p>
     */
    public WidgetJOGLPicker()
    {
        fWidget = null;
        fWidgetSceneGraph = new SimpleSceneGraph();
    }

    @Override
    protected PickEvent createPickEvent(final Scene scene, final int numberOfHits)
    {
        // If the Widget is not pickable, pick the Scene as normal.
        if (!fWidget.isHittable())
        {
            return (super.createPickEvent(scene, numberOfHits));
        }

        PickEvent event = new PickEvent();
        IntBuffer selectBuffer = getSelectBuffer();
        int bufferIndex = 0;

        // For every hit.
        for (int hitIndex = 0; hitIndex < numberOfHits; hitIndex++)
        {
            // Retrieve header information.
            Hit hit = new Hit();
            int numberOfNames = selectBuffer.get(bufferIndex++);
            hit.setMinimumDistance(selectBuffer.get(bufferIndex++));
            hit.setMaximumDistance(selectBuffer.get(bufferIndex++));

            // Retrieve the Node using the first (Widget) name.
            hit.setNode(fWidgetSceneGraph.getNode(selectBuffer.get(bufferIndex + SCENE_NAMES)));

            // Retrieve the primitive.
            Model model = ((ModelNode) hit.getNode()).getModel();
            if (model instanceof VertexGroup)
            {
                // For Vertex Groups the index of the primitive should be in the second (Widget) name.
                if (numberOfNames > SCENE_NAMES + 1)
                {
                    hit.setPrimitive(getSubsetVG((VertexGroup) model, selectBuffer.get(bufferIndex + SCENE_NAMES + 1)));
                }
            }
            else if (model instanceof Shape)
            {
                hit.setPrimitive(model);
            }

            // Finalise and prepare for the next hit.
            bufferIndex += numberOfNames;
            event.addHit(hit);
        }

        return (event);
    }

    /**
     * <p>
     * Retrieves the {@link com.se.simplicit.editor.internal.Widget Widget} to pick for.
     * </p>
     * 
     * @return The <code>Widget</code> to pick for.
     */
    public Widget getWidget()
    {
        return (fWidget);
    }

    /**
     * <p>
     * Sets the {@link com.se.simplicit.editor.internal.Widget Widget} to pick for.
     * </p>
     * 
     * @param widget The <code>Widget</code> to pick for.
     */
    public void setWidget(final Widget widget)
    {
        if (fWidget != null)
        {
            fWidgetSceneGraph.removeSubgraph(fWidget.getRootNode());
        }

        fWidget = widget;

        fWidgetSceneGraph.addSubgraph(fWidget.getRootNode());
    }
}
