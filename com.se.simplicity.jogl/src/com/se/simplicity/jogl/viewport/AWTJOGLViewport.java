package com.se.simplicity.jogl.viewport;

import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;

import javax.media.opengl.GLCanvas;

import com.se.simplicity.jogl.engine.JOGLEngine;
import com.se.simplicity.picking.engine.PickingEngine;
import com.se.simplicity.rendering.engine.RenderingEngine;
import com.se.simplicity.viewport.Viewport;

/**
 * <p>
 * A viewport on which a {@link com.se.simplicity.scenegraph.SceneGraph
 * SceneGraph} rendered by a JOGL rendering environment can be displayed.
 * </p>
 * 
 * @author simple
 */
public class AWTJOGLViewport extends GLCanvas implements Viewport
{
    /**
     * <p>
     * The version of this class.
     * <p>
     */
    private static final long serialVersionUID = 1L;

    /**
     * <p>
     * The <code>PickingEngine</code> with which the <code>SceneGraph</code> is
     * picked.
     * </p>
     */
    private PickingEngine pickingEngine;

    /**
     * <p>
     * The <code>RenderingEngine</code> that renders to this
     * <code>SimpleJOGLCanvasViewport</code>.
     * </p>
     */
    private RenderingEngine renderingEngine;

    /**
     * <p>
     * Creates an instance of <code>SimpleJOGLCanvasViewport</code>.
     * </p>
     */
    public AWTJOGLViewport()
    {
        super();

        this.pickingEngine = null;
        this.renderingEngine = null;
    }

    /**
     * TODO javadoc
     */
    public void enableMousePicking(final int width, final int height)
    {
        addMouseListener(new MouseAdapter()
        {
            public void mouseClicked(final MouseEvent event)
            {
                if (event.getButton() == MouseEvent.BUTTON1)
                {
                    pickingEngine.pick(event.getX(), event.getY(), width, height);
                }
            }
        });
    }

    @Override
    public void displaySceneGraph()
    {
        
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
    public void setHeight(final int height)
    {
        setSize(getWidth(), height);
    }

    @Override
    public void setPickingEngine(final PickingEngine pickingEngine)
    {
        if (this.pickingEngine != null)
        {
            removeGLEventListener((JOGLEngine) this.pickingEngine);
        }

        this.pickingEngine = pickingEngine;

        addGLEventListener((JOGLEngine) pickingEngine);
    }

    @Override
    public void setRenderingEngine(final RenderingEngine renderingEngine)
    {
        if (this.renderingEngine != null)
        {
            removeGLEventListener((JOGLEngine) this.renderingEngine);
        }

        this.renderingEngine = renderingEngine;

        addGLEventListener((JOGLEngine) renderingEngine);
    }

    @Override
    public void setWidth(final int width)
    {
        setSize(width, getHeight());
    }

    @Override
    public int getHeight()
    {

        // TODO Auto-generated method stub
        return 0;
    }

    @Override
    public int getWidth()
    {
        // TODO Auto-generated method stub
        return 0;
    }
}
