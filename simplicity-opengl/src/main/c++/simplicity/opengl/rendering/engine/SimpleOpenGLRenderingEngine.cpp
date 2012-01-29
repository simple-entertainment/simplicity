/*
 * Copyright © 2011 Simple Entertainment Limited
 *
 * This file is part of The Simplicity Engine.
 *
 * The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General
 * Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option)
 * any later version.
 *
 * The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the
 * implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more
 * details.
 *
 * You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see
 * <http://www.gnu.org/licenses/>.
 */
#include <algorithm>
#include <stdio.h>

#include <simplicity/common/shared_equals_raw.h>
#include <simplicity/math/SimpleRGBAColourVector4.h>
#include <simplicity/scene/PreorderNodeIterator.h>
#include <simplicity/SEInvalidOperationException.h>

#include "SimpleOpenGLRenderingEngine.h"

using namespace std;

namespace simplicity
{
	namespace opengl
	{
		log4cpp::Category& SimpleOpenGLRenderingEngine::logger = log4cpp::Category::getInstance(
			"simplicity::opengl::SimpleOpenGLRenderingEngine");

		SimpleOpenGLRenderingEngine::SimpleOpenGLRenderingEngine() :
			clearingColour(new SimpleRGBAColourVector4<>(0.0f, 0.0f, 0.0f, 1.0f)), clearsBuffers(true), initialised(
				false), viewportHeight(600), viewportWidth(800)
		{
		}

		SimpleOpenGLRenderingEngine::~SimpleOpenGLRenderingEngine()
		{
		}

		void SimpleOpenGLRenderingEngine::addEntities(std::vector<std::shared_ptr<Entity> > entities)
		{
			for (unsigned int index = 0; index < entities.size(); index++)
			{
				addEntity(entities.at(index));
			}
		}

		void SimpleOpenGLRenderingEngine::addEntity(std::shared_ptr<Entity> entity)
		{
			for (unsigned int index = 0; index < entity->getComponents().size(); index++)
			{
				std::shared_ptr<Node> node(dynamic_pointer_cast<Node>(entity->getComponents().at(index)));

				if (node.get())
				{
					scene->addNode(node);
				}
			}
		}

		void SimpleOpenGLRenderingEngine::addRenderer(const int index, std::shared_ptr<Renderer> renderer)
		{
			renderers.insert(renderers.begin() + index, renderer);

			if (scene.get())
			{
				setRendererRoot(*renderer, scene->getRoot());
			}
		}

		void SimpleOpenGLRenderingEngine::addRenderer(std::shared_ptr<Renderer> renderer)
		{
			addRenderer(renderers.size(), renderer);
		}

		std::shared_ptr<EngineInput> SimpleOpenGLRenderingEngine::advance(const std::shared_ptr<EngineInput> input)
		{
			if (!camera.get())
			{
				logger.fatal("Just how do you expect me to render without a camera then?");
				throw SEInvalidOperationException();
			}

			camera->init();

			if (!scene.get())
			{
				logger.fatal("Just what do you expect me to render then? I don't have a scene to play with.");
				throw SEInvalidOperationException();
			}

			if (!initialised)
			{
				init();
			}

			// Clear the buffers.
			if (clearsBuffers)
			{
				glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
			}

			for (unsigned int index = 0; index < renderers.size(); index++)
			{
				if (rendererRoots.find(renderers.at(index))->second.get())
				{
					renderers.at(index)->init();
					renderScene(*renderers.at(index));
					renderers.at(index)->dispose();
				}
			}

			return std::shared_ptr<EngineInput>();
		}

		void SimpleOpenGLRenderingEngine::backtrack(const int backtracks)
		{
			for (int index = 0; index < backtracks; index++)
			{
				glPopMatrix();
			}
		}

		bool SimpleOpenGLRenderingEngine::clearsBeforeRender() const
		{
			return clearsBuffers;
		}

		void SimpleOpenGLRenderingEngine::destroy()
		{
			// Revert depth test settings.
			glDepthFunc(GL_LESS);
			glDisable(GL_DEPTH_TEST);

			// Revert face culling settings.
			glDisable(GL_CULL_FACE);

			// Revert client state settings.
			glDisableClientState(GL_VERTEX_ARRAY);

			// Revert clearing settings.
			glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
		}

		std::shared_ptr<Camera> SimpleOpenGLRenderingEngine::getCamera() const
		{
			return camera;
		}

		std::shared_ptr<RGBAColourVector<> > SimpleOpenGLRenderingEngine::getClearingColour() const
		{
			return clearingColour;
		}

		std::shared_ptr<Node> SimpleOpenGLRenderingEngine::getRendererRoot(const Renderer& renderer) const
		{
			std::shared_ptr<Node> rendererRoot;

			shared_equals_raw<Renderer> sharedEqualsRaw(&renderer);
			std::shared_ptr<Renderer> sharedRenderer(*find_if(renderers.begin(), renderers.end(), sharedEqualsRaw));

			if (sharedRenderer != *renderers.end())
			{
				rendererRoot = rendererRoots.find(sharedRenderer)->second;
			}

			return rendererRoot;
		}

		vector<std::shared_ptr<Renderer> > SimpleOpenGLRenderingEngine::getRenderers() const
		{
			return renderers;
		}

		std::shared_ptr<Scene> SimpleOpenGLRenderingEngine::getScene() const
		{
			return scene;
		}

		int SimpleOpenGLRenderingEngine::getViewportHeight() const
		{
			return viewportHeight;
		}

		int SimpleOpenGLRenderingEngine::getViewportWidth() const
		{
			return viewportWidth;
		}

		void SimpleOpenGLRenderingEngine::onInit()
		{
			// Ensure objects further from the viewpoint are not drawn over the top of closer objects. To assist multi
			// pass rendering, objects at the exact same distance can be rendered over (i.e. the object will be rendered
			// using the result of the last Renderer executed).
			glDepthFunc(GL_LEQUAL);
			glEnable(GL_DEPTH_TEST);

			// Only render the front (counter-clockwise) side of a polygon.
			glEnable(GL_CULL_FACE);

			// Enable model data arrays.
			glEnableClientState(GL_VERTEX_ARRAY);

			// Set the colour buffer clearing colour.
			glClearColor(clearingColour->getRed(), clearingColour->getGreen(), clearingColour->getBlue(),
				clearingColour->getAlpha());

			// Initialise the viewport size.
			glViewport(0, 0, viewportWidth, viewportHeight);

			initialised = true;
		}

		void SimpleOpenGLRenderingEngine::onReset()
		{
			init();
		}

		void SimpleOpenGLRenderingEngine::removeRenderer(const Renderer& renderer)
		{
			shared_equals_raw<Renderer> sharedEqualsRaw(&renderer);
			vector<std::shared_ptr<Renderer> >::iterator sharedRenderer(
				find_if(renderers.begin(), renderers.end(), sharedEqualsRaw));

			renderers.erase(sharedRenderer);
			rendererRoots.erase(*sharedRenderer);
		}

		void SimpleOpenGLRenderingEngine::renderScene(Renderer& renderer)
		{
			glPushMatrix();
			{
				camera->apply();

				for (unsigned int index = 0; index < scene->getLights().size(); index++)
				{
					scene->getLights().at(index)->apply();
				}

				shared_equals_raw<Renderer> sharedEqualsRaw(&renderer);
				std::shared_ptr<Renderer> sharedRenderer(*find_if(renderers.begin(), renderers.end(), sharedEqualsRaw));
				renderSceneGraph(renderer, *rendererRoots.find(sharedRenderer)->second);
			}
			glPopMatrix();
		}

		void SimpleOpenGLRenderingEngine::renderSceneGraph(Renderer& renderer, const Node& root)
		{
			// For every node in the traversal of the scene.
			PreorderNodeIterator iterator(root);
			std::shared_ptr<Node> currentNode;

			while (iterator.hasMoreNodes())
			{
				// Remove transformations from the stack that do not apply to the next node.
				backtrack(iterator.getBacktracksToNextNode());

				// Apply the transformation of the current node.
				currentNode = iterator.getNextNode();

				glPushMatrix();
				glMultMatrixf(currentNode->getTransformation().getRawData());

				// Render the current node.
				ModelNode* modelNode = dynamic_cast<ModelNode*>(currentNode.get());
				if (modelNode)
				{
					NamedRenderer* namedRenderer = dynamic_cast<NamedRenderer*> (&renderer);
					if (namedRenderer)
					{
						namedRenderer->renderModel(*modelNode->getModel(), modelNode->getId());
					}
					else
					{
						renderer.renderModel(*modelNode->getModel());
					}
				}
			}

			// Remove all remaining transformations from the stack.
			backtrack(iterator.getBacktracksToNextNode());
		}

		void SimpleOpenGLRenderingEngine::setCamera(std::shared_ptr<Camera> camera)
		{
			this->camera = camera;
		}

		void SimpleOpenGLRenderingEngine::setClearingColour(std::shared_ptr<RGBAColourVector<> > clearingColour)
		{
			this->clearingColour = clearingColour;

			initialised = false;
		}

		void SimpleOpenGLRenderingEngine::setClearsBeforeRender(const bool clearsBeforeRender)
		{
			clearsBuffers = clearsBeforeRender;
		}

		void SimpleOpenGLRenderingEngine::setRendererRoot(const Renderer& renderer, std::shared_ptr<Node> root)
		{
			shared_equals_raw<Renderer> sharedEqualsRaw(&renderer);
			std::shared_ptr<Renderer> sharedRenderer(*find_if(renderers.begin(), renderers.end(), sharedEqualsRaw));
			rendererRoots.erase(sharedRenderer);
			rendererRoots.insert(pair<std::shared_ptr<Renderer>, std::shared_ptr<Node> >(sharedRenderer, root));
		}

		void SimpleOpenGLRenderingEngine::setScene(std::shared_ptr<Scene> scene)
		{
			this->scene = scene;

			for (unsigned int index = 0; index < renderers.size(); index++)
			{
				if (rendererRoots.find(renderers.at(index)) == rendererRoots.end())
				{
					rendererRoots.insert(
						pair<std::shared_ptr<Renderer>, std::shared_ptr<Node> >(renderers.at(index), scene->getRoot()));
				}
			}
		}

		void SimpleOpenGLRenderingEngine::setViewportHeight(const int viewportHeight)
		{
			this->viewportHeight = viewportHeight;

			initialised = false;
		}

		void SimpleOpenGLRenderingEngine::setViewportWidth(const int viewportWidth)
		{
			this->viewportWidth = viewportWidth;

			initialised = false;
		}
	}
}
