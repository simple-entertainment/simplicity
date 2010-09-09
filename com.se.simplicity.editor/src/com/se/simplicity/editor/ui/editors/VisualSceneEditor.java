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

import org.apache.log4j.Logger;
import org.eclipse.core.runtime.IProgressMonitor;
import org.eclipse.swt.SWT;
import org.eclipse.swt.opengl.GLCanvas;
import org.eclipse.swt.opengl.GLData;
import org.eclipse.swt.widgets.Composite;
import org.eclipse.ui.IEditorInput;
import org.eclipse.ui.IEditorSite;
import org.eclipse.ui.IFileEditorInput;
import org.eclipse.ui.PartInitException;
import org.eclipse.ui.part.EditorPart;

import com.se.simplicity.editor.internal.ContentProvider;
import com.se.simplicity.editor.internal.SceneManager;
import com.se.simplicity.editor.internal.event.SceneChangedEvent;
import com.se.simplicity.editor.internal.event.SceneChangedEventType;
import com.se.simplicity.editor.internal.event.SceneChangedListener;
import com.se.simplicity.scene.Scene;
import com.se.simplicity.util.scene.SceneFactory;

/**
 * <p>
 * An eclipse editor that displays a <code>Scene</code> visually on a 3D canvas using the JOGL rendering environment.
 * </p>
 * 
 * @author Gary Buyn
 */
public class VisualSceneEditor extends EditorPart implements SceneEditor, SceneChangedListener
{
    /**
     * <p>
     * The {@link com.se.simplicity.rendering.editor.internal.ContentProvider ContentProvider} providing content for this
     * <code>VisualSceneEditor</code>.
     * </p>
     */
    private ContentProvider fContentProvider;

    /**
     * <p>
     * Creates an instance of <code>VisualSceneEditor</code>.
     * </p>
     * 
     * @param contentProvider The {@link com.se.simplicity.rendering.editor.internal.ContentProvider ContentProvider} providing content for this
     * <code>VisualSceneEditor</code>.
     */
    public VisualSceneEditor(final ContentProvider contentProvider)
    {
        super();

        fContentProvider = contentProvider;

        SceneManager.getSceneManager().addSceneChangedListener(this);
    }

    @Override
    public void createPartControl(final Composite parent)
    {
        // Setup 3D canvas.
        GLData data = new GLData();
        data.doubleBuffer = true;
        data.stencilSize = 1;
        GLCanvas canvas = new GLCanvas(parent, SWT.NONE, data);

        // Setup JOGL rendering environment.
        canvas.setCurrent();
        GLContext glContext = GLDrawableFactory.getFactory().createExternalGLContext();
        fContentProvider.setGL(glContext.getGL());

        // Setup viewport size and Camera synchronisation with 3D canvas size.
        ResizeControlListener resizeListener = new ResizeControlListener(fContentProvider);
        canvas.addControlListener(resizeListener);

        // Setup mouse interaction.
        NavigationMouseListener navigationMouseListener = new NavigationMouseListener(fContentProvider);
        canvas.addMouseListener(navigationMouseListener);
        canvas.addMouseMoveListener(navigationMouseListener);
        canvas.addMouseWheelListener(navigationMouseListener);

        SceneMouseListener sceneMouseListener = new SceneMouseListener(fContentProvider.getScenePickingEngine());
        canvas.addMouseListener(sceneMouseListener);

        WidgetMouseListener widgetMouseListener = new WidgetMouseListener(fContentProvider);
        canvas.addMouseListener(widgetMouseListener);
        canvas.addMouseMoveListener(widgetMouseListener);

        fContentProvider.displayContent(canvas, glContext);
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

    @Override
    public ContentProvider getContentProvider()
    {
        return (fContentProvider);
    }

    @Override
    public void init(final IEditorSite site, final IEditorInput input) throws PartInitException
    {
        setSite(site);
        setInput(input);
        setPartName(input.getName());

        IFileEditorInput fileInput = (IFileEditorInput) input;
        String sceneName = fileInput.getFile().getFullPath().toString();

        Scene scene;
        try
        {
            scene = SceneFactory.loadFromSource(fileInput.getFile().getContents());
        }
        catch (Exception e)
        {
            Logger.getLogger(getClass()).error("Failed to load Scene from file '" + sceneName + "'.", e);
            throw new PartInitException("Failed to load Scene from file '" + sceneName + "'.", e);
        }

        SceneManager.getSceneManager().addScene(scene, sceneName);
        SceneManager.getSceneManager().setActiveScene(scene);

        fContentProvider.setScene(scene);
        fContentProvider.init();
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
        if (event.getType() == SceneChangedEventType.CAMERA_ACTIVATED || event.getType() == SceneChangedEventType.LIGHT_ACTIVATED
                || event.getType() == SceneChangedEventType.NODE_ACTIVATED)
        {
            fContentProvider.setSelectedSceneComponent(event.getSceneComponent());
        }
    }

    @Override
    public void setFocus()
    {
        SceneManager.getSceneManager().setActiveScene(fContentProvider.getScene());
    }
}
