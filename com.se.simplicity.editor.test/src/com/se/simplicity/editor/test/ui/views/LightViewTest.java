/*
    This file is part of The Simplicity Engine.

    The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
    by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

    The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
package com.se.simplicity.editor.test.ui.views;

import static org.easymock.EasyMock.expect;
import static org.easymock.classextension.EasyMock.createMock;
import static org.easymock.classextension.EasyMock.replay;
import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertTrue;

import java.util.ArrayList;

import org.eclipse.swt.SWT;
import org.eclipse.swt.widgets.Combo;
import org.eclipse.swt.widgets.Composite;
import org.eclipse.swt.widgets.Control;
import org.eclipse.swt.widgets.Shell;
import org.eclipse.swt.widgets.Text;
import org.junit.Before;
import org.junit.Test;

import com.se.simplicity.editor.internal.SceneChangedEvent;
import com.se.simplicity.editor.internal.SceneChangedEventType;
import com.se.simplicity.editor.internal.SceneManager;
import com.se.simplicity.editor.ui.views.LightView;
import com.se.simplicity.rendering.Light;
import com.se.simplicity.rendering.LightingMode;
import com.se.simplicity.scene.Scene;
import com.se.simplicity.scenegraph.Node;
import com.se.simplicity.scenegraph.SceneGraph;
import com.se.simplicity.util.metadata.rendering.MetaDataLight;

/**
 * <p>
 * Unit tests for the class {@link com.se.simplicity.editor.ui.views.LightView LightView}.
 * </p>
 * 
 * @author Gary Buyn
 */
public class LightViewTest
{
    /**
     * An instance of the class being unit tested.
     */
    private LightView testObject;

    /**
     * <p>
     * Setup to perform before each unit test.
     * </p>
     */
    @Before
    public void before()
    {
        testObject = new LightView(new Shell(), SWT.NONE);

        SceneManager.getSceneManager().reset();
    }

    /**
     * <p>
     * Unit test the constructor {@link com.se.simplicity.editor.ui.views.LightView#LightView(Composite, int) LightView(Composite, int)}.
     * </p>
     */
    @Test
    public void lightView()
    {
        testObject = new LightView(new Shell(), SWT.NONE);

        assertTrue(SceneManager.getSceneManager().getSceneChangedListeners().contains(testObject));
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.editor.ui.views.LightView#dispose() dispose()}.
     * </p>
     */
    @Test
    public void dispose()
    {
        testObject.dispose();

        assertTrue(!SceneManager.getSceneManager().getSceneChangedListeners().contains(testObject));
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.editor.ui.views.LightView#sceneChanged(SceneChangedEvent) sceneChanged(SceneChangedEvent)} with
     * the special condition that the event is of type 'LIGHT_ACTIVATED'.
     * </p>
     */
    @Test
    public void sceneChangedLightActivated()
    {
        // Create dependencies.
        SceneChangedEvent mockEvent = createMock(SceneChangedEvent.class);
        Light mockLight = createMock(Light.class);
        ArrayList<Light> lights = new ArrayList<Light>();
        lights.add(mockLight);

        Scene mockScene = createMock(Scene.class);
        Node mockNode = createMock(Node.class);

        // Dictate correct behaviour.
        expect(mockEvent.getSceneComponent()).andStubReturn(mockLight);
        expect(mockEvent.getType()).andStubReturn(SceneChangedEventType.LIGHT_ACTIVATED);
        expect(mockLight.getNode()).andStubReturn(mockNode);
        expect(mockLight.getLightingMode()).andStubReturn(LightingMode.SCENE);
        expect(mockLight.getAmbientLight()).andStubReturn(new float[] {0.1f, 0.1f, 0.1f, 1.0f});
        expect(mockLight.getDiffuseLight()).andStubReturn(new float[] {0.1f, 0.1f, 0.1f, 1.0f});
        expect(mockLight.getSpecularLight()).andStubReturn(new float[] {0.1f, 0.1f, 0.1f, 1.0f});
        expect(mockScene.getLights()).andStubReturn(lights);
        expect(mockNode.getID()).andStubReturn(0);
        replay(mockEvent, mockLight, mockScene, mockNode);

        // Initialise test environment.
        SceneManager.getSceneManager().addSceneDefinition(mockScene, "Test");
        SceneManager.getSceneManager().setActiveScene("Test");
        SceneManager.getSceneManager().setActiveLight(mockLight);

        // Verify test environment.
        Control[] sections = testObject.getChildren();

        Control[] idWidgets = ((Composite) sections[0]).getChildren();
        assertEquals("", ((Text) idWidgets[1]).getText());

        Control[] generalWidgets = ((Composite) sections[1]).getChildren();
        assertEquals("", ((Text) generalWidgets[1]).getText());
        assertEquals("", ((Combo) generalWidgets[3]).getText());

        Control[] ambientWidgets = ((Composite) sections[2]).getChildren();
        assertEquals("", ((Text) ambientWidgets[1]).getText());
        assertEquals("", ((Text) ambientWidgets[3]).getText());
        assertEquals("", ((Text) ambientWidgets[5]).getText());

        Control[] diffuseWidgets = ((Composite) sections[3]).getChildren();
        assertEquals("", ((Text) diffuseWidgets[1]).getText());
        assertEquals("", ((Text) diffuseWidgets[3]).getText());
        assertEquals("", ((Text) diffuseWidgets[5]).getText());

        Control[] specularWidgets = ((Composite) sections[4]).getChildren();
        assertEquals("", ((Text) specularWidgets[1]).getText());
        assertEquals("", ((Text) specularWidgets[3]).getText());
        assertEquals("", ((Text) specularWidgets[5]).getText());

        Control[] reflectionWidgets = ((Composite) sections[5]).getChildren();
        assertEquals("", ((Text) reflectionWidgets[1]).getText());

        // Perform test.
        testObject.sceneChanged(mockEvent);

        // Verify test.
        assertEquals("LightX", ((Text) idWidgets[1]).getText());

        assertEquals("0", ((Text) generalWidgets[1]).getText());
        assertEquals("SCENE", ((Combo) generalWidgets[3]).getText());

        assertEquals("0.1", ((Text) ambientWidgets[1]).getText());
        assertEquals("0.1", ((Text) ambientWidgets[3]).getText());
        assertEquals("0.1", ((Text) ambientWidgets[5]).getText());

        assertEquals("0.1", ((Text) diffuseWidgets[1]).getText());
        assertEquals("0.1", ((Text) diffuseWidgets[3]).getText());
        assertEquals("0.1", ((Text) diffuseWidgets[5]).getText());

        assertEquals("0.1", ((Text) specularWidgets[1]).getText());
        assertEquals("0.1", ((Text) specularWidgets[3]).getText());
        assertEquals("0.1", ((Text) specularWidgets[5]).getText());

        assertEquals("$Proxy5", ((Text) reflectionWidgets[1]).getText());
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.editor.ui.views.LightView#sceneChanged(SceneChangedEvent) sceneChanged(SceneChangedEvent)} with
     * the special condition that the event is of type 'LIGHT_ACTIVATED' and the <code>Light</code> that was activated was a
     * <code>MetaDataLight</code>.
     * </p>
     */
    @Test
    public void sceneChangedMetaDataLightActivated()
    {
        // Create dependencies.
        SceneChangedEvent mockEvent = createMock(SceneChangedEvent.class);
        MetaDataLight mockMetaDataLight = createMock(MetaDataLight.class);
        Light mockLight = createMock(Light.class);
        ArrayList<Light> lights = new ArrayList<Light>();
        lights.add(mockMetaDataLight);

        Scene mockScene = createMock(Scene.class);
        Node mockNode = createMock(Node.class);

        // Dictate correct behaviour.
        expect(mockEvent.getSceneComponent()).andStubReturn(mockMetaDataLight);
        expect(mockEvent.getType()).andStubReturn(SceneChangedEventType.LIGHT_ACTIVATED);
        expect(mockMetaDataLight.getAttribute("name")).andStubReturn("Test");
        expect(mockMetaDataLight.getNode()).andStubReturn(mockNode);
        expect(mockMetaDataLight.getLightingMode()).andStubReturn(LightingMode.SCENE);
        expect(mockMetaDataLight.getAmbientLight()).andStubReturn(new float[] {0.1f, 0.1f, 0.1f, 1.0f});
        expect(mockMetaDataLight.getDiffuseLight()).andStubReturn(new float[] {0.1f, 0.1f, 0.1f, 1.0f});
        expect(mockMetaDataLight.getSpecularLight()).andStubReturn(new float[] {0.1f, 0.1f, 0.1f, 1.0f});
        expect(mockScene.getLights()).andStubReturn(lights);
        expect(mockNode.getID()).andStubReturn(0);
        expect(mockMetaDataLight.getWrappedLight()).andStubReturn(mockLight);
        replay(mockEvent, mockMetaDataLight, mockLight, mockScene, mockNode);

        // Initialise test environment.
        SceneManager.getSceneManager().addSceneDefinition(mockScene, "Test");
        SceneManager.getSceneManager().setActiveScene("Test");
        SceneManager.getSceneManager().setActiveLight(mockMetaDataLight);

        // Verify test environment.
        Control[] sections = testObject.getChildren();

        Control[] idWidgets = ((Composite) sections[0]).getChildren();
        assertEquals("", ((Text) idWidgets[1]).getText());

        Control[] reflectionWidgets = ((Composite) sections[5]).getChildren();
        assertEquals("", ((Text) reflectionWidgets[1]).getText());

        // Perform test.
        testObject.sceneChanged(mockEvent);

        // Verify test.
        assertEquals("Test", ((Text) idWidgets[1]).getText());

        assertEquals("$Proxy5", ((Text) reflectionWidgets[1]).getText());
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.editor.ui.views.LightView#sceneChanged(SceneChangedEvent) sceneChanged(SceneChangedEvent)} with
     * the special condition that the scene component held in the event is null.
     * </p>
     */
    @Test
    public void sceneChangedNullSceneComponent()
    {
        // Create dependencies.
        SceneChangedEvent mockEvent = createMock(SceneChangedEvent.class);

        // Dictate correct behaviour.
        expect(mockEvent.getSceneComponent()).andStubReturn(null);
        replay(mockEvent);

        // Perform test.
        testObject.sceneChanged(mockEvent);
    }
}
