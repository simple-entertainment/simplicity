/*
    This file is part of The Simplicity Engine.

    The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
    by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

    The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
package com.se.simplicity.editor.ui.editors;

import javax.media.opengl.GLContext;
import javax.media.opengl.GLDrawableFactory;

import org.apache.commons.logging.LogFactory;
import org.eclipse.core.runtime.IProgressMonitor;
import org.eclipse.swt.SWT;
import org.eclipse.swt.opengl.GLCanvas;
import org.eclipse.swt.opengl.GLData;
import org.eclipse.swt.widgets.Composite;
import org.eclipse.swt.widgets.Display;
import org.eclipse.ui.IEditorInput;
import org.eclipse.ui.IEditorSite;
import org.eclipse.ui.IFileEditorInput;
import org.eclipse.ui.PartInitException;
import org.eclipse.ui.part.EditorPart;

import com.se.simplicity.editor.internal.SceneChangedEvent;
import com.se.simplicity.editor.internal.SceneChangedEventType;
import com.se.simplicity.editor.internal.SceneChangedListener;
import com.se.simplicity.editor.internal.SceneManager;
import com.se.simplicity.jogl.JOGLComponent;
import com.se.simplicity.jogl.picking.SimpleJOGLPicker;
import com.se.simplicity.jogl.picking.engine.SimpleJOGLPickingEngine;
import com.se.simplicity.jogl.rendering.SimpleJOGLCamera;
import com.se.simplicity.jogl.rendering.engine.SimpleJOGLRenderingEngine;
import com.se.simplicity.picking.engine.PickingEngine;
import com.se.simplicity.rendering.Camera;
import com.se.simplicity.rendering.Renderer;
import com.se.simplicity.rendering.engine.RenderingEngine;
import com.se.simplicity.scenegraph.Node;
import com.se.simplicity.scenegraph.SimpleNode;
import com.se.simplicity.vector.SimpleTranslationVectorf4;

/**
 * <p>
 * An eclipse editor that displays a <code>Scene</code> visually on a 3D canvas using the JOGL rendering environment.
 * </p>
 * 
 * @author Gary Buyn
 */
public class VisualSceneEditor extends EditorPart implements SceneChangedListener
{
    /**
     * <p>
     * The 3D canvas the <code>Scene</code> will be displayed visually on.
     * </p>
     */
    private GLCanvas fCanvas;

    /**
     * <p>
     * The <code>PickingEngine</code> used to select items in the <code>Scene</code>.
     * </p>
     */
    private SimpleJOGLPickingEngine fPickingEngine;

    /**
     * <p>
     * Retrieves the <code>RenderingEngine</code> that will render the <code>Scene</code> to the 3D canvas.
     * </p>
     */
    private RenderingEngine fRenderingEngine;

    /**
     * <p>
     * The name of the scene this editor is displaying.
     * </p>
     */
    private String fSceneName;

    /**
     * <p>
     * The <code>Camera</code> used to view the <code>Scene</code>.
     * </p>
     */
    private Camera fViewingCamera;

    /**
     * <p>
     * Creates an instance of <code>VisualSceneEditor</code>.
     * </p>
     */
    public VisualSceneEditor()
    {
        super();

        SceneManager.getSceneManager().addSceneChangedListener(this);
    }

    @Override
    public void createPartControl(final Composite parent)
    {
        // Setup 3D canvas.
        GLData data = new GLData();
        data.doubleBuffer = true;
        data.stencilSize = 1;
        fCanvas = new GLCanvas(parent, SWT.NONE, data);

        // Setup JOGL rendering environment.
        fCanvas.setCurrent();
        GLContext glContext = GLDrawableFactory.getFactory().createExternalGLContext();
        SimpleJOGLRenderingEngine pickerRenderingEngine = (SimpleJOGLRenderingEngine) ((SimpleJOGLPicker) fPickingEngine.getPicker())
                .getRenderingEngine();
        ((JOGLComponent) fRenderingEngine).setGL(glContext.getGL());
        fPickingEngine.setGL(glContext.getGL());
        pickerRenderingEngine.setGL(glContext.getGL());
        ((JOGLComponent) fViewingCamera).setGL(glContext.getGL());

        // Setup viewport size and Camera synchronisation with 3D canvas size.
        VisualSceneControlListener controlListener = new VisualSceneControlListener(fCanvas);
        controlListener.setCameraAspectRatioSyncronised(true);
        controlListener.addRenderingEngine(fRenderingEngine);
        controlListener.addRenderingEngine(pickerRenderingEngine);
        fCanvas.addControlListener(controlListener);

        // Setup mouse interaction.
        VisualSceneMouseListener mouseListener = new VisualSceneMouseListener(fPickingEngine, fViewingCamera);
        fCanvas.addMouseListener(mouseListener);
        fCanvas.addMouseMoveListener(mouseListener);
        fCanvas.addMouseWheelListener(mouseListener);
        fPickingEngine.addPickListener(new VisualScenePickListener(fRenderingEngine));

        // Continually display the Scene.
        Display display = fCanvas.getShell().getDisplay();
        VisualSceneAdvancer advancer = new VisualSceneAdvancer(display, fCanvas, glContext);
        advancer.addEngine(fPickingEngine);
        advancer.addEngine(fRenderingEngine);
        display.asyncExec(advancer);
    }

    @Override
    public void dispose()
    {
        SceneManager.getSceneManager().removeSceneChangedListener(this);

        super.dispose();
    }

    @Override
    public void doSave(final IProgressMonitor monitor)
    {}

    @Override
    public void doSaveAs()
    {}

    /**
     * <p>
     * Retrieves the 3D canvas the <code>Scene</code> will be displayed visually on.
     * </p>
     * 
     * @return The 3D canvas the <code>Scene</code> will be displayed visually on.
     */
    public GLCanvas getCanvas()
    {
        return (fCanvas);
    }

    /**
     * <p>
     * Retrieves the <code>PickingEngine</code> used to select items in the <code>Scene</code>.
     * </p>
     * 
     * @return The <code>PickingEngine</code> used to select items in the <code>Scene</code>.
     */
    public PickingEngine getPickingEngine()
    {
        return (fPickingEngine);
    }

    /**
     * <p>
     * Retrieves the <code>RenderingEngine</code> that will render the <code>Scene</code> to the 3D canvas.
     * </p>
     * 
     * @return The <code>RenderingEngine</code> that will render the <code>Scene</code> to the 3D canvas.
     */
    public RenderingEngine getRenderingEngine()
    {
        return (fRenderingEngine);
    }

    @Override
    public void init(final IEditorSite site, final IEditorInput input) throws PartInitException
    {
        setSite(site);
        setInput(input);
        setPartName(input.getName());

        IFileEditorInput fileInput = (IFileEditorInput) input;
        fSceneName = fileInput.getFile().getFullPath().toString();

        try
        {
            SceneManager.getSceneManager().addSceneDefinition(fileInput);
        }
        catch (Exception e)
        {
            LogFactory.getLog(getClass()).error("Failed to load scene from file '" + fSceneName + "'.", e);
            throw new PartInitException("Failed to load scene from file '" + fSceneName + "'.", e);
        }

        initViewingCamera();
        fRenderingEngine = SceneManager.getSceneManager().getRenderingEngineForScene(fSceneName);
        fRenderingEngine.setCamera(fViewingCamera);
        fPickingEngine = SceneManager.getSceneManager().getPickingEngineForScene(fSceneName);
        fPickingEngine.setCamera(fViewingCamera);

        // TODO temporary
        // SceneFactory.addXSceneAtOrigin(SceneManager.getSceneManager().getScene(fSceneName).getSceneGraph());

        SceneManager.getSceneManager().setActiveScene(fSceneName);
    }

    /**
     * <p>
     * Initialise the <code>Camera</code> used to view the <code>Scene</code>.
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

    @Override
    public boolean isDirty()
    {
        return (false);
    }

    @Override
    public boolean isSaveAsAllowed()
    {
        return (false);
    }

    @Override
    public void sceneChanged(final SceneChangedEvent event)
    {
        Renderer outlineRenderer = fRenderingEngine.getRenderers().get(1);

        if (event.getType() == SceneChangedEventType.CAMERA_ACTIVATED)
        {
            // fRenderingEngine.setRendererRoot(outlineRenderer, (Node) event.getSceneComponent());
        }
        else if (event.getType() == SceneChangedEventType.LIGHT_ACTIVATED)
        {
            // fRenderingEngine.setRendererRoot(outlineRenderer, (Node) event.getSceneComponent());
        }
        else if (event.getType() == SceneChangedEventType.NODE_ACTIVATED)
        {
            fRenderingEngine.setRendererRoot(outlineRenderer, (Node) event.getSceneComponent());
        }
    }

    @Override
    public void setFocus()
    {
        SceneManager.getSceneManager().setActiveScene(fSceneName);
    }
}
