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
#include "RendererDecorator.h"

using namespace boost;

namespace simplicity
{
	RendererDecorator::RendererDecorator(shared_ptr<Renderer> renderer) :
		renderer(renderer)
	{
	}

	void RendererDecorator::dispose()
	{
		renderer->dispose();

		onDispose();
	}

	Renderer::DrawingMode RendererDecorator::getDrawingMode() const
	{
		return (renderer->getDrawingMode());
	}

	/**
	 * <p>
	 * Retrieves the wrapped {@link simplicity::Renderer Renderer}.
	 * </p>
	 *
	 * @return The wrapped <code>Renderer</code>.
	 */
	shared_ptr<Renderer> RendererDecorator::getRenderer()
	{
		return (renderer);
	}

	void RendererDecorator::init()
	{
		onInit();

		renderer->init();
	}

	void RendererDecorator::renderModel(const Model& model)
	{
		renderer->renderModel(model);
	}

	void RendererDecorator::setDrawingMode(const Renderer::DrawingMode mode)
	{
		renderer->setDrawingMode(mode);
	}

	void RendererDecorator::setRenderer(shared_ptr<Renderer> renderer)
	{
		this->renderer = renderer;
	}
}
