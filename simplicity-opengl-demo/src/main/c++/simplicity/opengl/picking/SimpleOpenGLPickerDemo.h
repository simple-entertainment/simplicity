/*
 * Copyright © Simple Entertainment Limited 2011
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
#ifndef SIMPLEOPENGLPICKERDEMO_H_
#define SIMPLEOPENGLPICKERDEMO_H_

#include <simplicity/engine/SimpleCompositeEngine.h>
#include <simplicity/picking/engine/PickingEngine.h>
#include <simplicity/rendering/engine/RenderingEngine.h>

#include "../OpenGLDemo.h"

namespace simplicity
{
	namespace opengl
	{
		/**
		 * <p>
		 * A small demonstration of the {@link simplicity::opengl::SimpleOpenGLPicker SimpleOpenGLPicker}.
		 * </p>
		 */
		class SimpleOpenGLPickerDemo : public OpenGLDemo, public PickListener
		{
			public:
				/**
				 * <p>
				 * Creates an instance of <code>SimpleOpenGLPickerDemo</code>.
				 * </p>
				 */
				SimpleOpenGLPickerDemo();

				/**
				 * <p>
				 * Disposes of an instance of <code>SimpleOpenGLPickerDemo</code>.
				 * </p>
				 */
				virtual ~SimpleOpenGLPickerDemo();

				void advance();

				void dispose();

				std::shared_ptr<Camera> getCamera();

				std::string getDescription();

				std::string getTitle();

				void init();

				void mouseClick(const int x, const int y);

				void selectModel(const PickEvent& event);

				void operator()(const PickEvent& event) const;

			private:
				/**
				 * <p>
				 * The overall engine for the demo.
				 * </p>
				 */
				SimpleCompositeEngine engine;

				/**
				 * <p>
				 * The renderer used to render the outline of the selected shape.
				 * </p>
				 */
				std::shared_ptr<Renderer> outlineRenderer;

				/**
				 * <p>
				 * The picking engine for the demo.
				 * </p>
				 */
				std::shared_ptr<PickingEngine> pickingEngine;

				/**
				 * <p>
				 * The rendering engine for the demo.
				 * </p>
				 */
				std::shared_ptr<RenderingEngine> renderingEngine;
		};
	}
}

#endif /* SIMPLEOPENGLPICKERDEMO_H_ */
