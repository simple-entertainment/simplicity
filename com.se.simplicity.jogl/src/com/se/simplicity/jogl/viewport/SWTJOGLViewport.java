package com.se.simplicity.jogl.viewport;

import javax.media.opengl.GLContext;
import javax.media.opengl.GLDrawableFactory;

import org.eclipse.swt.SWT;
import org.eclipse.swt.graphics.Rectangle;
import org.eclipse.swt.opengl.GLCanvas;
import org.eclipse.swt.opengl.GLData;
import org.eclipse.swt.widgets.Composite;
import org.eclipse.swt.widgets.Display;
import org.eclipse.swt.widgets.Event;
import org.eclipse.swt.widgets.Listener;

import com.se.simplicity.jogl.JOGLComponent;
import com.se.simplicity.picking.engine.PickingEngine;
import com.se.simplicity.rendering.engine.RenderingEngine;
import com.se.simplicity.viewport.Viewport;

/**
 * <p>
 * A viewport on which a {@link com.se.simplicity.scenegraph.SceneGraph SceneGraph} rendered by a JOGL rendering environment can
 * be displayed.
 * </p>
 * 
 * @author simple
 */
public class SWTJOGLViewport extends GLCanvas implements Viewport
{
	/**
	 * <p>
	 * The version of this class.
	 * <p>
	 */
	private static final long serialVersionUID = 1L;
	
	private GLContext glContext;

	/**
	 * <p>
	 * The <code>PickingEngine</code> with which the <code>SceneGraph</code> is picked.
	 * </p>
	 */
	private PickingEngine pickingEngine;

	/**
	 * <p>
	 * The <code>RenderingEngine</code> that renders to this <code>SimpleJOGLCanvasViewport</code>.
	 * </p>
	 */
	private RenderingEngine renderingEngine;

	/**
	 * <p>
	 * Creates an instance of <code>SimpleJOGLCanvasViewport</code>.
	 * </p>
	 */	
	public SWTJOGLViewport(Composite parent, int style, GLData data)
	{
		super(parent, style, data);
		
		setCurrent();
		glContext = GLDrawableFactory.getFactory().createExternalGLContext();
		pickingEngine = null;
		renderingEngine = null;
		
		addListener(SWT.Resize, new Listener()
        {
            public void handleEvent(Event event)
            {
                Rectangle bounds = getBounds();
                setCurrent();
                glContext.makeCurrent();

                glContext.getGL().glViewport(0, 0, bounds.width, bounds.height);

                glContext.release();
            }
        });
	}
	
	public static SWTJOGLViewport getDoubleBufferedViewport(Composite parent)
	{
	    GLData data = new GLData();
	    data.doubleBuffer = true;
        return (new SWTJOGLViewport(parent, SWT.NONE, data));
	}
	
	/**
	 * TODO javadoc
	 */
	public void enableMousePicking(final int width, final int height)
	{
//		addMouseListener(new MouseAdapter()
//			{
//				public void mouseClicked(final MouseEvent event)
//				{
//					if (event.getButton() == MouseEvent.BUTTON1)
//					{
//						pickingEngine.pick(event.getX(), event.getY(), width, height);
//					}
//				}
//			});
	}

	@Override
	public void displaySceneGraph()
	{
	    final Display display = getShell().getDisplay();
	    
	    display.asyncExec(new Runnable()
        {            
            public void run()
            {
                if (!isDisposed())
                {
                    setCurrent();
                    glContext.makeCurrent();
                    
                    if (pickingEngine != null)
                    {
                        pickingEngine.advance();
                    }
                    
                    renderingEngine.advance();
                    
                    swapBuffers();
                    glContext.release();
                    display.asyncExec(this);
                }
            }
        });
	}

	@Override
	public int getHeight() {
		
		return (getSize().y);
	}

	@Override
	public PickingEngine getPickingEngine()
	{
		return (pickingEngine);
	}

	@Override
	public RenderingEngine getRenderingEngine()
	{
		return (renderingEngine);
	}

	@Override
	public int getWidth()
	{
		return (getSize().x);
	}
	
	@Override
	public void setHeight(final int height)
	{
		setSize(getWidth(), height);
	}

	@Override
	public void setPickingEngine(final PickingEngine pickingEngine)
	{
	    ((JOGLComponent) pickingEngine).setGL(glContext.getGL());
	    
		this.pickingEngine = pickingEngine;
	}

	@Override
	public void setRenderingEngine(final RenderingEngine renderingEngine)
	{
	    ((JOGLComponent) renderingEngine).setGL(glContext.getGL());
	    
		this.renderingEngine = renderingEngine;
	}

	@Override
	public void setWidth(final int width)
	{
		setSize(width, getHeight());
	}
}
