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
#ifndef LINE_H_
#define LINE_H_

#include "Model.h"

namespace simplicity
{
	template<unsigned int Dimensions>
	class Line : public Model
	{
		public:
			Line(const Vector<float, Dimensions>& pointA, const Vector<float, Dimensions>& pointB);

			const Vector4& getColour() const;

			Texture* getNormalMap() const;

			const Vector<float, Dimensions>& getPointA() const;

			const Vector<float, Dimensions>& getPointB() const;

			PrimitiveType getPrimitiveType() const;

			Texture* getTexture() const;

			bool isVisible() const;

			void render(Renderer& renderer) const;

			void setColour(const Vector4& color);

			void setNormalMap(Texture* texture);

			void setPointA(const Vector<float, Dimensions>& pointA);

			void setPointB(const Vector<float, Dimensions>& pointB);

			void setPrimitiveType(PrimitiveType primitiveType);

			void setTexture(Texture* texture);

			void setVisible(bool visible);

		private:
			Vector4 colour;

			Vector<float, Dimensions> pointA;

			Vector<float, Dimensions> pointB;

			bool visible;
	};

	typedef Line<2> Line2;

	typedef Line<3> Line3;
}

#include "Line.tpp"

#endif /* LINE_H_ */
