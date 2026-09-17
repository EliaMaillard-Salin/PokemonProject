#include "Scene.h"

#include "Drawable.h"
#include "Movable.h"
#include "Collidable.h"

#include "GameObject.h"

Scene::Scene()
{
}

Scene::~Scene()
{
}

void Scene::AddGameObject(GameObject const& gameObject)
{
	std::shared_ptr<GameObject> pGameObject = std::make_shared<GameObject>(gameObject);
	m_gameObjectToCreate.push_back(pGameObject);
}

void Scene::RemoveGameObject(GameObject const& gameObject)
{
	std::shared_ptr<GameObject> pGameObject = std::make_shared<GameObject>(gameObject);
	m_gameObjectToDestroy.push_back(pGameObject);
}

void Scene::Update()
{
	for (std::shared_ptr<GameObject> pGameObject : m_gameObjectInScene)
	{
		pGameObject->Update();
	}
}

void Scene::StartFrame()
{
	for (std::shared_ptr<GameObject> pGameObject : m_gameObjectToCreate)
	{
		m_gameObjectInScene.push_front(pGameObject);
		pGameObject->SetSceneIterator(m_gameObjectInScene.begin());
		
		if (pGameObject->GetType() & GameObject::Type::DRAWABLE)
		{
			std::shared_ptr<MeshComponent> pDrawObject = 
			m_drawableObjects.push_front(pDrawObject);
			pDrawObject->SetDrawingIterator(m_drawableObjects.begin());
		}

		if (pGameObject->GetType() & GameObject::Type::MOVABLE)
		{

		}

		if (pGameObject->GetType() & GameObject::Type::COLLIDABLE)
		{

		}
	}
	m_gameObjectToCreate.clear();
}

void Scene::EndFrame()
{
	for (std::shared_ptr<GameObject> pGameObject : m_gameObjectToDestroy)
	{
		m_gameObjectInScene.erase(pGameObject->GetSceneIterator());

		if (pGameObject->GetType() & GameObject::Type::DRAWABLE)
		{
			std::shared_ptr<MeshComponent> pDrawObject = std::dynamic_pointer_cast<MeshComponent>(pGameObject);
			m_drawableObjects.erase(pDrawObject->GetDrawingIterator());
		}

		if (pGameObject->GetType() & GameObject::Type::MOVABLE)
		{

		}

		if (pGameObject->GetType() & GameObject::Type::COLLIDABLE)
		{

		}
	}
	m_gameObjectToDestroy.clear();
}

std::list<std::shared_ptr<MeshComponent>> const& Scene::GetDrawableObjects()
{
	return m_drawableObjects;
}

std::list<std::shared_ptr<RigidBody>> const& Scene::GetMovableObjects()
{
	return m_movableObjects;
}

std::list<std::shared_ptr<Collider>> const& Scene::GetCollidableObjects()
{
	return m_collidableObjects;
}

