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
import com.se.simplicity.editor.ui.views.CameraView;
import com.se.simplicity.rendering.Camera;
import com.se.simplicity.scenegraph.Node;

/**
 * <p>
 * Unit tests for the class {@link com.se.simplicity.editor.ui.views.CameraView CameraView}.
 * </p>
 * 
 * @author Gary Buyn
 */
public class CameraViewTest
{
    /**
     * An instance of the class being unit tested.
     */
    private CameraView testObject;

    /**
     * <p>
     * Setup to perform before each unit test.
     * </p>
     */
    @Before
    public void before()
    {
        testObject = new CameraView(new Shell(), SWT.NONE);

        SceneManager.getSceneManager().reset();
    }

    /**
     * <p>
     * Unit test the constructor {@link com.se.simplicity.editor.ui.views.CameraView#CameraView(Composite, int) CameraView(Composite, int)}.
     * </p>
     */
    @Test
    public void nodeView()
    {
        testObject = new CameraView(new Shell(), SWT.NONE);

        assertTrue(SceneManager.getSceneManager().getSceneChangedListeners().contains(testObject));
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.editor.ui.views.CameraView#dispose() dispose()}.
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
     * Unit test the method {@link com.se.simplicity.editor.ui.views.CameraView#sceneChanged(SceneChangedEvent) sceneChanged(SceneChangedEvent)} with
     * the special condition that the event is of type 'CAMERA_ACTIVATED'.
     * </p>
     */
    @Test
    public void sceneChangedCameraActivated()
    {
        // Create dependencies.
        SceneChangedEvent mockEvent = createMock(SceneChangedEvent.class);
        Camera mockCamera = createMock(Camera.class);
        Node mockNode = createMock(Node.class);

        // Dictate correct behaviour.
        expect(mockEvent.getSceneComponent()).andStubReturn(mockCamera);
        expect(mockEvent.getType()).andStubReturn(SceneChangedEventType.CAMERA_ACTIVATED);
        expect(mockCamera.getNode()).andStubReturn(mockNode);
        expect(mockNode.getID()).andStubReturn(0);
        replay(mockEvent, mockCamera, mockNode);

        // Verify test environment.
        Control[] sections = testObject.getChildren();

        Control[] idWidgets = ((Composite) sections[0]).getChildren();
        assertEquals("", ((Text) idWidgets[1]).getText());

        Control[] sceneGraphWidgets = ((Composite) sections[1]).getChildren();
        assertEquals("", ((Text) sceneGraphWidgets[1]).getText());

        // Perform test.
        testObject.sceneChanged(mockEvent);

        // Verify test.
        assertEquals("CameraX", ((Text) idWidgets[1]).getText());

        assertEquals("0", ((Text) sceneGraphWidgets[1]).getText());
    }
}
