#ifndef COLLIDABLEOBJECT_H
#define COLLIDABLEOBJECT_H

#include "GameObject.h"

class CollidableObject : public GameObject
{
public:
	enum ColliderShape
	{
		NONE = 0,
		RECTANGLE = 1 << 0,
		CIRCLE = 1 << 1,
	};

	CollidableObject();
	virtual ~CollidableObject();
	void Update() override {}

	virtual void OnCollisionEnter() {}
	virtual void OnCollision() {}
	virtual void OnCollisionExit() {}

	std::uint8_t GetCollShape();
	rl::Vector2 GetPosition();
	rl::Vector2 GetSize();
	bool IsTrigger();



private:
	std::uint8_t m_shape;
	bool m_isTrigger;
	float m_width;
	float m_height;

	std::list<CollidableObject*>::iterator m_positionInCollider;
	bool m_isColliding;
};

#endif // !COLLIDABLEOBJECT_H
