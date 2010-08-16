package com.se.simplicity.jogl.picking;

import java.nio.ByteBuffer;
import java.nio.ByteOrder;
import java.nio.IntBuffer;

import javax.media.opengl.GL;

import com.se.simplicity.jogl.JOGLComponent;
import com.se.simplicity.model.VertexGroup;
import com.se.simplicity.picking.Pick;
import com.se.simplicity.picking.Picker;
import com.se.simplicity.picking.event.PickEvent;
import com.se.simplicity.rendering.Camera;
import com.se.simplicity.rendering.DrawingMode;
import com.se.simplicity.rendering.engine.RenderingEngine;
import com.se.simplicity.scenegraph.SceneGraph;
import com.se.simplicity.scenegraph.model.ModelNode;

/**
 * <p>
 * Picks from a JOGL rendering environment. This implementation uses only simple picking techniques and properties.
 * </p>
 * 
 * @author simple
 */
public class SimpleJOGLPicker implements Picker, JOGLComponent
{
	/**
	 * <p>
	 * The JOGL rendering environment.
	 * </p>
	 */
	private GL gl;

	/**
	 * <p>
	 * The <code>RenderingEngine</code> that renders the <code>SceneGraph</code> to determine which components will be picked.
	 * </p>
	 */
	private RenderingEngine renderingEngine;

	/**
	 * <p>
	 * The select buffer used by the JOGL rendering environment. Holds details of picked <code>SceneGraph</code> components.
	 * </p>
	 */
	private IntBuffer selectBuffer;

	/**
	 * <p>
	 * The capacity of the select buffer used by the JOGL rendering environment. This capacity determines how much hit data can be
	 * retrieved when picking a <code>SceneGraph</code>.
	 * </p>
	 */
	private int selectBufferCapacity;

	/**
	 * <p>
	 * Creates an instance of <code>SimpleJOGLPicker</code>.
	 * </p>
	 */
	public SimpleJOGLPicker()
	{
		this.selectBufferCapacity = 2048;
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
					hit[nameIndex] = getSubsetVG(((ModelNode) hit[nameIndex - 1]).getVertexGroup(), selectBuffer.get(bufferIndex));
				}
				else
				{
					hit[nameIndex] = renderingEngine.getSceneGraph().getNode(selectBuffer.get(bufferIndex));
				}

				bufferIndex++;
			}

			event.addHit(hit);
		}

		return (event);
	}

	@Override
	public GL getGL()
	{
		return (gl);
	}

	/**
	 * <p>
	 * Retrieves the <code>RenderingEngine</code> that renders the <code>SceneGraph</code> to determine which components will
	 * be picked.
	 * </p>
	 * 
	 * @return The <code>RenderingEngine</code> that renders the <code>SceneGraph</code> to determine which components will be
	 * picked.
	 */
	public RenderingEngine getRenderingEngine()
	{
		return renderingEngine;
	}

	/**
	 * <p>
	 * Retrieves the capacity of the select buffer used by the JOGL rendering environment.
	 * </p>
	 * 
	 * @return The capacity of the select buffer used by the JOGL rendering environment.
	 */
	public int getSelectBufferCapacity()
	{
		return (selectBufferCapacity);
	}

	/**
	 * <p>
	 * Retrieves a subset vertex group containing the rendered primitive at the given index of the given <code>VertexGroup</code>.
	 * </p>
	 * 
	 * @param vertexGroup The <code>VertexGroup</code> to create the subset from.
	 * @param index The index of the rendered primitive to contain in the subset.
	 * 
	 * @return A subset vertex group containing the rendered primitive at the given index of the given <code>VertexGroup</code>.
	 */
	protected VertexGroup getSubsetVG(final VertexGroup vertexGroup, final int index)
	{
		VertexGroup subsetVertexGroup = null;

		if (renderingEngine.getDrawingMode() == DrawingMode.VERTICES)
		{
			subsetVertexGroup = vertexGroup.createVertexSubsetVG(index);
		}
		else if (renderingEngine.getDrawingMode() == DrawingMode.EDGES)
		{
			subsetVertexGroup = vertexGroup.createEdgeSubsetVG(index);
		}
		else if (renderingEngine.getDrawingMode() == DrawingMode.FACES)
		{
			subsetVertexGroup = vertexGroup.createFaceSubsetVG(index);
		}

		return (subsetVertexGroup);
	}

	/**
	 * <p>
	 * Initialises the select buffer used by the JOGL rendering environment with the correct capacity.
	 * </p>
	 */
	protected void initSelectBuffer()
	{
		selectBuffer = ByteBuffer.allocateDirect(selectBufferCapacity << 2).order(ByteOrder.nativeOrder()).asIntBuffer();
		gl.glSelectBuffer(selectBuffer.capacity(), selectBuffer);
	}

	@Override
	public PickEvent pickSceneGraph(SceneGraph sceneGraph, Camera camera, Pick pick)
	{
		Camera pickCamera = camera.getPickCamera(pick);

		gl.glRenderMode(GL.GL_SELECT);

		renderingEngine.setSceneGraph(sceneGraph);
		renderingEngine.setCamera(pickCamera);
		renderingEngine.advance();

		gl.glRenderMode(GL.GL_RENDER);

		return (createPickEvent(selectBuffer));
	}

	@Override
	public void setGL(GL gl)
	{
		this.gl = gl;

		initSelectBuffer();
	}

	/**
	 * <p>
	 * Sets the <code>RenderingEngine</code> that renders the <code>SceneGraph</code> to determine which components will be
	 * picked.
	 * </p>
	 * 
	 * @param renderingEngine The <code>RenderingEngine</code> that renders the <code>SceneGraph</code> to determine which
	 * components will be picked.
	 */
	public void setRenderingEngine(RenderingEngine renderingEngine)
	{
		this.renderingEngine = renderingEngine;
	}

	/**
	 * <p>
	 * Sets the capacity of the select buffer used by the JOGL rendering environment.
	 * </p>
	 * 
	 * @param selectBufferCapacity The capacity of the select buffer used by the JOGL rendering environment.
	 */
	public void setSelectBufferCapacity(final int selectBufferCapacity)
	{
		this.selectBufferCapacity = selectBufferCapacity;

		if (gl != null)
		{
			initSelectBuffer();
		}
	}
}
