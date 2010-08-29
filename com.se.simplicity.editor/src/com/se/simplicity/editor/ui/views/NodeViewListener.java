/*
    This file is part of The Simplicity Engine.

    The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
    by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

    The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
package com.se.simplicity.editor.ui.views;

import java.util.Map;

import org.eclipse.swt.events.ModifyEvent;
import org.eclipse.swt.events.ModifyListener;
import org.eclipse.swt.events.SelectionEvent;
import org.eclipse.swt.events.SelectionListener;
import org.eclipse.swt.widgets.Button;
import org.eclipse.swt.widgets.Text;
import org.eclipse.swt.widgets.Widget;

import com.se.simplicity.editor.internal.SceneManager;
import com.se.simplicity.scenegraph.Node;
import com.se.simplicity.util.metadata.scenegraph.MetaDataNode;
import com.se.simplicity.vector.TransformationMatrixf;
import com.se.simplicity.vector.TranslationVectorf;

/**
 * <p>
 * Listens for events that signify a change in the value held by a widget and saves that property change to the model (i.e. <code>Node</code>).
 * </p>
 * 
 * @author Gary Buyn
 */
public class NodeViewListener implements ModifyListener, SelectionListener
{
    /**
     * <p>
     * Determines if this <code>NodeViewListener</code> should respond to events.
     * </p>
     */
    private boolean enabled;

    /**
     * <p>
     * Maps the <code>Widget</code>s displaying the properties of a <code>Node</code> to names so that they may be easily retrieved and their contents
     * saved to the model.
     * </p>
     */
    private Map<Widget, String> widgetBindings;

    /**
     * <p>
     * Creates an instance of <code>NodeViewListener</code>.
     * </p>
     * 
     * @param newWidgetBindings Maps the <code>Widget</code>s displaying the properties of a <code>Node</code> to names so that they may be easily
     * retrieved and their contents saved to the model.
     */
    public NodeViewListener(final Map<Widget, String> newWidgetBindings)
    {
        widgetBindings = newWidgetBindings;

        enabled = true;
    }

    /**
     * <p>
     * Stops this <code>NodeViewListener</code> from responding to events.
     * </p>
     */
    public void disable()
    {
        enabled = false;
    }

    /**
     * <p>
     * Ensures this <code>NodeViewListener</code> is responding to events.
     * </p>
     */
    public void enable()
    {
        enabled = true;
    }

    /**
     * <p>
     * Determines whether this <code>NodeViewListener</code> is responding to events.
     * </p>
     * 
     * @return True if this <code>NodeViewListener</code> is responding to events, false otherwise.
     */
    public boolean isEnabled()
    {
        return (enabled);
    }

    @Override
    public void modifyText(final ModifyEvent e)
    {
        if (!enabled)
        {
            return;
        }

        Node activeNode = SceneManager.getSceneManager().getActiveNode();

        if (widgetBindings.get(e.widget).startsWith("rotate"))
        {
            setNodeRotation(activeNode, e.widget);
        }
        else if (widgetBindings.get(e.widget).startsWith("translate"))
        {
            setNodeTranslation(activeNode, e.widget);
        }
        else
        {
            setNodeNonBooleanProperty(activeNode, e.widget);
        }

        SceneManager.getSceneManager().notifyNodeModified(activeNode.getID());
    }

    /**
     * <p>
     * Sets a boolean property of a <code>Node</code> in response to a change in the value held by a <code>Button</code>.
     * </p>
     * 
     * @param button The <code>Button</code> whose value has changed.
     */
    protected void setNodeBooleanProperty(final Button button)
    {
        if (!enabled)
        {
            return;
        }

        Node activeNode = SceneManager.getSceneManager().getActiveNode();

        if (widgetBindings.get(button).equals("collidable"))
        {
            activeNode.setCollidable(button.getSelection());
        }
        else if (widgetBindings.get(button).equals("modifiable"))
        {
            activeNode.setModifiable(button.getSelection());
        }
        else if (widgetBindings.get(button).equals("visible"))
        {
            activeNode.setVisible(button.getSelection());
        }

        SceneManager.getSceneManager().notifyNodeModified(activeNode.getID());
    }

    /**
     * <p>
     * Sets a non-boolean property of a <code>Node</code> in response to a change in the value held by a <code>Widget</code>.
     * </p>
     * 
     * @param node The <code>Node</code> to set the non-boolean property of.
     * @param widget The <code>Widget</code> whose value has changed.
     */
    protected void setNodeNonBooleanProperty(final Node node, final Widget widget)
    {
        String value = ((Text) widget).getText();

        if (widgetBindings.get(widget).equals("name"))
        {
            if (node instanceof MetaDataNode)
            {
                ((MetaDataNode) node).setAttribute("name", value);
            }
        }
    }

    /**
     * <p>
     * Sets the rotation of a <code>Node</code> in response to a change in the value held by a <code>Widget</code>.
     * </p>
     * 
     * @param node The <code>Node</code> to rotate.
     * @param widget The <code>Widget</code> whose value has changed.
     */
    protected void setNodeRotation(final Node node, final Widget widget)
    {
        TransformationMatrixf transformation = node.getTransformation();
        float value = (float) (Float.parseFloat(((Text) widget).getText()) * Math.PI / 180.0f);

        if (widgetBindings.get(widget).equals("rotateX"))
        {
            transformation.setXAxisRotation(value);
        }
        else if (widgetBindings.get(widget).equals("rotateY"))
        {
            transformation.setYAxisRotation(value);
        }
        else if (widgetBindings.get(widget).equals("rotateZ"))
        {
            transformation.setZAxisRotation(value);
        }
    }

    /**
     * <p>
     * Sets the translation of a <code>Node</code> in response to a change in the value held by a <code>Widget</code>.
     * </p>
     * 
     * @param node The <code>Node</code> to translate.
     * @param widget The <code>Widget</code> whose value has changed.
     */
    protected void setNodeTranslation(final Node node, final Widget widget)
    {
        TranslationVectorf translation = node.getTransformation().getTranslation();
        float value = Float.parseFloat(((Text) widget).getText());

        if (widgetBindings.get(widget).equals("translateX"))
        {
            translation.setX(value);
        }
        else if (widgetBindings.get(widget).equals("translateY"))
        {
            translation.setY(value);
        }
        else if (widgetBindings.get(widget).equals("translateZ"))
        {
            translation.setZ(value);
        }

        node.getTransformation().setTranslation(translation);
    }

    @Override
    public void widgetDefaultSelected(final SelectionEvent e)
    {
        setNodeBooleanProperty((Button) e.widget);
    }

    @Override
    public void widgetSelected(final SelectionEvent e)
    {
        setNodeBooleanProperty((Button) e.widget);
    }
}
