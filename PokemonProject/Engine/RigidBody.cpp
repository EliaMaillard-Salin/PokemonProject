#include "RigidBody.h"

#include "GameObject.h"


RigidBody::RigidBody(GameObject* owner) :
	Component(owner),
	m_direction({ 0.0f,0.0f }), m_speed(0.0f), m_isMoving(false)
{
	m_id = Component::ID::RIGIDBODY;
	m_type = ComponentType::FIXED_UPDATE;
}

RigidBody::~RigidBody()
{}

void RigidBody::FixedUpdate()
{
	Vector2 pos = m_pGameObject->GetPosition();
	pos.x += m_speed * m_direction.x;
	pos.y += m_speed * m_direction.y;
	m_pGameObject->SetPosition(pos);
}


float RigidBody::GetSpeed()
{
	return m_speed;
}

void RigidBody::SetSpeed(float speed)
{
	m_speed = speed;
}

void RigidBody::SetDirection(Vector2 dir)
{
	m_direction = dir;
}


void RigidBody::Move()
{
	m_isMoving = true;
}

void RigidBody::Stop()
{
	m_isMoving = false;
}
