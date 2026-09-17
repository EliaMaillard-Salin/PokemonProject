#ifndef MOVABLEOBJECT_H
#define MOVABLEOBJECT_H

#include "GameObject.h"

class MovableObject : public GameObject
{
public:
	MovableObject();
	virtual ~MovableObject();

	void Update() override {}

	float GetSpeed();
	rl::Vector2 GetDirection();
	rl::Vector2 GetPosition();

private:
	float m_speed;
	rl::Vector2 m_direction;

	std::list<MovableObject*>::iterator m_positionInMovable;
};

#endif // !MOVABLEOBJECT_H

