#include "CollidableObject.h"



CollidableObject::CollidableObject() : GameObject(), m_shape(ColliderShape::NONE), m_isTrigger(false), m_width(0.0f), m_height(0.0f), m_isColliding(false)
{
	m_type |= GameObject::Type::COLLIDABLE;
}

CollidableObject::~CollidableObject()
{}

std::uint8_t CollidableObject::GetCollShape()
{
	return m_shape;
}

rl::Vector2 CollidableObject::GetSize()
{
	return { m_width,m_height };
}

bool CollidableObject::IsTrigger()
{
	return m_isTrigger;
}
rl::Vector2 CollidableObject::GetPosition()
{
	return m_position;
}