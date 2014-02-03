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

#include "../Component.h"
#include "../math/Vector.h"
#include "../rendering/Renderer.h"
#include "../rendering/Texture.h"

namespace simplicity
{
	class Model : public Component
	{
		public:
			enum PrimitiveType
			{
				LINE_LIST,
				LINE_STRIP,
				NA,
				POINTS,
				TRIANGLE_LIST,
				TRIANGLE_STRIP
			};

			Model();

			virtual ~Model()
			{
			}

			virtual const Vector4& getColor() const = 0;

			virtual Texture* getNormalMap() const = 0;

			virtual PrimitiveType getPrimitiveType() const = 0;

			virtual Texture* getTexture() const = 0;

			virtual bool isVisible() const = 0;

			virtual void render(Renderer& renderer) const = 0;

			virtual void setColor(const Vector4& color) = 0;

			virtual void setNormalMap(Texture* texture) = 0;

			virtual void setPrimitiveType(PrimitiveType primitiveType) = 0;

			virtual void setTexture(Texture* texture) = 0;

			virtual void setVisible(bool visible) = 0;
	};
}

#endif /* MODEL_H_ */
