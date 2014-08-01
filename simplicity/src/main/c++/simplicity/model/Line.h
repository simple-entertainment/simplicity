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
	/**
	 * <p>
	 * A line between two points, A and B.
	 * </p>
	 */
	class SIMPLE_API Line : public Model
	{
		public:
			/**
			 * <p>
			 * An ID unique to the this model class.
			 * </p>
			 */
			static const unsigned int TYPE_ID = 0;

			/**
			 * @param pointA The point the line begins at.
			 * @param pointB The point the line ends at.
			 */
			Line(const Vector3& pointA, const Vector3& pointB);

			const Vector4& getColor() const override;

			Texture* getNormalMap() const override;

			/**
			 * <p>
			 * Retrieves the point the line begins at.
			 * </p>
			 *
			 * @return The point the line begins at.
			 */
			const Vector3& getPointA() const;

			/**
			 * <p>
			 * Retrieves the point the line ends at.
			 * </p>
			 *
			 * @return The point the line ends at.
			 */
			const Vector3& getPointB() const;

			Texture* getTexture() const override;

			unsigned short getTypeID() const override;

			bool isVisible() const override;

			void setColor(const Vector4& color) override;

			void setNormalMap(Texture* texture) override;

			/**
			 * <p>
			 * Sets the point the line begins at.
			 * </p>
			 *
			 * @param pointA The point the line begins at.
			 */
			void setPointA(const Vector3& pointA);

			/**
			 * <p>
			 * Sets the point the line ends at.
			 * </p>
			 *
			 * @param pointB The point the line ends at.
			 */
			void setPointB(const Vector3& pointB);

			void setTexture(Texture* texture) override;

			void setVisible(bool visible) override;

		private:
			Vector4 color;

			Vector3 pointA;

			Vector3 pointB;

			bool visible;
	};
}

#endif /* LINE_H_ */
