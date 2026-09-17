#include "Collider.h"

#include "GameObject.h"



Collider::Collider() : m_shape(ColliderShape::NONE), m_isTrigger(false), m_width(0.0f), m_height(0.0f), m_isColliding(false)
{}

Collider::~Collider()
{}

void Collider::InitObjectType(std::uint8_t& objectType)
{
	objectType |= GameObject::Type::COLLIDABLE;
}

std::uint8_t Collider::GetCollShape()
{
	return m_shape;
}

Vector2 Collider::GetSize()
{
	return { m_width,m_height };
}

bool Collider::IsTrigger()
{
	return m_isTrigger;
}
