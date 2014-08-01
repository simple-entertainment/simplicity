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
#ifndef SHAPE_H_
#define SHAPE_H_

#include "../Model.h"

namespace simplicity
{
	/**
	 * <p>
	 * A basic geometric shape that is not constructed from primitives like a mesh is. It has a level of detail which
	 * is a hint used by renderers etc. when they convert them to meshes.
	 * </p>
	 */
	class SIMPLE_API Shape : public Model
	{
		public:
			Shape();

			const Vector4& getColor() const override;

			/**
			 * <p>
			 * Retrieves the level of detail applied to this shape.
			 * </p>
			 *
			 * @return The level of detail applied to this shape.
			 */
			unsigned int getLevelOfDetail() const;

			Texture* getNormalMap() const override;

			Texture* getTexture() const override;

			bool isVisible() const override;

			void setColor(const Vector4& color) override;

			/**
			 * <p>
			 * Applies a level of detail to this shape.
			 * </p>
			 *
			 * @return The level of detail applied to this shape.
			 */
			void setLevelOfDetail(unsigned int levelOfDetail);

			void setNormalMap(Texture* texture) override;

			void setTexture(Texture* texture) override;

			void setVisible(bool visible) override;

		private:
			Vector4 color;

			unsigned int levelOfDetail;

			bool visible;
	};
}

#endif /* SHAPE_H_ */
