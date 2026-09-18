#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "Framework.h"

#include "Component.h"

#include <map>

class GameObject
{
public:
	
	GameObject();
	virtual ~GameObject() {};

	template<typename T>
	T& AddComponent(Component::ID componentID, Component::Type componentType);

	void RemoveComponent(Component::ID componentID, Component::Type componentType);

	template<typename T>
	T& GetComponent(Component::ID componentID, Component::Type componentType);

	virtual void Update() {};
	virtual void UpdateComponent(Component::Type componentType);

	Vector2 GetPosition() const;
	Vector2 GetSize() const;

	void SetPosition(Vector2 const& pos);
	void SetSize(Vector2 const& size);

	std::map<Component::Type, std::list<std::shared_ptr<Component>>> m_components;
protected:


	Vector2 m_position;
	Vector2 m_size;

private:

	std::list<std::shared_ptr<GameObject>>::iterator m_sceneIterator;

	friend class Scene;
};

template <typename T>
T& GameObject::AddComponent(Component::ID componentID, Component::Type componentType)
{
	for (std::shared_ptr<Component> pCompIn : m_components[componentType])
		if (pCompIn->GetID() & componentID)
			return *std::dynamic_pointer_cast<T>(pCompIn);
	
	std::shared_ptr<T> pComp = std::make_shared<T>(this);

	m_components[componentType].push_front(pComp);
	pComp->m_compIterator = m_components[componentType].begin();

	return *pComp;
}


template <typename T>
T& GameObject::GetComponent(Component::ID componentID, Component::Type componentType)
{
	for (std::shared_ptr<Component> pComp : m_components[componentType])
	{
		if (pComp->GetID() & componentID)
			return *std::dynamic_pointer_cast<T>(pComp);
	}
}

#endif //
