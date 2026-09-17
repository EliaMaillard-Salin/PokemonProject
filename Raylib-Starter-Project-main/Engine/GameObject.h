#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <cstdint>
#include "Framework.h"
#include <list>

class GameObject
{
public:
	enum Type
	{
		NONE = 0,
		DRAWABLE = 1<<0,
		COLLIDABLE = 1<<1,
		MOVABLE = 1<<2,
	};
	
	GameObject();
	virtual ~GameObject() {};

	virtual void Update() = 0;

	std::list<std::shared_ptr<GameObject>>::iterator GetSceneIterator();
	void SetSceneIterator(std::list<std::shared_ptr<GameObject>>::iterator const& it);

protected:
	std::uint8_t m_type;
	rl::Vector2 m_position;

private:
	std::list<std::shared_ptr<GameObject>>::iterator m_positionInScene;

};

#endif // !GAMEOBJECT_H
