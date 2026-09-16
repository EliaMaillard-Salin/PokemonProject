#include "DrawableObject.h"
#include "MovableObject.h"
#include "CollidableObject.h"

DrawableObject::DrawableObject() : GameObject(), m_color(RED),m_shape(DrawableShape::NONE),m_isUI(false)
{
	m_type |= GameObject::Type::DRAWABLE;
}
DrawableObject::~DrawableObject()
{}


std::uint8_t DrawableObject::GetShape()
{
	return m_shape;
}

Vector2 DrawableObject::GetPosition()
{
	return m_position;
}

Color DrawableObject::GetColor()
{
	return m_color;
}
