/*
    This file is part of The Simplicity Engine.

    The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
    by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

    The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
package com.se.simplicity.editor.test.controller.scene;

import static org.easymock.classextension.EasyMock.anyObject;
import static org.easymock.classextension.EasyMock.expect;
import static org.easymock.classextension.EasyMock.createMock;
import static org.easymock.classextension.EasyMock.replay;
import static org.easymock.classextension.EasyMock.reset;
import static org.easymock.classextension.EasyMock.verify;

import javax.media.opengl.GLContext;

import org.eclipse.swt.events.ControlListener;
import org.eclipse.swt.events.MouseListener;
import org.eclipse.swt.widgets.Composite;
import org.eclipse.swt.widgets.Display;
import org.eclipse.swt.widgets.Shell;
import org.junit.Before;
import org.junit.Test;

import com.se.simplicity.editor.controller.scene.visual.VisualSceneController;
import com.se.simplicity.editor.view.scene.visual.VisualSceneView;
import com.se.simplicity.jogl.test.mocks.MockGL;
import com.se.simplicity.jogl.viewport.SimpleJOGLViewport;

public class SceneControllerTest
{
    /**
     * An instance of the class being unit tested.
     */
    private VisualSceneController testObject;

    /**
     * <p>
     * Setup to perform before each unit test.
     * </p>
     */
    @Before
    public void before()
    {
        testObject = new VisualSceneController();
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.editor.controller.scene.VisualSceneController.init init()}.
     * </p>
     */
    @Test
    public void init()
    {
        Composite mockComposite = createMock(Composite.class);
        SimpleJOGLViewport mockViewport = createMock(SimpleJOGLViewport.class);
        VisualSceneView mockSceneView = createMock(VisualSceneView.class);
        GLContext mockGlContext = createMock(GLContext.class);
        Shell mockShell = createMock(Shell.class);
        MockGL mockGl = new MockGL();

        testObject.setModel(mockViewport);
        testObject.setView(mockSceneView);

        reset(mockSceneView, mockViewport);
        expect(mockSceneView.setParent(mockComposite)).andReturn(true);
        expect(mockSceneView.getGLContext()).andReturn(mockGlContext);
        expect(mockGlContext.getGL()).andStubReturn(mockGl);
        mockViewport.setGL(mockGl);
        mockSceneView.addControlListener((ControlListener) anyObject());
        mockSceneView.addMouseListener((MouseListener) anyObject());
        expect(mockSceneView.getShell()).andReturn(mockShell);
        expect(mockShell.getDisplay()).andReturn(createMock(Display.class));
        replay(mockSceneView, mockViewport, mockGlContext, mockShell);

        testObject.init(mockComposite);

        verify(mockSceneView, mockViewport);
    }
}
