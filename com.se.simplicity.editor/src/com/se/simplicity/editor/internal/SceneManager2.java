package com.se.simplicity.editor.internal;

import java.awt.Dimension;

import javax.media.opengl.GL;

import org.apache.commons.logging.LogFactory;

import com.se.simplicity.jogl.JOGLComponent;
import com.se.simplicity.jogl.picking.SimpleJOGLPicker;
import com.se.simplicity.jogl.picking.engine.SimpleJOGLPickingEngine;
import com.se.simplicity.jogl.rendering.NamedJOGLRenderer;
import com.se.simplicity.jogl.rendering.OutlineJOGLRenderer;
import com.se.simplicity.jogl.rendering.SimpleJOGLRenderer;
import com.se.simplicity.jogl.rendering.engine.SimpleJOGLRenderingEngine;
import com.se.simplicity.picking.engine.PickingEngine;
import com.se.simplicity.rendering.Camera;
import com.se.simplicity.rendering.DrawingMode;
import com.se.simplicity.rendering.Renderer;
import com.se.simplicity.rendering.engine.RenderingEngine;
import com.se.simplicity.scene.Scene;
import com.se.simplicity.scenegraph.Node;
import com.se.simplicity.util.metadata.scene.MetaDataScene;

/**
 * <p>
 * Manages the state of the {@link com.se.simplicity.scene.Scene Scene} displayed by a {@link com.se.simplicity.editor.ui.editors.SceneEditor
 * SceneEditor} including rendering, picking and interaction modes.
 * </p>
 * 
 * @author Gary Buyn
 */
public class SceneManager2
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
     * Creates an instance of <code>SceneManager</code>.
     * </p>
     */
    public SceneManager2()
    {
        fOutlineRenderer = null;
        fPickingEngine = null;
        fRenderer = null;
        fRenderingEngine = null;
        fScene = null;
    }

    /**
     * <p>
     * Creates an instance of <code>SceneManager</code>.
     * </p>
     * 
     * @param scene The {@link com.se.simplicity.scene.Scene Scene} displayed by the {@link com.se.simplicity.editor.ui.editors.SceneEditor
     * SceneEditor}.
     */
    public SceneManager2(final Scene scene)
    {
        fScene = scene;

        fOutlineRenderer = null;
        fPickingEngine = null;
        fRenderer = null;
        fRenderingEngine = null;
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
        NamedJOGLRenderer renderer = new NamedJOGLRenderer();

        fPickingEngine.setPicker(picker);
        picker.setRenderingEngine(renderingEngine);
        renderingEngine.addRenderer(renderer);

        if (fScene != null)
        {
            fPickingEngine.setScene(fScene);
        }
    }

    /**
     * <p>
     * Initialises the {@link com.se.simplicity.rendering.Renderer Renderer}s used to render the {@link com.se.simplicity.scene.Scene Scene} and
     * outlines.
     * </p>
     */
    protected void initRenderers()
    {
        if (fScene == null || fRenderingEngine == null)
        {
            throw new IllegalStateException("This Scene Manager must have a Scene and Rendering Engine before it can be initialised.");
        }

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

        fOutlineRenderer = new OutlineJOGLRenderer(fRenderer);

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
        if (fPickingEngine == null)
        {
            throw new IllegalStateException("This Scene Manager must be initialised before the Camera can be set.");
        }

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
        if (fRenderer == null)
        {
            throw new IllegalStateException("This Scene Manager must be initialised before the Drawing Mode can be set.");
        }

        fRenderer.setDrawingMode(drawingMode);
        fOutlineRenderer.setDrawingMode(drawingMode);

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
        if (fPickingEngine == null)
        {
            throw new IllegalStateException("This Scene Manager must be initialised before the JOGL rendering environment can be set.");
        }

        ((JOGLComponent) fPickingEngine).setGL(gl);
        ((JOGLComponent) ((SimpleJOGLPicker) fPickingEngine.getPicker()).getRenderingEngine()).setGL(gl);
    }

    /**
     * <p>
     * Sets the {@link com.se.simplicity.rendering.engine.RenderingEngine RenderingEngine} that will render the {@link com.se.simplicity.scene.Scene
     * Scene} to the 3D canvas.
     * </p>
     * 
     * @param renderingEngine The <code>RenderingEngine</code> that will render the <code>Scene</code> to the 3D canvas.
     */
    public void setRenderingEngine(final RenderingEngine renderingEngine)
    {
        fRenderingEngine = renderingEngine;
    }

    /**
     * <p>
     * Sets the {@link com.se.simplicity.scene.Scene Scene} displayed by the {@link com.se.simplicity.editor.ui.editors.SceneEditor SceneEditor}.
     * </p>
     * 
     * @param scene The <code>Scene</code> displayed by the <code>SceneEditor</code>.
     */
    public void setScene(final Scene scene)
    {
        fScene = scene;

        if (fPickingEngine != null)
        {
            fPickingEngine.setScene(fScene);
        }
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
        if (fOutlineRenderer == null)
        {
            throw new IllegalStateException("This Scene Manager must be initialised before a scene component can be selected.");
        }

        if (selectedSceneComponent == null)
        {
            fRenderingEngine.setRendererRoot(fOutlineRenderer, null);
        }
        else if (selectedSceneComponent instanceof Node)
        {
            fRenderingEngine.setRendererRoot(fOutlineRenderer, (Node) selectedSceneComponent);
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
        if (fPickingEngine == null)
        {
            throw new IllegalStateException("This Scene Manager must be initialised before a viewport size can be set.");
        }

        ((SimpleJOGLPicker) fPickingEngine.getPicker()).getRenderingEngine().setViewportSize(viewportSize);
    }
}
