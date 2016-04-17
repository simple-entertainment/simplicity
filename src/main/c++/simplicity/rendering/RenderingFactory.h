/*
 * Copyright © 2013 Simple Entertainment Limited
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
#ifndef RENDERINGFACTORY_H_
#define RENDERINGFACTORY_H_

#include <memory>
#include <string>

#include "../resources/Resource.h"
#include "FrameBuffer.h"
#include "Pipeline.h"
#include "PixelFormat.h"
#include "Shader.h"
#include "Texture.h"

namespace simplicity
{
	/**
	 * <p>
	 * A factory that creates textures.
	 * </p>
	 */
	class SIMPLE_API RenderingFactory
	{
		public:
			/**
			 * <p>
			 * Allows polymorphism.
			 * </p>
			 */
			virtual ~RenderingFactory()
			{
			}

			/**
			 * <p>
			 * Creates a frame buffer composed from the given textures.
			 * </p>
			 *
			 * @param textures The textures to draw to.
			 * @param hasDepth Determines if the frame buffer should contain a depth buffer.
			 *
			 * @return The frame buffer.
			 */
			static std::unique_ptr<FrameBuffer> createFrameBuffer(std::vector<std::shared_ptr<Texture>> textures, bool hasDepth);

			/**
			 * <p>
			 * Creates the named pipeline, see the documentation of the plugin you are using for supported pipelines.
			 * </p>
			 *
			 * @param name The name of the pipeline to create.
			 *
			 * @return The pipeline.
			 */
			static std::shared_ptr<Pipeline> createPipeline(const std::string& name = "simple");

			/**
			 * <p>
			 * Creates a pipeline composed from the given shaders.
			 * </p>
			 *
			 * @param vertexShader The vertex shader.
			 * @param geometryShader The geometry shader.
			 * @param fragmentShader The fragment shader.
			 *
			 * @return The pipeline.
			 */
			static std::shared_ptr<Pipeline> createPipeline(std::unique_ptr<Shader> vertexShader,
															std::unique_ptr<Shader> geometryShader,
															std::unique_ptr<Shader> fragmentShader);

			/**
			 * <p>
			 * Creates a shader from the given resource.
			 * </p>
			 *
			 * @param type The type of shader to create.
			 * @param resource The resource to create the shader from.
			 *
			 * @return The shader.
			 */
			static std::unique_ptr<Shader> createShader(Shader::Type type, const Resource& resource);

			/**
			 * <p>
			 * Creates the named shader, see the documentation of the plugin you are using for supported shaders.
			 * </p>
			 *
			 * @param type The type of shader to create.
			 * @param name The name of the shader to create.
			 *
			 * @return The shader.
			 */
			static std::unique_ptr<Shader> createShader(Shader::Type type, const std::string& name = "simple");

			/**
			 * <p>
			 * Creates a texture from in-memory data.
			 * </p>
			 *
			 * @param data The texture data.
			 * @param length The length of the data.
			 * @param format The format of the texture.
			 *
			 * @return The texture.
			 */
			static std::shared_ptr<Texture> createTexture(const char* data, unsigned int length, PixelFormat format);

			/**
			 * <p>
			 * Creates a texture from raw (i.e. non-encoded RGBA float) in-memory data.
			 * </p>
			 *
			 * @param data The texture data.
			 * @param width The width of the texture.
			 * @param height The height of the texture.
			 * @param format The format of the texture.
			 *
			 * @return The texture.
			 */
			static std::shared_ptr<Texture> createTexture(char* rawData, unsigned int width, unsigned int height,
														  PixelFormat format);

			/**
			 * <p>
			 * Creates a texture from a resource.
			 * </p>
			 *
			 * @param image The image resource.
			 * @param format The format of the texture.
			 *
			 * @return The texture.
			 */
			static std::shared_ptr<Texture> createTexture(Resource& image, PixelFormat format);

			/**
			 * <p>
			 * Sets the concrete factory instance used to create the textures.
			 * </p>
			 *
			 * @param instance The concrete factory instance.
			 */
			static void setInstance(std::unique_ptr<RenderingFactory> instance);

		private:
			static std::unique_ptr<RenderingFactory> instance;

			virtual std::unique_ptr<FrameBuffer> createFrameBufferInternal(std::vector<std::shared_ptr<Texture>> textures,
																		   bool hasDepth) = 0;

			virtual std::shared_ptr<Pipeline> createPipelineInternal(const std::string& name = "simple") = 0;

			virtual std::shared_ptr<Pipeline> createPipelineInternal(std::unique_ptr<Shader> vertexShader,
																	std::unique_ptr<Shader> geometryShader,
																	std::unique_ptr<Shader> fragmentShader) = 0;

			virtual std::unique_ptr<Shader> createShaderInternal(Shader::Type type, const Resource& resource) = 0;

			virtual std::unique_ptr<Shader> createShaderInternal(Shader::Type type, const std::string& name = "simple") = 0;

			virtual std::shared_ptr<Texture> createTextureInternal(const char* data, unsigned int length,
																  PixelFormat format) = 0;

			virtual std::shared_ptr<Texture> createTextureInternal(char* rawData, unsigned int width,
																  unsigned int height,
																  PixelFormat format) = 0;

			virtual std::shared_ptr<Texture> createTextureInternal(Resource& image, PixelFormat format) = 0;
	};
}

#endif /* RENDERINGFACTORY_H_ */
