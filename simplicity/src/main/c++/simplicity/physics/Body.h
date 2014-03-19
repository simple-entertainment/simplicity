#ifndef BODY_H_
#define BODY_H_

#include "../entity/Component.h"
#include "../model/Model.h"

namespace simplicity
{
	/**
	 * <p>
	 * A physical body.
	 * </p>
	 */
	class Body : public Component
	{
		public:
			/**
			 * <p>
			 * A physical material.
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

			//virtual void applyTorque(float torque) = 0;

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
			virtual const Vector3& getLinearVelocity() const = 0;

			/**
			 * <p>
			 * Retrieves the mass of the body.
			 * </p>
			 *
			 * @return The mass of the body.
			 */
			virtual float getMass() const = 0;

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
			 * Retrieves the geometry of the body.
			 * </p>
			 *
			 * @return The geometry of the body.
			 */
			virtual const Model* getModel() const = 0;

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
			 * Sets the mass of the body.
			 * </p>
			 *
			 * @param mass The mass of the body.
			 */
			virtual void setMass(float mass) = 0;

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
