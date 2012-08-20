/*
 * Copyright © 2011 Simple Entertainment Limited
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
#ifndef MOCKVERTEXGROUP_H_
#define MOCKVERTEXGROUP_H_

#include <gmock/gmock.h>

#include <simplicity/model/VertexGroup.h>

namespace simplicity
{
	/**
	 * <p>
	 * A mock implementation of {@link simplicity::VertexGroup VertexGroup}.
	 * </p>
	 *
	 * @author Gary Buyn
	 */
	class MockVertexGroup : public VertexGroup
	{
		public:
			MOCK_METHOD1(createEdgeSubsetVG, std::shared_ptr<VertexGroup>(const int index));
			MOCK_METHOD1(createFaceSubsetVG, std::shared_ptr<VertexGroup>(const int index));
			MOCK_METHOD2(createSubsetVG, std::shared_ptr<VertexGroup>(const int index, const int length));
			MOCK_METHOD1(createVertexSubsetVG, std::shared_ptr<VertexGroup>(const int index));
			MOCK_CONST_METHOD0(getCenter, const TranslationVector<>&());
			MOCK_METHOD0(getColours, std::vector<float>&());
			MOCK_CONST_METHOD0(getColours, const std::vector<float>&());
			MOCK_CONST_METHOD0(getEntity, const Entity&());
			MOCK_CONST_METHOD0(getIndexWithinParent, int());
			MOCK_CONST_METHOD0(getNode, TreeNode*());
			MOCK_METHOD0(getNormals, std::vector<float>&());
			MOCK_CONST_METHOD0(getNormals, const std::vector<float>&());
			MOCK_CONST_METHOD0(getParent, VertexGroup*());
			MOCK_CONST_METHOD0(getTexture, std::shared_ptr<Texture>());
			MOCK_METHOD0(getTextureCoordinates, std::vector<float>&());
			MOCK_CONST_METHOD0(getTextureCoordinates, const std::vector<float>&());
			MOCK_CONST_METHOD0(getVertexCount, int());MOCK_CONST_METHOD0(isSubset, bool());
			MOCK_METHOD0(getVertices, std::vector<float>&());
			MOCK_CONST_METHOD0(getVertices, const std::vector<float>&());
			MOCK_CONST_METHOD0(mergeWithParent, void());
			MOCK_METHOD1(setColours, void(std::shared_ptr<std::vector<float> > colours));
			MOCK_METHOD1(setEntity, void(std::shared_ptr<Entity> entity));
			MOCK_METHOD1(setIndexWithinParent, void(const int indexWithinParent));
			MOCK_METHOD1(setNode, void(TreeNode* node));
			MOCK_METHOD1(setNormals, void(std::shared_ptr<std::vector<float> > normals));
			MOCK_METHOD1(setTexture, void(std::shared_ptr<Texture> texture));
			MOCK_METHOD1(setTextureCoordinates, void(std::shared_ptr<std::vector<float> > textureCoordinates));
			MOCK_METHOD1(setVertices, void(std::shared_ptr<std::vector<float> > vertices));
	};
}

#endif /* MOCKVERTEXGROUP_H_ */
