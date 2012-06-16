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
#ifndef OPENGLDEMO_H_
#define OPENGLDEMO_H_

#include <boost/any.hpp>

#include <simplicity/rendering/Light.h>

#include <simplicity/Demo.h>

namespace simplicity
{
	namespace opengl
	{
		/**
		 * <p>
		 * Provides common elements required by OpenGL demos.
		 * </p>
		 */
		class OpenGLDemo : public Demo
		{
			public:
				OpenGLDemo();

			protected:
				/**
				 * <p>
				 * Creates a standard OpenGL camera in the standard location for use with demos.
				 * </p>
				 *
				 * @param parentNode The node under which the camera should be added.
				 *
				 * @return The standard camera.
				 */
				std::shared_ptr<Camera> addStandardCamera(std::shared_ptr<Node> parentNode);

				/**
				 * <p>
				 * Creates a standard OpenGL light in the standard location for use with demos.
				 * </p>
				 *
				 * @param parentNode The node under which the light should be added.
				 *
				 * @return The standard light.
				 */
				std::shared_ptr<Light> addStandardLight(std::shared_ptr<Node> parentNode);

				std::vector<std::shared_ptr<Model> > createDescription();

				std::shared_ptr<Model> createTitle();

				/**
				 * <p>
				 * Creates a standard OpenGL capsule in the standard location for use with demos.
				 * </p>
				 *
				 * @param parentNode The node under which the capsule should be added.
				 */
				std::shared_ptr<Model> createStandardCapsule();

				/**
				 * <p>
				 * Creates a standard OpenGL cylinder in the standard location for use with demos.
				 * </p>
				 *
				 * @param parentNode The node under which the cylinder should be added.
				 */
				std::shared_ptr<Model> createStandardCylinder();

				/**
				 * <p>
				 * Creates a standard OpenGL sphere in the standard location for use with demos.
				 * </p>
				 *
				 * @param parentNode The node under which the sphere should be added.
				 */
				std::shared_ptr<Model> createStandardSphere();

				/**
				 * <p>
				 * Creates a standard OpenGL torus in the standard location for use with demos.
				 * </p>
				 *
				 * @param parentNode The node under which the torus should be added.
				 */
				std::shared_ptr<Torus> createStandardTorus();

				void dispose();

				shared_ptr<Node> getModelsRoot();

				void init();

			private:
				/**
				 * <p>
				 * The root node of the scene (excluding the camera, light(s) and text).
				 * </p>
				 */
				std::shared_ptr<Node> modelsRoot;

				/**
				 * <p>
				 * The current position of the mouse on the x axis.
				 * </p>
				 */
				int mouseX;

				/**
				 * <p>
				 * The current position of the mouse on the y axis.
				 * </p>
				 */
				int mouseY;

				std::shared_ptr<Model> createDescriptionLine(const std::string& line, const unsigned int lineNum);

				virtual void onDispose() = 0;

				virtual void onInit() = 0;

				/**
				 * <p>
				 * Responds to motion events.
				 * </p>
				 */
				void onMotion(const boost::any data);
		};
	}
}

#endif /* OPENGLDEMO_H_ */
