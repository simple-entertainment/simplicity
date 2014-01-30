/*
 * Copyright © 2014 Simple Entertainment Limited
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
#ifndef POINT_H_
#define POINT_H_

#include "Model.h"

namespace simplicity
{
	class Point : public Model
	{
		public:
			Point(const Vector3& point);

			const Vector4& getColour() const;

			Texture* getNormalMap() const;

			const Vector3& getPoint() const;

			PrimitiveType getPrimitiveType() const;

			Texture* getTexture() const;

			bool isVisible() const;

			void render(Renderer& renderer) const;

			void setColour(const Vector4& color);

			void setNormalMap(Texture* texture);

			void setPoint(const Vector3& point);

			void setPrimitiveType(PrimitiveType primitiveType);

			void setTexture(Texture* texture);

			void setVisible(bool visible);

		private:
			Vector4 colour;

			Vector3 point;

			bool visible;
	};
}

#endif /* POINT_H_ */