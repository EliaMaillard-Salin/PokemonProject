#ifndef COMPONENT_H
#define COMPONENT_H

#include <cstdint>
#include <list>
#include <raylib.h>
#include <memory>

class GameObject;


class Component 
{
public:

	enum ID
	{
		ID_NONE,
		MESH,
		COLLIDER,
		TRANSFORM,
		//
	};

	enum Type
	{
		TYPE_NONE = 0,
		DRAW = 1 << 0,
		DRAW_UI = 1 << 1,
		UPDATE = 1 << 2,
		FIXED_UPDATE = 1 << 3,
	};

	Component(GameObject* owner);
	virtual ~Component();

	virtual void Update() {};
	virtual void FixedUpdate() {};
	virtual void Draw() {};


	Component::Type GetType();
	Component::ID GetID();

	GameObject* m_pGameObject;
protected:


	Component::ID m_id;
	Component::Type m_type;

private:

	std::list<std::shared_ptr<Component>>::iterator m_compIterator;

	friend class GameObject;
};

#endif // !COMPONENT_H
