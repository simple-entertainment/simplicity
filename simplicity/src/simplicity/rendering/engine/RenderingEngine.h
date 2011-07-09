/*
 This file is part of The Simplicity Engine.

 The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
 by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

 The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

 You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef RENDERINGENGINE_H_
#define RENDERINGENGINE_H_

#include "../Renderer.h"
#include "../../engine/Engine.h"

namespace simplicity
{
  /**
   * <p>
   * Manages the renderng of a {@link simplicity::Scene Scene}. Each advance renders the <code>Scene</code> in its current state.
   * </p>
   *
   * <p>
   * Any changes to settings made during the {@link simplicity::RenderingEngine#init() init()} method should be reverted during
   * the {@link simplicity::RenderingEngine#destroy() destroy()} method. It is the responsibility of the
   * <code>RenderingEngine</code> to leave the rendering environment as it was found (except for contents of buffers) so that multiple
   * <code>RenderingEngine</code>s may be used together without effecting each other.
   * </p>
   *
   * <p>
   * When used within a <code>RenderingEngine</code>, the {@link simplicity::Renderer Renderer} acts as a rendering pass. Adding
   * multiple <code>Renderer</code>s to a <code>RenderingEngine</code> effectively creates a multi pass rendering environment.
   * </p>
   *
   * @author Gary Buyn
   */
  class RenderingEngine : public Engine
  {
    public:
      /**
       * <p>
       * Determines if the screen buffer is cleared before rendering.
       * </p>
       *
       * @return True if the screen buffer is cleared before rendering.
       */
      bool
      clearsBeforeRender() const;

      /**
       * <p>
       * Adds a {@link simplicity::Renderer Renderer}. During the
       * {@link simplicity::RenderingEngine#advance(EngineInput) advance(EngineInput)} method, the <code>Renderer</code>s are
       * executed against the {@link simplicity::Scene Scene} in the order they were added.
       * </p>
       *
       * @param renderer The <code>Renderer</code> to be added.
       */
      void
      addRenderer(Renderer * const renderer);

      /**
       * <p>
       * Adds a {@link simplicity::Renderer Renderer} at the given index. During the
       * {@link simplicity::RenderingEngine#advance(EngineInput) advance(EngineInput)} method, the <code>Renderer</code>s are
       * executed against the {@link simplicity::Scene Scene} in the order they were added. By adding a <code>Renderer</code> at a specific
       * index, it can be executed before others that were added before it.
       * </p>
       *
       * @param index The index to add the <code>Renderer</code> at.
       * @param renderer The <code>Renderer</code> to be added.
       */
      void
      addRenderer(int const index, Renderer const * const renderer);

      /**
       * <p>
       * Renders the {@link simplicity::Scene Scene}.
       * </p>
       *
       * @param engineInput The {@link simplicity::EngineInput} to process during this advancement.
       *
       * @return The <code>EngineInput</code> for the next {@link simplicity::Engine Engine} in the chain.
       */
      EngineInput *
      advance(EngineInput const * const engineInput);

      /**
       * <p>
       * Retrieves the {@link simplicity::Camera Camera} through which the {@link simplicity::Scene Scene} will be rendered.
       * </p>
       *
       * @return The <code>Camera</code> through which the <code>Scene</code> will be rendered.
       */
      Camera *
      getCamera() const;

      /**
       * <p>
       * Retrieves the colour to clear the screen buffer with before rendering.
       * </p>
       *
       * @return The colour to clear the screen buffer with before rendering.
       */
      SimpleVectorf4 *
      getClearingColour() const;

      /**
       * <p>
       * Retrieves the root {@link simplicity::Node Node} of the portion of the {@link simplicity::Scene Scene} that the
       * given {@link simplicity::Renderer Renderer} will render when it is executed.
       * </p>
       *
       * @param renderer The <code>Renderer</code> to set the root <code>Node</code> for.
       *
       * @return The root <code>Node</code> of the portion of the <code>Scene</code> that will be rendered.
       */
      Node *
      getRendererRoot(Renderer const * const renderer);

      /**
       * <p>
       * Retrieves the {@link simplicity::Renderer Renderer}s that will be executed against the {@link simplicity::Scene
       * Scene} during the {@link simplicity::RenderingEngine#advance(EngineInput) advance(EngineInput)} method.
       * </p>
       *
       * <p>
       * NOTE: This method should only be used to examine the list of <code>Renderer</code>s, not to modify it.
       * </p>
       *
       * @return The <code>Renderer</code>s that will be executed against the <code>Scene</code> during the <code>advance()</code> method.
       */
      vector<Renderer *> *
      getRenderers() const;

      /**
       * <p>
       * Retrieves the {@link simplicity::Scene Scene} to be rendered.
       * </p>
       *
       * @return The {@link simplicity::Scene Scene} to be rendered.
       */
      Scene *
      getScene() const;

      /**
       * <p>
       * Retrieves the size of the viewport (the area on which the {@link simplicity::Scene Scene} will be rendered).
       * </p>
       *
       * @return The size of the viewport.
       */
      Dimension
      getViewportSize() const;

      /**
       * <p>
       * Removes a {@link simplicity::Renderer Renderer}.
       * </p>
       *
       * @param renderer The <code>Renderer</code> to be removed.
       */
      void
      removeRenderer(Renderer * const renderer);

      /**
       * <p>
       * Renders the portion of the {@link simplicity::Scene Scene} with the given root {@link simplicity::Node Node} using
       * the given {@link simplicity::Renderer Renderer}.
       * </p>
       *
       * <p>
       * Preparation of the rendering environment including {@link simplicity::Camera Camera} and
       * {@link simplicity.rendering.Light Light} applications should not be performed from within this method. Instead this should be performed
       * in the {@link simplicity::RenderingEngine#advance(EngineInput) advance(EngineInput)} method.
       * </p>
       *
       * @param renderer The <code>Renderer</code> that will render the portion of the <code>Scene</code>.
       * @param root The root <code>Node</code> of the portion of the <code>Scene</code> that will be rendered.
       */
      void
      renderSceneGraph(Renderer * const renderer, Node * const root);

      /**
       * <p>
       * Sets the {@link simplicity::Camera Camera} through which the {@link simplicity::Scene Scene} will be rendered.
       * </p>
       *
       * @param camera The <code>Camera</code> through which the <code>Scene</code> will be rendered.
       */
      void
      setCamera(Camera * const camera);

      /**
       * <p>
       * Sets the colour to clear the buffer with before rendering.
       * </p>
       *
       * @param clearingColour The colour to clear the buffer with before rendering.
       */
      void
      setClearingColour(SimpleVectorf4 * const clearingColour);

      /**
       * <p>
       * Sets the clearing mode. Determines if the screen buffer is cleared before rendering.
       * </p>
       *
       * @param clearsBeforeRender Determines if the screen buffer is cleared before rendering.
       */
      void
      setClearsBeforeRender(bool const clearsBeforeRender);

      /**
       * <p>
       * Sets the root {@link simplicity::Node Node} of the portion of the {@link simplicity::Scene Scene} that the given
       * {@link simplicity::Renderer Renderer} will render when it is executed. The default is the root <code>Node</code> of the
       * <code>Scene</code>.
       * </p>
       *
       * @param renderer The <code>Renderer</code> to set the root <code>Node</code> for.
       * @param root The root <code>Node</code> of the portion of the <code>Scene</code> that will be rendered.
       */
      void
      setRendererRoot(Renderer const * const renderer, Node * const root);

      /**
       * <p>
       * Sets the {@link simplicity::Scene Scene} to be rendered.
       * </p>
       *
       * @param scene The <code>Scene</code> to be rendered.
       */
      void
      setScene(Scene * const scene);

      /**
       * <p>
       * Sets the size of the viewport (the area on which the {@link simplicity::Scene Scene} will be rendered).
       * </p>
       *
       * @param viewportSize The size of the viewport.
       */
      void
      setViewportSize(Dimension const viewportSize);
  };
}

#endif /* RENDERINGENGINE_H_ */
