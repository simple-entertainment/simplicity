package com.se.simplicity.rendering;

/**
 * <p>
 * The lighting mode used to render a {@link com.se.simplicity.scenegraph.SceneGraph SceneGraph}. The modes are as follows:
 * </p>
 * 
 * @author simple
 */
public enum LightingMode
{
	/**
	 * <p>
	 * Renders the models with shading determined by the Lights within the SceneGraph.
	 * </p>
	 */
	SCENE,

	/**
	 * <p>
	 * Renders the models with simple shading. Lights to create the shading effects are added by the SceneGraph and are
	 * implementation specific.
	 * </p>
	 */
	SHADED,

	/**
	 * <p>
	 * Renders the models with solid shading. Lights to create the shading effects are added by the SceneGraph and are
	 * implementation specific.
	 * </p>
	 */
	SOLID
}
