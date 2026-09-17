#ifndef SCENE_H
#define SCENE_H

#include <memory>
#include <list>

class GameObject;
class DrawableObject;
class MovableObject;
class CollidableObject;

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

	std::list<std::shared_ptr<DrawableObject>> const& GetDrawableObjects();
	std::list<std::shared_ptr<MovableObject>> const& GetMovableObjects();
	std::list<std::shared_ptr<CollidableObject>> const& GetCollidableObjects();

private:

private:
	std::list<std::shared_ptr<GameObject>> m_gameObjectInScene;

	std::list<std::shared_ptr<DrawableObject>> m_drawableObjects;
	std::list<std::shared_ptr<MovableObject>> m_movableObjects;
	std::list<std::shared_ptr<CollidableObject>> m_collidableObjects;

	std::list<std::shared_ptr<GameObject>> m_gameObjectToCreate;
	std::list<std::shared_ptr<GameObject>> m_gameObjectToDestroy;
};

#endif // !SCENE_H
