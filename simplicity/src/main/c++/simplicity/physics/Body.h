#ifndef BODY_H_
#define BODY_H_

#include "../entity/Component.h"
#include "../model/Model.h"

namespace simplicity
{
	class Body : public Component
	{
		public:
			struct Material
			{
				float density;

				float friction;

				float mass;

				float restitution;
			};

			virtual ~Body()
			{
			}

			//virtual void applyAngularImpulse(float impulse) = 0;

			virtual void applyForce(const Vector3& force, const Vector3& position) = 0;

			//virtual void applyLinearImpulse(const Vector3& impulse, const Vector3& position) = 0;

			//virtual void applyTorque(float torque) = 0;

			virtual void clearForces() = 0;

			virtual const Vector3& getLinearAcceleration() const = 0;

			virtual const Vector3& getLinearVelocity() const = 0;

			virtual float getMass() const = 0;

			virtual const Material& getMaterial() const = 0;

			virtual const Model* getModel() const = 0;

			virtual bool isDynamic() = 0;

			virtual void setDynamic(bool dynamic) = 0;

			virtual void setLinearVelocity(const Vector3& linearVelocity) = 0;

			virtual void setMass(float mass) = 0;

			virtual void setMaterial(const Material& material) = 0;
	};
}

#endif /* BODY_H_ */
