#include "UIElement.h"

#include "GameObject.h"

UIElement::UIElement(GameObject* owner) :
	Component(owner), m_color(RED)
{
	m_type = ComponentType::DRAW_UI;
}

UIElement::~UIElement()
{
}

void UIElement::SetColor(Color color)
{
	m_color = color;
}

Font UIText::s_font = GetFontDefault();
bool UIText::s_isFontLoaded = false;

UIText::UIText(GameObject* owner) :
	UIElement(owner), m_text(""), m_textSize(10)
{
	if (!s_isFontLoaded)
	{
		s_isFontLoaded = true;
		s_font = LoadFont("../Asset/Pokemon_Solid.ttf");
	}
}

UIText::~UIText()
{
}

void UIText::Draw()
{
	DrawTextEx(s_font,m_text.c_str(), m_pGameObject->GetPosition(), m_textSize, 10, m_color);
}

void UIText::SetText(std::string text)
{
	m_text = text;
}

void UIText::SetTextSize(int size)
{
	m_textSize = size;
}

UIShape::UIShape(GameObject* owner) : 
	UIElement(owner), m_shape(CIRCLE)
{
}

UIShape::~UIShape()
{
}

void UIShape::Draw()
{
	Vector2 pos = m_pGameObject->GetPosition();
	Vector2 size = m_pGameObject->GetSize();

	switch (m_shape)
	{
	case UIShape::UIShapeType::RECTANGLE:
		DrawRectangleLines(pos.x, pos.y, size.x, size.y, m_color);
		break;
	case UIShape::UIShapeType::FILLED_RECTANGLE:
		DrawRectangleV(pos, size, m_color);
		break;

	case UIShape::UIShapeType::CIRCLE:
		DrawCircleLines(pos.x, pos.y, size.x, m_color);
		break;
	case UIShape::UIShapeType::FILLED_CIRCLE:
		DrawCircleV(pos, size.x, m_color);
		break;

	case UIShape::UIShapeType::ELLIPSE:
		DrawEllipseLines(pos.x, pos.y, size.x, size.y, m_color);
		break;
	case UIShape::UIShapeType::FILLED_ELLIPSE:
		DrawEllipse(pos.x, pos.y, size.x, size.y, m_color);
		break;
	default:
		break;
	}
}
