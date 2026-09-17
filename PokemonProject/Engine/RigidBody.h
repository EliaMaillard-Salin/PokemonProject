#ifndef RIGIDBODY_H
#define RIGIDBODY_H

#include "Component.h"

class RigidBody : public Component
{
public:
	RigidBody();
	virtual ~RigidBody();

	float GetSpeed();
	Vector2 GetDirection();

protected:
	float m_speed;
	Vector2 m_direction;

	std::list<std::shared_ptr<RigidBody>>::iterator m_moveIterator;
};

#endif // !MOVABLEOBJECT_H

