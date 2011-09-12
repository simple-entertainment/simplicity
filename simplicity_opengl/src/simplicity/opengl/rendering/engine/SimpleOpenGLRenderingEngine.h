/*
 This file is part of The Simplicity Engine.

 The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
 by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

 The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

 You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef SIMPLEOPENGLRENDERINGENGINE_H_
#define SIMPLEOPENGLRENDERINGENGINE_H_

#include <GL/glew.h>

#include <simplicity/engine/RunnableEngine.h>
#include <simplicity/rendering/engine/RenderingEngine.h>
#include <simplicity/rendering/NamedRenderer.h>
#include <simplicity/scenegraph/model/ModelNode.h>
#include <simplicity/vector/SimpleVector4.h>

namespace simplicity
{
  namespace opengl
  {
    /**
     * <p>
     * Manages the rendering of a {@link simplicity::Scene Scene} in an OpenGL environment. This implementation uses only simple rendering techniques
     * and properties.
     * </p>
     *
     * @author Gary Buyn
     */
    class SimpleOpenGLRenderingEngine : public RunnableEngine, public RenderingEngine
    {
      public:
        /**
         * <p>
         * Creates an instance of <code>SimpleOpenGLRenderingEngine</code>.
         * </p>
         */
        SimpleOpenGLRenderingEngine();

        /**
         * <p>
         * Disposes of an instance of <code>SimpleOpenGLRenderingEngine</code>.
         * </p>
         */
        virtual
        ~SimpleOpenGLRenderingEngine();

        void
        addEntities(std::vector<boost::shared_ptr<Entity> > entities);

        void
        addEntity(boost::shared_ptr<Entity> entity);

        void
        addRenderer(const int index, boost::shared_ptr<Renderer> renderer);

        void
        addRenderer(boost::shared_ptr<Renderer> renderer);

        boost::shared_ptr<EngineInput>
        advance(const boost::shared_ptr<EngineInput> input);

        bool
        clearsBeforeRender() const;

        void
        destroy();

        boost::shared_ptr<Camera>
        getCamera() const;

        boost::shared_ptr<RGBAColourVector<float> >
        getClearingColour() const;

        boost::shared_ptr<Node>
        getRendererRoot(const Renderer& renderer) const;

        std::vector<shared_ptr<Renderer> >
        getRenderers() const;

        boost::shared_ptr<Scene>
        getScene() const;

        int
        getViewportHeight() const;

        int
        getViewportWidth() const;

        void
        init();

        void
        removeRenderer(const Renderer& renderer);

        void
        renderSceneGraph(Renderer& renderer, const Node& root);

        void
        reset();

        void
        setCamera(boost::shared_ptr<Camera> camera);

        void
        setClearingColour(boost::shared_ptr<RGBAColourVector<float> > clearingColour);

        void
        setClearsBeforeRender(const bool clearsBeforeRender);

        void
        setRendererRoot(const Renderer& renderer, boost::shared_ptr<Node> root);

        void
        setScene(boost::shared_ptr<Scene> scene);

        void
        setViewportHeight(const int viewportHeight);

        void
        setViewportWidth(const int viewportWidth);

      private:
        /**
         * <p>
         * Logs messages associated with this class.
         * </p>
         */
        static log4cpp::Category& fLogger;

        /**
         * <p>
         * The {@link com.se.simplicity.rendering.Camera Camera} through which the {@link simplicity::SceneGraph SceneGraph} will be rendered.
         * </p>
         */
        boost::shared_ptr<Camera> fCamera;

        /**
         * <p>
         * The colour to clear the screen buffer with before rendering.
         * </p>
         */
        boost::shared_ptr<RGBAColourVector<float> > fClearingColour;

        /**
         * <p>
         * The clearing mode. Determines if the screen buffer is cleared before rendering.
         * </p>
         *
         * @return True if the screen buffer is cleared before rendering, false otherwise.
         */
        bool fClearsBeforeRender;

        /**
         * <p>
         * The initialisation status. Determines if this <code>SimpleOpenGLRenderingEngine</code> is initialised.
         * </p>
         */
        bool fInitialised;

        /**
         * <p>
         * The root {@link simplicity::Node Node}s of the portions of the {@link simplicity::Scene Scene}s that the
         * {@link simplicity::Renderer Renderer}s will render when they are executed.
         * </p>
         */
        std::map<boost::shared_ptr<Renderer>, boost::shared_ptr<Node> > fRendererRoots;

        /**
         * <p>
         * The {@link simplicity::Renderer Renderer}s that will be executed against the {@link simplicity::Scene Scene} during
         * the {@link simplicity::opengl::SimpleJOGLRenderingEngine#advance() advance()} method.
         * </p>
         */
        std::vector<boost::shared_ptr<Renderer> > fRenderers;

        /**
         * <p>
         * The {@link simplicity::SceneGraph SceneGraph} to be rendered.
         * </p>
         */
        boost::shared_ptr<Scene> fScene;

        /**
         * <p>
         * The height of the viewport.
         * </p>
         */
        int fViewportHeight;

        /**
         * <p>
         * The width of the viewport.
         * </p>
         */
        int fViewportWidth;

        /**
         * <p>
         * Backtracks up the <code>SceneGraph</code> the number of levels given.
         * </p>
         *
         * <p>
         * A backtrack is an upward movement in the graph being rendered.
         * </p>
         *
         * @param backtracks The number of levels to backtrack.
         */
        void
        backtrack(const int backtracks);

        /**
         * <p>
         * Renders the {@link simplicity::Scene Scene} with the given Renderer.
         * </p>
         *
         * @param renderer The Renderer that will render the <code>Scene</code>.
         */
        void
        renderScene(Renderer& renderer);
    };
  }
}

#endif /* SIMPLEOPENGLRENDERINGENGINE_H_ */
