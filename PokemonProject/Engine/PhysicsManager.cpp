#include "PhysicsManager.h"

#include <list>
#include "RigidBody.h"
#include "GameObject.h"
#include "Scene.h"

PhysicsManager::PhysicsManager() : m_pActiveScene(nullptr)
{
}

PhysicsManager::~PhysicsManager()
{
}

void PhysicsManager::FixedUpdate()
{
	MoveObjects();
	CheckCollisions();
}

void PhysicsManager::SetActiveScene(std::shared_ptr<Scene> pActiveScene)
{
	m_pActiveScene = pActiveScene;
}

void PhysicsManager::MoveObjects()
{
	std::list<std::shared_ptr<RigidBody>> const& listToMove= m_pActiveScene->GetMovableObjects();
	for (std::shared_ptr<RigidBody> pToMove : listToMove)
	{
		Vector2 newPos = pToMove->GetPosition();
		newPos.x = newPos.x + pToMove->GetDirection().x * pToMove->GetSpeed();
		newPos.y = newPos.y + pToMove->GetDirection().y * pToMove->GetSpeed();
		pToMove->SetPosition(newPos);
	}
}

void PhysicsManager::CheckCollisions()
{
}
