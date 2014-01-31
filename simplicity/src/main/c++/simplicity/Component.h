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
#ifndef COMPONENT_H_
#define COMPONENT_H_

#include "math/Matrix.h"

namespace simplicity
{
	class Entity;

	class Component
	{
		public:
			Component();

			virtual ~Component();

			unsigned short getCategory() const;

			Entity* getEntity();

			const Entity* getEntity() const;

			Matrix44& getTransform();

			const Matrix44& getTransform() const;

			void setCategory(unsigned short category);

			void setEntity(Entity* entity);

			void setTransform(const Matrix44& transform);

		private:
			unsigned short category;

			Entity* entity;

			Matrix44 transform; // TODO review! Is this a good idea?
	};
}

#endif /* COMPONENT_H_ */
