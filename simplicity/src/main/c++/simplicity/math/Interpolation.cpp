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
#include "Interpolation.h"

using namespace std;

namespace simplicity
{
	namespace Interpolation
	{
		float getLength(vector<Vector3>::const_iterator begin, vector<Vector3>::const_iterator end);

		float getLength(vector<Vector3>::const_iterator begin, vector<Vector3>::const_iterator end)
		{
			float length = 0.0f;

			while (begin + 1 < end)
			{
				Vector3 segment = *begin - *(begin + 1);
				length += segment.getMagnitude();
				begin++;
			}

			return length;
		}

		vector<Vector3> interpolateBezier(const vector<Vector3>& points, unsigned int interpolationCount)
		{
			vector<Vector3> interpolatedPoints;
			interpolatedPoints.reserve(interpolationCount);

			for (unsigned int interpolationIndex = 0; interpolationIndex < interpolationCount;
				interpolationIndex++)
			{
				float time = (float) interpolationIndex / (interpolationCount - 1);
				interpolatedPoints.push_back(interpolateBezier(points.begin(), points.end(), time));
			}

			return interpolatedPoints;
		}

		Vector3 interpolateBezier(const vector<Vector3>::const_iterator& begin,
			const vector<Vector3>::const_iterator& end, float time)
		{
			if (begin + 1 == end)
			{
				return *begin;
			}

			Vector3 p0 = interpolateBezier(begin, end - 1, time);
			p0 *= 1 - time;

			Vector3 p1 = interpolateBezier(begin + 1, end, time);
			p1 *= time;

			p0 += p1;

			return p0;
		}

		Vertex interpolateLinear(const vector<Vertex>& vertices, const Vector3& position)
		{
			/*float distanceFromA = (position - vertexA.position).getMagnitude();
			float distanceFromB = (position - vertexB.position).getMagnitude();
			float distanceFromC = (position - vertexC.position).getMagnitude();
			float distanceSum = distanceFromA + distanceFromB + distanceFromC;
			float influenceA = 1.0f - (distanceFromA / distanceSum);
			float influenceB = 1.0f - (distanceFromB / distanceSum);
			float influenceC = 1.0f - (distanceFromC / distanceSum);

			Vertex vertex;
			vertex.color = vertexA.color * influenceA +
					vertexB.color * influenceB +
					vertexC.color * influenceC;
			vertex.normal = vertexA.normal * influenceA +
					vertexB.normal * influenceB +
					vertexC.normal * influenceC;
			vertex.position = position;
			vertex.texCoord = vertexA.texCoord * influenceA +
					vertexB.texCoord * influenceB +
					vertexC.texCoord * influenceC;

			return vertex;*/
			return Vertex();
		}
	}
}
