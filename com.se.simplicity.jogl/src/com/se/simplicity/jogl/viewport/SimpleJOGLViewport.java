package com.se.simplicity.jogl.viewport;

import javax.media.opengl.GL;

import com.se.simplicity.jogl.JOGLComponent;
import com.se.simplicity.picking.engine.PickingEngine;
import com.se.simplicity.rendering.engine.RenderingEngine;
import com.se.simplicity.viewport.Viewport;

/**
 * <p>
 * A viewport on which a {@link com.se.simplicity.scenegraph.SceneGraph SceneGraph} rendered by a JOGL rendering environment can be displayed.
 * </p>
 * 
 * @author simple
 */
public class SimpleJOGLViewport implements Viewport, JOGLComponent
{
    private GL gl;
    
    private int height;

    private PickingEngine pickingEngine;

    private RenderingEngine renderingEngine;

    private int width;
    
    public SimpleJOGLViewport()
    {
        gl = null;
        height = -1;
        width = -1;
    }
    
    @Override
    public void displaySceneGraph()
    {        
        if (pickingEngine != null)
        {
            pickingEngine.advance();
        }
        
        try
        {
            renderingEngine.advance();
        }
        catch (NullPointerException e)
        {
            throw new IllegalStateException("This Viewport must have a Rendering Engine before it can displlay the Scene Graph", e);
        }
    }

    @Override
    public GL getGL()
    {
        return (gl);
    }

    @Override
    public int getHeight()
    {
        return (height);
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
        return (width);
    }

    @Override
    public void setGL(GL gl)
    {
        this.gl = gl;
        
        if (pickingEngine != null)
        {
            ((JOGLComponent) pickingEngine).setGL(gl);
        }
        
        if (renderingEngine != null)
        {
            ((JOGLComponent) renderingEngine).setGL(gl);
        }
    }

    @Override
    public void setPickingEngine(PickingEngine pickingEngine)
    {
        ((JOGLComponent) pickingEngine).setGL(gl);
        
        this.pickingEngine = pickingEngine;
    }

    @Override
    public void setRenderingEngine(RenderingEngine renderingEngine)
    {
        ((JOGLComponent) renderingEngine).setGL(gl);
        
        this.renderingEngine = renderingEngine;
    }

    @Override
    public void setSize(int width, int height)
    {
        this.width = width;
        this.height = height;
        
        gl.glViewport(0, 0, width, height);
    }
}
