/*
    This file is part of The Simplicity Engine.

    The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
    by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

    The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
package com.se.simplicity.editor.test.ui.editors;

import static org.easymock.EasyMock.expect;
import static org.easymock.classextension.EasyMock.createMock;
import static org.easymock.classextension.EasyMock.replay;
import static org.easymock.classextension.EasyMock.verify;
import static org.junit.Assert.assertEquals;

import java.util.ArrayList;

import org.junit.Before;
import org.junit.Test;

import com.se.simplicity.editor.internal.SceneManager;
import com.se.simplicity.editor.ui.editors.VisualScenePickListener;
import com.se.simplicity.jogl.rendering.OutlineJOGLRenderer;
import com.se.simplicity.picking.event.PickEvent;
import com.se.simplicity.rendering.Renderer;
import com.se.simplicity.rendering.engine.RenderingEngine;
import com.se.simplicity.scene.Scene;
import com.se.simplicity.scenegraph.Node;
import com.se.simplicity.scenegraph.SceneGraph;

/**
 * <p>
 * Unit tests for the class {@link com.se.simplicity.editor.ui.editors.VisualScenePickListener VisualScenePickListener}.
 * </p>
 * 
 * @author Gary Buyn
 */
public class VisualScenePickListenerTest
{
    /**
     * An instance of the class being unit tested.
     */
    private VisualScenePickListener testObject;

    /**
     * <p>
     * Setup to perform before each unit test.
     * </p>
     */
    @Before
    public void before()
    {
        SceneManager.getSceneManager().reset();
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.editor.ui.editors.VisualScenePickListener#scenePicked(PickEvent) scenePicked(PickEvent)}.
     * </p>
     */
    @Test
    public void scenePicked()
    {
        // Create dependencies.
        PickEvent mockPickEvent = createMock(PickEvent.class);

        Scene mockScene = createMock(Scene.class);
        SceneGraph mockSceneGraph = createMock(SceneGraph.class);
        Node mockNode = createMock(Node.class);

        RenderingEngine mockRenderingEngine = createMock(RenderingEngine.class);
        ArrayList<Renderer> renderers = new ArrayList<Renderer>();
        OutlineJOGLRenderer mockOutlineRenderer = createMock(OutlineJOGLRenderer.class);
        renderers.add(mockOutlineRenderer);
        renderers.add(mockOutlineRenderer);

        // Dictate correct behaviour.
        expect(mockScene.getSceneGraph()).andStubReturn(mockSceneGraph);
        expect(mockSceneGraph.getNode(0)).andStubReturn(mockNode);
        expect(mockNode.getID()).andStubReturn(0);
        expect(mockRenderingEngine.getRenderers()).andStubReturn(renderers);
        expect(mockPickEvent.getHitCount()).andStubReturn(1);
        expect(mockPickEvent.getHit(0)).andStubReturn(new Object[] {mockNode});
        mockRenderingEngine.setRendererRoot(mockOutlineRenderer, mockNode);
        replay(mockPickEvent, mockScene, mockSceneGraph, mockNode, mockRenderingEngine);

        // Initialise test environment.
        SceneManager.getSceneManager().addSceneDefinition(mockScene, "Test");
        SceneManager.getSceneManager().setActiveScene("Test");
        testObject = new VisualScenePickListener(mockRenderingEngine);

        // Perform test.
        testObject.scenePicked(mockPickEvent);

        // Verify test results.
        verify(mockRenderingEngine);

        assertEquals(mockNode, SceneManager.getSceneManager().getActiveNode());
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.editor.ui.editors.VisualScenePickListener#scenePicked(PickEvent) scenePicked(PickEvent)} with the
     * special condition that no hits were made.
     * </p>
     */
    @Test
    public void scenePickedNoHits()
    {
        // Create dependencies.
        PickEvent mockPickEvent = createMock(PickEvent.class);

        RenderingEngine mockRenderingEngine = createMock(RenderingEngine.class);
        ArrayList<Renderer> renderers = new ArrayList<Renderer>();
        OutlineJOGLRenderer mockOutlineRenderer = createMock(OutlineJOGLRenderer.class);
        renderers.add(mockOutlineRenderer);
        renderers.add(mockOutlineRenderer);

        // Dictate correct behaviour.
        expect(mockRenderingEngine.getRenderers()).andStubReturn(renderers);
        expect(mockPickEvent.getHitCount()).andStubReturn(0);
        mockRenderingEngine.setRendererRoot(mockOutlineRenderer, null);
        replay(mockPickEvent, mockRenderingEngine);

        // Initialise test environment.
        testObject = new VisualScenePickListener(mockRenderingEngine);

        // Perform test.
        testObject.scenePicked(mockPickEvent);

        // Verify test results.
        verify(mockRenderingEngine);

        assertEquals(null, SceneManager.getSceneManager().getActiveNode());
    }
}
