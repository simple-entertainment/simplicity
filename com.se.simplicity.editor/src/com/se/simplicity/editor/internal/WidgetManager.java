package com.se.simplicity.editor.internal;

import java.awt.Dimension;
import java.util.HashMap;
import java.util.Map;
import java.util.Map.Entry;

import javax.media.opengl.GL;

import com.se.simplicity.editor.internal.picking.WidgetJOGLPicker;
import com.se.simplicity.editor.internal.rendering.ManipulationWidgetJOGLRenderer;
import com.se.simplicity.editor.internal.rendering.SelectionWidgetJOGLRenderer;
import com.se.simplicity.editor.internal.selection.SceneSelection;
import com.se.simplicity.jogl.JOGLComponent;
import com.se.simplicity.jogl.picking.SimpleJOGLPicker;
import com.se.simplicity.jogl.picking.engine.SimpleJOGLPickingEngine;
import com.se.simplicity.jogl.rendering.AdaptingJOGLRenderer;
import com.se.simplicity.jogl.rendering.BlendingJOGLRenderer;
import com.se.simplicity.jogl.rendering.DepthClearingJOGLRenderer;
import com.se.simplicity.jogl.rendering.NamePassingJOGLRenderer;
import com.se.simplicity.jogl.rendering.NamedJOGLRenderer;
import com.se.simplicity.jogl.rendering.SimpleJOGLRenderer;
import com.se.simplicity.jogl.rendering.engine.SimpleJOGLRenderingEngine;
import com.se.simplicity.jogl.scene.SimpleJOGLScene;
import com.se.simplicity.picking.engine.PickingEngine;
import com.se.simplicity.rendering.Camera;
import com.se.simplicity.rendering.Renderer;
import com.se.simplicity.rendering.engine.RenderingEngine;
import com.se.simplicity.scene.Scene;
import com.se.simplicity.scenegraph.SimpleSceneGraph;

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
     * Fills the select buffer with {@link com.se.simplicity.editor.internal.Widget Widget} selection data.
     * </p>
     */
    private AdaptingJOGLRenderer fManipulationPickingRenderer;

    /**
     * <p>
     * Renders the manipulation {@link com.se.simplicity.editor.internal.Widget Widget}s.
     * </p>
     */
    private ManipulationWidgetJOGLRenderer fManipulationWidgetRenderer;

    /**
     * The {@link com.se.simplicity.scene.Scene Scene} that contains the manipulation {@link com.se.simplicity.editor.internal.Widget Widget}.
     */
    private Scene fManipulationWidgetScene;

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
    private SimpleJOGLRenderingEngine fPickingRenderingEngine;

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
     * Fills the select buffer with {@link com.se.simplicity.scene.Scene Scene} selection data.
     * </p>
     */
    private AdaptingJOGLRenderer fSelectionPickingRenderer;

    /**
     * <p>
     * Renders the selection {@link com.se.simplicity.editor.internal.Widget Widget}.
     * </p>
     */
    private SelectionWidgetJOGLRenderer fSelectionWidgetRenderer;

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

        Renderer basePickingRenderer = new NamedJOGLRenderer();
        Renderer baseWidgetRenderer = new BlendingJOGLRenderer(new DepthClearingJOGLRenderer(new SimpleJOGLRenderer()));

        fEditingMode = null;
        fManipulationPickingRenderer = new NamePassingJOGLRenderer(new ManipulationWidgetJOGLRenderer(basePickingRenderer));
        fManipulationWidgetRenderer = new ManipulationWidgetJOGLRenderer(baseWidgetRenderer);
        fManipulationWidgetScene = null;
        fPickingEngine = null;
        fPickingRenderingEngine = null;
        fSelectionPickingRenderer = new NamePassingJOGLRenderer(new SelectionWidgetJOGLRenderer(basePickingRenderer));
        fSelectionWidgetRenderer = new SelectionWidgetJOGLRenderer(baseWidgetRenderer);
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

        // The selection renderers are used with only one widget so it can be set during initialisation.
        fSelectionWidgetRenderer.setWidget(fWidgets.get(EditingMode.SELECTION));
        ((SelectionWidgetJOGLRenderer) fSelectionPickingRenderer.getRenderer()).setWidget(fWidgets.get(EditingMode.SELECTION));
    }

    /**
     * <p>
     * Initialises the {@link com.se.simplicity.picking.engine.PickingEngine PickingEngine} used to select widget components.
     * </p>
     */
    protected void initPickingEngine()
    {
        fPickingEngine = new SimpleJOGLPickingEngine();
        WidgetJOGLPicker picker = new WidgetJOGLPicker();
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

        fManipulationWidgetScene = new SimpleJOGLScene();
        fManipulationWidgetScene.setSceneGraph(new SimpleSceneGraph());
        fManipulationWidgetScene.getSceneGraph().addSubgraph(fWidgets.get(EditingMode.ROTATION).getRootNode());
        fManipulationWidgetScene.getSceneGraph().addSubgraph(fWidgets.get(EditingMode.TRANSLATION).getRootNode());
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
        fManipulationWidgetRenderer.setCamera(camera);
        fSelectionWidgetRenderer.setCamera(camera);

        fPickingEngine.setCamera(camera);
        ((ManipulationWidgetJOGLRenderer) fManipulationPickingRenderer.getRenderer()).setCamera(camera);
        ((SelectionWidgetJOGLRenderer) fSelectionPickingRenderer.getRenderer()).setCamera(camera);
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

        // Setup rendering engine.
        if (fEditingMode == EditingMode.SELECTION)
        {
            // Configure the rendering engine to render ONLY the selection widget.
            fRenderingEngine.addRenderer(fSelectionWidgetRenderer);
            fRenderingEngine.removeRenderer(fManipulationWidgetRenderer);

        }
        else
        {
            Widget widget = fWidgets.get(fEditingMode);
            widget.setSelectedWidgetNode(null);

            // Configure the renderer to render the appropriate manipulation widget.
            fManipulationWidgetRenderer.setWidget(widget);

            // Configure the rendering engine to render ONLY the appropriate manipulation widget.
            fRenderingEngine.removeRenderer(fSelectionWidgetRenderer);
            fRenderingEngine.addRenderer(fManipulationWidgetRenderer);
            fRenderingEngine.setRendererRoot(fManipulationWidgetRenderer, widget.getRootNode());

        }

        // Setup picking engine.
        if (fEditingMode == EditingMode.SELECTION)
        {
            // Configure the picking engine to pick ONLY the main scene (in reality it will be picking the selection widgets drawn instead of the
            // models in the main scene).
            fPickingEngine.setScene(fScene);
            fPickingRenderingEngine.addRenderer(fSelectionPickingRenderer);
            fPickingRenderingEngine.removeRenderer(fManipulationPickingRenderer);
        }
        else
        {
            // Configure the renderer to render the appropriate manipulation widget.
            ((ManipulationWidgetJOGLRenderer) fManipulationPickingRenderer.getRenderer()).setWidget(fWidgets.get(fEditingMode));

            // Configure the picking engine to pick ONLY the manipulation widget.
            fPickingEngine.setScene(fManipulationWidgetScene);
            fPickingRenderingEngine.removeRenderer(fSelectionPickingRenderer);
            fPickingRenderingEngine.addRenderer(fManipulationPickingRenderer);
            fPickingRenderingEngine.setRendererRoot(fManipulationPickingRenderer, fWidgets.get(fEditingMode).getRootNode());
        }
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
        for (Entry<EditingMode, Widget> widgetEntry : fWidgets.entrySet())
        {
            widgetEntry.getValue().setSelection(selection);
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
