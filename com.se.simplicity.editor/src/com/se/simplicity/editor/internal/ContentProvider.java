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
import com.se.simplicity.model.Model;
import com.se.simplicity.model.shape.Capsule;
import com.se.simplicity.model.shape.Shape;
import com.se.simplicity.model.shape.Sphere;
import com.se.simplicity.model.shape.Torus;
import com.se.simplicity.picking.engine.PickingEngine;
import com.se.simplicity.rendering.Camera;
import com.se.simplicity.rendering.Renderer;
import com.se.simplicity.rendering.engine.RenderingEngine;
import com.se.simplicity.scene.Scene;
import com.se.simplicity.scenegraph.Node;
import com.se.simplicity.scenegraph.SceneGraph;
import com.se.simplicity.scenegraph.SimpleNode;
import com.se.simplicity.scenegraph.SimpleSceneGraph;
import com.se.simplicity.scenegraph.model.ModelNode;
import com.se.simplicity.scenegraph.model.SimpleModelNode;
import com.se.simplicity.vector.SimpleRGBColourVectorf4;
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
     * The currently selected widget component.
     * </p>
     */
    private ModelNode fSelectedWidgetComponent;

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
     * The currently displayed {@link com.se.simplicity.editor.internal.Widget Widget}.
     * </p>
     */
    private Widget fWidget;

    /**
     * <p>
     * The {@link com.se.simplicity.picking.engine.PickingEngine PickingEngine} used to select widget components.
     * </p>
     */
    private PickingEngine fWidgetPickingEngine;

    /**
     * <p>
     * The root <code>Node</code>s for the subgraphs that contain the 3D widgets used to manipulate <code>Model</code>s.
     * </p>
     */
    private Map<Widget, Node> fWidgetRootNodes;

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
        fSelectedWidgetComponent = null;
        fViewingCamera = null;
        fSynchronisesCameraAspectRatio = true;
        fWidget = Widget.NONE;
        fWidgetPickingEngine = null;
        fWidgetRootNodes = new HashMap<Widget, Node>();
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
        fSelectedWidgetComponent = null;
        fViewingCamera = null;
        fSynchronisesCameraAspectRatio = true;
        fWidget = Widget.NONE;
        fWidgetPickingEngine = null;
        fWidgetRootNodes = new HashMap<Widget, Node>();
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
     * Executes an edit against the currently selected scene component.
     * </p>
     * 
     * @param x The x value of the edit.
     * @param y The y value of the edit.
     */
    public void executeEdit(final int x, final int y)
    {
        if (fSelectedSceneComponent == null)
        {
            return;
        }

        if (fSelectedSceneComponent instanceof Node)
        {
            if (fWidget == Widget.ROTATION)
            {
                ((Node) fSelectedSceneComponent).getTransformation().rotate((float) Math.toRadians(x),
                        new SimpleTranslationVectorf4(0.0f, 1.0f, 0.0f, 1.0f));
                ((Node) fSelectedSceneComponent).getTransformation().rotate((float) Math.toRadians(y),
                        new SimpleTranslationVectorf4(1.0f, 0.0f, 0.0f, 1.0f));

                fWidgetRootNodes.get(fWidget).getTransformation().rotate((float) Math.toRadians(x),
                        new SimpleTranslationVectorf4(0.0f, 1.0f, 0.0f, 1.0f));
                fWidgetRootNodes.get(fWidget).getTransformation().rotate((float) Math.toRadians(y),
                        new SimpleTranslationVectorf4(1.0f, 0.0f, 0.0f, 1.0f));
            }
            else if (fWidget == Widget.TRANSLATION)
            {
                ((Node) fSelectedSceneComponent).getTransformation().translate(new SimpleTranslationVectorf4(x * 0.01f, y * 0.01f, 0.0f, 1.0f));
                fWidgetRootNodes.get(fWidget).getTransformation().translate(new SimpleTranslationVectorf4(x * 0.01f, y * 0.01f, 0.0f, 1.0f));
            }
        }
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
        // Initialise the rotation widget.
        SimpleNode rotationRootNode = new SimpleNode();

        Torus xTorus = new Torus();
        xTorus.setColour(new SimpleRGBColourVectorf4(1.0f, 0.0f, 0.0f, 0.5f));
        xTorus.setInnerRadius(0.05f);
        xTorus.setOuterRadius(0.5f);
        SimpleModelNode xTorusNode = new SimpleModelNode();
        xTorusNode.getTransformation().rotate((float) (90.0f * Math.PI / 180.0f), new SimpleTranslationVectorf4(0.0f, 1.0f, 0.0f, 1.0f));
        xTorusNode.setModel(xTorus);

        Torus yTorus = new Torus();
        yTorus.setColour(new SimpleRGBColourVectorf4(0.0f, 1.0f, 0.0f, 0.5f));
        yTorus.setInnerRadius(0.05f);
        yTorus.setOuterRadius(0.5f);
        SimpleModelNode yTorusNode = new SimpleModelNode();
        yTorusNode.getTransformation().rotate((float) (90.0f * Math.PI / 180.0f), new SimpleTranslationVectorf4(1.0f, 0.0f, 0.0f, 1.0f));
        yTorusNode.setModel(yTorus);

        Torus zTorus = new Torus();
        zTorus.setColour(new SimpleRGBColourVectorf4(0.0f, 0.0f, 1.0f, 0.5f));
        zTorus.setInnerRadius(0.05f);
        zTorus.setOuterRadius(0.5f);
        SimpleModelNode zTorusNode = new SimpleModelNode();
        zTorusNode.setModel(zTorus);

        Sphere freeSphere = new Sphere();
        freeSphere.setColour(new SimpleRGBColourVectorf4(1.0f, 1.0f, 1.0f, 0.5f));
        freeSphere.setRadius(0.1f);

        SimpleModelNode freeSphereNode0 = new SimpleModelNode();
        freeSphereNode0.getTransformation().setXAxisTranslation(0.5f);
        freeSphereNode0.setModel(freeSphere);

        SimpleModelNode freeSphereNode1 = new SimpleModelNode();
        freeSphereNode1.getTransformation().setXAxisTranslation(-0.5f);
        freeSphereNode1.setModel(freeSphere);

        SimpleModelNode freeSphereNode2 = new SimpleModelNode();
        freeSphereNode2.getTransformation().setYAxisTranslation(0.5f);
        freeSphereNode2.setModel(freeSphere);

        SimpleModelNode freeSphereNode3 = new SimpleModelNode();
        freeSphereNode3.getTransformation().setYAxisTranslation(-0.5f);
        freeSphereNode3.setModel(freeSphere);

        SimpleModelNode freeSphereNode4 = new SimpleModelNode();
        freeSphereNode4.getTransformation().setZAxisTranslation(0.5f);
        freeSphereNode4.setModel(freeSphere);

        SimpleModelNode freeSphereNode5 = new SimpleModelNode();
        freeSphereNode5.getTransformation().setZAxisTranslation(-0.5f);
        freeSphereNode5.setModel(freeSphere);

        fWidgetRootNodes.put(Widget.ROTATION, rotationRootNode);
        rotationRootNode.addChild(xTorusNode);
        rotationRootNode.addChild(yTorusNode);
        rotationRootNode.addChild(zTorusNode);
        rotationRootNode.addChild(freeSphereNode0);
        rotationRootNode.addChild(freeSphereNode1);
        rotationRootNode.addChild(freeSphereNode2);
        rotationRootNode.addChild(freeSphereNode3);
        rotationRootNode.addChild(freeSphereNode4);
        rotationRootNode.addChild(freeSphereNode5);

        // Initialise the rotation widget.
        SimpleNode translationRootNode = new SimpleNode();

        Capsule xCapsule = new Capsule();
        xCapsule.setColour(new SimpleRGBColourVectorf4(1.0f, 0.0f, 0.0f, 0.5f));
        xCapsule.setLength(0.5f);
        xCapsule.setRadius(0.05f);
        SimpleModelNode xCapsuleNode = new SimpleModelNode();
        xCapsuleNode.getTransformation().rotate((float) (90.0f * Math.PI / 180.0f), new SimpleTranslationVectorf4(0.0f, 1.0f, 0.0f, 1.0f));
        xCapsuleNode.setModel(xCapsule);

        Capsule yCapsule = new Capsule();
        yCapsule.setColour(new SimpleRGBColourVectorf4(0.0f, 1.0f, 0.0f, 0.5f));
        yCapsule.setLength(0.5f);
        yCapsule.setRadius(0.05f);
        SimpleModelNode yCapsuleNode = new SimpleModelNode();
        yCapsuleNode.getTransformation().rotate((float) (90.0f * Math.PI / 180.0f), new SimpleTranslationVectorf4(1.0f, 0.0f, 0.0f, 1.0f));
        yCapsuleNode.setModel(yCapsule);

        Capsule zCapsule = new Capsule();
        zCapsule.setColour(new SimpleRGBColourVectorf4(0.0f, 0.0f, 1.0f, 0.5f));
        zCapsule.setLength(0.5f);
        zCapsule.setRadius(0.05f);
        SimpleModelNode zCapsuleNode = new SimpleModelNode();
        yCapsuleNode.getTransformation().rotate((float) Math.PI, new SimpleTranslationVectorf4(0.0f, 1.0f, 0.0f, 1.0f));
        zCapsuleNode.setModel(zCapsule);

        SimpleModelNode freeSphereNode = new SimpleModelNode();
        freeSphereNode.setModel(freeSphere);

        fWidgetRootNodes.put(Widget.TRANSLATION, translationRootNode);
        translationRootNode.addChild(xCapsuleNode);
        translationRootNode.addChild(yCapsuleNode);
        translationRootNode.addChild(zCapsuleNode);
        translationRootNode.addChild(freeSphereNode);
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
     * @param sceneComponent The currently selected scene component.
     */
    public void setSelectedSceneComponent(final Object sceneComponent)
    {
        if (sceneComponent == fSelectedSceneComponent)
        {
            return;
        }

        fSelectedSceneComponent = sceneComponent;

        if (fSelectedSceneComponent == null)
        {
            fRenderingEngine.setRendererRoot(fRenderingEngine.getRenderers().get(1), null);
            SceneManager.getSceneManager().setActiveNode(null);
        }
        else if (fSelectedSceneComponent instanceof Node)
        {
            fRenderingEngine.setRendererRoot(fRenderingEngine.getRenderers().get(1), (Node) fSelectedSceneComponent);
            SceneManager.getSceneManager().setActiveNode((Node) fSelectedSceneComponent);
        }
    }

    /**
     * <p>
     * Sets the currently selected widget component.
     * </p>
     * 
     * @param widgetComponent The currently selected widget component.
     */
    public void setSelectedWidgetComponent(final ModelNode widgetComponent)
    {
        Model oldModel = null;
        if (fSelectedWidgetComponent != null)
        {
            oldModel = fSelectedWidgetComponent.getModel();
        }
        Model newModel = null;
        if (widgetComponent != null)
        {
            newModel = widgetComponent.getModel();
        }

        if (oldModel != null)
        {
            ((SimpleRGBColourVectorf4) ((Shape) oldModel).getColour()).setAlpha(0.5f);
        }

        if (newModel != null)
        {
            ((SimpleRGBColourVectorf4) ((Shape) newModel).getColour()).setAlpha(1.0f);
        }

        fSelectedWidgetComponent = widgetComponent;
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
     * Sets the current {@link com.se.simplicity.editor.internal.Widget Widget} in the active editor.
     * </p>
     * 
     * @param widget The current {@link com.se.simplicity.editor.internal.Widget Widget} in the active editor.
     */
    public void setWidget(final Widget widget)
    {
        Renderer widgetRenderer = fRenderingEngine.getRenderers().get(2);
        SceneGraph widgetPickerSceneGraph = fWidgetPickingEngine.getScene().getSceneGraph();

        // Remove previous Widget from the Widget PickingEngine's Scene.
        if (fWidget != Widget.NONE)
        {
            widgetPickerSceneGraph.removeSubgraph(fWidgetRootNodes.get(fWidget));
        }

        fWidget = widget;

        if (fWidget == Widget.NONE)
        {
            fRenderingEngine.setRendererRoot(widgetRenderer, null);
        }

        // Set the root of the widget to be the root for the Widget Renderer and include it in the Widget PickingEngine's Scene but do NOT add it
        // to the main Scene. This stops the Widget from appearing in the various views displaying an analysis of the Scene or being synchronised
        // into the source file.
        else
        {
            fRenderingEngine.setRendererRoot(widgetRenderer, fWidgetRootNodes.get(widget));
            widgetPickerSceneGraph.addSubgraph(fWidgetRootNodes.get(widget));
        }

        setSelectedWidgetComponent(null);
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
