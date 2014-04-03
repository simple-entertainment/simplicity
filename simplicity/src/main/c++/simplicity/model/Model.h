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
#ifndef MODEL_H_
#define MODEL_H_

#include "../entity/Component.h"
#include "../math/Vector.h"
#include "../rendering/Renderer.h"
#include "../rendering/Texture.h"

namespace simplicity
{
	/**
	 * <p>
	 * A representation of 2D or 3D geometry.
	 * </p>
	 */
	class SIMPLE_API Model : public Component
	{
		public:
			/**
			 * <p>
			 * The type of primitive a model is constructed from.
			 * </p>
			 */
			enum PrimitiveType
			{
				/**
				 * <p>
				 * A list of lines.
				 * </p>
				 */
				LINE_LIST,

				/**
				 * <p>
				 * A strip of lines.
				 * </p>
				 */
				LINE_STRIP,

				/**
				 * <p>
				 * The model is not constructed from primitives.
				 * </p>
				 */
				NA,

				/**
				 * <p>
				 * A list of points.
				 * </p>
				 */
				POINTS,

				/**
				 * <p>
				 * A list of triangles.
				 * </p>
				 */
				TRIANGLE_LIST,

				/**
				 * <p>
				 * A strip of triangles.
				 * </p>
				 */
				TRIANGLE_STRIP
			};

			Model();

			/**
			 * <p>
			 * Allows polymorphism.
			 * </p>
			 */
			virtual ~Model()
			{
			}

			/**
			 * <p>
			 * Retrieves the color of this model.
			 * </p>
			 *
			 * @return The color of this model.
			 */
			virtual const Vector4& getColor() const = 0;

			/**
			 * <p>
			 * Retrieves the normal map applied to this model.
			 * </p>
			 *
			 * @return The normal map applied to this model.
			 */
			virtual Texture* getNormalMap() const = 0;

			/**
			 * <p>
			 * Retrieves the type of primitive this model is constructed from.
			 * </p>
			 *
			 * @return The type of primitive this model is constructed from.
			 */
			virtual PrimitiveType getPrimitiveType() const = 0;

			/**
			 * <p>
			 * Retrieves the texture applied to this model.
			 * </p>
			 *
			 * @return The texture applied to this model.
			 */
			virtual Texture* getTexture() const = 0;

			/**
			 * <p>
			 * Determines if this model is visible.
			 * </p>
			 *
			 * @return True if this model is visible, false otherwise.
			 */
			virtual bool isVisible() const = 0;

			/**
			 * <p>
			 * Renders this model using the specified renderer. This is provided to allow double-dispatch so that the
			 * type of the model is known to the renderer.
			 * </p>
			 *
			 * @param renderer The renderer.
			 */
			virtual void render(Renderer& renderer) const = 0;

			/**
			 * <p>
			 * Sets the color of this model.
			 * </p>
			 *
			 * @param color The color of this model.
			 */
			virtual void setColor(const Vector4& color) = 0;

			/**
			 * <p>
			 * Sets the normal map applied to this model.
			 * </p>
			 *
			 * @param normalMap The normal map applied to this model.
			 */
			virtual void setNormalMap(Texture* normalMap) = 0;

			/**
			 * <p>
			 * Sets the type of primitive this model is constructed from.
			 * </p>
			 *
			 * @param primitiveType The type of primitive this model is constructed from.
			 */
			virtual void setPrimitiveType(PrimitiveType primitiveType) = 0;

			/**
			 * <p>
			 * Sets the texture applied to this model.
			 * </p>
			 *
			 * @param texture The texture applied to this model.
			 */
			virtual void setTexture(Texture* texture) = 0;

			/**
			 * <p>
			 * Sets if this model is visible.
			 * </p>
			 *
			 * @param visible The visibility of the model.
			 */
			virtual void setVisible(bool visible) = 0;
	};
}

#endif /* MODEL_H_ */
