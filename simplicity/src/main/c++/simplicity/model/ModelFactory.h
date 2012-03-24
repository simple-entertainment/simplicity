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
#ifndef MODELFACTORY_H_
#define MODELFACTORY_H_

#include "shape/Capsule.h"
#include "shape/Cylinder.h"
#include "shape/Sphere.h"
#include "shape/Torus.h"
#include "IndexedVertexGroup.h"
#include "Text.h"
#include "VertexGroup.h"

namespace simplicity
{
	class ModelFactory
	{
		public:
			static const ModelFactory& getInstance();

			static void setInstance(std::unique_ptr<ModelFactory> instance);

			virtual ~ModelFactory();

			virtual std::unique_ptr<Capsule> createCapsule() const = 0;

			virtual std::unique_ptr<Cylinder> createCylinder() const = 0;

			virtual std::unique_ptr<Sphere> createSphere() const = 0;

			virtual std::unique_ptr<Torus> createTorus() const = 0;

			virtual std::unique_ptr<IndexedVertexGroup> createIndexedVertexGroup() const = 0;

			virtual std::unique_ptr<Text> createText() const = 0;

			virtual std::unique_ptr<VertexGroup> createVertexGroup() const = 0;

		private:
			static std::unique_ptr<ModelFactory> instance;
	};
}

#endif /* MODELFACTORY_H_ */
