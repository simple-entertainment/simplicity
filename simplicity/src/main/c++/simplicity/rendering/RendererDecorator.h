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
#ifndef RENDERERDECORATOR_H_
#define RENDERERDECORATOR_H_

#include "Renderer.h"

namespace simplicity
{
	/**
	 * <p>
	 * A convenience class for decorating a {@link simplicity::Renderer Renderer}. Ensures the correct order of
	 * initialisation and destruction. This is especially useful when more than one decoration is applied to a
	 * <code>Renderer</code>.
	 * </p>
	 *
	 * @author Gary Buyn
	 */
	class RendererDecorator : public virtual Renderer
	{
		public:
			/**
			 * <p>
			 * Creates an instance of <code>RendererDecorator</code>.
			 * </p>
			 *
			 * @param renderer The decorated {@link simplicity::Renderer Renderer}.
			 */
			RendererDecorator(boost::shared_ptr<Renderer> renderer);

			void
			dispose();

			Renderer::DrawingMode
			getDrawingMode() const;

			/**
			 * <p>
			 * Retrieves the decorated {@link simplicity::Renderer Renderer}.
			 * </p>
			 *
			 * @return The decorated <code>Renderer</code>.
			 */
			boost::shared_ptr<Renderer>
			getRenderer();

			void
			init();

			void
			renderModel(const Model& model);

			void
			setDrawingMode(const Renderer::DrawingMode mode);

			/**
			 * <p>
			 * Sets the decorated {@link simplicity::Renderer Renderer}.
			 * </p>
			 *
			 * @param renderer The decorated <code>Renderer</code>.
			 */
			void
			setRenderer(boost::shared_ptr<Renderer> renderer);

		private:
			/**
			 * <p>
			 * The decorated {@link simplicity::Renderer Renderer}.
			 * </p>
			 */
			boost::shared_ptr<Renderer> renderer;

			/**
			 * <p>
			 * Reverts the rendering environment after the decorated {@link simplicity::Renderer Renderer} is used.
			 * </p>
			 */
			virtual void
			onDispose() = 0;

			/**
			 * <p>
			 * Adapts the rendering environment before the decorated {@link simplicity::Renderer Renderer} is used.
			 * </p>
			 */
			virtual void
			onInit() = 0;
	};
}

#endif /* RENDERERDECORATOR_H_ */
