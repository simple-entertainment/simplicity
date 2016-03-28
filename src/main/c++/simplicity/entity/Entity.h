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

#include "../common/Category.h"
#include "../common/NonCopyable.h"
#include "../math/Matrix.h"
#include "../math/Vector.h"
#include "Component.h"

// STL Instantiations for Export/Import
#if defined(SIMPLE_WINDOWS) && (defined(SIMPLE_SHARED) || defined(SIMPLE_SHARED_EXE))
	SIMPLE_API_TEMPLATE template class SIMPLE_API std::basic_string<char>;
#endif

namespace simplicity
{
	class Scene;

	/**
	 * <p>
	 * An object that can be added to a scene. It is a container for components which describe the way the entity looks
	 * and behaves.
	 * </p>
	 */
	class SIMPLE_API Entity : private NonCopyable
	{
		public:
			/**
			 * @param category The category this entity will belong to (Categories::UNCATEGORIZED is the default).
			 * @param name The name of this entity (an empty name is the default).
			 */
			Entity(unsigned short category = Category::UNCATEGORIZED, const std::string& name = std::string());

			/**
			 * <p>
			 * Adds a component.
			 * </p>
			 *
			 * @param component The component to add.
			 */
			void addComponent(std::unique_ptr<Component> component);

			/**
			 * <p>
			 * Retrieves the category this entity belongs to.
			 * </p>
			 *
			 * @return The category this entity belongs to.
			 */
			unsigned short getCategory() const;

			/**
			 * <p>
			 * Retrieves a single component. If more than one component of the specified type and category exist, the
			 * first one found will be returned.
			 * </p>
			 *
			 * @param category The category of the component to retrieve. If Categories::ALL_CATEGORIES is specified
			 * (the default), a component of any category (including Categories::UNCATEGORIZED) will be accepted.
			 *
			 * @return The single component.
			 */
			template<typename ComponentType = Component>
			ComponentType* getComponent(unsigned short category = Category::ALL_CATEGORIES) const;

			/**
			 * <p>
			 * Retrieves the components.
			 * </p>
			 *
			 * @param category The category of the components to retrieve. If Categories::ALL_CATEGORIES is specified
			 * (the default), components of any category (including Categories::UNCATEGORIZED) will be accepted.
			 *
			 * @return The components.
			 */
			template<typename ComponentType = Component>
			std::vector<ComponentType*> getComponents(unsigned short category = Category::ALL_CATEGORIES) const;

			/**
			 * <p>
			 * Retrieves the unique identifier of this entity.
			 * </p>
			 *
			 * @return The unique identifier of this entity.
			 */
			unsigned int getId() const;

			/**
			 * <p>
			 * Retrieves the name of this entity.
			 * </p>
			 *
			 * @return The name of this entity.
			 */
			const std::string& getName() const;

			Vector3 getPosition() const;

			/**
			 * <p>
			 * Retrieves the scene containing this entity.
			 * </p>
			 *
			 * @return The scene containing this entity.
			 */
			Scene* getScene() const;

			/**
			 * <p>
			 * Retrieves the position and orientation of this entity.
			 * </p>
			 *
			 * <p>
			 * When modifying the transform directly, make sure you call Scene#onTransformEntity() to ensure the changes
			 * are reflected correctly in the scene.
			 * </p>
			 *
			 * @return The position and orientation of this entity.
			 */
			Matrix44& getTransform();

			/**
			 * <p>
			 * Retrieves the position and orientation of this entity.
			 * </p>
			 *
			 * @return The position and orientation of this entity.
			 */
			const Matrix44& getTransform() const;

			Vector3 getUp3() const;

			Vector4 getUp4() const;

			/**
			 * <p>
			 * Removes a component.
			 * </p>
			 *
			 * @param component The component to remove.
			 *
			 * @return The removed component.
			 */
			std::unique_ptr<Component> removeComponent(Component& component);

			void rotate(float angle, const Vector3& axis);

			void scale(const Vector3& scale);

			void setPosition(const Vector3& position);

			/**
			 * <p>
			 * Sets the scene containing this entity.
			 * </p>
			 *
			 * @param scene The scene containing this entity.
			 */
			void setScene(Scene* scene);

			/**
			 * <p>
			 * Sets the position and orientation of this entity.
			 * </p>
			 *
			 * @param transform The position and orientation of this entity.
			 */
			void setTransform(const Matrix44& transform);

			void translate(const Vector3& translation);

		private:
			unsigned short category;

			std::vector<std::unique_ptr<Component>> components;

			unsigned int id;

			std::string name;

			static unsigned int nextId;

			Scene* scene;

			Matrix44 transform;
	};
}

#include "Entity.tpp"

#endif /* ENTITY_H_ */
