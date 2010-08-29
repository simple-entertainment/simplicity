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
import org.eclipse.swt.widgets.Button;
import org.eclipse.swt.widgets.Composite;
import org.eclipse.swt.widgets.Label;
import org.eclipse.swt.widgets.Text;
import org.eclipse.swt.widgets.Widget;

import com.se.simplicity.editor.internal.SceneChangedEvent;
import com.se.simplicity.editor.internal.SceneChangedEventType;
import com.se.simplicity.editor.internal.SceneChangedListener;
import com.se.simplicity.editor.internal.SceneManager;
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
    private Button collidable;

    /**
     * <p>
     * Displays the 'id' property of a <code>Node</code>.
     * </p>
     */
    private Text id;

    /**
     * <p>
     * Displays the 'modifiable' property of a <code>Node</code>.
     * </p>
     */
    private Button modifiable;

    /**
     * <p>
     * Displays the 'name' property of a <code>Node</code>.
     * </p>
     */
    private Text name;

    /**
     * <p>
     * Listens for changes to displayed properties of a <code>Node</code> (or its sub-components).
     * </p>
     */
    private NodeViewListener nodeListener;

    /**
     * <p>
     * Displays the X axis rotation of a <code>Node</code>.
     * </p>
     */
    private Text rotateX;

    /**
     * <p>
     * Displays the Y axis rotation of a <code>Node</code>.
     * </p>
     */
    private Text rotateY;

    /**
     * <p>
     * Displays the Z axis rotation of a <code>Node</code>.
     * </p>
     */
    private Text rotateZ;

    /**
     * <p>
     * Displays the X axis translation of a <code>Node</code>.
     * </p>
     */
    private Text translateX;

    /**
     * <p>
     * Displays the Y axis translation of a <code>Node</code>.
     * </p>
     */
    private Text translateY;

    /**
     * <p>
     * Displays the Z axis translation of a <code>Node</code>.
     * </p>
     */
    private Text translateZ;

    /**
     * <p>
     * Displays the 'visible' property of a <code>Node</code>.
     * </p>
     */
    private Button visible;

    /**
     * <p>
     * Maps the <code>Widget</code>s displaying the properties of a <code>Node</code> to names so that they may be easily retrieved and their contents
     * saved to the model.
     * </p>
     */
    private Map<Widget, String> widgetBindings;

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

        widgetBindings = new HashMap<Widget, String>();

        SceneManager.getSceneManager().addSceneChangedListener(this);
        nodeListener = new NodeViewListener(widgetBindings);

        setLayout(new GridLayout(4, false));

        addIdentificationWidgets();
        addPropertyWidgets();
        addTranslationWidgets();
        addRotationWidgets();
    }

    /**
     * <p>
     * Adds widgets for the identification related properties of a <code>Node</code>.
     * </p>
     */
    protected void addIdentificationWidgets()
    {
        Composite translation = new Composite(this, SWT.NONE);
        translation.setLayout(new GridLayout(2, false));

        Label labelId = new Label(translation, SWT.NONE);
        labelId.setText("ID");
        id = new Text(translation, SWT.READ_ONLY);
        id.addModifyListener(nodeListener);
        widgetBindings.put(id, "id");

        Label labelName = new Label(translation, SWT.NONE);
        labelName.setText("Name");
        name = new Text(translation, SWT.NONE);
        name.addModifyListener(nodeListener);
        widgetBindings.put(name, "name");
    }

    /**
     * <p>
     * Adds widgets for the general properties of a <code>Node</code>.
     * </p>
     */
    protected void addPropertyWidgets()
    {
        Composite translation = new Composite(this, SWT.NONE);
        translation.setLayout(new GridLayout(1, false));

        collidable = new Button(translation, SWT.CHECK);
        collidable.setText("Collidable");
        // collidable.addModifyListener(nodeModifyListener);
        widgetBindings.put(collidable, "collidable");

        modifiable = new Button(translation, SWT.CHECK);
        modifiable.setText("Modifiable");
        // modifiable.addModifyListener(nodeModifyListener);
        widgetBindings.put(modifiable, "modifiable");

        visible = new Button(translation, SWT.CHECK);
        visible.setText("Visible");
        // visible.addModifyListener(nodeModifyListener);
        widgetBindings.put(visible, "visible");
    }

    /**
     * <p>
     * Adds widgets for the rotation related properties of a <code>Node</code>.
     * </p>
     */
    protected void addRotationWidgets()
    {
        Composite rotation = new Composite(this, SWT.NONE);
        rotation.setLayout(new GridLayout(2, false));

        Label labelX = new Label(rotation, SWT.NONE);
        labelX.setText("X");
        rotateX = new Text(rotation, SWT.NONE);
        rotateX.addModifyListener(nodeListener);
        widgetBindings.put(rotateX, "rotateX");

        Label labelY = new Label(rotation, SWT.NONE);
        labelY.setText("Y");
        rotateY = new Text(rotation, SWT.NONE);
        rotateY.addModifyListener(nodeListener);
        widgetBindings.put(rotateY, "rotateY");

        Label labelZ = new Label(rotation, SWT.NONE);
        labelZ.setText("Z");
        rotateZ = new Text(rotation, SWT.NONE);
        rotateZ.addModifyListener(nodeListener);
        widgetBindings.put(rotateZ, "rotateZ");
    }

    /**
     * <p>
     * Adds widgets for the translation related properties of a <code>Node</code>.
     * </p>
     */
    protected void addTranslationWidgets()
    {
        Composite translation = new Composite(this, SWT.NONE);
        translation.setLayout(new GridLayout(2, false));

        Label labelX = new Label(translation, SWT.NONE);
        labelX.setText("X");
        translateX = new Text(translation, SWT.NONE);
        translateX.addModifyListener(nodeListener);
        widgetBindings.put(translateX, "translateX");

        Label labelY = new Label(translation, SWT.NONE);
        labelY.setText("Y");
        translateY = new Text(translation, SWT.NONE);
        translateY.addModifyListener(nodeListener);
        widgetBindings.put(translateY, "translateY");

        Label labelZ = new Label(translation, SWT.NONE);
        labelZ.setText("Z");
        translateZ = new Text(translation, SWT.NONE);
        translateZ.addModifyListener(nodeListener);
        widgetBindings.put(translateZ, "translateZ");
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
        if (event.getType() == SceneChangedEventType.NODE_ACTIVATED)
        {
            nodeListener.disable();

            Node node = (Node) event.getSceneComponent();

            id.setText(Integer.toString(node.getID()));

            if (node instanceof MetaDataNode)
            {
                name.setText((String) ((MetaDataNode) node).getAttribute("name"));
            }
            else
            {
                name.setText("Node" + node.getID());
            }

            collidable.setSelection(node.isCollidable());
            modifiable.setSelection(node.isModifiable());
            visible.setSelection(node.isVisible());

            TransformationMatrixf transformation = node.getTransformation();

            translateX.setText(Float.toString(transformation.getTranslation().getX()));
            translateY.setText(Float.toString(transformation.getTranslation().getY()));
            translateZ.setText(Float.toString(transformation.getTranslation().getZ()));

            rotateX.setText(Float.toString(transformation.getXAxisRotation()));
            rotateY.setText(Float.toString(transformation.getYAxisRotation()));
            rotateZ.setText(Float.toString(transformation.getZAxisRotation()));

            nodeListener.enable();
        }
    }
}
