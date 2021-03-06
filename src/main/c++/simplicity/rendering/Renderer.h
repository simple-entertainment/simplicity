/*
 This file is part of The Simplicity Engine.

 The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
 by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

 The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

 You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef RENDERER_H_
#define RENDERER_H_

#include <memory>

#include "../model/MeshBuffer.h"
#include "../model/Model.h"
#include "Pipeline.h"

namespace simplicity
{
	/**
	 * <p>
	 * Renders models.
	 * </p>
	 */
	class SIMPLE_API Renderer
	{
		public:
			/**
			 * <p>
			 * Allows polymorphism.
			 * </p>
			 */
			virtual ~Renderer()
			{
			}

			/**
			 * <p>
			 * Determines whether this renderer clears the color buffer when it is initialised.
			 * </p>
			 *
			 * @return True if this renderer clears the color buffer, false otherwise.
			 */
			virtual bool clearsColorBuffer() const = 0;

			/**
			 * <p>
			 * Determines whether this renderer clears the depth buffer when it is initialised.
			 * </p>
			 *
			 * @return True if this renderer clears the depth buffer, false otherwise.
			 */
			virtual bool clearsDepthBuffer() const = 0;

			/**
			 * <p>
			 * Determines whether this renderer clears the stencil buffer when it is initialised.
			 * </p>
			 *
			 * @return True if this renderer clears the stencil buffer, false otherwise.
			 */
			virtual bool clearsStencilBuffer() const = 0;

			/**
			 * <p>
			 * Cleans up the rendering environment.
			 * </p>
			 */
			virtual void dispose() = 0;

			/**
			 * <p>
			 * Retrieves the color used to clear the color buffer.
			 * </p>
			 *
			 * @return The color used to clear the color buffer.
			 */
			virtual const Vector4& getClearingColor() const = 0;

			/**
			 * <p>
			 * Retrieves the default pipeline to be applied when rendering models that do not specify their own
			 * pipeline.
			 * </p>
			 *
			 * @return The default pipeline to be applied when rendering models that do not specify their own pipeline.
			 */
			virtual Pipeline* getDefaultPipeline() = 0;

			/**
			 * <p>
			 * Initializes the rendering environment.
			 * </p>
			 */
			virtual void init() = 0;

			/**
			 * <p>
			 * Determines if the scissor test is enabled.
			 * </p>
			 *
			 * @return True if the scissor test is enabled, false otherwise.
			 */
			virtual bool isScissorEnabled() const = 0;

			/**
			 * <p>
			 * Renders models in a buffer.
			 * </p>
			 *
			 * @param buffer The buffer the models are contained in.
			 * @param modelsAndTransforms The models to render and the transforms to apply to them.
			 */
			virtual void render(const MeshBuffer& buffer,
					const std::vector<std::pair<Model*, Matrix44>>& modelsAndTransforms) = 0;

			/**
			 * <p>
			 * Sets whether this renderer clears the color, depth and stencil buffers when it is initialised.
			 * </p>
			 *
			 * @param clearBuffers Clear the color, depth and stencil buffers?
			 */
			virtual void setClearBuffers(bool clearBuffers) = 0;

			/**
			 * <p>
			 * Sets whether this renderer clears the color buffer when it is initialised.
			 * </p>
			 *
			 * @param clearColorBuffer Clear the color buffer?
			 */
			virtual void setClearColorBuffer(bool clearColorBuffer) = 0;

			/**
			 * <p>
			 * Sets whether this renderer clears the depth buffer when it is initialised.
			 * </p>
			 *
			 * @param clearDepthBuffer Clear the depth buffer?
			 */
			virtual void setClearDepthBuffer(bool clearDepthBuffer) = 0;

			/**
			 * <p>
			 * Sets the color used to clear the color buffer.
			 * </p>
			 *
			 * @param clearingColor The color used to clear the color buffer.
			 */
			virtual void setClearingColor(const Vector4& clearingColor) = 0;

			/**
			 * <p>
			 * Sets whether this renderer clears the stencil buffer when it is initialised.
			 * </p>
			 *
			 * @param clearStencilBuffer Clear the stencil buffer?
			 */
			virtual void setClearStencilBuffer(bool clearStencilBuffer) = 0;

			/**
			* <p>
			* Sets the default pipeline to be applied when rendering models that do not specify their own pipeline.
			* </p>
			*
			* @param defaultPipeline The default pipeline to be applied when rendering models that do not specify
			* their own pipeline.
			*/
			virtual void setDefaultPipeline(std::unique_ptr<Pipeline> defaultPipeline) = 0;

			/**
			 * <p>
			 * Sets the region the scissor test will crop to.
			 * </p>
			 *
			 * @param topLeft The top left corner of the cropped area.
			 * @param bottomRight The bottom right corner of the cropped area.
			 */
			virtual void setScissor(const Vector2ui& topLeft,
					const Vector2ui& bottomRight) = 0;

			/**
			 * <p>
			 * Enables or disables the scissor test.
			 * </p>
			 *
			 * @param scissorEnabled Enable the scissor test?
			 */
			virtual void setScissorEnabled(bool scissorEnabled) = 0;
	};
}

#endif /* RENDERER_H_ */
