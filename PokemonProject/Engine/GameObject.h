#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "Framework.h"

#include "Component.h"

#include <memory>
#include <cstdint>
#include <list>

class GameObject
{
public:
	
	GameObject();
	virtual ~GameObject() {};

	void AddComponent(Component& component);

	void RemoveComponent(Component::ID componentType);

	Component& GetComponent(Component::ID componentType);

	virtual void Update();
	virtual void FixedUpdate();
	virtual void Draw();

	virtual void DrawUI() {};

	std::list<std::shared_ptr<GameObject>>::iterator GetSceneIterator();
	void SetSceneIterator(std::list<std::shared_ptr<GameObject>>::iterator const& it);

protected:
	std::list<std::shared_ptr<Component>> m_components;

	std::list<std::shared_ptr<Collider>> m_collidableObjects;
	std::list<std::shared_ptr<MeshComponent>> m_drawableComponents;
	//std::list<std::shared_ptr<UIElement>> m_uiComponents;

private:
	std::list<std::shared_ptr<GameObject>>::iterator m_sceneIterator;

};

#endif //
