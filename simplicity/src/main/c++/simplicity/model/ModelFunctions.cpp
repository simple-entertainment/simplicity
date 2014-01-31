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
#include "../Categories.h"
#include "../math/MathFunctions.h"
#include "ModelFunctions.h"

namespace simplicity
{
	namespace ModelFunctions
	{
		void colorizeVertices(vector<Vertex>& vertices, const Vector4& color)
		{
			for (Vertex& vertex : vertices)
			{
				vertex.color = color;
			}
		}

		unique_ptr<Circle> getCircleBoundsXZ(const std::vector<Vertex>& vertices)
		{
			Vector3 center(0.0f, 0.0f, 0.0f);
			float maxMagnitudeSquared = 0.0f;

			for (const Vertex& vertex : vertices)
			{
				center += vertex.position;
			}
			center /= vertices.size();

			for (const Vertex& vertex : vertices)
			{
				float magnitudeSquared = (vertex.position - center).getMagnitudeSquared();
				if (magnitudeSquared > maxMagnitudeSquared)
				{
					maxMagnitudeSquared = magnitudeSquared;
				}
			}

			unique_ptr<Circle> bounds(new Circle(sqrt(maxMagnitudeSquared)));
			bounds->setCategory(Categories::BOUNDS);
			setPosition(bounds->getTransform(), Vector3(center.X(), 0.0f, center.Z()));

			return move(bounds);
		}

		unique_ptr<Square> getSquareBoundsXZ(const std::vector<Vertex>& vertices)
		{
			float minX = 1000000.0f;
			float maxX = -1000000.0f;
			float minZ = 1000000.0f;
			float maxZ = -1000000.0f;

			for (const Vertex& vertex : vertices)
			{
				if (vertex.position.X() < minX)
				{
					minX = vertex.position.X();
				}
				if (vertex.position.X() > maxX)
				{
					maxX = vertex.position.X();
				}
				if (vertex.position.Z() < minZ)
				{
					minZ = vertex.position.Z();
				}
				if (vertex.position.Z() > maxZ)
				{
					maxZ = vertex.position.Z();
				}
			}

			float halfRangeX = (maxX - minX) / 2.0f;
			float centerX = maxX - halfRangeX;
			float halfRangeZ = (maxZ - minZ) / 2.0f;
			float centerZ = maxZ - halfRangeZ;

			unique_ptr<Square> bounds(new Square(max(halfRangeX, halfRangeZ)));
			bounds->setCategory(Categories::BOUNDS);
			setPosition(bounds->getTransform(), Vector3(centerX, 0.0f, centerZ));

			return move(bounds);
		}

		void scaleVertices(vector<Vertex>& vertices, float scale)
		{
			for (Vertex& vertex : vertices)
			{
				vertex.position *= scale;
			}
		}

		void translateVertices(vector<Vertex>& vertices, const Vector3& translation)
		{
			for (Vertex& vertex : vertices)
			{
				vertex.position += translation;
			}
		}
	}
}
