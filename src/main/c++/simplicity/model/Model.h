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

#include <memory>

#include "../entity/Component.h"
#include "../rendering/Texture.h"
#include "Mesh.h"

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
			Model();

			Mesh* getMesh() const;

			/**
			 * <p>
			 * Retrieves the texture applied to this model.
			 * </p>
			 *
			 * @return The texture applied to this model.
			 */
			Texture* getTexture() const;

			/**
			 * <p>
			 * Determines if this model is visible.
			 * </p>
			 *
			 * @return True if this model is visible, false otherwise.
			 */
			bool isVisible() const;

			void setMesh(std::shared_ptr<Mesh> mesh);

			/**
			 * <p>
			 * Sets the texture applied to this model.
			 * </p>
			 *
			 * @param texture The texture applied to this model.
			 */
			void setTexture(std::shared_ptr<Texture> texture);

			/**
			 * <p>
			 * Sets if this model is visible.
			 * </p>
			 *
			 * @param visible The visibility of the model.
			 */
			void setVisible(bool visible);

		private:
			std::shared_ptr<Mesh> mesh;

			std::shared_ptr<Texture> texture;

			bool visible;
	};
}

#endif /* MODEL_H_ */
