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

#include "Body.h"

namespace simplicity
{
	class PhysicsFactory
	{
		public:
			virtual ~PhysicsFactory()
			{
			}

			virtual std::unique_ptr<Body> createBody(const Body::Material& material, Model* model,
					const Matrix44& transform, bool dynamic = true) = 0;

			static PhysicsFactory& getInstance();

			static void setInstance(std::unique_ptr<PhysicsFactory> instance);

		private:
			static std::unique_ptr<PhysicsFactory> instance;
	};
}

#endif /* PHYSICSFACTORY_H_ */
