/*
 This file is part of The Simplicity Engine.

 The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
 by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

 The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

 You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
#include <simplicity/opengl/OpenGLDemoRunner.h>

#include "picking/SimpleOpenGLPickerDemo.h"
#include "rendering/AlwaysAndNotEqualStencilOpenGLRenderersDemo.h"
#include "rendering/BlendingOpenGLRendererDemo.h"
#include "rendering/CullFaceOpenGLRendererDemo.h"
#include "rendering/DepthClearingOpenGLRendererDemo.h"
#include "rendering/MonoColourOpenGLRendererDemo.h"
#include "rendering/OutlineOpenGLRendererDemo.h"
#include "rendering/SimpleOpenGLRendererDemo.h"
#include "rendering/StencilClearingOpenGLRendererDemo.h"

using namespace simplicity;
using namespace simplicity::opengl;

int
main(int argc, char** argv)
{
  OpenGLDemoRunner runner("Simplicity OpenGL Demo");

  runner.addDemo(shared_ptr < Demo > (new SimpleOpenGLRendererDemo));
  runner.addDemo(shared_ptr < Demo > (new MonoColourOpenGLRendererDemo));
  runner.addDemo(shared_ptr < Demo > (new CullFaceOpenGLRendererDemo));
  runner.addDemo(shared_ptr < Demo > (new BlendingOpenGLRendererDemo));
  runner.addDemo(shared_ptr < Demo > (new AlwaysAndNotEqualStencilOpenGLRenderersDemo));
  runner.addDemo(shared_ptr < Demo > (new StencilClearingOpenGLRendererDemo));
  runner.addDemo(shared_ptr < Demo > (new DepthClearingOpenGLRendererDemo));
  runner.addDemo(shared_ptr < Demo > (new OutlineOpenGLRendererDemo));
  runner.addDemo(shared_ptr < Demo > (new SimpleOpenGLPickerDemo));

  runner.init(argc, argv);
  runner.run();
  runner.dispose();

  return (0);
}
