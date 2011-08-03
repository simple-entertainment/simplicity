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
#include "../../scene/Scene.h"
#include "../../vector/RGBAColourVector.h"

namespace simplicity
{
  /**
   * <p>
   * Manages the renderng of a {@link simplicity::Scene Scene}. Each advance renders the <code>Scene</code> in its current state.
   * </p>
   *
   * <p>
   * Any changes to settings made during the {@link simplicity::RenderingEngine#init() init()} method should be reverted during the
   * {@link simplicity::RenderingEngine#destroy() destroy()} method. It is the responsibility of the <code>RenderingEngine</code> to leave the
   * rendering environment as it was found (except for contents of buffers) so that multiple <code>RenderingEngine</code>s may be used together
   * without effecting each other.
   * </p>
   *
   * <p>
   * When used within a <code>RenderingEngine</code>, the {@link simplicity::Renderer Renderer} acts as a rendering pass. Adding multiple
   * <code>Renderer</code>s to a <code>RenderingEngine</code> effectively creates a multi pass rendering environment.
   * </p>
   *
   * @author Gary Buyn
   */
  class RenderingEngine : public virtual Engine
  {
    public:
      /**
       * <p>
       * Determines if the screen buffer is cleared before rendering.
       * </p>
       *
       * @return True if the screen buffer is cleared before rendering.
       */
      virtual bool
      clearsBeforeRender() const = 0;

      /**
       * <p>
       * Adds a {@link simplicity::Renderer Renderer}. During the {@link simplicity::RenderingEngine#advance(EngineInput) advance(EngineInput)}
       * method, the <code>Renderer</code>s are executed against the {@link simplicity::Scene Scene} in the order they were added.
       * </p>
       *
       * @param renderer The <code>Renderer</code> to be added.
       */
      virtual void
      addRenderer(boost::shared_ptr<Renderer> renderer) = 0;

      /**
       * <p>
       * Adds a {@link simplicity::Renderer Renderer} at the given index. During the
       * {@link simplicity::RenderingEngine#advance(EngineInput) advance(EngineInput)} method, the <code>Renderer</code>s are executed against the
       * {@link simplicity::Scene Scene} in the order they were added. By adding a <code>Renderer</code> at a specific index, it can be executed
       * before others that were added before it.
       * </p>
       *
       * @param index The index to add the <code>Renderer</code> at.
       * @param renderer The <code>Renderer</code> to be added.
       */
      virtual void
      addRenderer(const int index, boost::shared_ptr<Renderer> renderer) = 0;

      /**
       * <p>
       * Renders the {@link simplicity::Scene Scene}.
       * </p>
       *
       * @param engineInput The {@link simplicity::EngineInput} to process during this advancement.
       *
       * @return The <code>EngineInput</code> for the next {@link simplicity::Engine Engine} in the chain.
       */
      virtual EngineInput *
      advance(const EngineInput* const engineInput) = 0;

      /**
       * <p>
       * Retrieves the {@link simplicity::Camera Camera} through which the {@link simplicity::Scene Scene} will be rendered.
       * </p>
       *
       * @return The <code>Camera</code> through which the <code>Scene</code> will be rendered.
       */
      virtual boost::shared_ptr<Camera>
      getCamera() const = 0;

      /**
       * <p>
       * Retrieves the colour to clear the screen buffer with before rendering.
       * </p>
       *
       * @return The colour to clear the screen buffer with before rendering.
       */
      virtual boost::shared_ptr<RGBAColourVector<float> >
      getClearingColour() const = 0;

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
      virtual boost::shared_ptr<Node>
      getRendererRoot(const Renderer& renderer) const = 0;

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
      virtual std::vector<boost::shared_ptr<Renderer> >
      getRenderers() const = 0;

      /**
       * <p>
       * Retrieves the {@link simplicity::Scene Scene} to be rendered.
       * </p>
       *
       * @return The {@link simplicity::Scene Scene} to be rendered.
       */
      virtual boost::shared_ptr<Scene>
      getScene() const = 0;

      /**
       * <p>
       * Retrieves the height of the viewport (the area on which the {@link simplicity::Scene Scene} will be rendered).
       * </p>
       *
       * @return The height of the viewport.
       */
      virtual int
      getViewportHeight() const = 0;

      /**
       * <p>
       * Retrieves the width of the viewport (the area on which the {@link simplicity::Scene Scene} will be rendered).
       * </p>
       *
       * @return The width of the viewport.
       */
      virtual int
      getViewportWidth() const = 0;

      /**
       * <p>
       * Removes a {@link simplicity::Renderer Renderer}.
       * </p>
       *
       * @param renderer The <code>Renderer</code> to be removed.
       */
      virtual void
      removeRenderer(const Renderer& renderer) = 0;

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
      virtual void
      renderSceneGraph(Renderer& renderer, const Node& root) = 0;

      /**
       * <p>
       * Sets the {@link simplicity::Camera Camera} through which the {@link simplicity::Scene Scene} will be rendered.
       * </p>
       *
       * @param camera The <code>Camera</code> through which the <code>Scene</code> will be rendered.
       */
      virtual void
      setCamera(boost::shared_ptr<Camera> camera) = 0;

      /**
       * <p>
       * Sets the colour to clear the buffer with before rendering.
       * </p>
       *
       * @param clearingColour The colour to clear the buffer with before rendering.
       */
      virtual void
      setClearingColour(boost::shared_ptr<RGBAColourVector<float> > clearingColour) = 0;

      /**
       * <p>
       * Sets the clearing mode. Determines if the screen buffer is cleared before rendering.
       * </p>
       *
       * @param clearsBeforeRender Determines if the screen buffer is cleared before rendering.
       */
      virtual void
      setClearsBeforeRender(const bool clearsBeforeRender) = 0;

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
      virtual void
      setRendererRoot(const Renderer& renderer, boost::shared_ptr<Node> root) = 0;

      /**
       * <p>
       * Sets the {@link simplicity::Scene Scene} to be rendered.
       * </p>
       *
       * @param scene The <code>Scene</code> to be rendered.
       */
      virtual void
      setScene(boost::shared_ptr<Scene> scene) = 0;

      /**
       * <p>
       * Sets the height of the viewport (the area on which the {@link simplicity::Scene Scene} will be rendered).
       * </p>
       *
       * @param viewportHeight The height of the viewport.
       */
      virtual void
      setViewportHeight(const int viewportHeight) = 0;

      /**
       * <p>
       * Sets the width of the viewport (the area on which the {@link simplicity::Scene Scene} will be rendered).
       * </p>
       *
       * @param viewportWidth The width of the viewport.
       */
      virtual void
      setViewportWidth(const int viewportWidth) = 0;
  };
}

#endif /* RENDERINGENGINE_H_ */
