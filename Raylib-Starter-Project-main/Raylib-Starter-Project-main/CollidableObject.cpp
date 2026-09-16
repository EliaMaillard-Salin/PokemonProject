#include "CollidableObject.h"



CollidableObject::CollidableObject() : GameObject(), m_shape(ColliderShape::NONE), m_isTrigger(false), m_width(0.0f), m_height(0.0f)
{
	m_type |= GameObject::Type::COLLIDABLE;
}

CollidableObject::~CollidableObject()
{}

std::uint8_t CollidableObject::GetCollShape()
{
	return m_shape;
}

Vector2 CollidableObject::GetSize()
{
	return Vector2();
}

bool CollidableObject::IsTrigger()
{
	return false;
}
Vector2 CollidableObject::GetPosition()
{
	return m_position;
}