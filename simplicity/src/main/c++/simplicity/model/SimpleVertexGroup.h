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
#ifndef SIMPLEVERTEXGROUP_H_
#define SIMPLEVERTEXGROUP_H_

#include "../math/TranslationVector.h"
#include "BaseModel.h"
#include "VertexGroup.h"

namespace simplicity
{
	/**
	 * <p>
	 * A {@link simplicity::VertexGroup VertexGroup} that contains its vertices in vectors.
	 * </p>
	 *
	 * <p>
	 * Three separate vectors are used to store the information for the vertices. One for the coordinates, one for the
	 * colours and one for the surface normals.
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
	 * For all the vectors the numbers show which vertex the value relates to. For coordinates, the letters x, y and z
	 * show which axis the value relates to. For colours the letters r, g and b show which component of the RGB colour
	 * model the value relates to. For surface normals the letters x, y and z show which axis the value relates to.
	 * </p>
	 *
	 * @author Gary Buyn
	 */
	class SimpleVertexGroup : public BaseModel, public VertexGroup
	{
		public:
			SimpleVertexGroup();

			std::shared_ptr<VertexGroup> createEdgeSubsetVG(const int index);

			std::shared_ptr<VertexGroup> createFaceSubsetVG(const int index);

			std::shared_ptr<VertexGroup> createSubsetVG(const int index, const int length);

			std::shared_ptr<VertexGroup> createVertexSubsetVG(const int index);

			const TranslationVector<>& getCenter() const;

			std::vector<float>& getColours();

			const std::vector<float>& getColours() const;

			int getIndexWithinParent() const;

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

			void setIndexWithinParent(const int indexWithinParent);

			void setNormals(std::shared_ptr<std::vector<float> > normals);

			void setTexture(std::shared_ptr<Texture> texture);

			void setTextureCoordinates(std::shared_ptr<std::vector<float> > textureCoordinates);

			void setVertices(std::shared_ptr<std::vector<float> > vertices);

		private:
			/**
			 * <p>
			 * Creates an instance of <code>SimpleVertexGroup</code>. This constructor should only be used when creating
			 * subset <code>SimpleVertexGroup</code>s.
			 * </p>
			 *
			 * @param parent The parent of this <code>SimpleVertexGroup</code>.
			 */
			SimpleVertexGroup(SimpleVertexGroup& parent);

			/**
			 * <p>
			 * The colours of all the vertices in this <code>SimpleVertexGroup</code>.
			 * </p>
			 */
			std::shared_ptr<std::vector<float> > colours;

			/**
			 * <p>
			 * The index in the parent <code>SimpleVertexGroup</code> from which the data in this
			 * <code>SimpleVertexGroup</code> was copied.
			 * </p>
			 */
			int indexWithinParent;

			/**
			 * <p>
			 * The surface normals of all the vertices in this <code>SimpleVertexGroup</code>.
			 * </p>
			 */
			std::shared_ptr<std::vector<float> > normals;

			/**
			 * <p>
			 * The parent of this <code>SimpleVertexGroup</code>. The parent should be set to <code>null</code> unless
			 * this <code>SimpleVertexGroup</code> is a subset.
			 * </p>
			 */
			SimpleVertexGroup* const parent;

			/**
			 * <p>
			 * The subset status. Determines if this <code>SimpleVertexGroup</code> is a subgroup of a parent
			 * <code>SimpleVertexGroup</code>. Subset <code>SimpleVertexGroup</code>s contain a copy of a subset of the
			 * parent <code>SimpleVertexGroup</code>s data.
			 * </p>
			 */
			bool subset;

			/**
			 * <p>
			 * The texture covering this <code>SimpleVertexGroup</code>.
			 * </p>
			 */
			std::shared_ptr<Texture> texture;

			/**
			 * <p>
			 * The texture coordinates of all the vertices in this <code>SimpleVertexGroup</code>.
			 * </p>
			 */
			std::shared_ptr<std::vector<float> > textureCoordinates;

			/**
			 * <p>
			 * The coordinates of all the vertices in this <code>SimpleVertexGroup</code>.
			 * </p>
			 */
			std::shared_ptr<std::vector<float> > vertices;
	};
}

#endif /* SIMPLEVERTEXGROUP_H_ */
