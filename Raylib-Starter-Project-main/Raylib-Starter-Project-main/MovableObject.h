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
	Vector2 GetDirection();
	Vector2 GetPosition();

private:
	float m_speed;
	Vector2 m_direction;
};

#endif // !MOVABLEOBJECT_H

