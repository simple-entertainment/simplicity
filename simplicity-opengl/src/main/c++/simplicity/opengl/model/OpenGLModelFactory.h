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
#ifndef OPENGLMODELFACTORY_H_
#define OPENGLMODELFACTORY_H_

#include <simplicity/model/ModelFactory.h>

namespace simplicity
{
	namespace opengl
	{
		class OpenGLModelFactory : public ModelFactory
		{
			public:
				std::unique_ptr<Capsule> createCapsule() const;

				std::unique_ptr<Cylinder> createCylinder() const;

				std::unique_ptr<Sphere> createSphere() const;

				std::unique_ptr<Torus> createTorus() const;

				std::unique_ptr<IndexedVertexGroup> createIndexedVertexGroup() const;

				std::unique_ptr<Text> createText() const;

				std::unique_ptr<VertexGroup> createVertexGroup() const;
		};
	}
}

#endif /* OPENGLMODELFACTORY_H_ */
