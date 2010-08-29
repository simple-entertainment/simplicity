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

import org.eclipse.swt.SWT;
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
import com.se.simplicity.scenegraph.Node;

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
        Node mockNode = createMock(Node.class);

        // Dictate correct behaviour.
        expect(mockEvent.getSceneComponent()).andStubReturn(mockLight);
        expect(mockEvent.getType()).andStubReturn(SceneChangedEventType.LIGHT_ACTIVATED);
        expect(mockLight.getNode()).andStubReturn(mockNode);
        expect(mockNode.getID()).andStubReturn(0);
        replay(mockEvent, mockLight, mockNode);

        // Verify test environment.
        Control[] sections = testObject.getChildren();

        Control[] idWidgets = ((Composite) sections[0]).getChildren();
        assertEquals("", ((Text) idWidgets[1]).getText());

        Control[] sceneGraphWidgets = ((Composite) sections[1]).getChildren();
        assertEquals("", ((Text) sceneGraphWidgets[1]).getText());

        // Perform test.
        testObject.sceneChanged(mockEvent);

        // Verify test.
        assertEquals("LightX", ((Text) idWidgets[1]).getText());

        assertEquals("0", ((Text) sceneGraphWidgets[1]).getText());
    }
}
