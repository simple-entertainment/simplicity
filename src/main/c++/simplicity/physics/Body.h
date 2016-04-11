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
#ifndef BODY_H_
#define BODY_H_

#include "../entity/Component.h"
#include "../math/Vector.h"

namespace simplicity
{
	/**
	 * <p>
	 * A physical body.
	 * </p>
	 */
	class SIMPLE_API Body : public Component
	{
		public:
			/**
			 * <p>
			 * A physical material.
			 * </p>
			 *
			 * <p>
			 * Physics implementations typically only use either density or mass but not both e.g. Bullet Physics uses
			 * mass and PhysX uses density.
			 * </p>
			 */
			struct Material
			{
				/**
				 * <p>
				 * The density of the body.
				 * </p>
				 */
				float density;

				/**
				 * <p>
				 * The friction coefficient of the body.
				 * </p>
				 */
				float friction;

				/**
				 * <p>
				 * The mass of the body.
				 * </p>
				 */
				float mass;

				/**
				 * <p>
				 * The restitution (bounciness) of the body.
				 * </p>
				 */
				float restitution;
			};

			/**
			 * <p>
			 * Allows polymorphism.
			 * </p>
			 */
			virtual ~Body()
			{
			}

			//virtual void applyAngularImpulse(float impulse) = 0;

			/**
			 * <p>
			 * Applies a force to a position on the body.
			 * </p>
			 *
			 * @param force The force to apply.
			 * @param position The position at which to apply the force.
			 */
			virtual void applyForce(const Vector3& force, const Vector3& position) = 0;

			//virtual void applyLinearImpulse(const Vector3& impulse, const Vector3& position) = 0;

			/**
			 * <p>
			 * Applies torque to the body.
			 * </p>
			 *
			 * @param force The torque to apply.
			 */
			virtual void applyTorque(const Vector3& torque) = 0;

			/**
			 * <p>
			 * Clears any forces acting on the body.
			 * </p>
			 */
			virtual void clearForces() = 0;

			/**
			 * <p>
			 * Retrieves the linear velocity of the body.
			 * </p>
			 *
			 * @return The linear velocity of the body.
			 */
			virtual Vector3 getLinearVelocity() const = 0;

			/**
			 * <p>
			 * Retrieves the material this body is constructed from.
			 * </p>
			 *
			 * @return The material this body is constructed from.
			 */
			virtual const Material& getMaterial() const = 0;

			/**
			 * <p>
			 * Determines if this body is dynamic.
			 * </p>
			 *
			 * @return True if this body is dynamic, false otherwise.
			 */
			virtual bool isDynamic() = 0;

			/**
			 * <p>
			 * Sets this body to be dynamic or static.
			 * </p>
			 *
			 * @param dynamic Dynamic or static?
			 */
			virtual void setDynamic(bool dynamic) = 0;

			/**
			 * <p>
			 * Sets the linear velocity of the body.
			 * </p>
			 *
			 * @param linearVelocity The linear velocity of the body.
			 */
			virtual void setLinearVelocity(const Vector3& linearVelocity) = 0;

			/**
			 * <p>
			 * Sets the material this body is constructed from.
			 * </p>
			 *
			 * @param material The material this body is constructed from.
			 */
			virtual void setMaterial(const Material& material) = 0;
	};
}

#endif /* BODY_H_ */
