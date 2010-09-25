/*
    This file is part of The Simplicity Engine.

    The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
    by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

    The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
package com.se.simplicity.editor.internal.rendering;

import static com.se.simplicity.model.ModelConstants.VERTICES_IN_A_FACE;

import javax.media.opengl.GL;

import com.se.simplicity.editor.internal.SelectionMode;
import com.se.simplicity.editor.internal.Widget;
import com.se.simplicity.jogl.JOGLComponent;
import com.se.simplicity.jogl.rendering.AdaptingJOGLRenderer;
import com.se.simplicity.jogl.rendering.OutlineJOGLRenderer;
import com.se.simplicity.jogl.rendering.StencilClearingJOGLRenderer;
import com.se.simplicity.model.Model;
import com.se.simplicity.model.VertexGroup;
import com.se.simplicity.rendering.Camera;
import com.se.simplicity.rendering.NamedRenderer;
import com.se.simplicity.rendering.Renderer;
import com.se.simplicity.scenegraph.Node;
import com.se.simplicity.scenegraph.SimpleTraversal;
import com.se.simplicity.scenegraph.model.ModelNode;
import com.se.simplicity.vector.SimpleMatrixf44;
import com.se.simplicity.vector.SimpleTransformationMatrixf44;

/**
 * <p>
 * Renders a {@link com.se.simplicity.editor.internal.Widget Widget} in a JOGL environment. The <code>Widget</code> is rendered in place of the
 * {@link com.se.simplicity.model.Model Model} passed to the method {@link #renderModel(Model)}. Depending on the
 * {@link com.se.simplicity.editor.internal.SelectionMode SelectionMode}, multiple copies of the <code>Widget</code> may be rendered at the vertices,
 * edges or faces of the <code>Model</code> passed to the method <code>renderModel(Model)</code>.
 * </p>
 * 
 * @author Gary Buyn
 */
public class WidgetJOGLRenderer extends AdaptingJOGLRenderer implements NamedRenderer
{
    /**
     * <p>
     * The {@link com.se.simplicity.rendering.Camera Camera} the {@link com.se.simplicity.editor.internal.Widget Widget} is being viewed through.
     * </p>
     */
    private Camera fCamera;

    /**
     * <p>
     * The {@link com.se.simplicity.rendering.Renderer Renderer} that renders the outline for the {@link com.se.simplicity.editor.internal.Widget
     * Widget} if required.
     * </p>
     */
    private Renderer fOutlineRenderer;

    /**
     * <p>
     * The {@link com.se.simplicity.editor.internal.SelectionMode SelectionMode} the scene components / primitives are being selected with.
     * </p>
     */
    private SelectionMode fSelectionMode;

    /**
     * <p>
     * The {@link com.se.simplicity.editor.internal.Widget Widget} that will be rendered.
     * </p>
     */
    private Widget fWidget;

    /**
     * <p>
     * Creates an instance of <code>WidgetJOGLRenderer</code>.
     * </p>
     * 
     * @param renderer The wrapped {@link com.se.simplicity.rendering.Renderer Renderer} that will actually render the
     * {@link com.se.simplicity.editor.internal.Widget Widget}.
     */
    public WidgetJOGLRenderer(final Renderer renderer)
    {
        super(renderer);

        fCamera = null;
        fOutlineRenderer = new StencilClearingJOGLRenderer(new OutlineJOGLRenderer());
        fSelectionMode = SelectionMode.MODEL;
        fWidget = null;
    }

    /**
     * <p>
     * Backtracks up the <code>SceneGraph</code> the number of levels given.
     * </p>
     * 
     * <p>
     * A backtrack is an upward movement in the graph being rendered.
     * </p>
     * 
     * @param backtracks The number of levels to backtrack.
     */
    protected void backtrack(final int backtracks)
    {
        for (int index = 0; index < backtracks; index++)
        {
            getGL().glPopMatrix();
        }
    }

    @Override
    public void dispose()
    {
        super.dispose();

        fOutlineRenderer.dispose();
    }

    /**
     * <p>
     * Retrieves the {@link com.se.simplicity.rendering.Camera Camera} the {@link com.se.simplicity.editor.internal.Widget Widget} is being viewed
     * through.
     * </p>
     * 
     * @return The <code>Camera</code> the <code>Widget</code> is being viewed through.
     */
    public Camera getCamera()
    {
        return fCamera;
    }

    /**
     * <p>
     * Retrieves the primitive at the given index in the given {@link com.se.simplicity.model.Model Model}. The type of primitive returned depends on
     * the {@link com.se.simplicity.editor.internal.SelectionMode SelectionMode}.
     * </p>
     * 
     * @param model The <code>Model</code> to retrieve the primitive from.
     * @param index The index of the primitive to retrieve.
     * 
     * @return The primitive at the given index in the given <code>Model</code>.
     */
    protected Model getPrimitive(final Model model, final int index)
    {
        Model primitive = model;

        if (model instanceof VertexGroup)
        {
            if (fSelectionMode == SelectionMode.EDGES)
            {
                primitive = ((VertexGroup) model).createEdgeSubsetVG(index);
            }
            else if (fSelectionMode == SelectionMode.FACES)
            {
                primitive = ((VertexGroup) model).createFaceSubsetVG(index);
            }
            else if (fSelectionMode == SelectionMode.VERTICES)
            {
                primitive = ((VertexGroup) model).createVertexSubsetVG(index);
            }
        }

        return (primitive);
    }

    /**
     * <p>
     * Retrieves the {@link com.se.simplicity.editor.internal.SelectionMode SelectionMode} the scene components / primitives are being selected with.
     * </p>
     * 
     * @return The <code>SelectionMode</code> the scene components / primitives are being selected with.
     */
    public SelectionMode getSelectionMode()
    {
        return fSelectionMode;
    }

    /**
     * <p>
     * Retrieves the {@link com.se.simplicity.editor.internal.SelectionMode SelectionMode} the scene components / primitives are being selected with.
     * </p>
     * 
     * @return The {@link com.se.simplicity.editor.internal.SelectionMode SelectionMode} the scene components / primitives are being selected with.
     */
    public Widget getWidget()
    {
        return fWidget;
    }

    /**
     * <p>
     * Retrieves the number of {@link com.se.simplicity.editor.internal.Widget Widget}s to be rendered in place of the
     * {@link com.se.simplicity.model.Model Model}.
     * </p>
     * 
     * @param model The <code>Model</code> to render the <code>Widget</code> in place of.
     * 
     * @return The number of <code>Widget</code>s to be rendered in place of the <code>Model</code>.
     */
    protected int getWidgetCount(final Model model)
    {
        int widgetCount = 1;

        if (model instanceof VertexGroup)
        {
            if (fSelectionMode == SelectionMode.EDGES)
            {
                widgetCount = ((VertexGroup) model).getVertexCount() - 1;
            }
            else if (fSelectionMode == SelectionMode.FACES)
            {
                widgetCount = ((VertexGroup) model).getVertexCount() / VERTICES_IN_A_FACE;
            }
            else if (fSelectionMode == SelectionMode.VERTICES)
            {
                widgetCount = ((VertexGroup) model).getVertexCount();
            }
        }

        return (widgetCount);
    }

    @Override
    public void init()
    {
        fOutlineRenderer.init();

        super.init();
    }

    /**
     * <p>
     * Determines if the given {@link com.se.simplicity.model.Model Model} and the index of the primitive in the <code>Model</code> match the selected
     * scene component and primitive.
     * </p>
     * 
     * @param model The <code>Model</code> to check.
     * @param primitiveIndex The index of the primitive to check.
     * 
     * @return True if the given <code>VertexGroup</code> is the selected primitive, false otherwise.
     */
    protected boolean matchesSelection(final Model model, final int primitiveIndex)
    {
        boolean matchesSelection = false;

        if (fWidget.getSelection().getNode() instanceof ModelNode)
        {
            if (model == ((ModelNode) fWidget.getSelection().getNode()).getModel())
            {
                if (fWidget.getSelection().getPrimitive() != null && model instanceof VertexGroup)
                {
                    if (primitiveIndex == ((VertexGroup) fWidget.getSelection().getPrimitive()).getIndexWithinParent())
                    {
                        matchesSelection = true;
                    }
                }
                else if (fSelectionMode == SelectionMode.MODEL)
                {
                    matchesSelection = true;
                }
            }
        }

        return (matchesSelection);
    }

    @Override
    public void renderModel(final Model model)
    {
        renderModel(model, model.hashCode());
    }

    @Override
    public void renderModel(final Model model, final int name)
    {
        GL gl = getGL();
        gl.glPushName(name);

        int widgetCount = getWidgetCount(model);
        SimpleTransformationMatrixf44 transformation = new SimpleTransformationMatrixf44();

        for (int index = 0; index < widgetCount; index++)
        {
            // If the Widget needs to be rendered.
            boolean matchesSelection = matchesSelection(model, index);
            if (!fWidget.atSelectionOnly() || matchesSelection)
            {
                // Get a transformation to the primitive in local coordinates.
                transformation.setIdentity();
                transformation.translate(getPrimitive(model, index).getCenter());

                gl.glPushMatrix();
                {
                    // Name the primitive.
                    gl.glPushName(index);

                    // Transform to the location of the primitive and orientation of the primitive. If required, override the rotation with that of
                    // the camera.
                    gl.glMultMatrixf(transformation.getArray(), 0);
                    if (fWidget.alwaysFacesCamera())
                    {
                        setCameraRotation();
                    }

                    fWidget.init(fCamera, matchesSelection);

                    renderWidgetSceneGraph(getRenderer());

                    // If required, render an outline.
                    if (fWidget.isOutlined())
                    {
                        renderWidgetSceneGraph(fOutlineRenderer);
                    }

                    gl.glPopName();
                }
                gl.glPopMatrix();
            }
        }

        gl.glPopName();
    }

    /**
     * <p>
     * Renders the {@link com.se.simplicity.editor.internal.Widget Widget}'s {@link com.se.simplicity.scenegraph.SceneGraph SceneGraph}.
     * </p>
     * 
     * @param renderer The {@link com.se.simplicity.rendering.Renderer Renderer} to render the <code>Widget</code> with.
     */
    protected void renderWidgetSceneGraph(final Renderer renderer)
    {
        GL gl = getGL();

        // For every node in the traversal of the scene.
        SimpleTraversal traversal = new SimpleTraversal(fWidget.getRootNode());
        Node currentNode;

        while (traversal.hasMoreNodes())
        {
            // Remove transformations from the stack that do not apply to the next node.
            backtrack(traversal.getBacktracksToNextNode());

            // Apply the transformation of the current node.
            currentNode = traversal.getNextNode();

            gl.glPushMatrix();
            gl.glMultMatrixf(((SimpleMatrixf44) currentNode.getTransformation()).getArray(), 0);

            // Render the current node if it is a model.
            if (currentNode instanceof ModelNode)
            {
                if (getRenderer() instanceof NamedRenderer)
                {
                    ((NamedRenderer) renderer).renderModel(((ModelNode) currentNode).getModel(), currentNode.getID());
                }
                else
                {
                    renderer.renderModel(((ModelNode) currentNode).getModel());
                }
            }
        }

        // Remove all remaining transformations from the stack.
        backtrack(traversal.getBacktracksToNextNode());
    }

    /**
     * <p>
     * Sets the {@link com.se.simplicity.rendering.Camera Camera} the {@link com.se.simplicity.editor.internal.Widget Widget} is being viewed through.
     * </p>
     * 
     * @param camera The <code>Camera</code> the <code>Widget</code> is being viewed through.
     */
    public void setCamera(final Camera camera)
    {
        this.fCamera = camera;
    }

    /**
     * <p>
     * Sets the rotation of the MODELVIEW matrix to match the absolute rotation of the {@link com.se.simplicity.rendering.Camera Camera}'s
     * {@link com.se.simplicity.scenegraph.Node Node}.
     * </p>
     */
    protected void setCameraRotation()
    {
        GL gl = getGL();

        // Retrieve the MODELVIEW matrix and remove the influence of the Camera.
        SimpleTransformationMatrixf44 sceneTransformation = new SimpleTransformationMatrixf44();
        SimpleTransformationMatrixf44 cameraTransformation = (SimpleTransformationMatrixf44) fCamera.getNode().getAbsoluteTransformation();
        gl.glGetFloatv(GL.GL_MODELVIEW_MATRIX, sceneTransformation.getArray(), 0);
        sceneTransformation.multiplyLeft(cameraTransformation);

        // Combine the orientation of the Camera with the location of the scene component.
        cameraTransformation.setTranslation(sceneTransformation.getTranslation());

        gl.glLoadIdentity();
        fCamera.apply();
        gl.glMultMatrixf(cameraTransformation.getArray(), 0);
    }

    @Override
    public void setGL(final GL gl)
    {
        super.setGL(gl);

        ((JOGLComponent) fOutlineRenderer).setGL(gl);
    }

    /**
     * <p>
     * Sets the {@link com.se.simplicity.editor.internal.SelectionMode SelectionMode} the scene components / primitives are being selected with.
     * </p>
     * 
     * @param selectionMode The <code>SelectionMode</code> the scene components / primitives are being selected with.
     */
    public void setSelectionMode(final SelectionMode selectionMode)
    {
        this.fSelectionMode = selectionMode;
    }

    /**
     * <p>
     * Sets the {@link com.se.simplicity.editor.internal.SelectionMode SelectionMode} the scene components / primitives are being selected with.
     * </p>
     * 
     * @param widget The {@link com.se.simplicity.editor.internal.SelectionMode SelectionMode} the scene components / primitives are being selected
     * with.
     */
    public void setWidget(final Widget widget)
    {
        this.fWidget = widget;
    }
}
