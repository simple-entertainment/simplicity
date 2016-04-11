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
#ifndef PHYSICSFACTORY_H_
#define PHYSICSFACTORY_H_

#include <memory>

#include "../model/Mesh.h"
#include "Body.h"

namespace simplicity
{
	/**
	 * <p>
	 * A factory that creates physical bodies.
	 * </p>
	 */
	class SIMPLE_API PhysicsFactory
	{
		public:
			/**
			 * <p>
			 * Allows polymorphism.
			 * </p>
			 */
			virtual ~PhysicsFactory()
			{
			}

			/**
			 * <p>
			 * Creates a physical body.
			 * </p>
			 *
			 * @param material The material to construct the body from.
			 * @param mesh The geometry of the body.
			 * @param bounds a bounding volume containing the body.
			 * @param transform The position and orientation of the body.
			 * @param dynamic Dynamic or static?
			 *
			 * @return A physical body.
			 */
			static std::unique_ptr<Body> createBody(const Body::Material& material, const Mesh& mesh,
													const Shape& bounds, const Matrix44& transform,
													bool dynamic = true);

			/**
			 * <p>
			 * Sets the concrete factory instance used to create the physical bodies.
			 * </p>
			 *
			 * @param instance The concrete factory instance.
			 */
			static void setInstance(std::unique_ptr<PhysicsFactory> instance);

		private:
			static std::unique_ptr<PhysicsFactory> instance;

			virtual std::unique_ptr<Body> createBodyInternal(const Body::Material& material, const Mesh& mesh,
															 const Shape& bounds, const Matrix44& transform,
															 bool dynamic = true) = 0;
	};
}

#endif /* PHYSICSFACTORY_H_ */
