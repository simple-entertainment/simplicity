/*
    This file is part of The Simplicity Engine.

    The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
    by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

    The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
package com.se.simplicity.editor.ui.views;

import java.util.HashMap;
import java.util.Map;

import org.eclipse.swt.SWT;
import org.eclipse.swt.layout.GridLayout;
import org.eclipse.swt.widgets.Composite;
import org.eclipse.swt.widgets.Label;
import org.eclipse.swt.widgets.Text;
import org.eclipse.swt.widgets.Widget;

import com.se.simplicity.editor.internal.SceneChangedEvent;
import com.se.simplicity.editor.internal.SceneChangedEventType;
import com.se.simplicity.editor.internal.SceneChangedListener;
import com.se.simplicity.editor.internal.SceneManager;
import com.se.simplicity.rendering.Camera;
import com.se.simplicity.util.metadata.rendering.MetaDataCamera;

/**
 * <p>
 * An eclipse view that displays details for the currently active <code>Camera</code> in the <code>Scene</code> (if there is one).
 * </p>
 * 
 * @author Gary Buyn
 */
public class CameraView extends Composite implements SceneChangedListener
{
    /**
     * <p>
     * Listens for changes to displayed properties of a <code>Camera</code> (or its sub-components).
     * </p>
     */
    private CameraViewListener cameraViewListener;

    /**
     * <p>
     * Displays the 'name' property of a <code>Camera</code>.
     * </p>
     */
    private Text name;

    /**
     * <p>
     * Displays the 'node' property of a <code>Camera</code>.
     * </p>
     */
    private Text node;

    /**
     * <p>
     * Maps the <code>Widget</code>s displaying the properties of a <code>Camera</code> to names so that they may be easily retrieved and their
     * contents saved to the model.
     * </p>
     */
    private Map<Widget, String> widgetBindings;

    /**
     * <p>
     * Creates an instance of <code>CameraView</code>.
     * </p>
     * 
     * @param parent The parent <code>Composite</code>.
     * @param style The SWT style.
     */
    public CameraView(final Composite parent, final int style)
    {
        super(parent, style);

        widgetBindings = new HashMap<Widget, String>();

        SceneManager.getSceneManager().addSceneChangedListener(this);
        cameraViewListener = new CameraViewListener(widgetBindings);

        setLayout(new GridLayout(2, false));

        addIdentificationWidgets();
        addSceneGraphWidgets();
    }

    /**
     * <p>
     * Adds widgets for the identification related properties of a <code>Camera</code>.
     * </p>
     */
    protected void addIdentificationWidgets()
    {
        Composite translation = new Composite(this, SWT.NONE);
        translation.setLayout(new GridLayout(2, false));

        Label labelName = new Label(translation, SWT.NONE);
        labelName.setText("Name");
        name = new Text(translation, SWT.NONE);
        name.addModifyListener(cameraViewListener);
        widgetBindings.put(name, "name");
    }

    /**
     * <p>
     * Adds widgets for the <code>SceneGraph</code> related properties of a <code>Camera</code>.
     * </p>
     */
    protected void addSceneGraphWidgets()
    {
        Composite translation = new Composite(this, SWT.NONE);
        translation.setLayout(new GridLayout(2, false));

        Label labelNode = new Label(translation, SWT.NONE);
        labelNode.setText("Node");
        node = new Text(translation, SWT.NONE);
        node.addModifyListener(cameraViewListener);
        widgetBindings.put(node, "node");
    }

    @Override
    public void dispose()
    {
        SceneManager.getSceneManager().removeSceneChangedListener(this);

        super.dispose();
    }

    @Override
    public void sceneChanged(final SceneChangedEvent event)
    {
        if (event.getType() == SceneChangedEventType.CAMERA_ACTIVATED)
        {
            cameraViewListener.disable();

            Camera camera = (Camera) event.getSceneComponent();

            if (camera instanceof MetaDataCamera)
            {
                name.setText((String) ((MetaDataCamera) camera).getAttribute("name"));
            }
            else
            {
                name.setText("CameraX");
            }

            node.setText(Integer.toString(camera.getNode().getID()));

            cameraViewListener.enable();
        }
    }
}
