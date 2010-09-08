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
import org.eclipse.swt.graphics.Image;
import org.eclipse.swt.layout.GridData;
import org.eclipse.swt.layout.GridLayout;
import org.eclipse.swt.widgets.Composite;
import org.eclipse.swt.widgets.Control;
import org.eclipse.swt.widgets.Label;
import org.eclipse.ui.part.ViewPart;

import com.se.simplicity.editor.internal.EditorResources;
import com.se.simplicity.editor.internal.SceneManager;
import com.se.simplicity.editor.internal.event.SceneChangedEvent;
import com.se.simplicity.editor.internal.event.SceneChangedEventType;
import com.se.simplicity.editor.internal.event.SceneChangedListener;

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
    private CameraView fCameraView;

    /**
     * <p>
     * The <code>Control</code> to display when a null scene component is activated.
     * </p>
     */
    private Composite fEmptyView;

    /**
     * <p>
     * The <code>Control</code> to display when a <code>Light</code> is activated.
     * </p>
     */
    private LightView fLightView;

    /**
     * <p>
     * The <code>Control</code> to display when a <code>Node</code> is activated.
     * </p>
     */
    private NodeView fNodeView;

    /**
     * <p>
     * The parent <code>Composite</code>.
     * </p>
     */
    private Composite fParent;

    /**
     * <p>
     * An image of Simple Eddy.
     * </p>
     */
    private Image fSimpleEddyImage;

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
        fSimpleEddyImage = EditorResources.getEditorResources().getImageRegistry().get("sceneComponentEmpty");

        fParent = newParent;
        fParent.setLayout(new StackLayout());

        fCameraView = new CameraView(fParent, SWT.NONE);
        fEmptyView = new Composite(fParent, SWT.NONE);
        fLightView = new LightView(fParent, SWT.NONE);
        fNodeView = new NodeView(fParent, SWT.NONE);

        fEmptyView.setLayout(new GridLayout());
        Label simpleEddy = new Label(fEmptyView, SWT.NONE);
        simpleEddy.setLayoutData(new GridData(SWT.CENTER, SWT.CENTER, true, true));
        simpleEddy.setImage(fSimpleEddyImage);

        ((StackLayout) fParent.getLayout()).topControl = fEmptyView;
        fParent.layout();
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
        return (fParent);
    }

    @Override
    public void sceneChanged(final SceneChangedEvent event)
    {
        Control topView = ((StackLayout) fParent.getLayout()).topControl;
        if (event.getType() == SceneChangedEventType.CAMERA_ACTIVATED)
        {
            if (event.getSceneComponent() == null)
            {
                topView = fEmptyView;
            }
            else
            {
                topView = fCameraView;
            }
        }
        else if (event.getType() == SceneChangedEventType.LIGHT_ACTIVATED)
        {
            if (event.getSceneComponent() == null)
            {
                topView = fEmptyView;
            }
            else
            {
                topView = fLightView;
            }
        }
        else if (event.getType() == SceneChangedEventType.NODE_ACTIVATED)
        {
            if (event.getSceneComponent() == null)
            {
                topView = fEmptyView;
            }
            else
            {
                topView = fNodeView;
            }
        }

        if (((StackLayout) fParent.getLayout()).topControl != topView)
        {
            ((StackLayout) fParent.getLayout()).topControl = topView;
            fParent.layout();
        }
    }

    @Override
    public void setFocus()
    {}
}
