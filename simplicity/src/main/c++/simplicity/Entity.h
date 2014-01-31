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
#ifndef ENTITY_H_
#define ENTITY_H_

#include <memory>
#include <string>
#include <vector>

#include "Categories.h"
#include "math/Matrix.h"

namespace simplicity
{
	class Component;

	class Entity
	{
		public:
			Entity(unsigned short category = Categories::UNCATEGORIZED, const std::string& name = std::string());

			/**
			 * <p>
			 * Adds a shared component.
			 * </p>
			 *
			 * @param component The component to add.
			 */
			void addSharedComponent(std::shared_ptr<Component> component);

			/**
			 * <p>
			 * Adds a unique component.
			 * </p>
			 *
			 * @param component The component to add.
			 */
			void addUniqueComponent(std::unique_ptr<Component> component);

			unsigned short getCategory() const;

			/**
			 * <p>
			 * Retrieves a single component.
			 * </p>
			 *
			 * @return The single component.
			 */
			template<typename ComponentType>
			ComponentType* getComponent(unsigned short category = Categories::ALL_CATEGORIES) const;

			/**
			 * <p>
			 * Retrieves the components.
			 * </p>
			 *
			 * @return The components.
			 */
			template<typename ComponentType>
			std::vector<ComponentType*> getComponents(unsigned short category = Categories::ALL_CATEGORIES) const;

			unsigned int getId() const;

			/**
			 * <p>
			 * Retrieves the name of this <code>Entity</code>.
			 * </p>
			 *
			 * @return The name of this <code>Entity</code>.
			 */
			const std::string& getName() const;

			Matrix44& getTransform();

			const Matrix44& getTransform() const;

			/**
			 * <p>
			 * Removes a shared component.
			 * </p>
			 *
			 * @param component The component to remove.
			 */
			std::shared_ptr<Component> removeSharedComponent(Component* component);

			/**
			 * <p>
			 * Removes a unique component.
			 * </p>
			 *
			 * @param component The component to remove.
			 */
			std::unique_ptr<Component> removeUniqueComponent(Component* component);

			void setTransform(const Matrix44& transform);

		private:
			unsigned short category;

			unsigned int id;

			/**
			 * <p>
			 * The name of this <code>Entity</code>.
			 * </p>
			 */
			std::string name;

			static unsigned int nextId;

			/**
			 * <p>
			 * The shared components.
			 * </p>
			 */
			std::vector<std::shared_ptr<Component>> sharedComponents;

			Matrix44 transform;

			/**
			 * <p>
			 * The unique components.
			 * </p>
			 */
			std::vector<std::unique_ptr<Component>> uniqueComponents;
	};
}

#include "Entity.tpp"

#endif /* ENTITY_H_ */
