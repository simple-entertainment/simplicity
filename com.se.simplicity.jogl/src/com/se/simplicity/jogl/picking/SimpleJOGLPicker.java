package com.se.simplicity.jogl.picking;

//J2SE imports.
import java.awt.Component;
import java.nio.ByteBuffer;
import java.nio.ByteOrder;
import java.nio.IntBuffer;
import java.util.List;

import javax.media.opengl.GL;

import com.se.simplicity.jogl.rendering.SimpleJOGLCamera;
import com.se.simplicity.model.VertexGroup;
import com.se.simplicity.picking.event.PickEvent;
import com.se.simplicity.rendering.DrawingMode;
import com.se.simplicity.rendering.Viewport;
import com.se.simplicity.scenegraph.model.ModelNode;

/**
 * <p>
 * This implementation uses only simple picking techniques and properties.
 * </p>
 * 
 * <p>
 * Copyright (c) 2007, simple entertainment
 * </p>
 * 
 * @author simple
 */
public class SimpleJOGLPicker extends JOGLPicker
{
	/**
	 * <p>
	 * Retrieves the picking viewpoint. All the components of the <code>SceneGraph</code> that can be seen through this viewpoint
	 * will be picked.
	 * </p>
	 * 
	 * @param pick The pick to create the viewpoint for.
	 * @param rendererCamera The viewpoint shown by the <code>Viewport</code> to which the pick was registered.
	 * 
	 * @return The picking viewpoint.
	 */
	protected SimpleJOGLCamera createPickCamera(final int[] pick, final SimpleJOGLCamera rendererCamera)
	{
		// Translate pick values from Viewport coordinates to frame coordinates.
		Component viewportCompCast = (Component) getViewport();

		float pickWidthFrame = (float) pick[2] / (float) viewportCompCast.getWidth() * rendererCamera.getFrameWidth();
		float pickXFrame = ((float) pick[0] / (float) viewportCompCast.getWidth() * rendererCamera.getFrameWidth());
		float pickYFrame = ((float) pick[1] / (float) viewportCompCast.getHeight() * (rendererCamera.getFrameWidth() * rendererCamera
				.getFrameAspectRatio()));

		// Create the Camera to pick with.
		SimpleJOGLCamera pickCamera = new SimpleJOGLCamera();
		pickCamera.setFarClippingDistance(rendererCamera.getFarClippingDistance());
		pickCamera.setFrameAspectRatio(rendererCamera.getFrameAspectRatio());
		pickCamera.setFrameWidth(pickWidthFrame);
		pickCamera.setFrameX(pickXFrame - (rendererCamera.getFrameWidth() / 2) + rendererCamera.getFrameX());
		pickCamera.setFrameY((rendererCamera.getFrameWidth() * rendererCamera.getFrameAspectRatio() / 2) - pickYFrame
				+ rendererCamera.getFrameY());
		pickCamera.setGL(getGL());
		pickCamera.setNearClippingDistance(rendererCamera.getNearClippingDistance());
		pickCamera.setNode(rendererCamera.getNode());

		return (pickCamera);
	}

	/**
	 * <p>
	 * Creates a <code>PickEvent</code> for the given select buffer.
	 * </p>
	 * 
	 * <p>
	 * It is assumed that names 1..n-1 in the select buffer correspond to the unique identifiers of <code>ModelNode</code>s
	 * containing the picked components of the <code>SceneGraph</code> and that name n in the select buffer corresponds to the
	 * subset (face/edge/vertex) of the component that was actually picked.
	 * </p>
	 * 
	 * @param selectBuffer The select buffer to create a <code>PickEvent</code> for.
	 * 
	 * @return A <code>PickEvent</code> for the given select buffer.
	 */
	protected PickEvent createPickEvent(final IntBuffer selectBuffer)
	{
		PickEvent event = new PickEvent();
		int bufferIndex = 0;

		while (bufferIndex < selectBuffer.capacity() && selectBuffer.get(bufferIndex) != 0)
		{
			Object[] hit = new Object[selectBuffer.get(bufferIndex)];
			bufferIndex += 3;

			for (int nameIndex = 0; nameIndex < hit.length; nameIndex++)
			{
				if (nameIndex + 1 == hit.length)
				{
					hit[nameIndex] = createSubsetVG(((ModelNode) hit[nameIndex - 1]).getVertexGroup(), selectBuffer
							.get(bufferIndex));
				}
				else
				{
					hit[nameIndex] = getViewport().getRenderer().getSceneGraph().getNode(selectBuffer.get(bufferIndex));
				}

				bufferIndex++;
			}

			event.addHit(hit);
		}

		return (event);
	}

	/**
	 * TODO Complete javadoc
	 * 
	 * <p>
	 * 
	 * </p>
	 * 
	 * @param vertexGroup
	 * @param index
	 * 
	 * @return
	 */
	protected VertexGroup createSubsetVG(final VertexGroup vertexGroup, final int index)
	{
		Viewport viewport = getViewport();
		VertexGroup subsetVertexGroup = null;

		if (viewport.getRenderer().getDrawingMode() == DrawingMode.VERTICES)
		{
			subsetVertexGroup = vertexGroup.createVertexSubsetVG(index);
		}
		else if (viewport.getRenderer().getDrawingMode() == DrawingMode.EDGES)
		{
			subsetVertexGroup = vertexGroup.createEdgeSubsetVG(index);
		}
		else if (viewport.getRenderer().getDrawingMode() == DrawingMode.FACES)
		{
			subsetVertexGroup = vertexGroup.createFaceSubsetVG(index);
		}

		return (subsetVertexGroup);
	}

	@Override
	public void pickSceneGraph()
	{
		super.pickSceneGraph();

		GL gl = getGL();
		List<Object> picks = getPicks();
		Viewport viewport = getViewport();

		// Setup the selection buffer.
		IntBuffer selectBuffer = ByteBuffer.allocateDirect(getSelectBufferCapacity() << 2).order(ByteOrder.nativeOrder())
				.asIntBuffer();
		gl.glSelectBuffer(selectBuffer.capacity(), selectBuffer);

		// For every pick.
		for (int index = 0; index < picks.size(); index++)
		{
			SimpleJOGLCamera pickCamera = createPickCamera((int[]) picks.get(index), (SimpleJOGLCamera) viewport.getRenderer()
					.getCamera());

			gl.glRenderMode(GL.GL_SELECT);

			gl.glPushMatrix();
			{
				pickCamera.apply();
				viewport.getRenderer().renderSceneGraph();
			}
			gl.glPopMatrix();

			gl.glRenderMode(GL.GL_RENDER);
			firePickEvent(createPickEvent(selectBuffer));
		}

		picks.clear();
	}
}
