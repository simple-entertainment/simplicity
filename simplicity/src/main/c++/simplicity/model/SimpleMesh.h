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

			const Vector4& getColor() const override;

			unsigned int getIndexCount() const override;

			unsigned int* getIndices() override;

			const unsigned int* getIndices() const override;

			Texture* getNormalMap() const override;

			PrimitiveType getPrimitiveType() const override;

			Texture* getTexture() const override;

			unsigned short getTypeID() const override;

			unsigned int getVertexCount() const override;

			Vertex* getVertices() override;

			const Vertex* getVertices() const override;

			void init() override;

			bool isVisible() const override;

			void resizeIndices(unsigned int size) override;

			void resizeVertices(unsigned int size) override;

			void setColor(const Vector4& color) override;

			void setNormalMap(Texture* texture) override;

			void setPrimitiveType(PrimitiveType primitiveType) override;

			void setTexture(Texture* texture) override;

			void setVisible(bool visible) override;

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
