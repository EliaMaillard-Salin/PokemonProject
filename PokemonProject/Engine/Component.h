#ifndef COMPONENT_H
#define COMPONENT_H

#include <cstdint>
#include <list>
#include <raylib.h>
#include <memory>

class GameObject;

namespace ComponentType
{
	enum Type
	{
		TYPE_NONE = 0,
		DRAW = 1 << 0,
		DRAW_UI = 1 << 1,
		UPDATE = 1 << 2,
		FIXED_UPDATE = 1 << 3,
	};

	static std::uint8_t componentTypeCount = 4;
}

class Component 
{
public:

	enum ID
	{
		ID_NONE,
		MESH,
		COLLIDER,
		RIGIDBODY,
		UI_SHAPE,
		UI_TEXT,
		//
	};

	Component(GameObject* owner);
	virtual ~Component();

	virtual void Update() {};
	virtual void FixedUpdate() {};
	virtual void Draw() {};


	std::uint8_t GetType();
	Component::ID GetID();

	void SetActive(bool isActive);
	bool GetActive();

protected:

	GameObject* m_pGameObject;
	Component::ID m_id;
	std::uint8_t m_type;
	bool m_isActive;
private:

	std::list<std::shared_ptr<Component>>::iterator m_compIterator;

	friend class GameObject;
};

#endif // !COMPONENT_H
