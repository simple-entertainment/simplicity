package com.se.simplicity.editor.internal;

import java.awt.Dimension;
import java.util.HashMap;
import java.util.Map;
import java.util.Map.Entry;

import javax.media.opengl.GL;

import com.se.simplicity.editor.internal.rendering.WidgetJOGLRenderer;
import com.se.simplicity.editor.internal.selection.SceneSelection;
import com.se.simplicity.jogl.JOGLComponent;
import com.se.simplicity.jogl.picking.SimpleJOGLPicker;
import com.se.simplicity.jogl.picking.engine.SimpleJOGLPickingEngine;
import com.se.simplicity.jogl.rendering.BlendingJOGLRenderer;
import com.se.simplicity.jogl.rendering.DepthClearingJOGLRenderer;
import com.se.simplicity.jogl.rendering.SimpleJOGLRenderer;
import com.se.simplicity.jogl.rendering.engine.SimpleJOGLRenderingEngine;
import com.se.simplicity.picking.engine.PickingEngine;
import com.se.simplicity.rendering.Camera;
import com.se.simplicity.rendering.DrawingMode;
import com.se.simplicity.rendering.engine.RenderingEngine;
import com.se.simplicity.scene.Scene;

/**
 * <p>
 * Provides the content that will be displayed by a {@link com.se.simplicity.editor.ui.editors.SceneEditor SceneEditor}.
 * </p>
 * 
 * @author Gary Buyn
 */
public class WidgetManager
{
    /**
     * <p>
     * The {@link com.se.simplicity.editor.internal.EditingMode EditingMode} used to manipulate the {@link com.se.simplicity.scene.Scene Scene}.
     * </p>
     */
    private EditingMode fEditingMode;

    /**
     * <p>
     * Renders the {@link com.se.simplicity.editor.internal.Widget Widget}s.
     * </p>
     */
    private WidgetJOGLRenderer fRenderer;

    /**
     * <p>
     * The {@link com.se.simplicity.picking.engine.PickingEngine PickingEngine} used to select the {@link com.se.simplicity.editor.internal.Widget
     * Widget}s.
     * </p>
     */
    private PickingEngine fPickingEngine;

    /**
     * <p>
     * The {@link com.se.simplicity.rendering.engine.RenderingEngine RenderingEngine} used to select the
     * {@link com.se.simplicity.editor.internal.Widget Widget}s.
     * </p>
     */
    private RenderingEngine fPickingRenderingEngine;

    /**
     * <p>
     * The {@link com.se.simplicity.rendering.engine.RenderingEngine RenderingEngine} that will render the
     * {@link com.se.simplicity.editor.internal.Widget Widget}s to the 3D canvas.
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
     * The {@link com.se.simplicity.editor.internal.Widget Widget}s used to manipulate {@link com.se.simplicity.model.Model Model}s.
     * </p>
     */
    private Map<EditingMode, Widget> fWidgets;

    /**
     * <p>
     * Creates an instance of <code>WidgetManager</code>.
     * </p>
     * 
     * @param scene The {@link com.se.simplicity.scene.Scene Scene} displayed by the {@link com.se.simplicity.editor.ui.editors.SceneEditor
     * SceneEditor}.
     * @param renderingEngine The {@link com.se.simplicity.rendering.engine.RenderingEngine RenderingEngine} that will render the
     * {@link com.se.simplicity.editor.internal.Widget Widget}s to the 3D canvas.
     */
    public WidgetManager(final Scene scene, final RenderingEngine renderingEngine)
    {
        fRenderingEngine = renderingEngine;
        fScene = scene;

        fEditingMode = null;
        fPickingEngine = null;
        fPickingRenderingEngine = null;
        fRenderer = new WidgetJOGLRenderer(new DepthClearingJOGLRenderer(new BlendingJOGLRenderer(new SimpleJOGLRenderer())));
        fSelectionMode = SelectionMode.MODEL;
        fWidgets = new HashMap<EditingMode, Widget>();
    }

    /**
     * <p>
     * Retrieves the {@link com.se.simplicity.editor.internal.EditingMode EditingMode} used to manipulate the {@link com.se.simplicity.scene.Scene
     * Scene}.
     * </p>
     * 
     * @return The <code>EditingMode</code> used to manipulate the <code>Scene</code>.
     */
    public EditingMode getEditingMode()
    {
        return (fEditingMode);
    }

    /**
     * <p>
     * Retrieves the {@link com.se.simplicity.picking.engine.PickingEngine PickingEngine} used to select the
     * {@link com.se.simplicity.editor.internal.Widget Widget}s.
     * </p>
     * 
     * @return The <code>PickingEngine</code> used to select the <code>Widget</code>s.
     */
    public PickingEngine getPickingEngine()
    {
        return (fPickingEngine);
    }

    /**
     * <p>
     * Retrieves the {@link com.se.simplicity.rendering.engine.RenderingEngine RenderingEngine} that will render the
     * {@link com.se.simplicity.editor.internal.Widget Widget}s to the 3D canvas.
     * </p>
     * 
     * @return The <code>RenderingEngine</code> that will render the <code>Widget</code>s to the 3D canvas.
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
     * Retrieves the {@link com.se.simplicity.editor.internal.Widget Widget} currently being used to manipulate {@link com.se.simplicity.model.Model
     * Model}s.
     * </p>
     * 
     * @return The <code>Widget</code> currently being used to manipulate <code>Model</code>s.
     */
    public Widget getWidget()
    {
        return (fWidgets.get(fEditingMode));
    }

    /**
     * <p>
     * Initialises this <code>WidgetManager</code>.
     * </p>
     */
    public void init()
    {
        initPickingEngine();
        initWidgets();

        fRenderingEngine.addRenderer(fRenderer);

        fPickingEngine.setScene(fScene);
        fPickingRenderingEngine.addRenderer(fRenderer);
    }

    /**
     * <p>
     * Initialises the {@link com.se.simplicity.picking.engine.PickingEngine PickingEngine} used to select widget components.
     * </p>
     */
    protected void initPickingEngine()
    {
        fPickingEngine = new SimpleJOGLPickingEngine();
        SimpleJOGLPicker picker = new SimpleJOGLPicker();
        fPickingRenderingEngine = new SimpleJOGLRenderingEngine();

        fPickingEngine.setPicker(picker);
        picker.setRenderingEngine(fPickingRenderingEngine);
    }

    /**
     * <p>
     * Initialises the widgets used to manipulate {@link com.se.simplicity.model.Model Model}s.
     * </p>
     */
    protected void initWidgets()
    {
        fWidgets.put(EditingMode.ROTATION, new RotationWidget());
        fWidgets.put(EditingMode.SELECTION, new SelectionWidget());
        fWidgets.put(EditingMode.TRANSLATION, new TranslationWidget());
    }

    /**
     * <p>
     * Sets the {@link com.se.simplicity.rendering.Camera Camera} the {@link com.se.simplicity.editor.internal.Widget Widget}s will be viewed through.
     * </p>
     * 
     * @param camera The <code>Camera</code> the <code>Widget</code>s will be viewed through.
     */
    public void setCamera(final Camera camera)
    {
        fRenderer.setCamera(camera);
        fPickingEngine.setCamera(camera);
    }

    /**
     * <p>
     * Sets the {@link com.se.simplicity.editor.internal.EditingMode EditingMode} used to manipulate the {@link com.se.simplicity.scene.Scene Scene}.
     * </p>
     * 
     * @param editingMode The <code>EditingMode</code> used to manipulate the <code>Scene</code>.
     */
    public void setEditingMode(final EditingMode editingMode)
    {
        fEditingMode = editingMode;

        Widget widget = fWidgets.get(fEditingMode);
        widget.setSelectedWidgetNode(null);
        fRenderer.setWidget(widget);
    }

    /**
     * <p>
     * Sets the JOGL rendering environment used to display the {@link com.se.simplicity.editor.internal.Widget Widget}s.
     * </p>
     * 
     * @param gl The JOGL rendering environment used to display the <code>Widget</code>s.
     */
    public void setGL(final GL gl)
    {
        ((JOGLComponent) fPickingEngine).setGL(gl);
        ((JOGLComponent) fPickingRenderingEngine).setGL(gl);
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
        if (fSelectionMode == SelectionMode.MODEL)
        {
            fRenderingEngine.setRendererRoot(fRenderer, fScene.getSceneGraph().getRoot());
            fPickingRenderingEngine.setRendererRoot(fRenderer, fScene.getSceneGraph().getRoot());
        }
        else
        {
            fRenderingEngine.setRendererRoot(fRenderer, selection.getNode());
            fPickingRenderingEngine.setRendererRoot(fRenderer, selection.getNode());
        }

        for (Entry<EditingMode, Widget> widgetEntry : fWidgets.entrySet())
        {
            widgetEntry.getValue().setSelection(selection);
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

        fRenderer.setSelectionMode(fSelectionMode);

        if (fSelectionMode == SelectionMode.EDGES)
        {
            fPickingEngine.getPicker().setDrawingMode(DrawingMode.EDGES);
        }
        else if (fSelectionMode == SelectionMode.FACES)
        {
            fPickingEngine.getPicker().setDrawingMode(DrawingMode.FACES);
        }
        else if (fSelectionMode == SelectionMode.MODEL)
        {
            fPickingEngine.getPicker().setDrawingMode(DrawingMode.FACES);
        }
        else if (fSelectionMode == SelectionMode.VERTICES)
        {
            fPickingEngine.getPicker().setDrawingMode(DrawingMode.VERTICES);
        }
    }

    /**
     * <p>
     * Sets the size of the viewport the {@link com.se.simplicity.editor.internal.Widget Widget}s are being viewed through (the size of the 3D
     * canvas).
     * </p>
     * 
     * @param viewportSize The size of the viewport the <code>Widget</code>s are being viewed through (the size of the 3D canvas).
     */
    public void setViewportSize(final Dimension viewportSize)
    {
        ((SimpleJOGLPicker) fPickingEngine.getPicker()).getRenderingEngine().setViewportSize(viewportSize);
    }
}
