#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <cstdint>
#include <raymath.h>
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

	std::list<GameObject*>::iterator GetSceneIterator();

protected:
	std::uint8_t m_type;
	Vector2 m_position;

private:
	std::list<GameObject*>::iterator m_positionInScene;

};

#endif // !GAMEOBJECT_H
