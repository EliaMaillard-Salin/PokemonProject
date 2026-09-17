#include "Scene.h"

#include "DrawableObject.h"
#include "MovableObject.h"
#include "CollidableObject.h"

Scene::Scene()
{
}

Scene::~Scene()
{
}

void Scene::AddGameObject(GameObject const& gameObject)
{
	//std::shared_ptr<GameObject> pGameObject = std::make_shared<GameObject>(gameObject);
	//m_gameObjectToCreate.push_back(pGameObject);
}

void Scene::RemoveGameObject(GameObject const& gameObject)
{
	//std::shared_ptr<GameObject> pGameObject = std::make_shared<GameObject>(gameObject);
	//m_gameObjectToDestroy.push_back(pGameObject);
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
		
		if (std::dynamic_pointer_cast<DrawableObject>(pGameObject) != nullptr)
		{
			std::shared_ptr<DrawableObject> pDrawObject = std::dynamic_pointer_cast<DrawableObject>(pGameObject);
			m_drawableObjects.push_front(pDrawObject);
			pDrawObject->SetDrawingIterator(m_drawableObjects.begin());
		}

		if (dynamic_cast<MovableObject*>(pGameObject.get()) != nullptr)
		{

		}

		if (dynamic_cast<CollidableObject*>(pGameObject.get()) != nullptr)
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

		if (std::dynamic_pointer_cast<DrawableObject>(pGameObject) != nullptr)
		{
			std::shared_ptr<DrawableObject> pDrawObject = std::dynamic_pointer_cast<DrawableObject>(pGameObject);
			m_drawableObjects.erase(pDrawObject->GetDrawingIterator());
		}

		if (dynamic_cast<MovableObject*>(pGameObject.get()) != nullptr)
		{

		}

		if (dynamic_cast<CollidableObject*>(pGameObject.get()) != nullptr)
		{

		}
	}
	m_gameObjectToDestroy.clear();
}

std::list<std::shared_ptr<DrawableObject>> const& Scene::GetDrawableObjects()
{
	return m_drawableObjects;
}

std::list<std::shared_ptr<MovableObject>> const& Scene::GetMovableObjects()
{
	return m_movableObjects;
}

std::list<std::shared_ptr<CollidableObject>> const& Scene::GetCollidableObjects()
{
	return m_collidableObjects;
}

