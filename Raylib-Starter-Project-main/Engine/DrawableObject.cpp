#include "DrawableObject.h"
#include "MovableObject.h"
#include "CollidableObject.h"

DrawableObject::DrawableObject() : GameObject(), m_color(rl::RED),m_shape(DrawableShape::NONE),m_isUI(false)
{
	m_type |= GameObject::Type::DRAWABLE;
}
DrawableObject::~DrawableObject()
{}


std::uint8_t DrawableObject::GetShape() const
{
	return m_shape;
}

rl::Vector2 DrawableObject::GetSize() const
{
	return m_size;
}

rl::Vector2 DrawableObject::GetPosition() const
{
	return m_position;
}

rl::Color DrawableObject::GetColor() const
{
	return m_color;
}

bool DrawableObject::IsSprite() const
{
	return m_isSprite;
}

bool DrawableObject::IsUI() const
{
	return m_isUI;
}

void DrawableObject::SetDrawingIterator(std::list<std::shared_ptr<DrawableObject>>::iterator const& it)
{
	m_posInDrawList = it;
}

std::list<std::shared_ptr<DrawableObject>>::iterator& DrawableObject::GetDrawingIterator()
{
	return m_posInDrawList;
}
