/*
 This file is part of The Simplicity Engine.

 The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
 by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

 The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

 You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef MOCKCAMERA_H_
#define MOCKCAMERA_H_

#include <gmock/gmock.h>

#include <simplicity/rendering/Camera.h>

namespace simplicity
{
  /**
   * <p>
   * A mock implementation of {@link simplicity::Camera Camera}.
   * </p>
   *
   * @author Gary Buyn
   */
  class MockCamera : public Camera
  {
    public:
      MOCK_METHOD0(apply, void());
      MOCK_CONST_METHOD0(getFarClippingDistance, float());
      MOCK_CONST_METHOD0(getFrameAspectRatio, float());
      MOCK_CONST_METHOD0(getFrameHeight, float());
      MOCK_CONST_METHOD0(getFrameWidth, float());
      MOCK_CONST_METHOD0(getFrameX, float());
      MOCK_CONST_METHOD0(getFrameY, float());
      MOCK_CONST_METHOD0(getNearClippingDistance, float());
      MOCK_CONST_METHOD0(getNode, TreeNode*());
      MOCK_CONST_METHOD1(getPickCamera, std::shared_ptr<Camera>(const Pick pick));
      MOCK_CONST_METHOD0(getProjectionMode, ProjectionMode());
      MOCK_CONST_METHOD0(getTransformation, const TransformationMatrix<>&());
      MOCK_METHOD0(init, void());
      MOCK_CONST_METHOD0(isInitialised, bool());
      MOCK_METHOD1(setFarClippingDistance, void(const float farClippingDistance));
      MOCK_METHOD1(setFrameAspectRatio, void(const float frameAspectRatio));
      MOCK_METHOD1(setFrameHeight, void(const float frameHeight));
      MOCK_METHOD1(setFrameWidth, void(const float frameWidth));
      MOCK_METHOD1(setFrameX, void(const float frameX));
      MOCK_METHOD1(setFrameY, void(const float frameY));
      MOCK_METHOD1(setInitialised, void(const bool isInitialised));
      MOCK_METHOD1(setNearClippingDistance, void(const float nearClippingDistance));
      MOCK_METHOD1(setNode, void(TreeNode* node));
      MOCK_METHOD1(setProjectionMode, void(const ProjectionMode projectionMode));
  };
}

#endif /* MOCKCAMERA_H_ */
