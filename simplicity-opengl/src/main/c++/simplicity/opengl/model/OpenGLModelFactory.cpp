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
#include <simplicity/model/SimpleIndexedVertexGroup.h>
#include <simplicity/model/SimpleVertexGroup.h>

#include "OpenGLModelFactory.h"
#include "shape/GLUCapsule.h"
#include "shape/GLUCylinder.h"
#include "shape/GLUSphere.h"
#include "shape/GLUTorus.h"
#include "OpenGLText.h"

using namespace std;

namespace simplicity
{
	namespace opengl
	{
		unique_ptr<Capsule> OpenGLModelFactory::createCapsule() const
		{
			return unique_ptr < Capsule > (new GLUCapsule);
		}

		unique_ptr<Cylinder> OpenGLModelFactory::createCylinder() const
		{
			return unique_ptr < Cylinder > (new GLUCylinder);
		}

		unique_ptr<Sphere> OpenGLModelFactory::createSphere() const
		{
			return unique_ptr < Sphere > (new GLUSphere);
		}

		unique_ptr<Torus> OpenGLModelFactory::createTorus() const
		{
			return unique_ptr < Torus > (new GLUTorus);
		}

		unique_ptr<IndexedVertexGroup> OpenGLModelFactory::createIndexedVertexGroup() const
		{
			return unique_ptr < IndexedVertexGroup > (new SimpleIndexedVertexGroup);
		}

		unique_ptr<Text> OpenGLModelFactory::createText() const
		{
			return unique_ptr < Text > (new OpenGLText);
		}

		unique_ptr<VertexGroup> OpenGLModelFactory::createVertexGroup() const
		{
			return unique_ptr < VertexGroup > (new SimpleVertexGroup);
		}
	}
}
