#include "MovableObject.h"


MovableObject::MovableObject() : GameObject(), m_direction({ 0.0f,0.0f }), m_speed(0.0f)
{
	m_type |= GameObject::Type::MOVABLE;
}

MovableObject::~MovableObject()
{
	GameObject::~GameObject();
}

float MovableObject::GetSpeed()
{
	return m_speed;
}

rl::Vector2 MovableObject::GetPosition()
{
	return m_position;
}

rl::Vector2 MovableObject::GetDirection()
{
	if (m_direction.x && m_direction.y)
	{
		m_direction.x /= 2.0f;
		m_direction.y /= 2.0f;
	}
	return m_direction;
}