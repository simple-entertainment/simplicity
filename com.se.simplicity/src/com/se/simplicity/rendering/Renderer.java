package com.se.simplicity.rendering;

import com.se.simplicity.model.VertexGroup;

/**
 * <p>
 * Renders {@link com.se.simplicity.rendering.VertexGroup VertexGroup}s.
 * </p>
 * 
 * @author simple
 */
public interface Renderer
{
	/**
	 * <p>
	 * Renders the given {@link com.se.simplicity.rendering.VertexGroup VertexGroup} with the given
	 * {@link com.se.simplicity.rendering.DrawingMode DrawingMode}.
	 * </p>
	 * 
	 * @param vertexGroup The {@link com.se.simplicity.rendering.VertexGroup VertexGroup} to render.
	 * @param drawingMode The {@link com.se.simplicity.rendering.DrawingMode DrawingMode} to render the
	 * {@link com.se.simplicity.rendering.VertexGroup VertexGroup} with.
	 */
	void renderVertexGroup(VertexGroup vertexGroup, DrawingMode drawingMode);
}
