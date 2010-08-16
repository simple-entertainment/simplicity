package com.se.simplicity.jogl.rendering;

// JOGL imports.
import java.util.ArrayList;
import java.util.List;

import javax.media.opengl.GL;

// simplicity imports.
import com.se.simplicity.model.ArrayVG;
import com.se.simplicity.model.IndexedArrayVG;
import com.se.simplicity.model.VertexGroup;
import com.se.simplicity.rendering.Camera;
import com.se.simplicity.rendering.DrawingMode;
import com.se.simplicity.rendering.Light;
import com.se.simplicity.scenegraph.Node;
import com.se.simplicity.scenegraph.SceneGraph;
import com.se.simplicity.scenegraph.SimpleTraversal;
import com.se.simplicity.scenegraph.model.ModelNode;
import com.se.simplicity.vector.SimpleMatrixf44;
import com.se.simplicity.vector.SimpleVectorf4;

/**
 * <p>
 * This implementation uses only simple rendering techniques and properties.
 * </p>
 * 
 * <p>
 * Copyright (c) 2007, simple entertainment
 * </p>
 * 
 * @author simple
 */
public class SimpleJOGLRenderer extends JOGLRenderer
{
	/**
	 * <p>
	 * The {@link com.se.simplicity.rendering.Camera Camera} through which the {@link com.se.simplicity.scenegraph.SceneGraph
	 * SceneGraph} will be rendered.
	 * </p>
	 */
	private Camera camera;
	
	/**
	 * <p>
	 * The {@link com.se.simplicity.rendering.Camera Camera}s within this <code>SimpleJOGLRenderer</code>.
	 * </p>
	 */
	private List<Camera> cameras;
	
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
	 * The JOGL drawing mode used to render the <code>SceneGraph</code>.
	 * </p>
	 */
	private int joglDrawingMode;

	/**
	 * <p>
	 * The {@link com.se.simplicity.rendering.Light Light}s within this <code>SimpleJOGLRenderer</code>.
	 * </p>
	 */
	private List<Light> lights;

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
	public SimpleJOGLRenderer()
	{
		super();

		camera = null;
		cameras = new ArrayList<Camera>();
		clearingColour = new SimpleVectorf4(0.0f, 0.0f, 0.0f, 1.0f);
		clearsBeforeRender = true;
		drawingMode = DrawingMode.FACES;
		isInitialised = false;
		joglDrawingMode = -1;
		lights = new ArrayList<Light>();
		sceneGraph = null;
	}
	
	@Override
	public void addCamera(final Camera camera)
	{
		cameras.add(camera);
	}
	
	@Override
	public void addLight(final Light light)
	{
		lights.add(light);
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
	public void display()
	{
		super.display();
		
		if (camera == null)
		{
			throw new IllegalStateException("This Renderer must have a camera to display the SceneGraph.");
		}

		if (!isInitialised)
		{
			try
			{
				init();
			}
			catch (IllegalStateException ex)
			{
				// TODO Write to log4j
				
				return;
			}
		}
		
		GL gl = getGL();

		// Clear the display.
		if (clearsBeforeRender)
		{
			gl.glClear(GL.GL_COLOR_BUFFER_BIT | GL.GL_DEPTH_BUFFER_BIT);
		}

		gl.glPushMatrix();
		{
			camera.apply();

			// TEMPORARY STATEMENTS
			((JOGLComponent) lights.get(0)).setGL(gl);
			lights.get(0).apply();

			renderSceneGraph();
		}
		gl.glPopMatrix();
	}
	
	@Override
	public Camera getCamera()
	{
		return (camera);
	}
	
	@Override
	public List<Camera> getCameras()
	{
		return (cameras);
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
	
	/**
	 * <p>
	 * The JOGL drawing mode used to render the <code>SceneGraph</code>.
	 * </p>
	 * 
	 * @return The JOGL drawing mode used to render the <code>SceneGraph</code>.
	 */
	public int getJOGLDrawingMode()
	{
		return (joglDrawingMode);
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
		super.init();
		
		GL gl = getGL();

		// Initialise the JOGL state.
		gl.glEnable(GL.GL_CULL_FACE);
		gl.glEnable(GL.GL_DEPTH_TEST);
		gl.glFrontFace(GL.GL_CCW);

		// Initialise modelview matrix.
		gl.glMatrixMode(GL.GL_MODELVIEW);

		setClearingColour(clearingColour);

		// Enable model data arrays.
		gl.glEnableClientState(GL.GL_VERTEX_ARRAY);

		setJOGLDrawingMode();
	}

	/**
	 * <p>
	 * Renders an <code>ArrayVG</code>.
	 * </p>
	 * 
	 * @param vertexGroup The <code>ArrayVG</code> to render.
	 */
	protected void renderArrayVG(final ArrayVG vertexGroup)
	{
		float[] colours = vertexGroup.getColours();
		float[] normals = vertexGroup.getNormals();
		float[] vertices = vertexGroup.getVertices();
		
		GL gl = getGL();

		for (int triangleIndex = 0; triangleIndex < vertices.length / 9; triangleIndex++)
		{
			gl.glBegin(joglDrawingMode);
			{
				for (int vertexIndex = 0; vertexIndex < 9; vertexIndex += 3)
				{
					int vertex = triangleIndex * 9 + vertexIndex;

					gl.glColor3f(colours[vertex], colours[vertex + 1], colours[vertex + 2]);
					gl.glNormal3f(normals[vertex], normals[vertex + 1], normals[vertex + 2]);
					gl.glVertex3f(vertices[vertex], vertices[vertex + 1], vertices[vertex + 2]);
				}
			}
			gl.glEnd();
		}
	}

	/**
	 * <p>
	 * Renders an <code>IndexedArrayVG</code>.
	 * </p>
	 * 
	 * @param vertexGroup The <code>IndexedArrayVG</code> to render.
	 */
	protected void renderIndexedArrayVG(final IndexedArrayVG vertexGroup)
	{
		int[] indices = vertexGroup.getIndices();
		float[] colours = vertexGroup.getColours();
		float[] normals = vertexGroup.getNormals();
		float[] vertices = vertexGroup.getVertices();
		int vertex;
		
		GL gl = getGL();

		for (int triangleIndex = 0; triangleIndex < indices.length / 3; triangleIndex++)
		{
			gl.glBegin(joglDrawingMode);
			{
				for (int vertexIndex = 0; vertexIndex < 9; vertexIndex += 3)
				{
					vertex = indices[triangleIndex * 3] * 3 + vertexIndex;

					gl.glColor3f(colours[vertex], colours[vertex + 1], colours[vertex + 2]);
					gl.glNormal3f(normals[vertex], normals[vertex + 1], normals[vertex + 2]);
					gl.glVertex3f(vertices[vertex], vertices[vertex + 1], vertices[vertex + 2]);
				}
			}
			gl.glEnd();
		}
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
				renderVertexGroup((ModelNode) currentNode);
			}
		}

		// Remove all remaining transformations from the stack.
		backtrack(traversal.getBacktracksToNextNode());
	}

	/**
	 * <p>
	 * Renders a <code>VertexGroup</code>.
	 * </p>
	 * 
	 * @param node The <code>ModelNode</code> that contains the <code>VertexGroup</code> to be rendered.
	 */
	protected void renderVertexGroup(final ModelNode node)
	{
		VertexGroup vertexGroup = node.getVertexGroup();

		if (vertexGroup instanceof ArrayVG)
		{
			renderArrayVG((ArrayVG) vertexGroup);
		}
		else if (vertexGroup instanceof IndexedArrayVG)
		{
			renderIndexedArrayVG((IndexedArrayVG) vertexGroup);
		}
	}
	
	@Override
	public void setCamera(final Camera camera)
	{
		super.setCamera(camera);
		
		this.camera = camera;
	}

	@Override
	public void setClearingColour(final SimpleVectorf4 clearingColour)
	{
		this.clearingColour = clearingColour;
		
		isInitialised = false;

		float[] clearingColourArray = clearingColour.getArray();

		getGL().glClearColor(clearingColourArray[0], clearingColourArray[1], clearingColourArray[2], clearingColourArray[3]);
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
		
		isInitialised = false;
	}

	/**
	 * <p>
	 * Sets the JOGL drawing mode used to render the <code>SceneGraph</code>.
	 * </p>
	 */
	protected void setJOGLDrawingMode()
	{
		if (drawingMode == DrawingMode.VERTICES)
		{
			getGL().glPointSize(2.0f);
			joglDrawingMode = GL.GL_POINTS;
		}

		if (drawingMode == DrawingMode.EDGES)
		{
			joglDrawingMode = GL.GL_LINE_LOOP;
		}

		if (drawingMode == DrawingMode.FACES)
		{
			joglDrawingMode = GL.GL_TRIANGLES;
		}
	}
	
	@Override
	public void setSceneGraph(final SceneGraph sceneGraph)
	{
		this.sceneGraph = sceneGraph;
		
		isInitialised = false;
	}
}
