/*
 This file is part of The Simplicity Engine.

 The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
 by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

 The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

 You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef NAMEDRENDERER_H_
#define NAMEDRENDERER_H_

#include "Renderer.h"

namespace simplicity
{
  /**
   * <p>
   * Renders {@link simplicity::Model Model}s and names them at the same time so that they may be picked.
   * </p>
   *
   * @author Gary Buyn
   */
  class NamedRenderer : public Renderer
  {
    public:
      /**
       * <p>
       * Renders the given {@link simplicity::Model Model} with the given {@link simplicity::DrawingMode
       * DrawingMode} and names it with the given name.
       * </p>
       *
       * @param model The <code>Model</code> to render.
       * @param name The name to assign to the <code>Model</code> being rendered.
       */
      void
      renderModel(const Model& model, const int name);
  };
}

#endif /* NAMEDRENDERER_H_ */
