#include "MeshComponent.h"
#include "GameObject.h"

MeshComponent::MeshComponent() : 
	m_color(RED),m_shape(DrawableShape::NONE), m_isUI(false),
	m_isSprite(false)
{
	m_id |= Component::ID::MESH;
}
MeshComponent::~MeshComponent()
{}

void MeshComponent::Draw()
{
}
void MeshComponent::DrawShape()
{
}

void MeshComponent::DrawSprite()
{
}

std::uint8_t MeshComponent::GetShape() const
{
	return m_shape;
}

Color MeshComponent::GetColor() const
{
	return m_color;
}

bool MeshComponent::IsSprite() const
{
	return m_isSprite;
}

bool MeshComponent::IsUI() const
{
	return m_isUI;
}

void MeshComponent::SetColor(Color color)
{
	m_color = color;
}

void MeshComponent::SetShape(DrawableShape shape)
{
	m_shape = shape;
}



