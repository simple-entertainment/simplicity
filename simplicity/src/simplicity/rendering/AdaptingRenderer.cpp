/*
 This file is part of The Simplicity Engine.

 The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
 by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

 The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

 You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
#include "AdaptingRenderer.h"

using namespace boost;

namespace simplicity
{
  AdaptingRenderer::AdaptingRenderer(shared_ptr<Renderer> renderer) :
    fRenderer(renderer)
  {
  }

  void
  AdaptingRenderer::dispose()
  {
    fRenderer->dispose();

    onDispose();
  }

  Renderer::DrawingMode
  AdaptingRenderer::getDrawingMode() const
  {
    return (fRenderer->getDrawingMode());
  }

  /**
   * <p>
   * Retrieves the wrapped {@link simplicity::Renderer Renderer}.
   * </p>
   *
   * @return The wrapped <code>Renderer</code>.
   */
  shared_ptr<Renderer>
  AdaptingRenderer::getRenderer()
  {
    return (fRenderer);
  }

  void
  AdaptingRenderer::AdaptingRenderer::init()
  {
    onInit();

    fRenderer->init();
  }

  void
  AdaptingRenderer::renderModel(const Model& model)
  {
    fRenderer->renderModel(model);
  }

  void
  AdaptingRenderer::setDrawingMode(const Renderer::DrawingMode mode)
  {
    fRenderer->setDrawingMode(mode);
  }

  /**
   * <p>
   * Sets the wrapped {@link simplicity::Renderer Renderer}.
   * </p>
   *
   * @param renderer The wrapped <code>Renderer</code>.
   */
  void
  AdaptingRenderer::setRenderer(shared_ptr<Renderer> renderer)
  {
    fRenderer = renderer;
  }
}
