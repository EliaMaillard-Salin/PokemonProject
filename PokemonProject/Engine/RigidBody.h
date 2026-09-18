#ifndef RIGIDBODY_H
#define RIGIDBODY_H

#include "Component.h"

class RigidBody : public Component
{
public:
	RigidBody(GameObject* owner);
	virtual ~RigidBody();

	void FixedUpdate() override;

	float GetSpeed();

	void SetSpeed(float speed);
	void SetDirection(Vector2 dir);

	void Move();
	void Stop();

protected:
	float m_speed;
	Vector2 m_direction;
	bool m_isMoving;

	std::list<std::shared_ptr<RigidBody>>::iterator m_moveIterator;
};

#endif // !MOVABLEOBJECT_H

