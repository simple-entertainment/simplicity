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
import org.eclipse.swt.layout.GridData;
import org.eclipse.swt.layout.GridLayout;
import org.eclipse.swt.widgets.Combo;
import org.eclipse.swt.widgets.Composite;
import org.eclipse.swt.widgets.Group;
import org.eclipse.swt.widgets.Label;
import org.eclipse.swt.widgets.Text;
import org.eclipse.swt.widgets.Widget;

import com.se.simplicity.editor.internal.SceneChangedEvent;
import com.se.simplicity.editor.internal.SceneChangedEventType;
import com.se.simplicity.editor.internal.SceneChangedListener;
import com.se.simplicity.editor.internal.SceneManager;
import com.se.simplicity.rendering.Camera;
import com.se.simplicity.rendering.ProjectionMode;
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
    private CameraViewListener fCameraViewListener;

    /**
     * <p>
     * Displays the 'far clipping distance' property of a <code>Camera</code>.
     * </p>
     */
    private Text fFarClippingDistance;

    /**
     * <p>
     * Displays the 'frame aspect ratio' property of a <code>Camera</code>.
     * </p>
     */
    private Text fFrameAspectRatio;

    /**
     * <p>
     * Displays the 'frame X position' property of a <code>Camera</code>.
     * </p>
     */
    private Text fFrameX;

    /**
     * <p>
     * Displays the 'frame Y position' property of a <code>Camera</code>.
     * </p>
     */
    private Text fFrameY;

    /**
     * <p>
     * Displays the 'frame width' property of a <code>Camera</code>.
     * </p>
     */
    private Text fFrameWidth;

    /**
     * <p>
     * Displays the 'frame height' property of a <code>Camera</code>.
     * </p>
     */
    private Text fFrameHeight;

    /**
     * <p>
     * Displays the 'name' property of a <code>Camera</code>.
     * </p>
     */
    private Text fName;

    /**
     * <p>
     * Displays the 'near clipping distance' property of a <code>Camera</code>.
     * </p>
     */
    private Text fNearClippingDistance;

    /**
     * <p>
     * Displays the 'node' property of a <code>Camera</code>.
     * </p>
     */
    private Text fNode;

    /**
     * <p>
     * Displays the 'projection mode' property of a <code>Camera</code>.
     * </p>
     */
    private Combo fProjectionMode;

    /**
     * <p>
     * Displays the type of a <code>Camera</code>.
     * </p>
     */
    private Text fType;

    /**
     * <p>
     * Maps the <code>Widget</code>s displaying the properties of a <code>Camera</code> to names so that they may be easily retrieved and their
     * contents saved to the model.
     * </p>
     */
    private Map<Widget, String> fWidgetBindings;

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

        fWidgetBindings = new HashMap<Widget, String>();

        SceneManager.getSceneManager().addSceneChangedListener(this);
        fCameraViewListener = new CameraViewListener(fWidgetBindings);

        setLayout(new GridLayout(4, false));

        addIdentificationWidgets();
        addGeneralWidgets();
        addFrameWidgets();
        addClippingWidgets();
        addReflectionWidgets();
    }

    /**
     * <p>
     * Adds widgets for the clipping related properties of a <code>Camera</code>.
     * </p>
     */
    protected void addClippingWidgets()
    {
        Group frame = new Group(this, SWT.NONE);
        frame.setLayoutData(new GridData(SWT.LEAD, SWT.FILL, false, false));
        frame.setLayout(new GridLayout(2, false));
        frame.setText("Clipping");

        Label labelNearClippingDistance = new Label(frame, SWT.NONE);
        labelNearClippingDistance.setText("Near Clipping Distance");
        fNearClippingDistance = new Text(frame, SWT.NONE);
        fNearClippingDistance.addModifyListener(fCameraViewListener);
        fWidgetBindings.put(fNearClippingDistance, "nearClippingDistance");

        Label labelFarClippingDistance = new Label(frame, SWT.NONE);
        labelFarClippingDistance.setText("Far Clipping Distance");
        fFarClippingDistance = new Text(frame, SWT.NONE);
        fFarClippingDistance.addModifyListener(fCameraViewListener);
        fWidgetBindings.put(fFarClippingDistance, "farClippingDistance");
    }

    /**
     * <p>
     * Adds widgets for the frame related properties of a <code>Camera</code>.
     * </p>
     */
    protected void addFrameWidgets()
    {
        Group frame = new Group(this, SWT.NONE);
        frame.setLayoutData(new GridData(SWT.LEAD, SWT.FILL, false, false));
        frame.setLayout(new GridLayout(2, false));
        frame.setText("Frame");

        Label labelFrameAspectRatio = new Label(frame, SWT.NONE);
        labelFrameAspectRatio.setText("Aspect Ratio");
        fFrameAspectRatio = new Text(frame, SWT.NONE);
        fFrameAspectRatio.addModifyListener(fCameraViewListener);
        fWidgetBindings.put(fFrameAspectRatio, "frameAspectRatio");

        Label labelFrameX = new Label(frame, SWT.NONE);
        labelFrameX.setText("X");
        fFrameX = new Text(frame, SWT.NONE);
        fFrameX.addModifyListener(fCameraViewListener);
        fWidgetBindings.put(fFrameX, "frameX");

        Label labelFrameY = new Label(frame, SWT.NONE);
        labelFrameY.setText("Y");
        fFrameY = new Text(frame, SWT.NONE);
        fFrameY.addModifyListener(fCameraViewListener);
        fWidgetBindings.put(fFrameY, "frameY");

        Label labelFrameWidth = new Label(frame, SWT.NONE);
        labelFrameWidth.setText("Width");
        fFrameWidth = new Text(frame, SWT.NONE);
        fFrameWidth.addModifyListener(fCameraViewListener);
        fWidgetBindings.put(fFrameWidth, "frameWidth");

        Label labelFrameHeight = new Label(frame, SWT.NONE);
        labelFrameHeight.setText("Height");
        fFrameHeight = new Text(frame, SWT.NONE);
        fFrameHeight.addModifyListener(fCameraViewListener);
        fWidgetBindings.put(fFrameHeight, "frameHeight");
    }

    /**
     * <p>
     * Adds widgets for the general properties of a <code>Camera</code>.
     * </p>
     */
    protected void addGeneralWidgets()
    {
        Group general = new Group(this, SWT.NONE);
        general.setLayoutData(new GridData(SWT.LEAD, SWT.FILL, false, false));
        general.setLayout(new GridLayout(2, false));
        general.setText("General");

        Label labelNode = new Label(general, SWT.NONE);
        labelNode.setText("Node");
        fNode = new Text(general, SWT.NONE);
        fNode.addModifyListener(fCameraViewListener);
        fWidgetBindings.put(fNode, "node");

        Label labelProjectionMode = new Label(general, SWT.NONE);
        labelProjectionMode.setText("Projection Mode");
        fProjectionMode = new Combo(general, SWT.NONE);
        fProjectionMode.add("ORTHOGONAL");
        fProjectionMode.add("PERSPECTIVE");
        fProjectionMode.addSelectionListener(fCameraViewListener);
        fWidgetBindings.put(fProjectionMode, "projectionMode");
    }

    /**
     * <p>
     * Adds widgets for the identification related properties of a <code>Camera</code>.
     * </p>
     */
    protected void addIdentificationWidgets()
    {
        Group identification = new Group(this, SWT.NONE);
        identification.setLayoutData(new GridData(SWT.LEAD, SWT.FILL, false, false));
        identification.setLayout(new GridLayout(2, false));
        identification.setText("Identification");

        Label labelName = new Label(identification, SWT.NONE);
        labelName.setText("Name");
        fName = new Text(identification, SWT.NONE);
        fName.addModifyListener(fCameraViewListener);
        fWidgetBindings.put(fName, "name");
    }

    /**
     * <p>
     * Adds widgets for reflected properties of a <code>Light</code>.
     * </p>
     */
    protected void addReflectionWidgets()
    {
        Group reflection = new Group(this, SWT.NONE);
        reflection.setLayoutData(new GridData(SWT.FILL, SWT.TOP, false, false, ((GridLayout) this.getLayout()).numColumns, 1));
        reflection.setText("Reflection");

        reflection.setLayout(new GridLayout(2, false));

        Label labelType = new Label(reflection, SWT.NONE);
        labelType.setText("Type");
        fType = new Text(reflection, SWT.READ_ONLY);
        fType.setLayoutData(new GridData(SWT.FILL, SWT.TOP, true, false));
        fType.addModifyListener(fCameraViewListener);
        fWidgetBindings.put(fType, "type");
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
        if (SceneManager.getSceneManager().getActiveCamera() == null)
        {
            return;
        }

        if (event.getType() == SceneChangedEventType.CAMERA_ACTIVATED || event.getType() == SceneChangedEventType.SCENE_MODIFIED)
        {
            fCameraViewListener.disable();

            Camera camera = SceneManager.getSceneManager().getActiveCamera();

            if (camera instanceof MetaDataCamera)
            {
                fName.setText((String) ((MetaDataCamera) camera).getAttribute("name"));
            }
            else
            {
                fName.setText("CameraX");
            }

            fNode.setText(Integer.toString(camera.getNode().getID()));

            if (camera.getProjectionMode() == ProjectionMode.ORTHOGONAL)
            {
                fProjectionMode.setText("ORTHOGONAL");
            }
            else if (camera.getProjectionMode() == ProjectionMode.PERSPECTIVE)
            {
                fProjectionMode.setText("PERSPECTIVE");
            }

            fFrameAspectRatio.setText(Float.toString(camera.getFrameAspectRatio()));
            fFrameX.setText(Float.toString(camera.getFrameX()));
            fFrameY.setText(Float.toString(camera.getFrameY()));
            fFrameWidth.setText(Float.toString(camera.getFrameWidth()));
            fFrameHeight.setText(Float.toString(camera.getFrameHeight()));

            fNearClippingDistance.setText(Float.toString(camera.getNearClippingDistance()));
            fFarClippingDistance.setText(Float.toString(camera.getFarClippingDistance()));

            if (camera instanceof MetaDataCamera)
            {
                fType.setText((String) ((MetaDataCamera) camera).getWrappedCamera().getClass().getName());
            }
            else
            {
                fType.setText(camera.getClass().getName());
            }

            fCameraViewListener.enable();
        }
    }
}
