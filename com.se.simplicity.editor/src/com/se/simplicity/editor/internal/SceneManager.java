/*
    This file is part of The Simplicity Engine.

    The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
    by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

    The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
package com.se.simplicity.editor.internal;

import java.awt.Dimension;

import javax.media.opengl.GL;

import org.apache.commons.logging.LogFactory;

import com.se.simplicity.editor.internal.selection.SceneSelection;
import com.se.simplicity.jogl.JOGLComponent;
import com.se.simplicity.jogl.picking.SimpleJOGLPicker;
import com.se.simplicity.jogl.picking.engine.SimpleJOGLPickingEngine;
import com.se.simplicity.jogl.rendering.NamedJOGLRenderer;
import com.se.simplicity.jogl.rendering.OutlineJOGLRenderer;
import com.se.simplicity.jogl.rendering.SimpleJOGLRenderer;
import com.se.simplicity.jogl.rendering.engine.SimpleJOGLRenderingEngine;
import com.se.simplicity.model.Model;
import com.se.simplicity.picking.engine.PickingEngine;
import com.se.simplicity.rendering.Camera;
import com.se.simplicity.rendering.DrawingMode;
import com.se.simplicity.rendering.Renderer;
import com.se.simplicity.rendering.engine.RenderingEngine;
import com.se.simplicity.scene.Scene;
import com.se.simplicity.scenegraph.Node;
import com.se.simplicity.scenegraph.model.SimpleModelNode;
import com.se.simplicity.util.metadata.scene.MetaDataScene;

/**
 * <p>
 * Manages the state of the {@link com.se.simplicity.scene.Scene Scene} displayed by a {@link com.se.simplicity.editor.ui.editors.SceneEditor
 * SceneEditor} including rendering, picking and interaction modes.
 * </p>
 * 
 * @author Gary Buyn
 */
public class SceneManager
{
    /**
     * <p>
     * Renders the outline of the selected scene component.
     * </p>
     */
    private Renderer fOutlineRenderer;

    /**
     * <p>
     * The {@link com.se.simplicity.picking.engine.PickingEngine PickingEngine} used to select the scene components in the
     * {@link com.se.simplicity.scene.Scene Scene}.
     * </p>
     */
    private PickingEngine fPickingEngine;

    /**
     * <p>
     * Fills the select buffer with {@link com.se.simplicity.scene.Scene Scene} selection data.
     * </p>
     */
    private Renderer fPickingRenderer;

    /**
     * <p>
     * Renders the {@link com.se.simplicity.scene.Scene Scene}.
     * </p>
     */
    private Renderer fRenderer;

    /**
     * <p>
     * The {@link com.se.simplicity.rendering.engine.RenderingEngine RenderingEngine} that will render the {@link com.se.simplicity.scene.Scene Scene}
     * to the 3D canvas.
     * </p>
     */
    private RenderingEngine fRenderingEngine;

    /**
     * <p>
     * The {@link com.se.simplicity.scene.Scene Scene} displayed by the {@link com.se.simplicity.editor.ui.editors.SceneEditor SceneEditor}.
     * </p>
     */
    private Scene fScene;

    /**
     * <p>
     * The {@link com.se.simplicity.editor.internal.SelectionMode SelectionMode} to select scene components / primitives with.
     * </p>
     */
    private SelectionMode fSelectionMode;

    /**
     * <p>
     * Creates an instance of <code>SceneManager</code>.
     * </p>
     * 
     * @param scene The {@link com.se.simplicity.scene.Scene Scene} displayed by the {@link com.se.simplicity.editor.ui.editors.SceneEditor
     * SceneEditor}.
     * @param renderingEngine The {@link com.se.simplicity.rendering.engine.RenderingEngine RenderingEngine} that will render the <code>Scene</code>
     * to the 3D canvas.
     */
    public SceneManager(final Scene scene, final RenderingEngine renderingEngine)
    {
        fRenderingEngine = renderingEngine;
        fScene = scene;

        fOutlineRenderer = null;
        fPickingEngine = null;
        fPickingRenderer = null;
        fRenderer = null;
        fSelectionMode = null;
    }

    /**
     * <p>
     * Retrieves the {@link com.se.simplicity.picking.engine.PickingEngine PickingEngine} used to select scene components in the
     * {@link com.se.simplicity.scene.Scene Scene}.
     * </p>
     * 
     * @return The <code>PickingEngine</code> used to select scene components in the <code>Scene</code>.
     */
    public PickingEngine getPickingEngine()
    {
        return (fPickingEngine);
    }

    /**
     * <p>
     * Retrieves the {@link com.se.simplicity.rendering.engine.RenderingEngine RenderingEngine} that will render the
     * {@link com.se.simplicity.scene.Scene Scene} to the 3D canvas.
     * </p>
     * 
     * @return The <code>RenderingEngine</code> that will render the <code>Scene</code> to the 3D canvas.
     */
    public RenderingEngine getRenderingEngine()
    {
        return (fRenderingEngine);
    }

    /**
     * <p>
     * Retrieves the {@link com.se.simplicity.scene.Scene Scene} displayed by the {@link com.se.simplicity.editor.ui.editors.SceneEditor SceneEditor}.
     * </p>
     * 
     * @return The <code>Scene</code> displayed by the <code>SceneEditor</code>.
     */
    public Scene getScene()
    {
        return (fScene);
    }

    /**
     * <p>
     * Retrieves the {@link com.se.simplicity.editor.internal.SelectionMode SelectionMode} to select scene components / primitives with.
     * </p>
     * 
     * @return The {@link com.se.simplicity.editor.internal.SelectionMode SelectionMode} to select scene components / primitives with.
     */
    public SelectionMode getSelectionMode()
    {
        return (fSelectionMode);
    }

    /**
     * <p>
     * Initialises this <code>SceneManager</code>.
     * </p>
     */
    public void init()
    {
        initRenderers();
        initPickingEngine();
    }

    /**
     * <p>
     * Initialises the {@link com.se.simplicity.picking.engine.PickingEngine PickingEngine} used to select scene components in the
     * {@link com.se.simplicity.scene.Scene Scene}.
     * </p>
     */
    protected void initPickingEngine()
    {
        fPickingEngine = new SimpleJOGLPickingEngine();
        SimpleJOGLPicker picker = new SimpleJOGLPicker();
        SimpleJOGLRenderingEngine renderingEngine = new SimpleJOGLRenderingEngine();
        fPickingRenderer = new NamedJOGLRenderer();

        fPickingEngine.setPicker(picker);
        picker.setRenderingEngine(renderingEngine);
        renderingEngine.addRenderer(fPickingRenderer);

        fPickingEngine.setScene(fScene);
    }

    /**
     * <p>
     * Initialises the {@link com.se.simplicity.rendering.Renderer Renderer}s used to render the {@link com.se.simplicity.scene.Scene Scene} and
     * outlines.
     * </p>
     */
    protected void initRenderers()
    {
        // Retrieve preferred rendering environment if one is available.
        String preferredRenderer = null;
        if (fScene instanceof MetaDataScene)
        {
            MetaDataScene metaDataScene = (MetaDataScene) fScene;
            preferredRenderer = (String) metaDataScene.getAttribute("preferredRenderer");
        }

        // Initialise Renderer.
        if (preferredRenderer == null)
        {
            fRenderer = new SimpleJOGLRenderer();
        }
        else
        {
            try
            {
                fRenderer = (Renderer) Class.forName(preferredRenderer).newInstance();
            }
            catch (Exception e)
            {
                LogFactory.getLog(getClass()).warn("Failed to instantiate preferred Renderer, instantiating default.", e);
                fRenderer = new SimpleJOGLRenderer();
            }
        }

        fOutlineRenderer = new OutlineJOGLRenderer();

        fRenderingEngine.addRenderer(fRenderer);
        fRenderingEngine.addRenderer(fOutlineRenderer);
        fRenderingEngine.setRendererRoot(fOutlineRenderer, null);
    }

    /**
     * <p>
     * Sets the {@link com.se.simplicity.rendering.Camera Camera} the {@link com.se.simplicity.scene.Scene Scene} will be viewed through.
     * </p>
     * 
     * @param camera The <code>Camera</code> the <code>Scene</code> will be viewed through.
     */
    public void setCamera(final Camera camera)
    {
        fPickingEngine.setCamera(camera);
    }

    /**
     * <p>
     * Sets the {@link com.se.simplicity.rendering.DrawingMode DrawingMode} used to render the {@link com.se.simplicity.scene.Scene Scene}.
     * </p>
     * 
     * @param drawingMode The <code>DrawingMode</code> used to render the <code>Scene</code>.
     */
    public void setDrawingMode(final DrawingMode drawingMode)
    {
        fRenderer.setDrawingMode(drawingMode);

        ((SimpleJOGLPicker) fPickingEngine.getPicker()).getRenderingEngine().getRenderers().get(0).setDrawingMode(drawingMode);
    }

    /**
     * <p>
     * Sets the JOGL rendering environment used to display the {@link com.se.simplicity.scene.Scene Scene}.
     * </p>
     * 
     * @param gl The JOGL rendering environment used to display the <code>Scene</code>.
     */
    public void setGL(final GL gl)
    {
        ((JOGLComponent) fPickingEngine).setGL(gl);
        ((JOGLComponent) ((SimpleJOGLPicker) fPickingEngine.getPicker()).getRenderingEngine()).setGL(gl);
    }

    /**
     * <p>
     * Sets the selected scene component and primitive.
     * </p>
     * 
     * @param selection The selected scene component and primitive.
     */
    public void setSelection(final SceneSelection selection)
    {
        Object sceneComponent = selection.getSceneComponent();
        Model primitive = selection.getPrimitive();

        if (sceneComponent instanceof Node)
        {
            if (primitive != null && fSelectionMode != SelectionMode.MODEL)
            {
                SimpleModelNode primitiveNode = new SimpleModelNode();
                primitiveNode.setModel(primitive);

                // Translate the primitive model to its correct position.
                primitiveNode.setTransformation(((Node) sceneComponent).getAbsoluteTransformation());

                fRenderingEngine.setRendererRoot(fOutlineRenderer, primitiveNode);
            }
            else
            {
                fRenderingEngine.setRendererRoot(fOutlineRenderer, (Node) sceneComponent);
            }
        }
        else
        {
            fRenderingEngine.setRendererRoot(fOutlineRenderer, null);
        }
    }

    /**
     * <p>
     * Sets the {@link com.se.simplicity.editor.internal.SelectionMode SelectionMode} to select scene components / primitives with.
     * </p>
     * 
     * @param selectionMode The {@link com.se.simplicity.editor.internal.SelectionMode SelectionMode} to select scene components / primitives with.
     */
    public void setSelectionMode(final SelectionMode selectionMode)
    {
        fSelectionMode = selectionMode;

        if (fSelectionMode == SelectionMode.EDGES)
        {
            fOutlineRenderer.setDrawingMode(DrawingMode.EDGES);
            fPickingEngine.getPicker().setDrawingMode(DrawingMode.EDGES);
            fPickingRenderer.setDrawingMode(DrawingMode.EDGES);
        }
        else if (fSelectionMode == SelectionMode.VERTICES)
        {
            fOutlineRenderer.setDrawingMode(DrawingMode.VERTICES);
            fPickingEngine.getPicker().setDrawingMode(DrawingMode.VERTICES);
            fPickingRenderer.setDrawingMode(DrawingMode.VERTICES);
        }
        else
        {
            fOutlineRenderer.setDrawingMode(DrawingMode.FACES);
            fPickingEngine.getPicker().setDrawingMode(DrawingMode.FACES);
            fPickingRenderer.setDrawingMode(DrawingMode.FACES);
        }
    }

    /**
     * <p>
     * Sets the size of the viewport the {@link com.se.simplicity.scene.Scene Scene} is being viewed through (the size of the 3D canvas).
     * </p>
     * 
     * @param viewportSize The size of the viewport the <code>Scene</code> is being viewed through (the size of the 3D canvas).
     */
    public void setViewportSize(final Dimension viewportSize)
    {
        ((SimpleJOGLPicker) fPickingEngine.getPicker()).getRenderingEngine().setViewportSize(viewportSize);
    }
}
