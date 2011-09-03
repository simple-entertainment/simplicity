/*
 This file is part of The Simplicity Engine.

 The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
 by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

 The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

 You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
#include <simplicity/model/MockModel.h>
#include <simplicity/rendering/MockNamedRenderer.h>

#include <simplicity/opengl/rendering/DepthClearingOpenGLRenderer.h>

#include "NamePassingOpenGLRendererTest.h"

using namespace boost;
using namespace testing;

namespace simplicity
{
  namespace opengl
  {
    /**
     * <p>
     * Unit test the method
     * {@link simplicity::opengl::NamePassingOpenGLRenderer#renderModel(const Model&, const int) renderModel(const Model&, const int)}.
     * </p>
     */
    TEST_F(NamePassingOpenGLRendererTest, renderModel)
    {
      // Create dependencies.
      // //////////////////////////////////////////////////
      shared_ptr<MockNamedRenderer> renderer0(new MockNamedRenderer);
      shared_ptr<DepthClearingOpenGLRenderer> renderer1(new DepthClearingOpenGLRenderer(renderer0));

      // Dictate expected results.
      // //////////////////////////////////////////////////
      EXPECT_CALL(*renderer0, renderModel(_, 5551));

      // Initialise the test environment.
      // //////////////////////////////////////////////////
      NamePassingOpenGLRenderer testObject(renderer1);

      // Perform test
      // //////////////////////////////////////////////////
      testObject.renderModel(MockModel(), 5551);
    }
  }
}
