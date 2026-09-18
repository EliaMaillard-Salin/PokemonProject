#include "MeshComponent.h"
#include "GameObject.h"

MeshComponent::MeshComponent(GameObject* owner) :
	Component(owner), m_color(RED),m_shape(DrawableShape::NONE),
	m_isSprite(false)
{
	m_id = Component::ID::MESH;
	m_type |= ComponentType::DRAW;
}
MeshComponent::~MeshComponent()
{}

void MeshComponent::Draw()
{
	m_isSprite ? DrawSprite() : DrawShape();
}

void MeshComponent::DrawShape()
{
	Vector2 pos = m_pGameObject->GetPosition();
	Vector2 size = m_pGameObject->GetSize();

	switch (m_shape)
	{
	case MeshComponent::DrawableShape::RECTANGLE:
		DrawRectangleLines(pos.x, pos.y, size.x, size.y, m_color);
		break;
	case MeshComponent::DrawableShape::FILLED_RECTANGLE:
		DrawRectangleV(pos, size, m_color);
		break;

	case MeshComponent::DrawableShape::CIRCLE:
		DrawCircleLines(pos.x, pos.y, size.x, m_color);
		break;
	case MeshComponent::DrawableShape::FILLED_CIRCLE:
		DrawCircleV(pos, size.x, m_color);
		break;

	case MeshComponent::DrawableShape::ELLIPSE:
		DrawEllipseLines(pos.x, pos.y, size.x, size.y, m_color);
		break;
	case MeshComponent::DrawableShape::FILLED_ELLIPSE:
		DrawEllipse(pos.x, pos.y, size.x, size.y, m_color);
		break;

	case MeshComponent::DrawableShape::LINE:
		DrawLine(pos.x, pos.y, size.x, size.y, m_color);
		break;

	default:
		break;
	}
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

void MeshComponent::SetColor(Color color)
{
	m_color = color;
}

void MeshComponent::SetShape(DrawableShape shape)
{
	m_shape = shape;
}



