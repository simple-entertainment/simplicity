/*
    This file is part of The Simplicity Engine.

    The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
    by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

    The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
package com.se.simplicity.editor.ui.views;

import org.eclipse.swt.SWT;
import org.eclipse.swt.custom.StackLayout;
import org.eclipse.swt.widgets.Composite;
import org.eclipse.ui.part.ViewPart;

import com.se.simplicity.editor.internal.SceneChangedEvent;
import com.se.simplicity.editor.internal.SceneChangedEventType;
import com.se.simplicity.editor.internal.SceneChangedListener;
import com.se.simplicity.editor.internal.SceneManager;

/**
 * <p>
 * An eclipse view that displays details for the currently active component in the <code>Scene</code> (if there is one).
 * </p>
 * 
 * @author Gary Buyn
 */
public class SceneComponentView extends ViewPart implements SceneChangedListener
{
    /**
     * <p>
     * The <code>Control</code> to display when a <code>Camera</code> is activated.
     * </p>
     */
    private CameraView cameraView;

    /**
     * <p>
     * The <code>Control</code> to display when a <code>Light</code> is activated.
     * </p>
     */
    private LightView lightView;

    /**
     * <p>
     * The <code>Control</code> to display when a <code>Node</code> is activated.
     * </p>
     */
    private NodeView nodeView;

    /**
     * <p>
     * The parent <code>Composite</code>.
     * </p>
     */
    private Composite parent;

    /**
     * <p>
     * Creates an instance of <code>SceneComponentView</code>.
     * </p>
     */
    public SceneComponentView()
    {
        super();

        SceneManager.getSceneManager().addSceneChangedListener(this);
    }

    @Override
    public void createPartControl(final Composite newParent)
    {
        parent = newParent;
        parent.setLayout(new StackLayout());

        cameraView = new CameraView(parent, SWT.NONE);
        lightView = new LightView(parent, SWT.NONE);
        nodeView = new NodeView(parent, SWT.NONE);
    }

    @Override
    public void dispose()
    {
        SceneManager.getSceneManager().removeSceneChangedListener(this);

        super.dispose();
    }

    /**
     * <p>
     * Retrieves the parent <code>Composite</code>.
     * </p>
     * 
     * @return The parent <code>Composite</code>.s
     */
    public Composite getParent()
    {
        return (parent);
    }

    @Override
    public void sceneChanged(final SceneChangedEvent event)
    {
        if (event.getType() == SceneChangedEventType.CAMERA_ACTIVATED)
        {
            ((StackLayout) parent.getLayout()).topControl = cameraView;
            parent.layout();
        }
        else if (event.getType() == SceneChangedEventType.LIGHT_ACTIVATED)
        {
            ((StackLayout) parent.getLayout()).topControl = lightView;
            parent.layout();
        }
        else if (event.getType() == SceneChangedEventType.NODE_ACTIVATED)
        {
            ((StackLayout) parent.getLayout()).topControl = nodeView;
            parent.layout();
        }
    }

    @Override
    public void setFocus()
    {}
}
