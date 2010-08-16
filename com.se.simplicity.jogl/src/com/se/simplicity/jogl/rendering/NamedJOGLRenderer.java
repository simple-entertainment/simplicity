package com.se.simplicity.jogl.rendering;

import javax.media.opengl.GL;

import com.se.simplicity.model.ArrayVG;
import com.se.simplicity.model.IndexedArrayVG;
import com.se.simplicity.model.VertexGroup;
import com.se.simplicity.rendering.DrawingMode;

/**
 * <p>
 * This implementation names the <code>VertexGroup</code>s rendered as well as the primitives rendered (faces, edges or vertices).
 * <code>VertexGroup</code>s are named using the unique identifiers of their <code>Node</code>s. The naming of the primitives is
 * specific to the <code>VertexGroup</code> implementation.
 * </p>
 * 
 * @author simple
 */
public class NamedJOGLRenderer extends SimpleJOGLRenderer
{
	@Override
	protected void renderArrayVG(final ArrayVG vertexGroup, DrawingMode drawingMode)
	{
		if (drawingMode == DrawingMode.EDGES)
		{
			// renderArrayVGEdges(vertexGroup);
		}
		else if (drawingMode == DrawingMode.FACES)
		{
			renderArrayVGFaces(vertexGroup, drawingMode);
		}
		else if (drawingMode == DrawingMode.VERTICES)
		{
			renderArrayVGVertices(vertexGroup, drawingMode);
		}
	}

	/**
	 * <p>
	 * Renders the given <code>ArrayVG</code> naming the faces with consecutive integers beginning with zero. This means that the
	 * section of the <code>ArrayVG</code>'s arrays containing data for a particular face can be found as follows:
	 * </p>
	 * 
	 * <p>
	 * <code>int firstIndexOfFaceSection = faceName * 9;</code>
	 * </p>
	 * 
	 * <p>
	 * The section containing a particular face consists of nine consecutive items of data beginning at
	 * <code>firstIndexOfFaceSection</code> in each array.
	 * </p>
	 * 
	 * @param vertexGroup The <code>ArrayVG</code> to render.
	 */
	protected void renderArrayVGFaces(final ArrayVG vertexGroup, DrawingMode drawingMode)
	{
		GL gl = getGL();
		
		float[] colours = vertexGroup.getColours();
		float[] normals = vertexGroup.getNormals();
		float[] vertices = vertexGroup.getVertices();

		for (int triangleIndex = 0; triangleIndex < vertices.length / 9; triangleIndex++)
		{
			gl.glPushName(triangleIndex);
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
			gl.glPopName();
		}
	}

	/**
	 * <p>
	 * Renders the given <code>ArrayVG</code> naming the vertices with consecutive integers beginning with zero. This means that
	 * the section of the <code>ArrayVG</code>'s arrays containing data for a particular vertex can be found as follows:
	 * </p>
	 * 
	 * <p>
	 * <code>int firstIndexOfVertexSection = vertexName * 3;</code>
	 * </p>
	 * 
	 * <p>
	 * The section containing a particular vertex consists of three consecutive items of data beginning at
	 * <code>firstIndexOfVertexSection</code> in each array.
	 * </p>
	 * 
	 * @param vertexGroup The <code>ArrayVG</code> to render.
	 */
	protected void renderArrayVGVertices(final ArrayVG vertexGroup, DrawingMode drawingMode)
	{
		GL gl = getGL();
		
		float[] colours = vertexGroup.getColours();
		float[] normals = vertexGroup.getNormals();
		float[] vertices = vertexGroup.getVertices();

		for (int triangleIndex = 0; triangleIndex < vertices.length / 9; triangleIndex++)
		{
			for (int vertexIndex = 0; vertexIndex < 9; vertexIndex += 3)
			{
				int vertex = triangleIndex * 9 + vertexIndex;

				gl.glPushName(vertex / 3);
				gl.glBegin(getJOGLDrawingMode(drawingMode));
				{
					gl.glColor3f(colours[vertex], colours[vertex + 1], colours[vertex + 2]);
					gl.glNormal3f(normals[vertex], normals[vertex + 1], normals[vertex + 2]);
					gl.glVertex3f(vertices[vertex], vertices[vertex + 1], vertices[vertex + 2]);
				}
				gl.glEnd();
				gl.glPopName();
			}
		}
	}

	protected void renderIndexedArrayVG(final IndexedArrayVG vertexGroup, DrawingMode drawingMode)
	{
		if (drawingMode == DrawingMode.EDGES)
		{
			// renderNamedIAVertexGroupEdges(vertexGroup);
		}
		else if (drawingMode == DrawingMode.FACES)
		{
			renderIndexedArrayVGFaces(vertexGroup, drawingMode);
		}
		else if (drawingMode == DrawingMode.VERTICES)
		{
			renderIndexedArrayVGVertices(vertexGroup, drawingMode);
		}
	}

	/**
	 * <p>
	 * Renders the given <code>IndexedArrayVG</code> naming the faces with consecutive integers beginning with zero. This means
	 * that the section of the <code>ArrayVG</code>'s index array containing references to data for a particular face can be found
	 * as follows:
	 * </p>
	 * 
	 * <p>
	 * <code>int firstIndexOfFaceSection = faceName * 3;</code>
	 * </p>
	 * 
	 * <p>
	 * The section containing a particular face consists of three consecutive indexes beginning at
	 * <code>firstIndexOfFaceSection</code> in the index array.
	 * </p>
	 * 
	 * @param vertexGroup The <code>IndexedArrayVG</code> to render.
	 */
	protected void renderIndexedArrayVGFaces(final IndexedArrayVG vertexGroup, DrawingMode drawingMode)
	{
		GL gl = getGL();
		
		int[] indices = vertexGroup.getIndices();
		float[] colours = vertexGroup.getColours();
		float[] normals = vertexGroup.getNormals();
		float[] vertices = vertexGroup.getVertices();
		int vertex;

		for (int triangleIndex = 0; triangleIndex < indices.length / 3; triangleIndex++)
		{
			gl.glPushName(triangleIndex);
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
			gl.glPopName();
		}
	}

	/**
	 * <p>
	 * Renders the given <code>IndexedArrayVG</code> naming the vertices with consecutive integers beginning with zero. This means
	 * that the section of the <code>ArrayVG</code>'s index array containing references to data for a particular vertex can be
	 * found as follows:
	 * </p>
	 * 
	 * <p>
	 * <code>int firstIndexOfVertexSection = vertexName;</code>
	 * </p>
	 * 
	 * <p>
	 * The section containing a particular vertex consists of one index beginning at <code>firstIndexOfVertexSection</code> in the
	 * index array.
	 * </p>
	 * 
	 * @param vertexGroup The <code>IndexedArrayVG</code> to render.
	 */
	protected void renderIndexedArrayVGVertices(final IndexedArrayVG vertexGroup, DrawingMode drawingMode)
	{
		GL gl = getGL();
		
		int[] indices = vertexGroup.getIndices();
		float[] colours = vertexGroup.getColours();
		float[] normals = vertexGroup.getNormals();
		float[] vertices = vertexGroup.getVertices();
		int vertex;

		for (int triangleIndex = 0; triangleIndex < indices.length / 3; triangleIndex++)
		{
			for (int vertexIndex = 0; vertexIndex < 9; vertexIndex += 3)
			{
				vertex = indices[triangleIndex * 3] * 3 + vertexIndex;

				gl.glPushName(vertex / 3);
				gl.glBegin(getJOGLDrawingMode(drawingMode));
				{
					gl.glColor3f(colours[vertex], colours[vertex + 1], colours[vertex + 2]);
					gl.glNormal3f(normals[vertex], normals[vertex + 1], normals[vertex + 2]);
					gl.glVertex3f(vertices[vertex], vertices[vertex + 1], vertices[vertex + 2]);
				}
				gl.glEnd();
				gl.glPopName();
			}
		}
	}

	/**
	 * <p>
	 * Assigns the hash code of the <code>VertexGroup</code> being rendered as its name.
	 * </p>
	 */
	@Override
	public void renderVertexGroup(final VertexGroup vertexGroup, final DrawingMode drawingMode)
	{
		GL gl = getGL();
		
		gl.glPushName(vertexGroup.hashCode());

		super.renderVertexGroup(vertexGroup, drawingMode);

		gl.glPopName();
	}
	
	/**
	 * <p>
	 * Assigns the given name to the <code>VertexGroup</code> being rendered.
	 * </p>
	 * 
	 * @param name The name to assign to the <code>VertexGroup</code> being rendered.
	 */
	public void renderVertexGroup(final VertexGroup vertexGroup, final DrawingMode drawingMode, final int name)
	{
		GL gl = getGL();
		
		gl.glPushName(name);

		super.renderVertexGroup(vertexGroup, drawingMode);

		gl.glPopName();
	}
}
