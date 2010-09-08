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
import org.eclipse.swt.widgets.Button;
import org.eclipse.swt.widgets.Composite;
import org.eclipse.swt.widgets.Group;
import org.eclipse.swt.widgets.Label;
import org.eclipse.swt.widgets.Text;
import org.eclipse.swt.widgets.Widget;

import com.se.simplicity.editor.internal.SceneManager;
import com.se.simplicity.editor.internal.event.SceneChangedEvent;
import com.se.simplicity.editor.internal.event.SceneChangedEventType;
import com.se.simplicity.editor.internal.event.SceneChangedListener;
import com.se.simplicity.scenegraph.Node;
import com.se.simplicity.util.metadata.scenegraph.MetaDataNode;
import com.se.simplicity.vector.TransformationMatrixf;

/**
 * <p>
 * An eclipse view that displays details for the currently active <code>Node</code> in the <code>Scene</code> (if there is one).
 * </p>
 * 
 * @author Gary Buyn
 */
public class NodeView extends Composite implements SceneChangedListener
{
    /**
     * <p>
     * Displays the 'collidable' property of a <code>Node</code>.
     * </p>
     */
    private Button fCollidable;

    /**
     * <p>
     * Displays the 'id' property of a <code>Node</code>.
     * </p>
     */
    private Text fId;

    /**
     * <p>
     * Displays the 'modifiable' property of a <code>Node</code>.
     * </p>
     */
    private Button fModifiable;

    /**
     * <p>
     * Displays the 'name' property of a <code>Node</code>.
     * </p>
     */
    private Text fName;

    /**
     * <p>
     * Listens for changes to displayed properties of a <code>Node</code> (or its sub-components).
     * </p>
     */
    private NodeViewListener fNodeViewListener;

    /**
     * <p>
     * Displays the X axis rotation of a <code>Node</code>.
     * </p>
     */
    private Text fRotateX;

    /**
     * <p>
     * Displays the Y axis rotation of a <code>Node</code>.
     * </p>
     */
    private Text fRotateY;

    /**
     * <p>
     * Displays the Z axis rotation of a <code>Node</code>.
     * </p>
     */
    private Text fRotateZ;

    /**
     * <p>
     * Displays the X axis translation of a <code>Node</code>.
     * </p>
     */
    private Text fTranslateX;

    /**
     * <p>
     * Displays the Y axis translation of a <code>Node</code>.
     * </p>
     */
    private Text fTranslateY;

    /**
     * <p>
     * Displays the Z axis translation of a <code>Node</code>.
     * </p>
     */
    private Text fTranslateZ;

    /**
     * <p>
     * Displays the type of a <code>Node</code>.
     * </p>
     */
    private Text fType;

    /**
     * <p>
     * Displays the 'visible' property of a <code>Node</code>.
     * </p>
     */
    private Button fVisible;

    /**
     * <p>
     * Maps the <code>Widget</code>s displaying the properties of a <code>Node</code> to names so that they may be easily retrieved and their contents
     * saved to the model.
     * </p>
     */
    private Map<Widget, String> fWidgetBindings;

    /**
     * <p>
     * Creates an instance of <code>NodeView</code>.
     * </p>
     * 
     * @param parent The parent <code>Composite</code>.
     * @param style The SWT style.
     */
    public NodeView(final Composite parent, final int style)
    {
        super(parent, style);

        fWidgetBindings = new HashMap<Widget, String>();

        SceneManager.getSceneManager().addSceneChangedListener(this);
        fNodeViewListener = new NodeViewListener(fWidgetBindings);

        setLayout(new GridLayout(4, false));

        addIdentificationWidgets();
        addGeneralWidgets();
        addTranslationWidgets();
        addRotationWidgets();
        addReflectionWidgets();
    }

    /**
     * <p>
     * Adds widgets for the identification related properties of a <code>Node</code>.
     * </p>
     */
    protected void addIdentificationWidgets()
    {
        Group identification = new Group(this, SWT.NONE);
        identification.setLayoutData(new GridData(SWT.LEAD, SWT.FILL, false, false));
        identification.setLayout(new GridLayout(2, false));
        identification.setText("Identification");

        Label labelId = new Label(identification, SWT.NONE);
        labelId.setText("ID");
        fId = new Text(identification, SWT.READ_ONLY);
        fId.addModifyListener(fNodeViewListener);
        fWidgetBindings.put(fId, "id");

        Label labelName = new Label(identification, SWT.NONE);
        labelName.setText("Name");
        fName = new Text(identification, SWT.NONE);
        fName.addModifyListener(fNodeViewListener);
        fWidgetBindings.put(fName, "name");
    }

    /**
     * <p>
     * Adds widgets for the general properties of a <code>Node</code>.
     * </p>
     */
    protected void addGeneralWidgets()
    {
        Group general = new Group(this, SWT.NONE);
        general.setLayoutData(new GridData(SWT.LEAD, SWT.FILL, false, false));
        general.setLayout(new GridLayout(1, false));
        general.setText("General");

        fCollidable = new Button(general, SWT.CHECK);
        fCollidable.setText("Collidable");
        fCollidable.addSelectionListener(fNodeViewListener);
        fWidgetBindings.put(fCollidable, "collidable");

        fModifiable = new Button(general, SWT.CHECK);
        fModifiable.setText("Modifiable");
        fModifiable.addSelectionListener(fNodeViewListener);
        fWidgetBindings.put(fModifiable, "modifiable");

        fVisible = new Button(general, SWT.CHECK);
        fVisible.setText("Visible");
        fVisible.addSelectionListener(fNodeViewListener);
        fWidgetBindings.put(fVisible, "visible");
    }

    /**
     * <p>
     * Adds widgets for reflected properties of a <code>Node</code>.
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
        fType.addModifyListener(fNodeViewListener);
        fWidgetBindings.put(fType, "type");
    }

    /**
     * <p>
     * Adds widgets for the rotation related properties of a <code>Node</code>.
     * </p>
     */
    protected void addRotationWidgets()
    {
        Group rotation = new Group(this, SWT.NONE);
        rotation.setLayoutData(new GridData(SWT.LEAD, SWT.FILL, false, false));
        rotation.setLayout(new GridLayout(2, false));
        rotation.setText("Rotation");

        Label labelX = new Label(rotation, SWT.NONE);
        labelX.setText("X");
        fRotateX = new Text(rotation, SWT.NONE);
        fRotateX.addModifyListener(fNodeViewListener);
        fWidgetBindings.put(fRotateX, "rotateX");

        Label labelY = new Label(rotation, SWT.NONE);
        labelY.setText("Y");
        fRotateY = new Text(rotation, SWT.NONE);
        fRotateY.addModifyListener(fNodeViewListener);
        fWidgetBindings.put(fRotateY, "rotateY");

        Label labelZ = new Label(rotation, SWT.NONE);
        labelZ.setText("Z");
        fRotateZ = new Text(rotation, SWT.NONE);
        fRotateZ.addModifyListener(fNodeViewListener);
        fWidgetBindings.put(fRotateZ, "rotateZ");
    }

    /**
     * <p>
     * Adds widgets for the translation related properties of a <code>Node</code>.
     * </p>
     */
    protected void addTranslationWidgets()
    {
        Group translation = new Group(this, SWT.NONE);
        translation.setLayoutData(new GridData(SWT.LEAD, SWT.FILL, false, false));
        translation.setLayout(new GridLayout(2, false));
        translation.setText("Translation");

        Label labelX = new Label(translation, SWT.NONE);
        labelX.setText("X");
        fTranslateX = new Text(translation, SWT.NONE);
        fTranslateX.addModifyListener(fNodeViewListener);
        fWidgetBindings.put(fTranslateX, "translateX");

        Label labelY = new Label(translation, SWT.NONE);
        labelY.setText("Y");
        fTranslateY = new Text(translation, SWT.NONE);
        fTranslateY.addModifyListener(fNodeViewListener);
        fWidgetBindings.put(fTranslateY, "translateY");

        Label labelZ = new Label(translation, SWT.NONE);
        labelZ.setText("Z");
        fTranslateZ = new Text(translation, SWT.NONE);
        fTranslateZ.addModifyListener(fNodeViewListener);
        fWidgetBindings.put(fTranslateZ, "translateZ");
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
        if (SceneManager.getSceneManager().getActiveNode() == null)
        {
            return;
        }

        if (event.getType() == SceneChangedEventType.NODE_ACTIVATED || event.getType() == SceneChangedEventType.SCENE_MODIFIED)
        {
            fNodeViewListener.disable();

            Node node = SceneManager.getSceneManager().getActiveNode();

            fId.setText(Integer.toString(node.getID()));

            if (node instanceof MetaDataNode)
            {
                fName.setText((String) ((MetaDataNode) node).getAttribute("name"));
            }
            else
            {
                fName.setText(MetaDataNode.getDefaultName(node));
            }

            fCollidable.setSelection(node.isCollidable());
            fModifiable.setSelection(node.isModifiable());
            fVisible.setSelection(node.isVisible());

            TransformationMatrixf transformation = node.getTransformation();

            fTranslateX.setText(Float.toString(transformation.getTranslation().getX()));
            fTranslateY.setText(Float.toString(transformation.getTranslation().getY()));
            fTranslateZ.setText(Float.toString(transformation.getTranslation().getZ()));

            fRotateX.setText(Float.toString(transformation.getXAxisRotation() * 180.0f / (float) Math.PI));
            fRotateY.setText(Float.toString(transformation.getYAxisRotation() * 180.0f / (float) Math.PI));
            fRotateZ.setText(Float.toString(transformation.getZAxisRotation() * 180.0f / (float) Math.PI));

            if (node instanceof MetaDataNode)
            {
                fType.setText((String) ((MetaDataNode) node).getWrappedNode().getClass().getName());
            }
            else
            {
                fType.setText(node.getClass().getName());
            }

            fNodeViewListener.enable();
        }
    }
}
