/*
    This file is part of The Simplicity Engine.

    The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
    by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

    The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
package com.se.simplicity.editor.test.internal.rendering;

import static org.easymock.EasyMock.expect;
import static org.easymock.classextension.EasyMock.createMock;
import static org.easymock.classextension.EasyMock.replay;
import static org.easymock.classextension.EasyMock.reset;
import static org.easymock.classextension.EasyMock.verify;

import org.junit.Test;

import com.se.simplicity.editor.internal.SelectionMode;
import com.se.simplicity.editor.internal.Widget;
import com.se.simplicity.editor.internal.rendering.WidgetJOGLRenderer;
import com.se.simplicity.editor.internal.selection.SceneSelection;
import com.se.simplicity.jogl.rendering.SimpleJOGLRenderer;
import com.se.simplicity.jogl.test.mocks.MockGL;
import com.se.simplicity.model.Model;
import com.se.simplicity.model.VertexGroup;
import com.se.simplicity.scenegraph.model.ModelNode;
import com.se.simplicity.vector.SimpleTransformationMatrixf44;
import com.se.simplicity.vector.SimpleTranslationVectorf4;

/**
 * <p>
 * Unit tests for the class {@link com.se.simplicity.editor.internal.rendering.WidgetJOGLRenderer WidgetJOGLRenderer}.
 * </p>
 * 
 * @author Gary Buyn
 */
public class WidgetJOGLRendererTest
{
    /**
     * An instance of the class being unit tested.
     */
    private WidgetJOGLRenderer testObject;

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.editor.internal.rendering.WidgetJOGLRenderer#renderModel(Model, int) renderModel(Model, int)}
     * with the special condition that a primitive is selected.
     * </p>
     */
    @Test
    public void renderModelPrimitiveSelected()
    {
        // Create dependencies.
        SimpleJOGLRenderer mockRenderer = createMock(SimpleJOGLRenderer.class);
        MockGL mockGl = new MockGL();
        VertexGroup mockModel0 = createMock(VertexGroup.class);
        VertexGroup mockModel0Subset = createMock(VertexGroup.class);

        Widget mockWidget = createMock(Widget.class);
        ModelNode mockNode0 = createMock(ModelNode.class);
        Model mockModel1 = createMock(Model.class);

        SceneSelection mockSelection = createMock(SceneSelection.class);
        ModelNode mockNode1 = createMock(ModelNode.class);
        VertexGroup mockPrimitive = createMock(VertexGroup.class);

        // Dictate correct behaviour.
        expect(mockModel0.getVertexCount()).andStubReturn(3);
        expect(mockModel0Subset.getCenter()).andStubReturn(new SimpleTranslationVectorf4());
        expect(mockWidget.getSelection()).andStubReturn(mockSelection);
        expect(mockWidget.atSelectionOnly()).andStubReturn(true);
        expect(mockWidget.alwaysFacesCamera()).andStubReturn(false);
        expect(mockWidget.getRootNode()).andStubReturn(mockNode0);
        expect(mockWidget.isOutlined()).andStubReturn(false);
        expect(mockSelection.getNode()).andStubReturn(mockNode1);
        expect(mockSelection.getPrimitive()).andStubReturn(mockPrimitive);
        expect(mockNode0.hasChildren()).andStubReturn(false);
        expect(mockNode0.getTransformation()).andStubReturn(new SimpleTransformationMatrixf44());
        expect(mockNode0.getModel()).andStubReturn(mockModel1);
        expect(mockNode1.getModel()).andStubReturn(mockModel0);
        expect(mockPrimitive.getIndexWithinParent()).andStubReturn(1);
        replay(mockModel0Subset, mockSelection, mockNode0, mockNode1, mockPrimitive);

        // Initialise test environment.
        testObject = new WidgetJOGLRenderer(mockRenderer);
        testObject.setGL(mockGl);
        testObject.setSelectionMode(SelectionMode.VERTICES);
        testObject.setWidget(mockWidget);

        // Dictate expected results.
        reset(mockRenderer);
        expect(mockModel0.createVertexSubsetVG(1)).andStubReturn(mockModel0Subset);
        mockWidget.init(null, true);
        mockRenderer.renderModel(mockModel1);
        replay(mockModel0, mockRenderer, mockWidget);

        // Perform test.
        testObject.renderModel(mockModel0, 0);

        // Verify test results.
        verify(mockRenderer);
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.editor.internal.rendering.WidgetJOGLRenderer#renderModel(Model, int) renderModel(Model, int)}
     * with the special condition that the selection mode is 'EDGES'.
     * </p>
     */
    @Test
    public void renderModelSelectionModeEdges()
    {
        // Create dependencies.
        SimpleJOGLRenderer mockRenderer = createMock(SimpleJOGLRenderer.class);
        MockGL mockGl = new MockGL();
        VertexGroup mockModel0 = createMock(VertexGroup.class);
        VertexGroup mockModel0Subset = createMock(VertexGroup.class);

        Widget mockWidget = createMock(Widget.class);
        ModelNode mockNode0 = createMock(ModelNode.class);
        Model mockModel1 = createMock(Model.class);

        SceneSelection mockSelection = createMock(SceneSelection.class);
        ModelNode mockNode1 = createMock(ModelNode.class);

        // Dictate correct behaviour.
        expect(mockModel0.getVertexCount()).andStubReturn(3);
        expect(mockModel0Subset.getCenter()).andStubReturn(new SimpleTranslationVectorf4());
        expect(mockWidget.getSelection()).andStubReturn(mockSelection);
        expect(mockWidget.atSelectionOnly()).andStubReturn(false);
        expect(mockWidget.alwaysFacesCamera()).andStubReturn(false);
        expect(mockWidget.getRootNode()).andStubReturn(mockNode0);
        expect(mockWidget.isOutlined()).andStubReturn(false);
        expect(mockSelection.getNode()).andStubReturn(mockNode1);
        expect(mockSelection.getPrimitive()).andStubReturn(null);
        expect(mockNode0.hasChildren()).andStubReturn(false);
        expect(mockNode0.getTransformation()).andStubReturn(new SimpleTransformationMatrixf44());
        expect(mockNode0.getModel()).andStubReturn(mockModel1);
        expect(mockNode1.getModel()).andStubReturn(mockModel0);
        replay(mockModel0Subset, mockSelection, mockNode0, mockNode1);

        // Initialise test environment.
        testObject = new WidgetJOGLRenderer(mockRenderer);
        testObject.setGL(mockGl);
        testObject.setSelectionMode(SelectionMode.EDGES);
        testObject.setWidget(mockWidget);

        // Dictate expected results.
        reset(mockRenderer);
        expect(mockModel0.createEdgeSubsetVG(0)).andStubReturn(mockModel0Subset);
        mockWidget.init(null, false);
        mockRenderer.renderModel(mockModel1);
        expect(mockModel0.createEdgeSubsetVG(1)).andStubReturn(mockModel0Subset);
        mockWidget.init(null, false);
        mockRenderer.renderModel(mockModel1);
        replay(mockModel0, mockRenderer, mockWidget);

        // Perform test.
        testObject.renderModel(mockModel0, 0);

        // Verify test results.
        verify(mockRenderer);
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.editor.internal.rendering.WidgetJOGLRenderer#renderModel(Model, int) renderModel(Model, int)}
     * with the special condition that the selection mode is 'FACES'.
     * </p>
     */
    @Test
    public void renderModelSelectionModeFaces()
    {
        // Create dependencies.
        SimpleJOGLRenderer mockRenderer = createMock(SimpleJOGLRenderer.class);
        MockGL mockGl = new MockGL();
        VertexGroup mockModel0 = createMock(VertexGroup.class);
        VertexGroup mockModel0Subset = createMock(VertexGroup.class);

        Widget mockWidget = createMock(Widget.class);
        ModelNode mockNode0 = createMock(ModelNode.class);
        Model mockModel1 = createMock(Model.class);

        SceneSelection mockSelection = createMock(SceneSelection.class);
        ModelNode mockNode1 = createMock(ModelNode.class);

        // Dictate correct behaviour.
        expect(mockModel0.getVertexCount()).andStubReturn(3);
        expect(mockModel0Subset.getCenter()).andStubReturn(new SimpleTranslationVectorf4());
        expect(mockWidget.getSelection()).andStubReturn(mockSelection);
        expect(mockWidget.atSelectionOnly()).andStubReturn(false);
        expect(mockWidget.alwaysFacesCamera()).andStubReturn(false);
        expect(mockWidget.getRootNode()).andStubReturn(mockNode0);
        expect(mockWidget.isOutlined()).andStubReturn(false);
        expect(mockSelection.getNode()).andStubReturn(mockNode1);
        expect(mockSelection.getPrimitive()).andStubReturn(null);
        expect(mockNode0.hasChildren()).andStubReturn(false);
        expect(mockNode0.getTransformation()).andStubReturn(new SimpleTransformationMatrixf44());
        expect(mockNode0.getModel()).andStubReturn(mockModel1);
        expect(mockNode1.getModel()).andStubReturn(mockModel0);
        replay(mockModel0Subset, mockSelection, mockNode0, mockNode1);

        // Initialise test environment.
        testObject = new WidgetJOGLRenderer(mockRenderer);
        testObject.setGL(mockGl);
        testObject.setSelectionMode(SelectionMode.FACES);
        testObject.setWidget(mockWidget);

        // Dictate expected results.
        reset(mockRenderer);
        expect(mockModel0.createFaceSubsetVG(0)).andStubReturn(mockModel0Subset);
        mockWidget.init(null, false);
        mockRenderer.renderModel(mockModel1);
        replay(mockModel0, mockRenderer, mockWidget);

        // Perform test.
        testObject.renderModel(mockModel0, 0);

        // Verify test results.
        verify(mockRenderer);
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.editor.internal.rendering.WidgetJOGLRenderer#renderModel(Model, int) renderModel(Model, int)}
     * with the special condition that the selection mode is 'MODEL'.
     * </p>
     */
    @Test
    public void renderModelSelectionModeModel()
    {
        // Create dependencies.
        SimpleJOGLRenderer mockRenderer = createMock(SimpleJOGLRenderer.class);
        MockGL mockGl = new MockGL();
        VertexGroup mockModel0 = createMock(VertexGroup.class);

        Widget mockWidget = createMock(Widget.class);
        ModelNode mockNode0 = createMock(ModelNode.class);
        Model mockModel1 = createMock(Model.class);

        SceneSelection mockSelection = createMock(SceneSelection.class);
        ModelNode mockNode1 = createMock(ModelNode.class);

        // Dictate correct behaviour.
        expect(mockModel0.getVertexCount()).andStubReturn(3);
        expect(mockModel0.getCenter()).andStubReturn(new SimpleTranslationVectorf4());
        expect(mockWidget.getSelection()).andStubReturn(mockSelection);
        expect(mockWidget.atSelectionOnly()).andStubReturn(true);
        expect(mockWidget.alwaysFacesCamera()).andStubReturn(false);
        expect(mockWidget.getRootNode()).andStubReturn(mockNode0);
        expect(mockWidget.isOutlined()).andStubReturn(false);
        expect(mockSelection.getNode()).andStubReturn(mockNode1);
        expect(mockSelection.getPrimitive()).andStubReturn(null);
        expect(mockNode0.hasChildren()).andStubReturn(false);
        expect(mockNode0.getTransformation()).andStubReturn(new SimpleTransformationMatrixf44());
        expect(mockNode0.getModel()).andStubReturn(mockModel1);
        expect(mockNode1.getModel()).andStubReturn(mockModel0);
        replay(mockModel0, mockSelection, mockNode0, mockNode1);

        // Initialise test environment.
        testObject = new WidgetJOGLRenderer(mockRenderer);
        testObject.setGL(mockGl);
        testObject.setWidget(mockWidget);

        // Dictate expected results.
        reset(mockRenderer);
        mockWidget.init(null, true);
        mockRenderer.renderModel(mockModel1);
        replay(mockRenderer, mockWidget);

        // Perform test.
        testObject.renderModel(mockModel0, 0);

        // Verify test results.
        verify(mockRenderer);
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.editor.internal.rendering.WidgetJOGLRenderer#renderModel(Model, int) renderModel(Model, int)}
     * with the special condition that the selection mode is 'VERTICES'.
     * </p>
     */
    @Test
    public void renderModelSelectionModeVertices()
    {
        // Create dependencies.
        SimpleJOGLRenderer mockRenderer = createMock(SimpleJOGLRenderer.class);
        MockGL mockGl = new MockGL();
        VertexGroup mockModel0 = createMock(VertexGroup.class);
        VertexGroup mockModel0Subset = createMock(VertexGroup.class);

        Widget mockWidget = createMock(Widget.class);
        ModelNode mockNode0 = createMock(ModelNode.class);
        Model mockModel1 = createMock(Model.class);

        SceneSelection mockSelection = createMock(SceneSelection.class);
        ModelNode mockNode1 = createMock(ModelNode.class);

        // Dictate correct behaviour.
        expect(mockModel0.getVertexCount()).andStubReturn(3);
        expect(mockModel0Subset.getCenter()).andStubReturn(new SimpleTranslationVectorf4());
        expect(mockWidget.getSelection()).andStubReturn(mockSelection);
        expect(mockWidget.atSelectionOnly()).andStubReturn(false);
        expect(mockWidget.alwaysFacesCamera()).andStubReturn(false);
        expect(mockWidget.getRootNode()).andStubReturn(mockNode0);
        expect(mockWidget.isOutlined()).andStubReturn(false);
        expect(mockSelection.getNode()).andStubReturn(mockNode1);
        expect(mockSelection.getPrimitive()).andStubReturn(null);
        expect(mockNode0.hasChildren()).andStubReturn(false);
        expect(mockNode0.getTransformation()).andStubReturn(new SimpleTransformationMatrixf44());
        expect(mockNode0.getModel()).andStubReturn(mockModel1);
        expect(mockNode1.getModel()).andStubReturn(mockModel0);
        replay(mockModel0Subset, mockSelection, mockNode0, mockNode1);

        // Initialise test environment.
        testObject = new WidgetJOGLRenderer(mockRenderer);
        testObject.setGL(mockGl);
        testObject.setSelectionMode(SelectionMode.VERTICES);
        testObject.setWidget(mockWidget);

        // Dictate expected results.
        reset(mockRenderer);
        expect(mockModel0.createVertexSubsetVG(0)).andStubReturn(mockModel0Subset);
        mockWidget.init(null, false);
        mockRenderer.renderModel(mockModel1);
        expect(mockModel0.createVertexSubsetVG(1)).andStubReturn(mockModel0Subset);
        mockWidget.init(null, false);
        mockRenderer.renderModel(mockModel1);
        expect(mockModel0.createVertexSubsetVG(2)).andStubReturn(mockModel0Subset);
        mockWidget.init(null, false);
        mockRenderer.renderModel(mockModel1);
        replay(mockModel0, mockRenderer, mockWidget);

        // Perform test.
        testObject.renderModel(mockModel0, 0);

        // Verify test results.
        verify(mockRenderer);
    }
}
