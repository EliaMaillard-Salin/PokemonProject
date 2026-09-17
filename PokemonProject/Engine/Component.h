#ifndef COMPONENT_H
#define COMPONENT_H

#include <cstdint>
#include <list>
#include <raylib.h>
#include <memory>


class Component 
{
public:

	enum ID
	{
		NONE = 0,
		MESH = 1 << 0,
		COLLIDER = 1 << 1,
		TRANSFORM = 1 << 2,
	};

	enum Type
	{
		NONE = 0,
		DRAWABLE = 1 << 0,
		UI = 1 << 1,
		COLLIDER = 1 << 2,
	};

	Component();
	virtual ~Component();

	virtual void Update() = 0;
	virtual void FixedUpdate() {};
	virtual void Draw() {};


	void SetComponentIterator(std::list<std::shared_ptr<Component>>::iterator const& it);
	std::list<std::shared_ptr<Component>>::iterator GetComponentIterator();

	std::uint8_t GetType();
	std::uint8_t GetID();



	Vector2 GetPosition() const;
	Vector2 GetSize() const;

	void SetPosition(Vector2 const& pos);
	void SetSize(Vector2 const& size);

protected:
	Vector2 m_position;
	Vector2 m_size;

	std::uint8_t m_id;
	std::uint8_t m_type;
	std::list<std::shared_ptr<Component>>::iterator m_compIterator;
};

#endif // !COMPONENT_H
