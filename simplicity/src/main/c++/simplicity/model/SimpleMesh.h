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
#ifndef SIMPLEMESH_H_
#define SIMPLEMESH_H_

#include <vector>

#include "Mesh.h"
#include "Vertex.h"

namespace simplicity
{
	/**
	 * <p>
	 * A simple implementation of a mesh. No fancy GPU stuff here.
	 * </p>
	 */
	class SIMPLE_API SimpleMesh : public Mesh
	{
		public:
			/**
			 * <p>
			 * An ID unique to the this model class.
			 * </p>
			 */
			static const unsigned int TYPE_ID = 13;

			SimpleMesh();

			/**
			 * @param indices The indices into the collection of vertices.
			 * @param vertices The collection of vertices.
			 */
			SimpleMesh(const std::vector<unsigned int>& indices, const std::vector<Vertex>& vertices);

			const Vector4& getColor() const;

			unsigned int getIndexCount() const;

			unsigned int* getIndices();

			const unsigned int* getIndices() const;

			Texture* getNormalMap() const;

			PrimitiveType getPrimitiveType() const;

			Texture* getTexture() const;

			unsigned short getTypeID() const;

			unsigned int getVertexCount() const;

			Vertex* getVertices();

			const Vertex* getVertices() const;

			void init();

			bool isVisible() const;

			void resizeIndices(unsigned int size);

			void resizeVertices(unsigned int size);

			void setColor(const Vector4& color);

			void setNormalMap(Texture* texture);

			void setPrimitiveType(PrimitiveType primitiveType);

			void setTexture(Texture* texture);

			void setVisible(bool visible);

		private:
			Vector4 color;

			std::vector<unsigned int> indices;

			static unsigned int nextID;

			PrimitiveType primitiveType;

			std::vector<Vertex> vertices;

			bool visible;
	};
}

#endif /* SIMPLEMESH_H_ */
