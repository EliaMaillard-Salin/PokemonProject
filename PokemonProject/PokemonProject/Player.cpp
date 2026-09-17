#include "Player.h"

Player::Player()
{
	MeshComponent::InitObjectType(m_type);
	RigidBody::InitObjectType(m_type);
	Collider::InitObjectType(m_type);

	MeshComponent::SetShape(MeshComponent::DrawableShape::FILLED_ELLIPSE);
	SetColor(YELLOW);
	SetSize({ 15.0f,25.0f });
}

Player::~Player()
{}

void Player::Update()
{
	HandleMovement();
}

Vector2 Player::GetDrawingPosition() const
{
	return m_position;
}

Vector2 Player::GetDrawingSize() const
{
	return m_size;
}

Vector2 Player::GetMovePosition() const
{
	return m_position;
}

void Player::SetMovePosition(Vector2 newPos)
{
	m_position = newPos;
}

void Player::HandleMovement()
{
	m_speed = 2.0f;
	if (IsKeyDown(KEY_Q))
		m_direction.x = -1.0f;
	if (IsKeyDown(KEY_D))
		m_direction.x = 1.0f;
	if (IsKeyDown(KEY_Z))
		m_direction.y = -1.0f;
	if (IsKeyDown(KEY_S))
		m_direction.y = 1.0f;

	if (m_direction.x && m_direction.y)
	{
		m_direction.x /= 2.0f;
		m_direction.y /= 2.0f;
	}

	if (!(m_direction.x || m_direction.y))
		m_speed = 0.0f;
}
