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
	T& AddComponent(Component::ID componentID);

	void RemoveComponent(Component::ID componentID);

	template<typename T>
	T& GetComponent(Component::ID componentID);

	virtual void Update() {};
	virtual void UpdateComponent(std::uint8_t componentType);

	Vector2 GetPosition() const;
	Vector2 GetSize() const;

	void SetPosition(Vector2 const& pos);
	void SetSize(Vector2 const& size);

	std::map<std::uint8_t,std::list<std::shared_ptr<Component>>> m_components;
protected:


	Vector2 m_position;
	Vector2 m_size;

private:

	std::list<std::shared_ptr<GameObject>>::iterator m_sceneIterator;

	friend class Scene;
};

template <typename T>
T& GameObject::AddComponent(Component::ID componentID)
{
	for (auto copsInList = m_components.begin(); copsInList != m_components.end(); copsInList++)
	{
		for (auto it = copsInList->second.begin(); it != copsInList->second.end(); it++)
		{
			if (it->get()->GetID() == componentID)
			{
				return *std::dynamic_pointer_cast<T>(*it);
			}
		}
	}

	std::shared_ptr<T> pComp = std::make_shared<T>(this);
	for (auto copsInList = m_components.begin(); copsInList != m_components.end(); copsInList++)
	{
		if (pComp->GetType() == copsInList->first)
		{
			copsInList->second.push_front(pComp);
		}
	}

	return *pComp;
}


template <typename T>
T& GameObject::GetComponent(Component::ID componentID)
{
	for (auto copsInList : m_components)
	{
		for (auto it = copsInList.second.begin(); it != copsInList.second.end(); it++)
		{
			if (it->get()->GetID() == componentID)
			{
				return *std::dynamic_pointer_cast<T>(*it);
			}
		}
	}
}

#endif //
