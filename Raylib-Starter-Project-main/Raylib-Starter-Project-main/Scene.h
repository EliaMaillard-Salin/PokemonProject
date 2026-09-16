#ifndef SCENE_H
#define SCENE_H

#include <memory>
#include <list>

class GameObject;

class Scene
{
public:

	Scene();
	void AddGameObject(GameObject const* pGameObject);
	void RemoveGameObject(GameObject const* pGameObject);


	// Loop Functions
	void GameObjectsCreation();
	void GameObjectsDeletion();

	void UpdateGameObjects();

private:
	std::list<GameObject*> m_gameObjectInScene;

	std::list<GameObject*> m_gameObjectToCreate;
	std::list<GameObject*> m_gameObjectToDestroy;
};

#endif // !SCENE_H
