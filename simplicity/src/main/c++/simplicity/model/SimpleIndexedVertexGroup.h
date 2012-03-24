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
#ifndef SIMPLEINDEXEDVERTEXGROUP_H_
#define SIMPLEINDEXEDVERTEXGROUP_H_

#include <vector>

#include "../math/TranslationVector.h"
#include "BaseModel.h"
#include "IndexedVertexGroup.h"

namespace simplicity
{
	/**
	 * <p>
	 * A {@link simplicity::VertexGroup VertexGroup} that contains its vertices in indexed vectors.
	 * </p>
	 *
	 * <p>
	 * Three separate vectors are used to store the information for the vertices. One for the coordinates, one for the
	 * colours and one for the surface normals. A fourth vector contains indexes. This array makes it possible to create
	 * a sequence of vertices from the other three vectors without the need to repeat vertices in those vectors.
	 * </p>
	 *
	 * <p>
	 * This kind of vertex group can have a smaller memory footprint and/or faster processing than the standard array of
	 * vertices (as used by the <code>VectorVG</code>) in some situations.
	 * </p>
	 *
	 * <p>
	 * Each vertex is stored as three consecutive values in each vector as follows:
	 * </p>
	 *
	 * <pre>
	 * coordinates = {x1, y1, z1, x2, y2, z2, x3, y3, z3,..}
	 * colours = {r1, g1, b1, r2, g2, b2, r3, g3, b3,..}
	 * surface normals = {x1, y1, z1, x2, y2, z2, x3, y3, z3,..}
	 * </pre>
	 *
	 * <p>
	 * For all the arrays the numbers show which vertex the value relates to. For coordinates, the letters x, y and z
	 * show which axis the value relates to. For colours the letters r, g and b show which component of the RGB colour
	 * model the value relates to. For surface normals the letters x, y and z show which axis the value relates to.
	 * </p>
	 *
	 * @author Gary Buyn
	 */
	class SimpleIndexedVertexGroup : public BaseModel, public IndexedVertexGroup
	{
		public:
			SimpleIndexedVertexGroup();

			std::shared_ptr<VertexGroup> createEdgeSubsetVG(const int index);

			std::shared_ptr<VertexGroup> createFaceSubsetVG(const int index);

			std::shared_ptr<VertexGroup> createSubsetVG(const int index, const int length);

			std::shared_ptr<VertexGroup> createVertexSubsetVG(const int index);

			const TranslationVector<>& getCenter() const;

			std::vector<float>& getColours();

			const std::vector<float>& getColours() const;

			int getIndexWithinParent() const;

			std::vector<int>& getIndices();

			const std::vector<int>& getIndices() const;

			std::vector<float>& getNormals();

			const std::vector<float>& getNormals() const;

			VertexGroup* getParent() const;

			std::shared_ptr<Texture> getTexture() const;

			std::vector<float>& getTextureCoordinates();

			const std::vector<float>& getTextureCoordinates() const;

			int getVertexCount() const;

			std::vector<float>& getVertices();

			const std::vector<float>& getVertices() const;

			bool isSubset() const;

			void mergeWithParent() const;

			void setColours(std::shared_ptr<std::vector<float> > colours);

			void setIndices(std::shared_ptr<std::vector<int> > indices);

			void setIndexWithinParent(const int indexWithinParent);

			void setNormals(std::shared_ptr<std::vector<float> > normals);

			void setTexture(std::shared_ptr<Texture> texture);

			void setTextureCoordinates(std::shared_ptr<std::vector<float> > textureCoordinates);

			void setVertices(std::shared_ptr<std::vector<float> > vertices);

		private:
			/**
			 * <p>
			 * Creates an instance of <code>SimpleIndexedVertexGroup</code>. This constructor should only be used when
			 * creating subset <code>SimpleIndexedVertexGroup</code>s.
			 * </p>
			 *
			 * @param parent The parent of this <code>SimpleIndexedVertexGroup</code>.
			 */
			SimpleIndexedVertexGroup(SimpleIndexedVertexGroup& parent);

			/**
			 * <p>
			 * The colours of all the vertices in this <code>SimpleIndexedVertexGroup</code>.
			 * </p>
			 */
			std::shared_ptr<std::vector<float> > colours;

			/**
			 * <p>
			 * The index in the parent <code>SimpleIndexedVertexGroup</code> from which the data in this
			 * <code>SimpleIndexedVertexGroup</code> was copied.
			 * </p>
			 */
			int indexWithinParent;

			/**
			 * <p>
			 * The indices of all the vertices in this <code>SimpleIndexedVertexGroup</code>.
			 * </p>
			 */
			std::shared_ptr<std::vector<int> > indices;

			/**
			 * <p>
			 * The surface normals of all the vertices in this <code>SimpleIndexedVertexGroup</code>.
			 * </p>
			 */
			std::shared_ptr<std::vector<float> > normals;

			/**
			 * <p>
			 * The parent of this <code>SimpleIndexedVertexGroup</code>. The parent should be set to <code>null</code>
			 * unless this <code>SimpleIndexedVertexGroup</code> is a subset.
			 * </p>
			 */
			SimpleIndexedVertexGroup* const parent;

			/**
			 * <p>
			 * The subset status. Determines if this <code>SimpleIndexedVertexGroup</code> is a subgroup of a parent
			 * <code>SimpleIndexedVertexGroup</code>. Subset <code>SimpleIndexedVertexGroup</code>s contain a copy of a
			 * subset of the parent <code>SimpleIndexedVertexGroup</code>s data.
			 * </p>
			 */
			bool subset;

			/**
			 * <p>
			 * The texture covering this <code>SimpleIndexedVertexGroup</code>.
			 * </p>
			 */
			std::shared_ptr<Texture> texture;

			/**
			 * <p>
			 * The texture coordinates of all the vertices in this <code>SimpleIndexedVertexGroup</code>.
			 * </p>
			 */
			std::shared_ptr<std::vector<float> > textureCoordinates;

			/**
			 * <p>
			 * The coordinates of all the vertices in this <code>SimpleIndexedVertexGroup</code>.
			 * </p>
			 */
			std::shared_ptr<std::vector<float> > vertices;
	};
}

#endif /* SIMPLEINDEXEDVERTEXGROUP_H_ */
