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

}

void PhysicsManager::CheckCollisions()
{
}
