/*
 This file is part of The Simplicity Engine.

 The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
 by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

 The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

 You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef MOCKRENDERER_H_
#define MOCKRENDERER_H_

#include <gmock/gmock.h>

#include <simplicity/rendering/Renderer.h>

namespace simplicity
{
  /**
   * <p>
   * A mock implementation of {@link simplicity::Renderer Renderer}.
   * </p>
   *
   * @author Gary Buyn
   */
  class MockRenderer : public Renderer
  {
    public:
      MOCK_METHOD0(dispose, void());
      MOCK_CONST_METHOD0(getDrawingMode, DrawingMode());
      MOCK_METHOD0(init, void());
      MOCK_METHOD1(renderModel, void(const Model& model));
      MOCK_METHOD1(setDrawingMode, void(const DrawingMode mode));
  };
}

#endif /* MOCKRENDERER_H_ */
