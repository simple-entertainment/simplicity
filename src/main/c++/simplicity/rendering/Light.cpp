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
#include "Light.h"

using namespace std;

namespace simplicity
{
	Light::Light(const string& name) :
		active(false),
		ambient(),
		attenuation(),
		diffuse(),
		direction(),
		name(name),
		range(100.0f),
		specular(),
		strength(1.0f)
	{
		activate();
	}

	void Light::activate()
	{
		active = true;
	}

	void Light::apply(Pipeline& pipeline, const Vector3& position)
	{
		pipeline.set(name + "Light", "attenuation", attenuation);
		pipeline.set(name + "Light", "direction", direction);
		pipeline.set(name + "Light", "position", position);
		pipeline.set(name + "Light", "range", range);
		pipeline.set(name + "Light", "specular", specular);
		pipeline.set(name + "Light", "strength", strength);

		if (active)
		{
			pipeline.set(name + "Light", "ambient", ambient);
			pipeline.set(name + "Light", "diffuse", diffuse);
			pipeline.set(name + "Light", "specular", specular);
		}
		else
		{
			pipeline.set(name + "Light", "ambient", Vector4(0.0f, 0.0f, 0.0f, 1.0f));
			pipeline.set(name + "Light", "diffuse", Vector4(0.0f, 0.0f, 0.0f, 1.0f));
			pipeline.set(name + "Light", "specular", Vector4(0.0f, 0.0f, 0.0f, 1.0f));
		}
	}

	void Light::deactivate()
	{
		active = false;
	}

	const Vector4& Light::getAmbient() const
	{
		return ambient;
	}

	const Vector3& Light::getAttenuation() const
	{
		return attenuation;
	}

	const Vector4& Light::getDiffuse() const
	{
		return diffuse;
	}

	const Vector3& Light::getDirection() const
	{
		return direction;
	}

	const string& Light::getName() const
	{
		return name;
	}

	float Light::getRange() const
	{
		return range;
	}

	const Vector4& Light::getSpecular() const
	{
		return specular;
	}

	float Light::getStrength() const
	{
		return strength;
	}

	bool Light::isActive() const
	{
		return active;
	}

	void Light::setAmbient(const Vector4& ambient)
	{
		this->ambient = ambient;
	}

	void Light::setAttenuation(const Vector3& attenuation)
	{
		this->attenuation = attenuation;
	}

	void Light::setDiffuse(const Vector4& diffuse)
	{
		this->diffuse = diffuse;
	}

	void Light::setDirection(const Vector3& direction)
	{
		this->direction = direction;
	}

	void Light::setRange(float range)
	{
		this->range = range;
	}

	void Light::setSpecular(const Vector4& specular)
	{
		this->specular = specular;
	}

	void Light::setStrength(float strength)
	{
		this->strength = strength;
	}
}
