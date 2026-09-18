#include "Collider.h"

#include "GameObject.h"



Collider::Collider(GameObject* owner) :
	Component(owner), m_shape(ColliderShape::NONE), 
	m_isTrigger(false), m_width(0.0f), m_height(0.0f), m_isColliding(false)
{
	m_type = Component::Type::FIXED_UPDATE;
	m_id = Component::ID::COLLIDER;
}

Collider::~Collider()
{}

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
