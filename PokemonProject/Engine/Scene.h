#ifndef SCENE_H
#define SCENE_H

#include <list>
#include <memory>

class GameObject;
class MeshComponent;
class RigidBody;
class Collider;

class Scene
{
public:

	Scene();
	virtual ~Scene();

	template <typename T>
	std::shared_ptr<T> AddGameObject();

	void RemoveGameObject(GameObject & gameObject);

	// Loop Functions
	void StartFrame();
	void EndFrame();

	virtual void FixedUpdate();
	virtual void Update();
	virtual void Draw();

	std::list<std::shared_ptr<GameObject>> m_gameObjectInScene;
private:

private:

	std::list<std::shared_ptr<GameObject>> m_gameObjectToDestroy;
	std::list<std::shared_ptr<GameObject>> m_gameObjectToCreate;
};


template<typename T>
inline std::shared_ptr<T> Scene::AddGameObject()
{
	std::shared_ptr<T> pGameObject = std::make_shared<T>();
	m_gameObjectToCreate.push_back(pGameObject);
	return pGameObject;
}

#endif // !SCENE_H