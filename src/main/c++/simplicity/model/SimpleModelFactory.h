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
#ifndef SIMPLEMODELFACTORY_H_
#define SIMPLEMODELFACTORY_H_

#include "ModelFactory.h"

namespace simplicity
{
	/**
	 * <p>
	 * An ModelFactory implementation that uses the SimpleMeshBuffer.
	 * </p>
	 */
	class SIMPLE_API SimpleModelFactory : public ModelFactory
	{
		public:
			std::shared_ptr<MeshBuffer> createMeshBufferInternal(unsigned int vertexCount,
																 unsigned int indexCount,
																 Buffer::AccessHint accessHint) override;
	};
}

#endif /* SIMPLEMODELFACTORY_H_ */
