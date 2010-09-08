package com.se.simplicity.editor.internal;

import java.awt.Dimension;
import java.util.HashMap;
import java.util.Map;

import javax.media.opengl.GL;
import javax.media.opengl.GLContext;

import org.eclipse.swt.graphics.Rectangle;
import org.eclipse.swt.opengl.GLCanvas;

import com.se.simplicity.editor.internal.engine.DisplayAsyncJOGLCompositeEngine;
import com.se.simplicity.jogl.JOGLComponent;
import com.se.simplicity.jogl.picking.SimpleJOGLPicker;
import com.se.simplicity.jogl.picking.engine.SimpleJOGLPickingEngine;
import com.se.simplicity.jogl.rendering.NamedJOGLRenderer;
import com.se.simplicity.jogl.rendering.SimpleJOGLCamera;
import com.se.simplicity.jogl.rendering.engine.SimpleJOGLRenderingEngine;
import com.se.simplicity.jogl.scene.SimpleJOGLScene;
import com.se.simplicity.picking.engine.PickingEngine;
import com.se.simplicity.rendering.Camera;
import com.se.simplicity.rendering.Renderer;
import com.se.simplicity.rendering.engine.RenderingEngine;
import com.se.simplicity.scene.Scene;
import com.se.simplicity.scenegraph.Node;
import com.se.simplicity.scenegraph.SceneGraph;
import com.se.simplicity.scenegraph.SimpleNode;
import com.se.simplicity.scenegraph.SimpleSceneGraph;
import com.se.simplicity.vector.SimpleTranslationVectorf4;

/**
 * <p>
 * Provides the content that will be displayed by a {@link com.se.simplicity.editor.ui.editors.SceneEditor SceneEditor}.
 * </p>
 * 
 * @author Gary Buyn
 */
public class ContentProvider
{
    /**
     * <p>
     * The {@link com.se.simplicity.rendering.engine.RenderingEngine RenderingEngine} that will render the {@link com.se.simplicity.scene.Scene Scene}
     * to the 3D canvas.
     * </p>
     */
    private RenderingEngine fRenderingEngine;

    /**
     * <p>
     * The {@link com.se.simplicity.scene.Scene Scene} displayed by this <code>ContentProvider</code>.
     * </p>
     */
    private Scene fScene;

    /**
     * <p>
     * The {@link com.se.simplicity.picking.engine.PickingEngine PickingEngine} used to select scene components in the
     * {@link com.se.simplicity.scene.Scene Scene}.
     * </p>
     */
    private PickingEngine fScenePickingEngine;

    /**
     * <p>
     * The currently selected scene component.
     * </p>
     */
    private Object fSelectedSceneComponent;

    /**
     * <p>
     * Determines whether the viewing <code>Camera</code>'s aspect ratio should be synchronised with the aspect ratio of the canvas.
     * </p>
     */
    private boolean fSynchronisesCameraAspectRatio;

    /**
     * <p>
     * The {@link com.se.simplicity.rendering.Camera Camera} used to view the {@link com.se.simplicity.scene.Scene Scene}.
     * </p>
     */
    private Camera fViewingCamera;

    /**
     * <p>
     * The current {@link com.se.simplicity.editor.internal.EditMode EditMode}.
     * </p>
     */
    private EditMode fEditMode;

    /**
     * <p>
     * The {@link com.se.simplicity.picking.engine.PickingEngine PickingEngine} used to select widget components.
     * </p>
     */
    private PickingEngine fWidgetPickingEngine;

    /**
     * <p>
     * The {@link com.se.simplicity.editor.internal.Widget Widget}s used to manipulate {@link com.se.simplicity.model.Model Model}s.
     * </p>
     */
    private Map<EditMode, Widget> fWidgets;

    /**
     * <p>
     * Creates an instance of <code>ContentProvider</code>.
     * </p>
     */
    public ContentProvider()
    {
        fRenderingEngine = null;
        fScene = null;
        fScenePickingEngine = null;
        fSelectedSceneComponent = null;
        fViewingCamera = null;
        fSynchronisesCameraAspectRatio = true;
        fEditMode = EditMode.SELECTION;
        fWidgetPickingEngine = null;
        fWidgets = new HashMap<EditMode, Widget>();
    }

    /**
     * <p>
     * Creates an instance of <code>ContentProvider</code>.
     * </p>
     * 
     * @param scene The {@link com.se.simplicity.scene.Scene Scene} displayed by this <code>ContentProvider</code>.
     */
    public ContentProvider(final Scene scene)
    {
        fScene = scene;

        fRenderingEngine = null;
        fScenePickingEngine = null;
        fSelectedSceneComponent = null;
        fViewingCamera = null;
        fSynchronisesCameraAspectRatio = true;
        fEditMode = EditMode.SELECTION;
        fWidgetPickingEngine = null;
        fWidgets = new HashMap<EditMode, Widget>();
    }

    /**
     * <p>
     * Displays the content for the lifetime of the given <code>GLCanvas</code>.
     * </p>
     * 
     * @param canvas The <code>GLCanvas</code> to display the contents on.
     * @param glContext The <code>GLContext</code> to use when displaying.
     */
    public void displayContent(final GLCanvas canvas, final GLContext glContext)
    {
        DisplayAsyncJOGLCompositeEngine compositeEngine = new DisplayAsyncJOGLCompositeEngine(canvas, glContext);
        compositeEngine.addEngine(fWidgetPickingEngine);
        compositeEngine.addEngine(fScenePickingEngine);
        compositeEngine.addEngine(fRenderingEngine);

        compositeEngine.run();
    }

    /**
     * <p>
     * Retrieves the {@link com.se.simplicity.editor.internal.Widget Widget} currently being used to manipulate {@link com.se.simplicity.model.Model
     * Model}s.
     * </p>
     * 
     * @return The <code>Widget</code> currently being used to manipulate {@link com.se.simplicity.model.Model Model}s.
     */
    public Widget getCurrentWidget()
    {
        return (fWidgets.get(fEditMode));
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
     * Retrieves the {@link com.se.simplicity.scene.Scene Scene} displayed by this <code>ContentProvider</code>.
     * </p>
     * 
     * @return The <code>Scene</code> displayed by this <code>ContentProvider</code>.
     */
    public Scene getScene()
    {
        return (fScene);
    }

    /**
     * <p>
     * Retrieves the {@link com.se.simplicity.picking.engine.PickingEngine PickingEngine} used to select scene components in the
     * {@link com.se.simplicity.scene.Scene Scene}.
     * </p>
     * 
     * @return The <code>PickingEngine</code> used to select scene components in the <code>Scene</code>.
     */
    public PickingEngine getScenePickingEngine()
    {
        return (fScenePickingEngine);
    }

    /**
     * <p>
     * Retrieves the {@link com.se.simplicity.rendering.Camera Camera} used to view the {@link com.se.simplicity.scene.Scene Scene}.
     * </p>
     * 
     * @return The <code>Camera</code> used to view the <code>Scene</code>.
     */
    public Camera getViewingCamera()
    {
        return (fViewingCamera);
    }

    /**
     * <p>
     * Retrieves the {@link com.se.simplicity.picking.engine.PickingEngine PickingEngine} used to select widget components.
     * </p>
     * 
     * @return The <code>PickingEngine</code> used to select widget components.
     */
    public PickingEngine getWidgetPickingEngine()
    {
        return (fWidgetPickingEngine);
    }

    /**
     * <p>
     * Initialises the content.
     * </p>
     */
    public void init()
    {
        SceneManager sceneManager = SceneManager.getSceneManager();

        // Initialise engines.
        fRenderingEngine = sceneManager.getRenderingEngineForScene(fScene);
        fScenePickingEngine = sceneManager.getPickingEngineForScene(fScene);
        initWidgetPickingEngine();

        initViewingCamera();
        initWidgets();

        // Set the viewing Camera as the viewpoint for picking and rendering but do NOT add to the Scene. This stops the Camera from appearing in the
        // various views displaying an analysis of the Scene or being synchronised into the source file.
        fRenderingEngine.setCamera(fViewingCamera);
        fScenePickingEngine.setCamera(fViewingCamera);
        fWidgetPickingEngine.setCamera(fViewingCamera);

        fScenePickingEngine.addPickListener(new ScenePickListener(this));
        fWidgetPickingEngine.addPickListener(new WidgetPickListener(this));
    }

    /**
     * <p>
     * Initialises the {@link com.se.simplicity.rendering.Camera Camera} used to view the {@link com.se.simplicity.scene.Scene Scene}.
     * </p>
     */
    protected void initViewingCamera()
    {
        fViewingCamera = new SimpleJOGLCamera();
        SimpleNode subjectNode = new SimpleNode();
        SimpleNode cameraNode = new SimpleNode();
        subjectNode.addChild(cameraNode);
        cameraNode.getTransformation().translate(new SimpleTranslationVectorf4(0.0f, 0.0f, 5.0f, 1.0f));
        fViewingCamera.setNode(cameraNode);
    }

    /**
     * <p>
     * Initialises the {@link com.se.simplicity.picking.engine.PickingEngine PickingEngine} used to select widget components.
     * </p>
     */
    protected void initWidgetPickingEngine()
    {
        fWidgetPickingEngine = new SimpleJOGLPickingEngine();
        SimpleJOGLPicker picker = new SimpleJOGLPicker();
        SimpleJOGLRenderingEngine renderingEngine = new SimpleJOGLRenderingEngine();
        NamedJOGLRenderer renderer = new NamedJOGLRenderer();
        SimpleJOGLScene scene = new SimpleJOGLScene();

        fWidgetPickingEngine.setPicker(picker);
        fWidgetPickingEngine.setScene(scene);
        picker.setRenderingEngine(renderingEngine);
        renderingEngine.addRenderer(renderer);
        scene.setSceneGraph(new SimpleSceneGraph());
    }

    /**
     * <p>
     * Initialises the widgets used to manipulate {@link com.se.simplicity.model.Model Model}s.
     * </p>
     */
    protected void initWidgets()
    {
        fWidgets.put(EditMode.ROTATION, new RotationWidget());
        fWidgets.put(EditMode.TRANSLATION, new TranslationWidget());
    }

    /**
     * <p>
     * Sets the size of the canvas the content will be rendered on.
     * </p>
     * 
     * @param canvasSize The size of the canvas the content will be rendered on.
     */
    public void setCanvasSize(final Rectangle canvasSize)
    {
        Dimension viewportSize = new Dimension();
        viewportSize.setSize(canvasSize.width, canvasSize.height);

        fRenderingEngine.setViewportSize(viewportSize);
        ((SimpleJOGLPicker) fScenePickingEngine.getPicker()).getRenderingEngine().setViewportSize(viewportSize);
        ((SimpleJOGLPicker) fWidgetPickingEngine.getPicker()).getRenderingEngine().setViewportSize(viewportSize);

        if (fSynchronisesCameraAspectRatio)
        {
            fViewingCamera.setFrameAspectRatio((float) canvasSize.height / (float) canvasSize.width);
        }
    }

    /**
     * <p>
     * Sets the JOGL rendering environment used to display the content.
     * </p>
     * 
     * @param gl The JOGL rendering environment used to display the content.
     */
    public void setGL(final GL gl)
    {
        ((JOGLComponent) fRenderingEngine).setGL(gl);

        ((JOGLComponent) fScenePickingEngine).setGL(gl);
        ((JOGLComponent) ((SimpleJOGLPicker) fScenePickingEngine.getPicker()).getRenderingEngine()).setGL(gl);

        ((JOGLComponent) fWidgetPickingEngine).setGL(gl);
        ((JOGLComponent) ((SimpleJOGLPicker) fWidgetPickingEngine.getPicker()).getRenderingEngine()).setGL(gl);

        ((JOGLComponent) fViewingCamera).setGL(gl);
    }

    /**
     * <p>
     * Sets the {@link com.se.simplicity.scene.Scene Scene} displayed by this <code>ContentProvider</code>.
     * </p>
     * 
     * @param scene The <code>Scene</code> displayed by this <code>ContentProvider</code>.
     */
    public void setScene(final Scene scene)
    {
        fScene = scene;
    }

    /**
     * <p>
     * Sets the currently selected scene component.
     * </p>
     * 
     * @param selectedSceneComponent The currently selected scene component.
     */
    public void setSelectedSceneComponent(final Object selectedSceneComponent)
    {
        if (selectedSceneComponent == fSelectedSceneComponent)
        {
            return;
        }

        fSelectedSceneComponent = selectedSceneComponent;

        if (fSelectedSceneComponent == null)
        {
            fRenderingEngine.setRendererRoot(fRenderingEngine.getRenderers().get(1), null);
            SceneManager.getSceneManager().setActiveNode(null);
        }
        else if (fSelectedSceneComponent instanceof Node)
        {
            fRenderingEngine.setRendererRoot(fRenderingEngine.getRenderers().get(1), (Node) fSelectedSceneComponent);
            SceneManager.getSceneManager().setActiveNode((Node) fSelectedSceneComponent);

            if (fWidgets.get(fEditMode) != null)
            {
                fWidgets.get(fEditMode).setSelectedSceneComponent(fSelectedSceneComponent);
            }
        }
    }

    /**
     * <p>
     * Determines whether the viewing <code>Camera</code>'s aspect ratio should be synchronised with the aspect ratio of the canvas.
     * </p>
     * 
     * @param synchronisesCameraAspectRatio Determines whether the viewing <code>Camera</code>'s aspect ratio should be synchronised with the aspect
     * ratio of the canvas.
     */
    public void setSynchronisesCameraAspectRatio(final boolean synchronisesCameraAspectRatio)
    {
        fSynchronisesCameraAspectRatio = synchronisesCameraAspectRatio;
    }

    /**
     * <p>
     * Sets the current {@link com.se.simplicity.editor.internal.EditMode EditMode} in the active editor.
     * </p>
     * 
     * @param editMode The current {@link com.se.simplicity.editor.internal.EditMode EditMode} in the active editor.
     */
    public void setEditMode(final EditMode editMode)
    {
        Renderer widgetRenderer = fRenderingEngine.getRenderers().get(2);
        SceneGraph widgetPickerSceneGraph = fWidgetPickingEngine.getScene().getSceneGraph();

        // Remove previous Widget from the Widget PickingEngine's Scene.
        if (fEditMode != EditMode.SELECTION)
        {
            widgetPickerSceneGraph.removeSubgraph(fWidgets.get(fEditMode).getRootNode());
        }

        fEditMode = editMode;

        if (fEditMode == EditMode.SELECTION)
        {
            fRenderingEngine.setRendererRoot(widgetRenderer, null);
        }

        else
        {
            Widget widget = fWidgets.get(fEditMode);

            // Set the root of the widget to be the root for the Widget Renderer and include it in the Widget PickingEngine's Scene but do NOT add it
            // to the main Scene. This stops the Widget from appearing in the various views displaying an analysis of the Scene or being synchronised
            // into the source file.
            fRenderingEngine.setRendererRoot(widgetRenderer, widget.getRootNode());
            widgetPickerSceneGraph.addSubgraph(widget.getRootNode());

            fWidgets.get(fEditMode).setSelectedSceneComponent(null);
        }
    }

    /**
     * <p>
     * Determines whether the viewing <code>Camera</code>'s aspect ratio should be synchronised with the aspect ratio of the canvas.
     * </p>
     * 
     * @return True if the viewing <code>Camera</code>'s aspect ratio should be synchronised with the aspect ratio of the canvas, false otherwise.
     */
    public boolean synchronisesCameraAspectRatio()
    {
        return (fSynchronisesCameraAspectRatio);
    }
}
