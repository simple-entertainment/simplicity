package com.se.simplicity.jogl.rendering;

// simplicity imports.
import javax.media.opengl.GL;

import com.se.simplicity.model.ArrayVG;
import com.se.simplicity.model.IndexedArrayVG;
import com.se.simplicity.rendering.DrawingMode;
import com.se.simplicity.scenegraph.Node;
import com.se.simplicity.scenegraph.model.ModelNode;

/**
 * <p>
 * This implementation names the <code>VertexGroup</code>s rendered as well as the primitives rendered (faces, edges or vertices).
 * <code>VertexGroup</code>s are named using the unique identifiers of their <code>Node</code>s. The naming of the primitives is
 * specific to the <code>VertexGroup</code> implementation.
 * </p>
 * 
 * <p>
 * Copyright (c) 2007, simple entertainment
 * </p>
 * 
 * @author simple
 */
public class NamedJOGLRenderer extends SimpleJOGLRenderer
{
	@Override
	protected void renderArrayVG(ArrayVG vertexGroup)
	{
		if (getDrawingMode() == DrawingMode.EDGES)
		{
			// renderNamedIAVertexGroupEdges(vertexGroup);
		}
		else if (getDrawingMode() == DrawingMode.FACES)
		{
			renderArrayVGFaces(vertexGroup);
		}
		else if (getDrawingMode() == DrawingMode.VERTICES)
		{
			renderArrayVGVertices(vertexGroup);
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
	protected void renderArrayVGFaces(final ArrayVG vertexGroup)
	{
		GL gl = getGL();
		
		float[] colours = vertexGroup.getColours();
		float[] normals = vertexGroup.getNormals();
		float[] vertices = vertexGroup.getVertices();

		for (int triangleIndex = 0; triangleIndex < vertices.length / 9; triangleIndex++)
		{
			gl.glPushName(triangleIndex);
			gl.glBegin(getJOGLDrawingMode());
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
	protected void renderArrayVGVertices(final ArrayVG vertexGroup)
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
				gl.glBegin(getJOGLDrawingMode());
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

	protected void renderIndexedArrayVG(final IndexedArrayVG vertexGroup)
	{
		if (getDrawingMode() == DrawingMode.EDGES)
		{
			// renderNamedIAVertexGroupEdges(vertexGroup);
		}
		else if (getDrawingMode() == DrawingMode.FACES)
		{
			renderIndexedArrayVGFaces(vertexGroup);
		}
		else if (getDrawingMode() == DrawingMode.VERTICES)
		{
			renderIndexedArrayVGVertices(vertexGroup);
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
	protected void renderIndexedArrayVGFaces(final IndexedArrayVG vertexGroup)
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
			gl.glBegin(getJOGLDrawingMode());
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
	protected void renderIndexedArrayVGVertices(final IndexedArrayVG vertexGroup)
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
				gl.glBegin(getJOGLDrawingMode());
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
	 * Assigns the ID of the <code>ModelNode</code> being rendered to the rendered elements of the <code>VertexGroup</code>.
	 * </p>
	 * 
	 * @param node The <code>ModelNode</code> that contains the <code>VertexGroup</code> to be rendered.
	 */
	@Override
	protected void renderVertexGroup(final ModelNode node)
	{
		GL gl = getGL();
		
		gl.glPushName(node.getID());

		super.renderVertexGroup(node);

		gl.glPopName();
	}
}
