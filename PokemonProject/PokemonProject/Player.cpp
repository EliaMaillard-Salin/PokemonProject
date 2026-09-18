#include "Player.h"

Player::Player()
{
	MeshComponent& mesh = AddComponent<MeshComponent>(Component::ID::MESH, Component::Type::DRAW);
	mesh.SetShape(MeshComponent::DrawableShape::FILLED_ELLIPSE);
	mesh.SetColor(YELLOW);
	SetSize({ 15.0f,25.0f });
	SetPosition({ 50.0f,50.0f });
}

Player::~Player()
{}

void Player::Update()
{
	HandleMovement();
}

void Player::HandleMovement()
{
	//m_speed = 2.0f;
	//if (IsKeyDown(KEY_Q))
	//	m_direction.x = -1.0f;
	//if (IsKeyDown(KEY_D))
	//	m_direction.x = 1.0f;
	//if (IsKeyDown(KEY_Z))
	//	m_direction.y = -1.0f;
	//if (IsKeyDown(KEY_S))
	//	m_direction.y = 1.0f;

	//if (m_direction.x && m_direction.y)
	//{
	//	m_direction.x /= 2.0f;
	//	m_direction.y /= 2.0f;
	//}

	//if (!(m_direction.x || m_direction.y))
	//	m_speed = 0.0f;
}
