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

#include "../math/Matrix.h"

namespace simplicity
{
	class Entity;

	/**
	 * <p>
	 * An object that can be added to an entity. Components describe the way an entity looks and behaves.
	 * </p>
	 */
	class SIMPLE_API Component
	{
		public:
			Component();

			/**
			 * <p>
			 * Allows polymorphism.
			 * </p>
			 */
			virtual ~Component()
			{
			}

			/**
			 * <p>
			 * Retrieves the category this component belongs to.
			 * </p>
			 *
			 * @return The category this component belongs to.
			 */
			unsigned short getCategory() const;

			/**
			 * <p>
			 * Retrieves the entity this component is part of.
			 * </p>
			 *
			 * @return The entity this component is part of.
			 */
			Entity* getEntity() const;

			/**
			 * <p>
			 * Retrieves the position and orientation of this component relative to the entity (or entities) to which
			 * it is attached.
			 * </p>
			 *
			 * @return The position and orientation of this component.
			 */
			Matrix44& getTransform();

			/**
			 * <p>
			 * Retrieves the position and orientation of this component relative to the entity (or entities) to which
			 * it is attached.
			 * </p>
			 *
			 * @return The position and orientation of this component.
			 */
			const Matrix44& getTransform() const;

			/**
			 * <p>
			 * Sets the category this component belongs to (Categories::UNCATEGORIZED is the default).
			 * </p>
			 *
			 * @param category The category this component belongs to.
			 */
			void setCategory(unsigned short category);

			/**
			 * <p>
			 * Sets the entity this component is part of.
			 * </p>
			 *
			 * @param entity The entity this component is part of.
			 */
			void setEntity(Entity* entity);

			/**
			 * <p>
			 * Sets the position and orientation of this component relative to the entity (or entities) to which it is
			 * attached.
			 * </p>
			 *
			 * @param transform The position and orientation of this component.
			 */
			void setTransform(const Matrix44& transform);

		private:
			unsigned short category;

			Entity* entity;

			Matrix44 transform; // TODO review! Is this a good idea?
	};
}

#endif /* COMPONENT_H_ */
