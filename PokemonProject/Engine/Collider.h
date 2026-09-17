#ifndef COLLIDABLE_H
#define COLLIDABLE_H

#include "Component.h"

class Collider : public Component
{
public:
	enum ColliderShape
	{
		NONE = 0,
		RECTANGLE = 1 << 0,
		CIRCLE = 1 << 1,
	};

	Collider();
	virtual ~Collider();

	virtual void OnCollisionEnter() {}
	virtual void OnCollision() {}
	virtual void OnCollisionExit() {}

	std::uint8_t GetCollShape();
	Vector2 GetSize();
	bool IsTrigger();



protected:
	std::uint8_t m_shape;
	bool m_isTrigger;
	float m_width;
	float m_height;

	std::list<Collider*>::iterator m_collideIterator;
	bool m_isColliding;
};

#endif // !
