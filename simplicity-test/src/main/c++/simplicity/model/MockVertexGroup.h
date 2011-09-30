/*
 This file is part of The Simplicity Engine.

 The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
 by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

 The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

 You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
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
      MOCK_METHOD1(createEdgeSubsetVG, boost::shared_ptr<VertexGroup>(const int index));
      MOCK_METHOD1(createFaceSubsetVG, boost::shared_ptr<VertexGroup>(const int index));
      MOCK_METHOD2(createSubsetVG, boost::shared_ptr<VertexGroup>(const int index, const int length));
      MOCK_METHOD1(createVertexSubsetVG, boost::shared_ptr<VertexGroup>(const int index));
      MOCK_CONST_METHOD0(getCenter, const TranslationVector<float>&());
      MOCK_CONST_METHOD0(getIndexWithinParent, int());
      MOCK_CONST_METHOD0(getParent, VertexGroup*());
      MOCK_CONST_METHOD0(getVertexCount, int());
      MOCK_CONST_METHOD0(isSubset, bool());
      MOCK_CONST_METHOD0(mergeWithParent, void());
      MOCK_METHOD1(setIndexWithinParent, void(const int indexWithinParent));
  };
}

#endif /* MOCKVERTEXGROUP_H_ */
