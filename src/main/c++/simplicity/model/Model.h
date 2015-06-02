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
			 * User defined type IDs should start with this ID.
			 * </p>
			 *
			 * <p>
			 * For example:
			 * </p>
			 *
			 * <pre><code>
			 * static const unsigned short TYPE_ID = USER_ID_0;
			 * ...
			 * static const unsigned short TYPE_ID = USER_ID_0 + 1;
			 * </code></pre>
			 */
			static const unsigned short USER_TYPE_ID_0 = 128;

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
			 * Retrieves the texture applied to this model.
			 * </p>
			 *
			 * @return The texture applied to this model.
			 */
			virtual Texture* getTexture() const = 0;

			/**
			 * <p>
			 * Retrieves an ID unique to the class this model is an instance of. This is part of the ID member +
			 * static_cast pattern for faster 'dynamic' casting.
			 * </p>
			 *
			 * <p>
			 * Instead of this:
			 * </p>
			 *
			 * <pre>
			 * <code>
			 * Model* model = // some model...
			 * Square* square = dynamic_cast<Square*>(model);
			 * if (square != nullptr)
			 * {
			 *     // do stuff...
			 * }
			 * </code>
			 * </pre>
			 *
			 * <p>
			 * You can do this to avoid the expensive dynamic_cast operation:
			 * </p>
			 *
			 * <pre>
			 * <code>
			 * Model* model = // some model...
			 * if (model->getTypeID() == Square::TYPE_ID)
			 * {
			 *     Square* square = static_cast<Square*>(model);
			 *     // do stuff...
			 * }
			 * </code>
			 * </pre>
			 *
			 * <p>
			 * Each model implementation should provide a public static TYPE_ID member whose value is returned by this
			 * function.
			 * </p>
			 *
			 * @return An ID unique to the class this model is an instance of.
			 */
			virtual unsigned short getTypeID() const = 0;

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
			 * Sets the color of this model.
			 * </p>
			 *
			 * @param color The color of this model.
			 */
			virtual void setColor(const Vector4& color) = 0;

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
