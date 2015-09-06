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

#include "../entity/Component.h"
#include "../math/Vector.h"
#include "../rendering/Pipeline.h"

namespace simplicity
{
	/**
	 * <p>
	 * A light source. All of the properties of this light source are passed to the shader and it is the shader which
	 * will determine which properties are used and how to use them.
	 * </p>
	 */
	class SIMPLE_API Light : public Component
	{
		public:
			/**
			 * @param name The name of the light source.
			 */
			Light();

			/**
			 * <p>
			 * Activates this light source. Models will be illuminated by it.
			 * </p>
			 */
			void activate();

			/**
			 * <p>
			 * Applies this light source to a pipeline.
			 * </p>
			 *
			 * @param pipeline The pipeline to apply this light source to.
			 * @param position The position of this light source.
			 */
			void apply(Pipeline& pipeline, const Vector3& position);

			/**
			 * <p>
			 * Deactivates this light source. Models will not be illuminated by it.
			 * </p>
			 */
			void deactivate();

			/**
			 * <p>
			 * Retrieves the ambient light provided by this light source.
			 * </p>
			 *
			 * @return The ambient light provided by this light source.
			 */
			const Vector4& getAmbient() const;

			/**
			 * <p>
			 * Retrieves the rate at which the intensity of the light provided by this light source will decrease at
			 * longer range. The first element of the vector is the linear dropoff, the second is the square dropoff
			 * and the third is the cubic dropoff.
			 * </p>
			 *
			 * @return The rate at which the intensity of the light provided by this light source will decrease at
			 * longer range.
			 */
			const Vector3& getAttenuation() const;

			/**
			 * <p>
			 * Retrieves the diffuse light provided by this light source.
			 * </p>
			 *
			 * @return The diffuse light provided by this light source.
			 */
			const Vector4& getDiffuse() const;

			/**
			 * <p>
			 * Retrieves the direction in which this light source is pointed.
			 * </p>
			 *
			 * @return The direction in which this light source is pointed.
			 */
			const Vector3& getDirection() const;

			/**
			 * <p>
			 * Retrieves the name of the light source. This name will be used to identify it in the shader code.
			 * </p>
			 *
			 * @return The name of the light source.
			 */
			const std::string& getName() const;

			/**
			 * <p>
			 * Retrieves the distance that the light from this light source will reach.
			 * </p>
			 *
			 * @return The distance that the light from this light source will reach.
			 */
			float getRange() const;

			/**
			 * <p>
			 * Retrieves the specular light provided by this light source.
			 * </p>
			 *
			 * @return The specular light provided by this light source.
			 */
			const Vector4& getSpecular() const;

			/**
			 * <p>
			 * Retrieves the strength of this light source.
			 * </p>
			 *
			 * @return The strength of this light source.
			 */
			float getStrength() const;

			/**
			 * <p>
			 * Determines if this light source is active. Models will only be illuminated by an active light source.
			 * </p>
			 */
			bool isActive() const;

			/**
			 * <p>
			 * Sets the ambient light provided by this light source.
			 * </p>
			 *
			 * @param ambient The ambient light provided by this light source.
			 */
			void setAmbient(const Vector4& ambient);

			/**
			 * <p>
			 * Sets the rate at which the intensity of the light provided by this light source will decrease at longer
			 * range. The first element of the vector is the linear dropoff, the second is the square dropoff and the
			 * third is the cubic dropoff.
			 * </p>
			 *
			 * @param attenuation The rate at which the intensity of the light provided by this light source will
			 * decrease at longer range.
			 */
			void setAttenuation(const Vector3& attenuation);

			/**
			 * <p>
			 * Sets the diffuse light provided by this light source.
			 * </p>
			 *
			 * @param diffuse The diffuse light provided by this light source.
			 */
			void setDiffuse(const Vector4& diffuse);

			/**
			 * <p>
			 * Sets the direction in which this light source is pointed.
			 * </p>
			 *
			 * @param direction The direction in which this light source is pointed.
			 */
			void setDirection(const Vector3& direction);

			/**
			 * <p>
			 * Sets the name of the light source. This name will be used to identify it in the shader code.
			 * </p>
			 *
			 * @param name The name of the light source.
			 */
			 void setName(const std::string& name);

			/**
			 * <p>
			 * Sets the distance that the light from this light source will reach.
			 * </p>
			 *
			 * @param range The distance that the light from this light source will reach.
			 */
			void setRange(float range);

			/**
			 * <p>
			 * Sets the specular light provided by this light source.
			 * </p>
			 *
			 * @param specular The specular light provided by this light source.
			 */
			void setSpecular(const Vector4& specular);

			/**
			 * <p>
			 * Sets the strength of this light source.
			 * </p>
			 *
			 * @param strength The strength of this light source.
			 */
			void setStrength(float strength);

		private:
			bool active;

			Vector4 ambient;

			Vector3 attenuation;

			Vector4 diffuse;

			Vector3 direction;

			std::string name;

			float range;

			Vector4 specular;

			float strength;
	};
}

#endif /* LIGHT_H_ */
