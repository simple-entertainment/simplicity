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

import com.se.simplicity.editor.internal.SceneManager;
import com.se.simplicity.jogl.JOGLComponent;
import com.se.simplicity.jogl.viewport.SimpleJOGLViewport;

/**
 * <p>
 * An eclipse editor that displays a <code>Scene</code> visually on a 3D canvas using the JOGL rendering environment.
 * </p>
 * 
 * @author Gary Buyn
 */
public class VisualSceneEditor extends EditorPart
{
    /**
     * <p>
     * The 3D canvas the <code>Scene</code> will be displayed visually on.
     * </p>
     */
    private GLCanvas canvas;

    /**
     * <p>
     * The name of the scene this editor is displaying.
     * </p>
     */
    private String sceneName;

    /**
     * <p>
     * The <code>Viewport</code> to the <code>Scene</code> that will be drawn to the 3D canvas.
     * </p>
     */
    private SimpleJOGLViewport viewport;

    @Override
    public void createPartControl(final Composite parent)
    {
        GLData data = new GLData();
        data.doubleBuffer = true;
        canvas = new GLCanvas(parent, SWT.NONE, data);

        canvas.setCurrent();
        GLContext glContext = GLDrawableFactory.getFactory().createExternalGLContext();
        ((JOGLComponent) viewport).setGL(glContext.getGL());

        canvas.addControlListener(new VisualSceneControlListener(viewport, canvas));
        canvas.addMouseListener(new VisualSceneMouseListener(viewport, canvas));

        Display display = canvas.getShell().getDisplay();
        display.asyncExec(new VisualSceneDisplayer(display, viewport, canvas, glContext));
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
        return (canvas);
    }

    /**
     * <p>
     * Retrieves the <code>Viewport</code> to the <code>Scene</code> that will be drawn to the 3D canvas.
     * </p>
     * 
     * @return The <code>Viewport</code> to the <code>Scene</code> that will be drawn to the 3D canvas.
     */
    public SimpleJOGLViewport getViewport()
    {
        return (viewport);
    }

    @Override
    public void init(final IEditorSite site, final IEditorInput input) throws PartInitException
    {
        setSite(site);
        setInput(input);
        setPartName(input.getName());

        IFileEditorInput fileInput = (IFileEditorInput) input;
        sceneName = fileInput.getFile().getFullPath().toString();

        try
        {
            SceneManager.getSceneManager().addSceneDefinition(fileInput);
        }
        catch (Exception e)
        {
            LogFactory.getLog(getClass()).error("Failed to load scene from file '" + sceneName + "'.", e);
            throw new PartInitException("Failed to load scene from file '" + sceneName + "'.", e);
        }

        viewport = (SimpleJOGLViewport) SceneManager.getSceneManager().getViewportToScene(sceneName);

        SceneManager.getSceneManager().setActiveScene(sceneName);
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
    public void setFocus()
    {
        SceneManager.getSceneManager().setActiveScene(sceneName);
    }
}
