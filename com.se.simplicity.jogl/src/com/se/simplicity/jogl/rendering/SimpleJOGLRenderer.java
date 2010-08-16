package com.se.simplicity.jogl.rendering;

import javax.media.opengl.GL;

import com.se.simplicity.jogl.JOGLComponent;
import com.se.simplicity.model.ArrayVG;
import com.se.simplicity.model.IndexedArrayVG;
import com.se.simplicity.model.VertexGroup;
import com.se.simplicity.rendering.DrawingMode;
import com.se.simplicity.rendering.Renderer;

/**
 * <p>
 * This implementation uses only simple rendering techniques and properties.
 * </p>
 * 
 * @author simple
 */
public class SimpleJOGLRenderer implements Renderer, JOGLComponent
{
	/**
	 * <p>
	 * The JOGL rendering environment.
	 * </p>
	 */
	private GL gl;
	
	@Override
	public GL getGL()
	{
		return (gl);
	}

	/**
	 * <p>
	 * Sets the JOGL drawing mode used to render the <code>SceneGraph</code>.
	 * </p>
	 */
	protected int getJOGLDrawingMode(final DrawingMode drawingMode)
	{
		int joglDrawingMode = -1;

		if (drawingMode == DrawingMode.VERTICES)
		{
			gl.glPointSize(2.0f);
			joglDrawingMode = GL.GL_POINTS;
		}
		else if (drawingMode == DrawingMode.EDGES)
		{
			joglDrawingMode = GL.GL_LINE_LOOP;
		}
		else if (drawingMode == DrawingMode.FACES)
		{
			joglDrawingMode = GL.GL_TRIANGLES;
		}

		return (joglDrawingMode);
	}

	/**
	 * <p>
	 * Renders an <code>ArrayVG</code>.
	 * </p>
	 * 
	 * @param vertexGroup The <code>ArrayVG</code> to render.
	 */
	protected void renderArrayVG(final ArrayVG vertexGroup, DrawingMode drawingMode)
	{
		float[] colours = vertexGroup.getColours();
		float[] normals = vertexGroup.getNormals();
		float[] vertices = vertexGroup.getVertices();

		for (int triangleIndex = 0; triangleIndex < vertices.length / 9; triangleIndex++)
		{
			gl.glBegin(getJOGLDrawingMode(drawingMode));
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
	protected void renderIndexedArrayVG(final IndexedArrayVG vertexGroup, DrawingMode drawingMode)
	{
		int[] indices = vertexGroup.getIndices();
		float[] colours = vertexGroup.getColours();
		float[] normals = vertexGroup.getNormals();
		float[] vertices = vertexGroup.getVertices();
		int vertex;

		for (int triangleIndex = 0; triangleIndex < indices.length / 3; triangleIndex++)
		{
			gl.glBegin(getJOGLDrawingMode(drawingMode));
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

	/**
	 * <p>
	 * Renders a <code>VertexGroup</code>.
	 * </p>
	 * 
	 * @param node The <code>ModelNode</code> that contains the <code>VertexGroup</code> to be rendered.
	 */
	public void renderVertexGroup(final VertexGroup vertexGroup, final DrawingMode drawingMode)
	{
		if (vertexGroup instanceof ArrayVG)
		{
			renderArrayVG((ArrayVG) vertexGroup, drawingMode);
		}
		else if (vertexGroup instanceof IndexedArrayVG)
		{
			renderIndexedArrayVG((IndexedArrayVG) vertexGroup, drawingMode);
		}
	}

	@Override
	public void setGL(GL gl)
	{
		this.gl = gl;
	}
}
