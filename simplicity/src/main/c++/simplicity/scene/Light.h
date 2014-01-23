/*
 * Copyright © 2012 Simple Entertainment Limited
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
#ifndef LIGHT_H_
#define LIGHT_H_

#include <string>

#include "../math/Vector.h"
#include "../rendering/Shader.h"

namespace simplicity
{
	class Light
	{
		public:
			virtual ~Light()
			{
			}

			virtual void activate() = 0;

			virtual void apply(Shader& shader) = 0;

			virtual void deactivate() = 0;

			virtual const Vector4& getAmbientComponent() const = 0;

			virtual const Vector3& getAttenuation() const = 0;

			virtual const Vector4& getDiffuseComponent() const = 0;

			virtual const Vector3& getDirection() const = 0;

			virtual const std::string& getName() const = 0;

			virtual float getRange() const = 0;

			virtual const Vector4& getSpecularComponent() const = 0;

			virtual float getStrength() const = 0;

			virtual const Vector3& getTranslation() const = 0;

			virtual bool isActive() const = 0;

			virtual void setAmbientComponent(const Vector4& ambient) = 0;

			virtual void setAttenuation(const Vector3& attenuation) = 0;

			virtual void setDiffuseComponent(const Vector4& diffuse) = 0;

			virtual void setDirection(const Vector3& direction) = 0;

			virtual void setRange(float range) = 0;

			virtual void setSpecularComponent(const Vector4& specular) = 0;

			virtual void setStrength(float strength) = 0;

			virtual void setTranslation(const Vector3& translation) = 0;
	};
}

#endif /* LIGHT_H_ */
