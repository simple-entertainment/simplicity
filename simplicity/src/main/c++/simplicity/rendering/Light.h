/*
 * Copyright © 2012 Simple Entertainment Limited
 *
 * This file is part of The Simplicity Engine.
 *
 * The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General
 * Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option)
 * any later version.
 *
 * The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the
 * implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more
 * details.
 *
 * You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see
 * <http://www.gnu.org/licenses/>.
 */
#ifndef LIGHT_H_
#define LIGHT_H_

#include <vector>

#include "../graph/TreeNode.h"
#include "../math/ColourVector.h"
#include "../math/TransformationMatrix.h"

namespace simplicity
{
	/**
	 * <p>
	 * A light within a {@link simplicity::Scene Scene}.
	 * </p>
	 *
	 * @author Gary Buyn
	 */
	class Light
	{
		public:
			/**
			 * <p>
			 * The lighting mode used to render a {@link simplicity::Scene Scene}. The modes are as follows:
			 * </p>
			 *
			 * @author Gary Buyn
			 */
			enum LightingMode
			{
				/**
				 * <p>
				 * Renders the models with shading determined by the Lights within the Scene.
				 * </p>
				 */
				SCENE,

				/**
				 * <p>
				 * Renders the models with simple shading. Lights to create the shading effects are added by the Scene
				 * and are implementation specific.
				 * </p>
				 */
				SHADED,

				/**
				 * <p>
				 * Renders the models with solid shading. Lights to create the shading effects are added by the Scene
				 * and are implementation specific.
				 * </p>
				 */
				SOLID
			};

			/**
			 * <p>
			 * Disposes of an instance of <code>Light</code> (included to allow polymorphic deletion).
			 * </p>
			 */
			virtual ~Light()
			{
			}

			/**
			 * <p>
			 * Applies this <code>Light</code> to the rendering environment.
			 * </p>
			 */
			virtual void apply() = 0;

			/**
			 * <p>
			 * Retrieves the ambient component of this <code>Light</code>.
			 * </p>
			 *
			 * @return The ambient component of this <code>Light</code>.
			 */
			virtual ColourVector<>& getAmbientLight() const = 0;

			/**
			 * <p>
			 * Retrieves the diffuse component of this <code>Light</code>.
			 * </p>
			 *
			 * @return The diffuse component of this <code>Light</code>.
			 */
			virtual ColourVector<>& getDiffuseLight() const = 0;

			/**
			 * <p>
			 * Retrieves the lighting mode used to render a {@link simplicity::Scene Scene}.
			 * </p>
			 *
			 * @return The lighting mode used to render a <code>Scene</code>.
			 */
			virtual LightingMode getLightingMode() const = 0;

			/**
			 * <p>
			 * Retrieves the {@link simplicity::Node Node} that represents this <code>Light</code>'s location and
			 * orientation.
			 * </p>
			 *
			 * @return The <code>Node</code> that represents this <code>Light</code>'s location and orientation.
			 */
			virtual TreeNode* getNode() const = 0;

			/**
			 * <p>
			 * Retrieves the specular component of this <code>Light</code>.
			 * </p>
			 *
			 * @return The specular component of this <code>Light</code>.
			 */
			virtual ColourVector<>& getSpecularLight() const = 0;

			/**
			 * <p>
			 * Retrieves the inverted absolute transformation for the {@link simplicity::Node Node} of this
			 * <code>Light</code>.
			 * </p>
			 *
			 * @return The inverted absolute transformation for the <code>Node</code> of this <code>Light</code>, or a
			 * zero vector if the <code>Node</code> does not exist.
			 */
			virtual const TransformationMatrix<>& getTransformation() const = 0;

			/**
			 * <p>
			 * Initialises this <code>Light</code>.
			 * </p>
			 */
			virtual void init() = 0;

			/**
			 * <p>
			 * Determines the initialisation status of this <code>Light</code>.
			 * </p>
			 *
			 * @return True if this <code>Light</code> has been initialised, false otherwise.
			 */
			virtual bool isInitialised() const = 0;

			/**
			 * <p>
			 * Sets the ambient component of this <code>Light</code>.
			 * </p>
			 *
			 * @param ambientLight The ambient component of this <code>Light</code>.
			 */
			virtual void setAmbientLight(std::unique_ptr<ColourVector<> > ambientLight) = 0;

			/**
			 * <p>
			 * Sets the diffuse component of this <code>Light</code>.
			 * </p>
			 *
			 * @param diffuseLight The diffuse component of this <code>Light</code>.
			 */
			virtual void setDiffuseLight(std::unique_ptr<ColourVector<> > diffuseLight) = 0;

			/**
			 * <p>
			 * Sets the initialisation status of this <code>Light</code>.
			 * </p>
			 *
			 * @param isInitialised The initialisation status of this <code>Light</code>.
			 */
			virtual void setInitialised(const bool isInitialised) = 0;

			/**
			 * <p>
			 * Sets the lighting mode used to render a {@link simplicity::Scene Scene}.
			 * </p>
			 *
			 * @param lightingMode The lighting mode used to render a <code>Scene</code>.
			 */
			virtual void setLightingMode(const LightingMode lightingMode) = 0;

			/**
			 * <p>
			 * Sets the {@link simplicity::Node Node} that represents this <code>Light</code>'s location and
			 * orientation.
			 * </p>
			 *
			 * @param node The <code>Node</code> that represents this <code>Light</code>'s location and orientation.
			 */
			virtual void setNode(TreeNode* node) = 0;

			/**
			 * <p>
			 * Sets the specular component of this <code>Light</code>.
			 * </p>
			 *
			 * @param specularLight The specular component of this <code>Light</code>.
			 */
			virtual void setSpecularLight(std::unique_ptr<ColourVector<> > specularLight) = 0;
	};
}

#endif /* LIGHT_H_ */
