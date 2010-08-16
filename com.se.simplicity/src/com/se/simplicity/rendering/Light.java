package com.se.simplicity.rendering;

// simplicity imports.
import com.se.simplicity.scenegraph.Node;
import com.se.simplicity.vector.TransformationMatrixf;

/**
 * <p>
 * A light within a {@link com.se.simplicity.scenegraph.SceneGraph SceneGraph}.
 * </p>
 * 
 * @author simple
 */
public interface Light
{
	/**
	 * <p>
	 * Applies this <code>Light</code> to the rendering environment.
	 * </p>
	 */
	void apply();

	/**
	 * <p>
	 * Retrieves the ambient component of this <code>Light</code>.
	 * </p>
	 * 
	 * @return The ambient component of this <code>Light</code>.
	 */
	float[] getAmbientLight();

	/**
	 * <p>
	 * Retrieves the diffuse component of this <code>Light</code>.
	 * </p>
	 * 
	 * @return The diffuse component of this <code>Light</code>.
	 */
	float[] getDiffuseLight();

	/**
	 * <p>
	 * Retrieves the lighting mode used to render a {@link com.se.simplicity.scenegraph.SceneGraph SceneGraph}.
	 * </p>
	 * 
	 * @return The lighting mode used to render a {@link com.se.simplicity.scenegraph.SceneGraph SceneGraph}.
	 */
	LightingMode getLightingMode();

	/**
	 * <p>
	 * Retrieves the {@link com.se.simplicity.scenegraph.Node Node} that represents this <code>Light</code>'s location and
	 * orientation.
	 * </p>
	 * 
	 * @return The {@link com.se.simplicity.scenegraph.Node Node} that represents this <code>Light</code>'s location and
	 * orientation.
	 */
	Node getNode();

	/**
	 * <p>
	 * Retrieves the specular component of this <code>Light</code>.
	 * </p>
	 * 
	 * @return The specular component of this <code>Light</code>.
	 */
	float[] getSpecularLight();

	/**
	 * <p>
	 * Retrieves the absolute transformation for the {@link com.se.simplicity.scenegraph.Node Node} of this <code>Light</code>.
	 * </p>
	 * 
	 * @return The absolute transformation for the {@link com.se.simplicity.scenegraph.Node Node} of this <code>Light</code>, or
	 * null if the {@link com.se.simplicity.scenegraph.Node Node} does not exist.
	 */
	TransformationMatrixf getTransformation();

	/**
	 * <p>
	 * Initialises this <code>Light</code>.
	 * </p>
	 */
	void init();

	/**
	 * <p>
	 * Determines the initialisation status of this <code>Light</code>.
	 * </p>
	 * 
	 * @return True if this <code>Light</code> has been initialised, false otherwise.
	 */
	boolean isInitialised();

	/**
	 * <p>
	 * Sets the ambient component of this <code>Light</code>.
	 * </p>
	 * 
	 * @param ambientLight The ambient component of this <code>Light</code>.
	 */
	void setAmbientLight(float[] ambientLight);

	/**
	 * <p>
	 * Sets the diffuse component of this <code>Light</code>.
	 * </p>
	 * 
	 * @param diffuseLight The diffuse component of this <code>Light</code>.
	 */
	void setDiffuseLight(float[] diffuseLight);

	/**
	 * <p>
	 * Sets the initialisation status of this <code>Light</code>.
	 * </p>
	 * 
	 * @param isInitialised The initialisation status of this <code>Light</code>.
	 */
	void setInitialised(boolean isInitialised);

	/**
	 * <p>
	 * Sets the lighting mode used to render a {@link com.se.simplicity.scenegraph.SceneGraph SceneGraph}.
	 * </p>
	 * 
	 * @param lightingMode The lighting mode used to render a {@link com.se.simplicity.scenegraph.SceneGraph SceneGraph}.
	 */
	void setLightingMode(LightingMode lightingMode);

	/**
	 * <p>
	 * Sets the {@link com.se.simplicity.scenegraph.Node Node} that represents this <code>Light</code>'s location and orientation.
	 * </p>
	 * 
	 * @param node The {@link com.se.simplicity.scenegraph.Node Node} that represents this <code>Light</code>'s location and
	 * orientation.
	 */
	void setNode(Node node);

	/**
	 * <p>
	 * Sets the specular component of this <code>Light</code>.
	 * </p>
	 * 
	 * @param specularLight The specular component of this <code>Light</code>.
	 */
	void setSpecularLight(float[] specularLight);
}
