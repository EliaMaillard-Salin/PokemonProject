#include "Player.h"

Player::Player()
{
	MeshComponent& mesh = AddComponent<MeshComponent>(Component::ID::MESH);
	mesh.SetShape(MeshComponent::DrawableShape::FILLED_ELLIPSE);
	mesh.SetColor(YELLOW);
	SetSize({ 15.0f,25.0f });
	SetPosition({ 50.0f,50.0f });

	RigidBody& rigid = AddComponent<RigidBody>(Component::ID::RIGIDBODY);
	rigid.SetSpeed(2.0f);
}

Player::~Player()
{}

void Player::Update()
{
	GameObject::Update();

	if (!m_isInCombat)
		HandleMovement();
}

void Player::HandleMovement()
{
	RigidBody& rigid = GetComponent<RigidBody>(Component::ID::RIGIDBODY);

	Vector2 dir = { 0.0f,0.0f };
	if (IsKeyDown(KEY_A))
		dir.x = -1.0f;
	if (IsKeyDown(KEY_D))
		dir.x = 1.0f;
	if (IsKeyDown(KEY_W))
		dir.y = -1.0f;
	if (IsKeyDown(KEY_S))
		dir.y = 1.0f;

	if (dir.x && dir.y)
	{
		dir.x /= 2.0f;
		dir.y /= 2.0f;
	}

	rigid.SetDirection(dir);
}
