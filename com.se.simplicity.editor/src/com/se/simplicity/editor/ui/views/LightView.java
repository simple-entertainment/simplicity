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
import com.se.simplicity.rendering.Light;
import com.se.simplicity.rendering.LightingMode;
import com.se.simplicity.util.metadata.rendering.MetaDataLight;

/**
 * <p>
 * An eclipse view that displays details for the currently active <code>Light</code> in the <code>Scene</code> (if there is one).
 * </p>
 * 
 * @author Gary Buyn
 */
public class LightView extends Composite implements SceneChangedListener
{
    /**
     * <p>
     * Displays the blue ambient colour of a <code>Light</code>.
     * </p>
     */
    private Text fAmbientB;

    /**
     * <p>
     * Displays the green ambient colour of a <code>Light</code>.
     * </p>
     */
    private Text fAmbientG;

    /**
     * <p>
     * Displays the red ambient colour of a <code>Light</code>.
     * </p>
     */
    private Text fAmbientR;

    /**
     * <p>
     * Displays the blue diffuse colour of a <code>Light</code>.
     * </p>
     */
    private Text fDiffuseB;

    /**
     * <p>
     * Displays the green diffuse colour of a <code>Light</code>.
     * </p>
     */
    private Text fDiffuseG;

    /**
     * <p>
     * Displays the red diffuse colour of a <code>Light</code>.
     * </p>
     */
    private Text fDiffuseR;

    /**
     * <p>
     * Displays the <code>LightingMode</code> of a <code>Light</code>.
     * </p>
     */
    private Combo fLightingMode;

    /**
     * <p>
     * Listens for changes to displayed properties of a <code>Light</code> (or its sub-components).
     * </p>
     */
    private LightViewListener fLightViewListener;

    /**
     * <p>
     * Displays the 'name' property of a <code>Light</code>.
     * </p>
     */
    private Text fName;

    /**
     * <p>
     * Displays the 'node' property of a <code>Light</code>.
     * </p>
     */
    private Text fNode;

    /**
     * <p>
     * Displays the blue specular colour of a <code>Light</code>.
     * </p>
     */
    private Text fSpecularB;

    /**
     * <p>
     * Displays the green specular colour of a <code>Light</code>.
     * </p>
     */
    private Text fSpecularG;

    /**
     * <p>
     * Displays the red specular colour of a <code>Light</code>.
     * </p>
     */
    private Text fSpecularR;

    /**
     * <p>
     * Displays the type of a <code>Light</code>.
     * </p>
     */
    private Text fType;

    /**
     * <p>
     * Maps the <code>Widget</code>s displaying the properties of a <code>Light</code> to names so that they may be easily retrieved and their
     * contents saved to the model.
     * </p>
     */
    private Map<Widget, String> fWidgetBindings;

    /**
     * <p>
     * Creates an instance of <code>LightView</code>.
     * </p>
     * 
     * @param parent The parent <code>Composite</code>.
     * @param style The SWT style.
     */
    public LightView(final Composite parent, final int style)
    {
        super(parent, style);

        fWidgetBindings = new HashMap<Widget, String>();

        SceneManager.getSceneManager().addSceneChangedListener(this);
        fLightViewListener = new LightViewListener(fWidgetBindings);

        setLayout(new GridLayout(5, false));

        addIdentificationWidgets();
        addGeneralWidgets();
        addAmbientWidgets();
        addDiffuseWidgets();
        addSpecularWidgets();
        addReflectionWidgets();
    }

    /**
     * <p>
     * Adds widgets for the ambient light related properties of a <code>Light</code>.
     * </p>
     */
    protected void addAmbientWidgets()
    {
        Group diffuse = new Group(this, SWT.NONE);
        diffuse.setLayoutData(new GridData(SWT.LEAD, SWT.FILL, false, false));
        diffuse.setLayout(new GridLayout(2, false));
        diffuse.setText("Ambient Light");

        Label labelR = new Label(diffuse, SWT.NONE);
        labelR.setText("R");
        fAmbientR = new Text(diffuse, SWT.NONE);
        fAmbientR.addModifyListener(fLightViewListener);
        fWidgetBindings.put(fAmbientR, "ambientR");

        Label labelG = new Label(diffuse, SWT.NONE);
        labelG.setText("G");
        fAmbientG = new Text(diffuse, SWT.NONE);
        fAmbientG.addModifyListener(fLightViewListener);
        fWidgetBindings.put(fAmbientG, "ambientG");

        Label labelB = new Label(diffuse, SWT.NONE);
        labelB.setText("B");
        fAmbientB = new Text(diffuse, SWT.NONE);
        fAmbientB.addModifyListener(fLightViewListener);
        fWidgetBindings.put(fAmbientB, "ambientB");
    }

    /**
     * <p>
     * Adds widgets for the diffuse light related properties of a <code>Light</code>.
     * </p>
     */
    protected void addDiffuseWidgets()
    {
        Group diffuse = new Group(this, SWT.NONE);
        diffuse.setLayoutData(new GridData(SWT.LEAD, SWT.FILL, false, false));
        diffuse.setLayout(new GridLayout(2, false));
        diffuse.setText("Diffuse Light");

        Label labelR = new Label(diffuse, SWT.NONE);
        labelR.setText("R");
        fDiffuseR = new Text(diffuse, SWT.NONE);
        fDiffuseR.addModifyListener(fLightViewListener);
        fWidgetBindings.put(fDiffuseR, "diffuseR");

        Label labelG = new Label(diffuse, SWT.NONE);
        labelG.setText("G");
        fDiffuseG = new Text(diffuse, SWT.NONE);
        fDiffuseG.addModifyListener(fLightViewListener);
        fWidgetBindings.put(fDiffuseG, "diffuseG");

        Label labelB = new Label(diffuse, SWT.NONE);
        labelB.setText("B");
        fDiffuseB = new Text(diffuse, SWT.NONE);
        fDiffuseB.addModifyListener(fLightViewListener);
        fWidgetBindings.put(fDiffuseB, "diffuseB");
    }

    /**
     * <p>
     * Adds widgets for the general properties of a <code>Light</code>.
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
        fNode.addModifyListener(fLightViewListener);
        fWidgetBindings.put(fNode, "node");

        Label labelLightingMode = new Label(general, SWT.NONE);
        labelLightingMode.setText("Lighting Mode");
        fLightingMode = new Combo(general, SWT.NONE);
        fLightingMode.add("SCENE");
        fLightingMode.add("SHADED");
        fLightingMode.add("SOLID");
        fLightingMode.addSelectionListener(fLightViewListener);
        fWidgetBindings.put(fLightingMode, "lightingMode");
    }

    /**
     * <p>
     * Adds widgets for the identification related properties of a <code>Light</code>.
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
        fName.addModifyListener(fLightViewListener);
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
        fType.addModifyListener(fLightViewListener);
        fWidgetBindings.put(fType, "type");
    }

    /**
     * <p>
     * Adds widgets for the specular light related properties of a <code>Light</code>.
     * </p>
     */
    protected void addSpecularWidgets()
    {
        Group diffuse = new Group(this, SWT.NONE);
        diffuse.setLayoutData(new GridData(SWT.LEAD, SWT.FILL, false, false));
        diffuse.setLayout(new GridLayout(2, false));
        diffuse.setText("Specular Light");

        Label labelR = new Label(diffuse, SWT.NONE);
        labelR.setText("R");
        fSpecularR = new Text(diffuse, SWT.NONE);
        fSpecularR.addModifyListener(fLightViewListener);
        fWidgetBindings.put(fSpecularR, "specularR");

        Label labelG = new Label(diffuse, SWT.NONE);
        labelG.setText("G");
        fSpecularG = new Text(diffuse, SWT.NONE);
        fSpecularG.addModifyListener(fLightViewListener);
        fWidgetBindings.put(fSpecularG, "specularG");

        Label labelB = new Label(diffuse, SWT.NONE);
        labelB.setText("B");
        fSpecularB = new Text(diffuse, SWT.NONE);
        fSpecularB.addModifyListener(fLightViewListener);
        fWidgetBindings.put(fSpecularB, "specularB");
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
        if (event.getSceneComponent() == null)
        {
            return;
        }

        if (event.getType() == SceneChangedEventType.LIGHT_ACTIVATED)
        {
            fLightViewListener.disable();

            Light light = (Light) event.getSceneComponent();

            if (light instanceof MetaDataLight)
            {
                fName.setText((String) ((MetaDataLight) light).getAttribute("name"));
            }
            else
            {
                fName.setText("LightX");
            }

            fNode.setText(Integer.toString(light.getNode().getID()));

            if (light.getLightingMode() == LightingMode.SCENE)
            {
                fLightingMode.setText("SCENE");
            }
            else if (light.getLightingMode() == LightingMode.SHADED)
            {
                fLightingMode.setText("SHADED");
            }
            else if (light.getLightingMode() == LightingMode.SOLID)
            {
                fLightingMode.setText("SOLID");
            }

            float[] ambientLight = light.getAmbientLight();
            fAmbientR.setText(Float.toString(ambientLight[0]));
            fAmbientG.setText(Float.toString(ambientLight[1]));
            fAmbientB.setText(Float.toString(ambientLight[2]));

            float[] diffuseLight = light.getDiffuseLight();
            fDiffuseR.setText(Float.toString(diffuseLight[0]));
            fDiffuseG.setText(Float.toString(diffuseLight[1]));
            fDiffuseB.setText(Float.toString(diffuseLight[2]));

            float[] specularLight = light.getSpecularLight();
            fSpecularR.setText(Float.toString(specularLight[0]));
            fSpecularG.setText(Float.toString(specularLight[1]));
            fSpecularB.setText(Float.toString(specularLight[2]));

            if (light instanceof MetaDataLight)
            {
                fType.setText((String) ((MetaDataLight) light).getWrappedLight().getClass().getName());
            }
            else
            {
                fType.setText(light.getClass().getName());
            }

            fLightViewListener.enable();
        }
    }
}
