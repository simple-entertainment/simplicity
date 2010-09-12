/*
    This file is part of The Simplicity Engine.

    The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
    by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

    The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
package com.se.simplicity.editor.test.ui.views;

import static org.easymock.classextension.EasyMock.expect;
import static org.easymock.classextension.EasyMock.createMock;
import static org.easymock.classextension.EasyMock.replay;
import static org.junit.Assert.assertTrue;

import org.eclipse.swt.custom.StackLayout;
import org.eclipse.swt.widgets.Shell;
import org.eclipse.ui.IViewSite;
import org.eclipse.ui.IWorkbenchPage;
import org.eclipse.ui.PartInitException;
import org.junit.Before;
import org.junit.Test;

import com.se.simplicity.editor.internal.SceneSelection;
import com.se.simplicity.editor.ui.views.CameraView;
import com.se.simplicity.editor.ui.views.LightView;
import com.se.simplicity.editor.ui.views.NodeView;
import com.se.simplicity.editor.ui.views.SceneComponentView;
import com.se.simplicity.jogl.rendering.SimpleJOGLCamera;
import com.se.simplicity.jogl.rendering.SimpleJOGLLight;
import com.se.simplicity.scenegraph.Node;
import com.se.simplicity.scenegraph.SimpleNode;

/**
 * <p>
 * Unit tests for the class {@link com.se.simplicity.editor.ui.views.SceneComponentView SceneComponentView}.
 * </p>
 * 
 * @author Gary Buyn
 */
public class SceneComponentViewTest
{
    /**
     * An instance of the class being unit tested.
     */
    private SceneComponentView testObject;

    /**
     * <p>
     * Setup to perform before each unit test.
     * </p>
     */
    @Before
    public void before()
    {
        testObject = new SceneComponentView();
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.editor.ui.views.SceneComponentView#selectionChanged(ISelection) selectionChanged(ISelection)}
     * with the special condition that the scene component is a Camera.
     * </p>
     * 
     * @throws PartInitException Thrown if the initialisation fails.
     */
    @Test
    public void selectionChangedCamera() throws PartInitException
    {
        // Create dependencies.
        IViewSite mockSite = createMock(IViewSite.class);
        IWorkbenchPage mockPage = createMock(IWorkbenchPage.class);
        SceneSelection mockSelection = createMock(SceneSelection.class);
        SimpleJOGLCamera camera = new SimpleJOGLCamera();
        camera.setNode(createMock(Node.class));

        // Dictate correct behaviour.
        expect(mockSite.getPage()).andStubReturn(mockPage);
        expect(mockSelection.getSceneComponent()).andStubReturn(camera);
        replay(mockSite, mockSelection);

        // Initialise test environment.
        testObject.init(mockSite);
        testObject.createPartControl(new Shell());

        // Perform test.
        testObject.selectionChanged(null, mockSelection);

        // Verify test.
        assertTrue(((StackLayout) testObject.getParent().getLayout()).topControl instanceof CameraView);
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.editor.ui.views.SceneComponentView#selectionChanged(ISelection) selectionChanged(ISelection)}
     * with the special condition that the scene component is a Light.
     * </p>
     * 
     * @throws PartInitException Thrown if the initialisation fails.
     */
    @Test
    public void selectionChangedLight() throws PartInitException
    {
        // Create dependencies.
        IViewSite mockSite = createMock(IViewSite.class);
        IWorkbenchPage mockPage = createMock(IWorkbenchPage.class);
        SceneSelection mockSelection = createMock(SceneSelection.class);
        SimpleJOGLLight light = new SimpleJOGLLight();
        light.setNode(createMock(Node.class));

        // Dictate correct behaviour.
        expect(mockSite.getPage()).andStubReturn(mockPage);
        expect(mockSelection.getSceneComponent()).andStubReturn(light);
        replay(mockSite, mockSelection);

        // Initialise test environment.
        testObject.init(mockSite);
        testObject.createPartControl(new Shell());

        // Perform test.
        testObject.selectionChanged(null, mockSelection);

        // Verify test.
        assertTrue(((StackLayout) testObject.getParent().getLayout()).topControl instanceof LightView);
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.editor.ui.views.SceneComponentView#selectionChanged(ISelection) selectionChanged(ISelection)}
     * with the special condition that the scene component is a Node.
     * </p>
     * 
     * @throws PartInitException Thrown if the initialisation fails.
     */
    @Test
    public void selectionChangedNode() throws PartInitException
    {
        // Create dependencies.
        IViewSite mockSite = createMock(IViewSite.class);
        IWorkbenchPage mockPage = createMock(IWorkbenchPage.class);
        SceneSelection mockSelection = createMock(SceneSelection.class);
        SimpleNode node = new SimpleNode();

        // Dictate correct behaviour.
        expect(mockSite.getPage()).andStubReturn(mockPage);
        expect(mockSelection.getSceneComponent()).andStubReturn(node);
        replay(mockSite, mockSelection);

        // Initialise test environment.
        testObject.init(mockSite);
        testObject.createPartControl(new Shell());

        // Perform test.
        testObject.selectionChanged(null, mockSelection);

        // Verify test.
        assertTrue(((StackLayout) testObject.getParent().getLayout()).topControl instanceof NodeView);
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.editor.ui.views.SceneComponentView#setSelectedSceneComponent(Object)
     * setSelectedSceneComponent(Object)} with the special condition that the scene component is null.
     * </p>
     * 
     * @throws PartInitException Thrown if the initialisation fails.
     */
    @Test
    public void selectionChangedNull() throws PartInitException
    {
        // Create dependencies.
        IViewSite mockSite = createMock(IViewSite.class);
        IWorkbenchPage mockPage = createMock(IWorkbenchPage.class);
        SceneSelection mockSelection = createMock(SceneSelection.class);

        // Dictate correct behaviour.
        expect(mockSite.getPage()).andStubReturn(mockPage);
        expect(mockSelection.getSceneComponent()).andStubReturn(null);
        replay(mockSite, mockSelection);

        // Initialise test environment.
        testObject.init(mockSite);
        testObject.createPartControl(new Shell());

        // Perform test.
        testObject.selectionChanged(null, mockSelection);

        // Verify test results.
        assertTrue(!(((StackLayout) testObject.getParent().getLayout()).topControl instanceof CameraView));
        assertTrue(!(((StackLayout) testObject.getParent().getLayout()).topControl instanceof LightView));
        assertTrue(!(((StackLayout) testObject.getParent().getLayout()).topControl instanceof NodeView));
    }
}
