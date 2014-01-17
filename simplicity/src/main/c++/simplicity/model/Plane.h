/*
 * Copyright © 2013 Simple Entertainment Limited
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
#ifndef PLANE_H_
#define PLANE_H_

#include "Model.h"

namespace simplicity
{
	class Plane : public Model
	{
		public:
			Plane(const Vector3& normal, const Vector3& positionOnPlane);

			const Vector3& getNormal() const;

			Texture* getNormalMap() const;

			const Vector3& getPositionOnPlane() const;

			PrimitiveType getPrimitiveType() const;

			Texture* getTexture() const;

			bool isVisible() const;

			void render(Renderer& renderer) const;

			void setNormal(const Vector3& normal);

			void setNormalMap(Texture* texture);

			void setPositionOnPlane(const Vector3& positionOnPlane);

			void setTexture(Texture* texture);

			void setVisible(bool visible);

		private:
			Vector3 normal;

			Vector3 positionOnPlane;

			bool visible;
	};
}

#endif /* PLANE_H_ */
