/*
 This file is part of The Simplicity Engine.

 The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
 by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

 The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

 You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef MOCKMODELNODE_H_
#define MOCKMODELNODE_H_

#include <gmock/gmock.h>

#include <simplicity/scene/model/ModelNode.h>

namespace simplicity
{
  class MockModelNode : public ModelNode
  {
    public:
      MOCK_METHOD1(addChild, void(std::shared_ptr<Node> child));
      //MOCK_CONST_METHOD0(getAbsoluteTransformation, std::unique_ptr<TransformationMatrix<> >());
      //MOCK_CONST_METHOD0(getBounds, std::shared_ptr<simplicity::BoundingVolume>());
      MOCK_CONST_METHOD0(getChildren, const std::vector<std::shared_ptr<Node> >&());
      MOCK_CONST_METHOD0(getId, int());
      MOCK_CONST_METHOD0(getModel, std::shared_ptr<Model>());
      MOCK_CONST_METHOD0(getParent, Node*());
      MOCK_CONST_METHOD0(getTransformation, TransformationMatrix<>&());
      MOCK_CONST_METHOD0(hasChildren, bool());
      MOCK_CONST_METHOD1(isAncestor, bool(const Node& ancestor));
      MOCK_CONST_METHOD0(isCollidable, bool());
      MOCK_CONST_METHOD0(isModifiable, bool());
      MOCK_CONST_METHOD1(isSuccessor, bool(const Node& successor));
      MOCK_CONST_METHOD0(isVisible, bool());
      MOCK_METHOD1(removeChild, void(Node& child));
      MOCK_METHOD1(setCollidable, void(const bool collidable));
      MOCK_METHOD1(setId, void(const int id));
      MOCK_METHOD1(setModel, void(std::shared_ptr<Model> model));
      MOCK_METHOD1(setModifiable, void(const bool modifiable));
      MOCK_METHOD1(setParent, void(Node* parent));
      //MOCK_METHOD1(setTransformation, void(std::unique_ptr<TransformationMatrix<> > transformation));
      MOCK_METHOD1(setVisible, void(const bool visible));

	  // TODO Mock this properly when it is supported!
	  std::unique_ptr<TransformationMatrix<> > getAbsoluteTransformation() const
	  {
		return std::unique_ptr<TransformationMatrix<> >();
	  }

	  // TODO Mock this properly when it is supported!
	  void setTransformation(std::unique_ptr<TransformationMatrix<> > transformation)
	  {
	  }
  };
}

#endif /* MOCKMODELNODE_H_ */
