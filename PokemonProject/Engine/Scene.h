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

	void AddGameObject(GameObject const& gameObject);
	void RemoveGameObject(GameObject const& gameObject);

	// Loop Functions
	void StartFrame();
	void EndFrame();

	void Update();

	std::list<std::shared_ptr<MeshComponent>> const& GetDrawableObjects();
	std::list<std::shared_ptr<RigidBody>> const& GetMovableObjects();
	std::list<std::shared_ptr<Collider>> const& GetCollidableObjects();

private:

private:
	std::list<std::shared_ptr<GameObject>> m_gameObjectInScene;

	std::list<std::shared_ptr<GameObject>> m_gameObjectToDestroy;
	std::list<std::shared_ptr<GameObject>> m_gameObjectToCreate;
};

#endif // !SCENE_H
