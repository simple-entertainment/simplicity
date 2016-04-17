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
#include "RenderingFactory.h"

using namespace std;

namespace simplicity
{
	unique_ptr<RenderingFactory> RenderingFactory::instance;

	unique_ptr<FrameBuffer> RenderingFactory::createFrameBuffer(vector<shared_ptr<Texture>> textures, bool hasDepth)
	{
		return instance->createFrameBufferInternal(textures, hasDepth);
	}

	shared_ptr<Pipeline> RenderingFactory::createPipeline(const string& name)
	{
		return instance->createPipelineInternal(name);
	}

	shared_ptr<Pipeline> RenderingFactory::createPipeline(unique_ptr<Shader> vertexShader,
														  unique_ptr<Shader> geometryShader,
														  unique_ptr<Shader> fragmentShader)
	{
		return instance->createPipelineInternal(move(vertexShader), move(geometryShader), move(fragmentShader));
	}

	unique_ptr<Shader> RenderingFactory::createShader(Shader::Type type, const Resource& resource)
	{
		return instance->createShaderInternal(type, resource);
	}

	unique_ptr<Shader> RenderingFactory::createShader(Shader::Type type, const string& name)
	{
		return instance->createShaderInternal(type, name);
	}

	shared_ptr<Texture> RenderingFactory::createTexture(const char* data, unsigned int length, PixelFormat format)
	{
		return instance->createTextureInternal(data, length, format);
	}

	shared_ptr<Texture> RenderingFactory::createTexture(char* rawData, unsigned int width, unsigned int height,
														PixelFormat format)
	{
		return instance->createTextureInternal(rawData, width, height, format);
	}

	shared_ptr<Texture> RenderingFactory::createTexture(Resource& image, PixelFormat format)
	{
		return instance->createTextureInternal(image, format);
	}

	void RenderingFactory::setInstance(unique_ptr<RenderingFactory> instance)
	{
		RenderingFactory::instance = move(instance);
	}
}
