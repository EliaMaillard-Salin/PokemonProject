#include "Scene.h"

#include "GameObject.h"

Scene::Scene()
{
}

Scene::~Scene()
{
}

void Scene::RemoveGameObject(GameObject& gameObject)
{
	std::shared_ptr<GameObject> pGameObject = std::make_shared<GameObject>(gameObject);
	m_gameObjectToDestroy.push_back(pGameObject);
}


void Scene::Update()
{
	for (std::shared_ptr<GameObject> pGameObject : m_gameObjectInScene)
	{
		if (!pGameObject->GetActive())
			continue;
		pGameObject->Update();
		pGameObject->UpdateComponent(ComponentType::UPDATE);
	}
}

void Scene::FixedUpdate()
{
	for (std::shared_ptr<GameObject> pGameObject : m_gameObjectInScene)
	{
		if (!pGameObject->GetActive())
			continue;
		pGameObject->UpdateComponent(ComponentType::FIXED_UPDATE);
	}
}

void Scene::Draw()
{
	for (std::shared_ptr<GameObject> pGameObject : m_gameObjectInScene)
	{
		if (!pGameObject->GetActive())
			continue;
		pGameObject->UpdateComponent(ComponentType::DRAW);
	}
	for (std::shared_ptr<GameObject> pGameObject : m_gameObjectInScene)
	{
		if (!pGameObject->GetActive())
			continue;
		pGameObject->UpdateComponent(ComponentType::DRAW_UI);
	}

}

void Scene::StartFrame()
{
	for (std::shared_ptr<GameObject> pGameObject : m_gameObjectToCreate)
	{
		m_gameObjectInScene.push_front(pGameObject);
		pGameObject->m_sceneIterator = m_gameObjectInScene.begin();
	}
	m_gameObjectToCreate.clear();
}

void Scene::EndFrame()
{
	for (std::shared_ptr<GameObject> pGameObject : m_gameObjectToDestroy)
	{
		m_gameObjectInScene.erase(pGameObject->m_sceneIterator);
	}
	m_gameObjectToDestroy.clear();
}

