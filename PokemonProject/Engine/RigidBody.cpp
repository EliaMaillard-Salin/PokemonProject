#include "RigidBody.h"

#include "GameObject.h"


RigidBody::RigidBody() : m_direction({ 0.0f,0.0f }), m_speed(0.0f)
{}

RigidBody::~RigidBody()
{}


float RigidBody::GetSpeed()
{
	return m_speed;
}

Vector2 RigidBody::GetDirection()
{
	return m_direction;
}