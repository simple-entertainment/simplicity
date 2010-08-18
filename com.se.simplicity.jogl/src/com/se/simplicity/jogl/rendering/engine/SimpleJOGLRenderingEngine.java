package com.se.simplicity.jogl.rendering.engine;

import java.util.ArrayList;
import java.util.List;

import javax.media.opengl.GL;

import org.apache.log4j.Logger;

import com.se.simplicity.jogl.JOGLComponent;
import com.se.simplicity.jogl.engine.JOGLEngine;
import com.se.simplicity.jogl.rendering.NamedJOGLRenderer;
import com.se.simplicity.rendering.Camera;
import com.se.simplicity.rendering.DrawingMode;
import com.se.simplicity.rendering.Light;
import com.se.simplicity.rendering.Renderer;
import com.se.simplicity.rendering.engine.RenderingEngine;
import com.se.simplicity.scenegraph.Node;
import com.se.simplicity.scenegraph.SceneGraph;
import com.se.simplicity.scenegraph.SimpleTraversal;
import com.se.simplicity.scenegraph.model.ModelNode;
import com.se.simplicity.vector.SimpleMatrixf44;
import com.se.simplicity.vector.SimpleVectorf4;

/**
 * <p>
 * Manages the rendering of a {@link com.se.simplicity.scenegraph.SceneGraph SceneGraph} in a JOGL environment. This implementation uses only simple
 * rendering techniques and properties.
 * </p>
 * 
 * @author simple
 */
public class SimpleJOGLRenderingEngine extends JOGLEngine implements RenderingEngine
{
    /**
     * <p>
     * The {@link com.se.simplicity.rendering.Camera Camera} through which the {@link com.se.simplicity.scenegraph.SceneGraph SceneGraph} will be
     * rendered.
     * </p>
     */
    private Camera camera;

    /**
     * <p>
     * The colour to clear the screen buffer with before rendering.
     * </p>
     */
    private SimpleVectorf4 clearingColour;

    /**
     * <p>
     * The clearing mode. Determines if the screen buffer is cleared before rendering.
     * </p>
     * 
     * @return True if the screen buffer is cleared before rendering, false otherwise.
     */
    private boolean clearsBeforeRender;

    /**
     * <p>
     * The drawing mode used to render the <code>SceneGraph</code>.
     * </p>
     */
    private DrawingMode drawingMode;

    /**
     * <p>
     * The initialisation status. Determines if this <code>Renderer</code> is initialised.
     * </p>
     */
    private boolean isInitialised;

    /**
     * <p>
     * The {@link com.se.simplicity.rendering.Light Light}s within this <code>SimpleJOGLRenderer</code>.
     * </p>
     */
    private List<Light> lights;

    /**
     * <p>
     * Logs messages associated with this class.
     * </p>
     */
    private Logger logger;

    /**
     * <p>
     * The preferred frequency (advancements per second) of this <code>SimpleJOGLRenderingEngine</code>.
     * </p>
     */
    private int preferredFrequency;

    /**
     * <p>
     * The <code>Renderer</code> that renders <code>@link com.se.simplicity.model.VertexGroup VertexGroup</code>s for this
     * <code>SimpleJOGLRenderingEngine</code>.
     * </p>
     */
    private Renderer renderer;

    /**
     * <p>
     * The {@link com.se.simplicity.scenegraph.SceneGraph SceneGraph} to be rendered.
     * </p>
     */
    private SceneGraph sceneGraph;

    /**
     * <p>
     * Creates an instance of <code>SimpleJOGLRenderer</code>.
     * </p>
     */
    public SimpleJOGLRenderingEngine()
    {
        camera = null;
        clearingColour = new SimpleVectorf4(0.0f, 0.0f, 0.0f, 1.0f);
        clearsBeforeRender = true;
        drawingMode = DrawingMode.FACES;
        isInitialised = false;
        lights = new ArrayList<Light>();
        logger = Logger.getLogger(getClass().getName());
        sceneGraph = null;
    }

    @Override
    public void addLight(final Light light)
    {
        ((JOGLComponent) light).setGL(getGL());

        lights.add(light);
    }

    @Override
    public void advance()
    {
        super.advance();

        if (camera == null)
        {
            throw new IllegalStateException("This Renderer does not have a Camera to view the SceneGraph through.");
        }

        if (sceneGraph == null)
        {
            throw new IllegalStateException("This Renderer does not have a SceneGraph to display.");
        }

        if (!isInitialised)
        {
            try
            {
                init();
            }
            catch (IllegalStateException e)
            {
                logger.error("Failed to initialise the engine.", e);

                return;
            }
        }

        GL gl = getGL();

        // Clear the display.
        if (clearsBeforeRender)
        {
            gl.glClear(GL.GL_COLOR_BUFFER_BIT | GL.GL_DEPTH_BUFFER_BIT);
        }

        // Render the Scene Graph.
        gl.glPushMatrix();
        {
            camera.apply();

            for (Light light : lights)
            {
                light.apply();
            }

            renderSceneGraph();
        }
        gl.glPopMatrix();
    }

    /**
     * <p>
     * Backtracks up the <code>SceneGraph</code> the number of levels given.
     * </p>
     * 
     * <p>
     * A backtrack is an upward movement in the graph being rendered.
     * </p>
     * 
     * @param backtracks The number of levels to backtrack.
     */
    protected void backtrack(final int backtracks)
    {
        for (int index = 0; index < backtracks; index++)
        {
            getGL().glPopMatrix();
        }
    }

    @Override
    public boolean clearsBeforeRender()
    {
        return (clearsBeforeRender);
    }

    @Override
    public void destroy()
    {}

    @Override
    public Camera getCamera()
    {
        return (camera);
    }

    @Override
    public SimpleVectorf4 getClearingColour()
    {
        return (clearingColour);
    }

    @Override
    public DrawingMode getDrawingMode()
    {
        return (drawingMode);
    }

    @Override
    public List<Light> getLights()
    {
        return (lights);
    }

    @Override
    public SceneGraph getSceneGraph()
    {
        return (sceneGraph);
    }

    @Override
    public void init()
    {
        GL gl = getGL();

        if (renderer != null)
        {
            ((JOGLComponent) renderer).setGL(gl);
        }

        if (camera != null)
        {
            ((JOGLComponent) camera).setGL(gl);
        }

        for (Light light : lights)
        {
            ((JOGLComponent) light).setGL(gl);
        }

        // Initialise the JOGL state.
        gl.glEnable(GL.GL_CULL_FACE);
        gl.glEnable(GL.GL_DEPTH_TEST);
        gl.glFrontFace(GL.GL_CCW);

        // Initialise modelview matrix.
        gl.glMatrixMode(GL.GL_MODELVIEW);

        setClearingColour(clearingColour);

        // Enable model data arrays.
        gl.glEnableClientState(GL.GL_VERTEX_ARRAY);
        
        isInitialised = true;
    }

    @Override
    public void renderSceneGraph()
    {
        GL gl = getGL();

        // For every node in the traversal of the scene.
        SimpleTraversal traversal = new SimpleTraversal(sceneGraph.getRoot());
        Node currentNode;

        while (traversal.hasMoreNodes())
        {
            // Remove transformations from the stack that do not apply to the next node.
            backtrack(traversal.getBacktracksToNextNode());

            // Apply the transformation of the current node.
            currentNode = traversal.getNextNode();

            gl.glPushMatrix();
            gl.glMultMatrixf(((SimpleMatrixf44) currentNode.getTransformation()).getArray(), 0);

            // Render the current node if it is a model.
            if (currentNode instanceof ModelNode && currentNode.isVisible())
            {
                if (renderer instanceof NamedJOGLRenderer)
                {
                    ((NamedJOGLRenderer) renderer).renderVertexGroup(((ModelNode) currentNode).getVertexGroup(), drawingMode, currentNode.getID());
                }
                else
                {
                    renderer.renderVertexGroup(((ModelNode) currentNode).getVertexGroup(), drawingMode);
                }
            }
        }

        // Remove all remaining transformations from the stack.
        backtrack(traversal.getBacktracksToNextNode());
    }

    @Override
    public void reset()
    {
        init();
    }

    @Override
    public void setCamera(final Camera camera)
    {
        ((JOGLComponent) camera).setGL(getGL());

        this.camera = camera;
    }

    @Override
    public void setClearingColour(final SimpleVectorf4 clearingColour)
    {
        this.clearingColour = clearingColour;
        
        isInitialised = false;
    }

    @Override
    public void setClearsBeforeRender(final boolean clearsBeforeRender)
    {
        this.clearsBeforeRender = clearsBeforeRender;
    }

    @Override
    public void setDrawingMode(final DrawingMode drawingMode)
    {
        this.drawingMode = drawingMode;
    }

    @Override
    public void setSceneGraph(final SceneGraph sceneGraph)
    {
        this.sceneGraph = sceneGraph;
    }

    @Override
    public int getPreferredFrequency()
    {
        return (preferredFrequency);
    }

    @Override
    public void setPreferredFrequency(int preferredFrequency)
    {
        this.preferredFrequency = preferredFrequency;
    }

    @Override
    public void run()
    {
        init();

        while (!Thread.interrupted())
        {
            sleep();
            advance();
        }

        destroy();
    }

    @Override
    public Renderer getRenderer()
    {
        return (renderer);
    }

    @Override
    public void setRenderer(Renderer renderer)
    {
        ((JOGLComponent) renderer).setGL(getGL());

        this.renderer = renderer;
    }

    /**
     * <p>
     * Causes this <code>SimpleJOGLRenderingEngine</code> to sleep for the appropriate amount of time to allow for its preferred frequency.
     * </p>
     */
    protected void sleep()
    {
        try
        {
            Thread.sleep((long) 1000.0 / preferredFrequency);
        }
        catch (InterruptedException e)
        {
            Thread.currentThread().interrupt();

            logger.debug("The engine was interrupted while sleeping.");
        }
    }
}
