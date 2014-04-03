/*
 * Copyright © 2014 Simple Entertainment Limited
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
#ifndef SHADER_H_
#define SHADER_H_

#include <string>

#include "../math/Matrix.h"
#include "../math/Vector.h"

namespace simplicity
{
	/**
	 * <p>
	 * A rendering pipeline.
	 * </p>
	 */
	class SIMPLE_API Shader
	{
		public:
			/**
			 * <p>
			 * Allows polymorphism.
			 * </p>
			 */
			virtual ~Shader()
			{
			}

			/**
			 * <p>
			 * Applies this shader to the rendering environment.
			 * </p>
			 */
			virtual void apply() = 0;

			/**
			 * <p>
			 * Sets a variable for use in the shaders.
			 * </p>
			 *
			 * @param name The name of the variable to set.
			 * @param value The value to set.
			 */
			virtual void setVar(const std::string& name, float value) = 0;

			/**
			 * <p>
			 * Sets a variable for use in the shaders.
			 * </p>
			 *
			 * @param name The name of the variable to set.
			 * @param value The value to set.
			 */
			virtual void setVar(const std::string& name, int value) = 0;

			/**
			 * <p>
			 * Sets a variable for use in the shaders.
			 * </p>
			 *
			 * @param name The name of the variable to set.
			 * @param value The value to set.
			 */
			virtual void setVar(const std::string& name, const Matrix44& value) = 0;

			/**
			 * <p>
			 * Sets a variable for use in the shaders.
			 * </p>
			 *
			 * @param name The name of the variable to set.
			 * @param value The value to set.
			 */
			virtual void setVar(const std::string& name, const Vector2& value) = 0;

			/**
			 * <p>
			 * Sets a variable for use in the shaders.
			 * </p>
			 *
			 * @param name The name of the variable to set.
			 * @param value The value to set.
			 */
			virtual void setVar(const std::string& name, const Vector3& value) = 0;

			/**
			 * <p>
			 * Sets a variable for use in the shaders.
			 * </p>
			 *
			 * @param name The name of the variable to set.
			 * @param value The value to set.
			 */
			virtual void setVar(const std::string& name, const Vector4& value) = 0;

			/**
			 * <p>
			 * Sets a variable for use in the shaders.
			 * </p>
			 *
			 * @param structName The name of the struct the variable belongs to.
			 * @param name The name of the variable to set.
			 * @param value The value to set.
			 */
			virtual void setVar(const std::string& structName, const std::string& name, float value) = 0;

			/**
			 * <p>
			 * Sets a variable for use in the shaders.
			 * </p>
			 *
			 * @param structName The name of the struct the variable belongs to.
			 * @param name The name of the variable to set.
			 * @param value The value to set.
			 */
			virtual void setVar(const std::string& structName, const std::string& name, int value) = 0;

			/**
			 * <p>
			 * Sets a variable for use in the shaders.
			 * </p>
			 *
			 * @param structName The name of the struct the variable belongs to.
			 * @param name The name of the variable to set.
			 * @param value The value to set.
			 */
			virtual void setVar(const std::string& structName, const std::string& name, const Matrix44& value) = 0;

			/**
			 * <p>
			 * Sets a variable for use in the shaders.
			 * </p>
			 *
			 * @param structName The name of the struct the variable belongs to.
			 * @param name The name of the variable to set.
			 * @param value The value to set.
			 */
			virtual void setVar(const std::string& structName, const std::string& name, const Vector2& value) = 0;

			/**
			 * <p>
			 * Sets a variable for use in the shaders.
			 * </p>
			 *
			 * @param structName The name of the struct the variable belongs to.
			 * @param name The name of the variable to set.
			 * @param value The value to set.
			 */
			virtual void setVar(const std::string& structName, const std::string& name, const Vector3& value) = 0;

			/**
			 * <p>
			 * Sets a variable for use in the shaders.
			 * </p>
			 *
			 * @param structName The name of the struct the variable belongs to.
			 * @param name The name of the variable to set.
			 * @param value The value to set.
			 */
			virtual void setVar(const std::string& structName, const std::string& name, const Vector4& value) = 0;
	};
}

#endif /* SHADER_H_ */
