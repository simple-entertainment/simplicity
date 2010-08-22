/*
    This file is part of The Simplicity Engine.

    The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
    by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

    The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
package com.se.simplicity.editor.view.scene.visual;

import javax.media.opengl.GLContext;
import javax.media.opengl.GLDrawableFactory;

import org.eclipse.swt.SWT;
import org.eclipse.swt.opengl.GLCanvas;
import org.eclipse.swt.opengl.GLData;
import org.eclipse.swt.widgets.Composite;
import org.eclipse.swt.widgets.Shell;

/**
 * <p>
 * A viewport on which a {@link com.se.simplicity.scenegraph.SceneGraph SceneGraph} rendered by a JOGL rendering environment can
 * be displayed.
 * </p>
 * 
 * @author Gary Buyn
 */
public class VisualSceneView extends GLCanvas
{
    public static VisualSceneView getDoubleBufferedSceneView()
    {
        GLData data = new GLData();
        data.doubleBuffer = true;
        return (new VisualSceneView(new Shell(), SWT.NONE, data));
    }
    
	private GLContext glContext;
	
	/**
	 * <p>
	 * Creates an instance of <code>SimpleJOGLCanvasViewport</code>.
	 * </p>
	 */	
	public VisualSceneView(Composite parent, int style, GLData data)
	{
		super(parent, style, data);
		
		setCurrent();
		glContext = GLDrawableFactory.getFactory().createExternalGLContext();
	}
	
	public GLContext getGLContext()
	{
	    return (glContext);
	}
}
