/*
    This file is part of The Simplicity Engine.

    The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
    by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

    The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
package com.se.simplicity.editor.ui.editors;

import java.awt.Dimension;

import javax.media.opengl.GLContext;
import javax.media.opengl.GLDrawableFactory;

import org.apache.commons.logging.LogFactory;
import org.apache.log4j.Logger;
import org.eclipse.core.runtime.IProgressMonitor;
import org.eclipse.core.runtime.ListenerList;
import org.eclipse.jface.viewers.ISelection;
import org.eclipse.jface.viewers.ISelectionChangedListener;
import org.eclipse.jface.viewers.SelectionChangedEvent;
import org.eclipse.swt.SWT;
import org.eclipse.swt.graphics.Rectangle;
import org.eclipse.swt.opengl.GLCanvas;
import org.eclipse.swt.opengl.GLData;
import org.eclipse.swt.widgets.Canvas;
import org.eclipse.swt.widgets.Composite;
import org.eclipse.ui.IEditorInput;
import org.eclipse.ui.IEditorSite;
import org.eclipse.ui.IFileEditorInput;
import org.eclipse.ui.ISelectionListener;
import org.eclipse.ui.IWorkbenchPart;
import org.eclipse.ui.PartInitException;
import org.eclipse.ui.part.EditorPart;
import org.eclipse.ui.views.contentoutline.IContentOutlinePage;

import com.se.simplicity.editor.internal.EditingMode;
import com.se.simplicity.editor.internal.PickSelection;
import com.se.simplicity.editor.internal.SceneManager2;
import com.se.simplicity.editor.internal.ScenePickListener;
import com.se.simplicity.editor.internal.SceneSelection;
import com.se.simplicity.editor.internal.WidgetManager;
import com.se.simplicity.editor.internal.WidgetPickListener;
import com.se.simplicity.editor.internal.engine.DisplayAsyncJOGLCompositeEngine;
import com.se.simplicity.editor.ui.editors.outline.SceneOutlinePage;
import com.se.simplicity.jogl.JOGLComponent;
import com.se.simplicity.jogl.rendering.SimpleJOGLCamera;
import com.se.simplicity.jogl.rendering.engine.SimpleJOGLRenderingEngine;
import com.se.simplicity.model.Model;
import com.se.simplicity.rendering.Camera;
import com.se.simplicity.rendering.DrawingMode;
import com.se.simplicity.rendering.ProjectionMode;
import com.se.simplicity.rendering.engine.RenderingEngine;
import com.se.simplicity.scene.Scene;
import com.se.simplicity.scenegraph.SimpleNode;
import com.se.simplicity.util.metadata.scene.MetaDataScene;
import com.se.simplicity.util.scene.SceneFactory;
import com.se.simplicity.vector.SimpleTranslationVectorf4;

/**
 * <p>
 * An eclipse editor that displays a <code>Scene</code> visually on a 3D canvas using the JOGL rendering environment.
 * </p>
 * 
 * @author Gary Buyn
 */
public class VisualSceneEditor extends EditorPart implements SceneEditor, ISelectionListener
{
    /**
     * <p>
     * The {@link com.se.simplicity.rendering.Camera Camera} the {@link com.se.simplicity.scene.Scene Scene} will be viewed through.
     * </p>
     */
    private Camera fCamera;

    /**
     * <p>
     * The {@link com.se.simplicity.editor.internal.EditingMode EditingMode} used to manipulate the {@link com.se.simplicity.scene.Scene Scene}.
     * </p>
     */
    private EditingMode fEditingMode;

    /**
     * <p>
     * The {@link com.se.simplicity.rendering.engine.RenderingEngine RenderingEngine} that will render the {@link com.se.simplicity.rendering.Camera
     * Camera} and {@link com.se.simplicity.editor.internal.Widget Widget}s to the 3D canvas.
     * </p>
     */
    private RenderingEngine fRenderingEngine;

    /**
     * <p>
     * The {@link com.se.simplicity.scene.Scene Scene} displayed by this <code>VisualSceneEditor</code>.
     * </p>
     */
    private Scene fScene;

    /**
     * <p>
     * The manager for the {@link com.se.simplicity.scene.Scene Scene}.
     * </p>
     */
    private SceneManager2 fSceneManager;

    /**
     * <p>
     * The selected scene component and primitive.
     * </p>
     */
    private SceneSelection fSelection;

    /**
     * <p>
     * Determines whether the aspect ratio of the {@link com.se.simplicity.rendering.Camera Camera} is synchronised with the aspect ratio of the
     * viewport.
     * </p>
     */
    private boolean fSyncCameraAspectRatio;

    /**
     * <p>
     * The manager for the {@link com.se.simplicity.editor.internal.Widget Widget}s used to manipulate the {@link com.se.simplicity.scene.Scene Scene}
     * .
     * </p>
     */
    private WidgetManager fWidgetManager;

    /**
     * <p>
     * Listeners to a change in selection.
     * </p>
     */
    private ListenerList fSelectionChangedListeners;

    /**
     * <p>
     * Creates an instance of <code>VisualSceneEditor</code>.
     * </p>
     */
    public VisualSceneEditor()
    {
        super();

        fCamera = null;
        fEditingMode = EditingMode.SELECTION;
        fRenderingEngine = null;
        fSelection = new SceneSelection(null, null);
        fSelectionChangedListeners = new ListenerList();
        fScene = null;
        fSceneManager = new SceneManager2();
        fSyncCameraAspectRatio = true;
        fWidgetManager = new WidgetManager();
    }

    @Override
    public void addSelectionChangedListener(final ISelectionChangedListener listener)
    {
        fSelectionChangedListeners.add(listener);
    }

    @Override
    public void createPartControl(final Composite parent)
    {
        Canvas canvas = null;
        GLContext glContext = null;
        if (fRenderingEngine instanceof JOGLComponent)
        {
            // Setup 3D canvas.
            GLData data = new GLData();
            data.doubleBuffer = true;
            data.stencilSize = 1;
            canvas = new GLCanvas(parent, SWT.NONE, data);

            // Setup JOGL rendering environment.
            ((GLCanvas) canvas).setCurrent();
            glContext = GLDrawableFactory.getFactory().createExternalGLContext();
            ((JOGLComponent) fCamera).setGL(glContext.getGL());
            ((JOGLComponent) fRenderingEngine).setGL(glContext.getGL());
            fSceneManager.setGL(glContext.getGL());
            fWidgetManager.setGL(glContext.getGL());
        }

        // Setup viewport size and Camera synchronisation with 3D canvas size.
        canvas.addControlListener(new ResizeControlListener(this));

        // Setup mouse interaction.
        NavigationMouseListener navigationMouseListener = new NavigationMouseListener(fCamera);
        canvas.addMouseListener(navigationMouseListener);
        canvas.addMouseMoveListener(navigationMouseListener);
        canvas.addMouseWheelListener(navigationMouseListener);

        canvas.addMouseListener(new SelectionMouseListener(this));

        WidgetMouseListener widgetMouseListener = new WidgetMouseListener(fWidgetManager);
        canvas.addMouseListener(widgetMouseListener);
        canvas.addMouseMoveListener(widgetMouseListener);

        if (fRenderingEngine instanceof JOGLComponent)
        {
            display((GLCanvas) canvas, glContext);
        }

        getSite().setSelectionProvider(this);
        getSite().getPage().addSelectionListener(this);
    }

    /**
     * <p>
     * Displays the content for the lifetime of the given <code>GLCanvas</code>.
     * </p>
     * 
     * @param canvas The <code>GLCanvas</code> to display the contents on.
     * @param glContext The <code>GLContext</code> to use when displaying.
     */
    public void display(final GLCanvas canvas, final GLContext glContext)
    {
        DisplayAsyncJOGLCompositeEngine compositeEngine = new DisplayAsyncJOGLCompositeEngine(canvas, glContext);

        // Widget picking should occur first because it takes precedence.
        compositeEngine.addEngine(fWidgetManager.getPickingEngine());

        compositeEngine.addEngine(fSceneManager.getPickingEngine());
        compositeEngine.addEngine(fRenderingEngine);

        compositeEngine.run();
    }

    @Override
    public void doSave(final IProgressMonitor monitor)
    {}

    @Override
    public void doSaveAs()
    {}

    @SuppressWarnings("unchecked")
    @Override
    public Object getAdapter(final Class adapter)
    {
        Object adapterInstance = null;

        if (adapter == IContentOutlinePage.class)
        {
            adapterInstance = new SceneOutlinePage(fScene);
        }
        else
        {
            adapterInstance = super.getAdapter(adapter);
        }

        return (adapterInstance);
    }

    @Override
    public EditingMode getEditingMode()
    {
        return (fEditingMode);
    }

    /**
     * <p>
     * Retrieves the {@link com.se.simplicity.scene.Scene Scene} displayed by this <code>VisualSceneEditor</code>.
     * </p>
     * 
     * @return The {@link com.se.simplicity.scene.Scene Scene} displayed by this <code>VisualSceneEditor</code>.
     */
    public Scene getScene()
    {
        return (fScene);
    }

    @Override
    public SceneManager2 getSceneManager()
    {
        return (fSceneManager);
    }

    @Override
    public ISelection getSelection()
    {
        return (fSelection);
    }

    @Override
    public WidgetManager getWidgetManager()
    {
        return (fWidgetManager);
    }

    @Override
    public void init(final IEditorSite site, final IEditorInput input) throws PartInitException
    {
        setSite(site);
        setInput(input);
        setPartName(input.getName());

        IFileEditorInput fileInput = (IFileEditorInput) input;
        String sceneName = fileInput.getFile().getFullPath().toString();

        try
        {
            fScene = SceneFactory.loadFromSource(fileInput.getFile().getContents());
        }
        catch (Exception e)
        {
            Logger.getLogger(getClass()).error("Failed to load Scene from file '" + sceneName + "'.", e);
            throw new PartInitException("Failed to load Scene from file '" + sceneName + "'.", e);
        }

        initCamera();
        initRenderingEngine();

        // Set the Camera as the viewpoint for picking and rendering but do NOT add to the Scene. This stops the Camera from appearing in the
        // various views displaying an analysis of the Scene or being synchronised into the source file.
        fRenderingEngine.setCamera(fCamera);

        fSceneManager.setScene(fScene);
        fSceneManager.setRenderingEngine(fRenderingEngine);
        fSceneManager.init();
        fSceneManager.setCamera(fCamera);

        fWidgetManager.setScene(fScene);
        fWidgetManager.setRenderingEngine(fRenderingEngine);
        fWidgetManager.init();
        fWidgetManager.setCamera(fCamera);

        fSceneManager.getPickingEngine().addPickListener(new ScenePickListener(this));
        fWidgetManager.getPickingEngine().addPickListener(new WidgetPickListener(this));

        setEditingMode(EditingMode.SELECTION);
    }

    /**
     * <p>
     * Initialises the {@link com.se.simplicity.rendering.Camera Camera} used to view the {@link com.se.simplicity.scene.Scene Scene}.
     * </p>
     */
    protected void initCamera()
    {
        fCamera = new SimpleJOGLCamera();
        SimpleNode subjectNode = new SimpleNode();
        SimpleNode cameraNode = new SimpleNode();
        subjectNode.addChild(cameraNode);
        cameraNode.getTransformation().translate(new SimpleTranslationVectorf4(0.0f, 0.0f, 5.0f, 1.0f));
        fCamera.setNode(cameraNode);
    }

    /**
     * <p>
     * Initialises the {@link com.se.simplicity.rendering.engine.RenderingEngine RenderingEngine} that will render the
     * {@link com.se.simplicity.rendering.Camera Camera} and {@link com.se.simplicity.editor.internal.Widget Widget}s to the 3D canvas.
     * </p>
     */
    protected void initRenderingEngine()
    {
        // Retrieve preferred rendering environment if one is available.
        String preferredRenderingEngine = null;
        if (fScene instanceof MetaDataScene)
        {
            MetaDataScene metaDataScene = (MetaDataScene) fScene;
            preferredRenderingEngine = (String) metaDataScene.getAttribute("preferredRenderingEngine");
        }

        // Initialise Rendering Engine.
        if (preferredRenderingEngine == null)
        {
            fRenderingEngine = new SimpleJOGLRenderingEngine();
        }
        else
        {
            try
            {
                fRenderingEngine = (RenderingEngine) Class.forName(preferredRenderingEngine).newInstance();
            }
            catch (Exception e)
            {
                LogFactory.getLog(getClass()).warn("Failed to instantiate preferred Rendering Engine, instantiating default.", e);
                fRenderingEngine = new SimpleJOGLRenderingEngine();
            }
        }
        fRenderingEngine.setScene(fScene);
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
    public void pickForSelection(final Dimension viewportSize, final int x, final int y, final int width, final int height)
    {
        // Widget picking should occur first because it takes precedence.
        fWidgetManager.getPickingEngine().pickViewport(viewportSize, x, y, width, height);

        fSceneManager.getPickingEngine().pickViewport(viewportSize, x, y, width, height);
    }

    @Override
    public void removeSelectionChangedListener(final ISelectionChangedListener listener)
    {
        fSelectionChangedListeners.remove(listener);
    }

    @Override
    public void selectionChanged(final IWorkbenchPart part, final ISelection selection)
    {
        if (selection instanceof SceneSelection)
        {
            fSelection = (SceneSelection) selection;
            setSelection(fSelection.getSceneComponent(), fSelection.getPrimitive());
        }
    }

    @Override
    public void setCanvasSize(final Rectangle canvasSize)
    {
        Dimension viewportSize = new Dimension();
        viewportSize.setSize(canvasSize.width, canvasSize.height);

        fRenderingEngine.setViewportSize(viewportSize);
        fSceneManager.setViewportSize(viewportSize);
        fWidgetManager.setViewportSize(viewportSize);

        if (fSyncCameraAspectRatio)
        {
            fCamera.setFrameAspectRatio((float) canvasSize.height / (float) canvasSize.width);
        }
    }

    @Override
    public void setDrawingMode(final DrawingMode drawingMode)
    {
        fSceneManager.setDrawingMode(drawingMode);
    }

    @Override
    public void setEditingMode(final EditingMode editingMode)
    {
        fEditingMode = editingMode;

        fWidgetManager.setEditingMode(editingMode);
    }

    @Override
    public void setFocus()
    {}

    @Override
    public void setProjectionMode(final ProjectionMode projectionMode)
    {
        fCamera.setProjectionMode(projectionMode);
    }

    @Override
    public void setSelection(final ISelection selection)
    {
        ISelection tempSelection = selection;

        // If the selection originated from a pick.
        if (tempSelection instanceof PickSelection)
        {
            PickSelection pickSelection = (PickSelection) tempSelection;

            // If the selection originated from a Widget pick and the selection is empty, do not process any further. Instead wait for the selection
            // originating from a Scene pick.
            if (pickSelection.getSource() == PickSelection.WIDGET_PICK && pickSelection.isEmpty())
            {
                return;
            }

            // Create a SceneSelection from the PickSelection so that the selection is processed.
            tempSelection = new SceneSelection(((PickSelection) tempSelection).getSceneComponent(), null);
        }

        if (tempSelection instanceof SceneSelection)
        {
            // Set the selection internally.
            fSelection = (SceneSelection) tempSelection;
            setSelection(fSelection.getSceneComponent(), fSelection.getPrimitive());

            // Notify listeners.
            SelectionChangedEvent event = new SelectionChangedEvent(this, fSelection);
            for (Object listener : fSelectionChangedListeners.getListeners())
            {
                ((ISelectionChangedListener) listener).selectionChanged(event);
            }
        }
    }

    /**
     * <p>
     * Sets the selected scene component and primitive in the managers.
     * </p>
     * 
     * @param sceneComponent The selected scene component.
     * @param primitive The selected primitive.
     */
    protected void setSelection(final Object sceneComponent, final Model primitive)
    {
        fSceneManager.setSelectedSceneComponent(sceneComponent);
        fWidgetManager.setSelectedSceneComponent(sceneComponent);
    }

    /**
     * <p>
     * Sets whether the aspect ratio of the {@link com.se.simplicity.rendering.Camera Camera} is synchronised with the aspect ratio of the viewport.
     * </p>
     * 
     * @param syncCameraAspectRatio Determines whether the aspect ratio of the <code>Camera</code> is synchronised with the aspect ratio of the
     * viewport.
     */
    public void setSyncCameraAspectRatio(final boolean syncCameraAspectRatio)
    {
        fSyncCameraAspectRatio = syncCameraAspectRatio;
    }

    /**
     * <p>
     * Determines whether the aspect ratio of the {@link com.se.simplicity.rendering.Camera Camera} is synchronised with the aspect ratio of the
     * viewport.
     * </p>
     * 
     * @return True if the aspect ratio of the <code>Camera</code> is synchronised with the aspect ratio of the viewport, false otherwise.
     */
    public boolean syncCameraAspectRatio()
    {
        return (fSyncCameraAspectRatio);
    }
}
