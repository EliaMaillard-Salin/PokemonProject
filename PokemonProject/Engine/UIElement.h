#ifndef UI_ELEMENT_H
#define UI_ELEMENT_H

#include "Component.h"

#include <string>

class UIElement : public Component
{
public:
	UIElement(GameObject* owner);
	virtual ~UIElement();
	
	virtual void Draw() override = 0;

	void SetColor(Color color);

protected:
	Color m_color;
};


class UIText : public UIElement
{
public:
	UIText(GameObject* owner);
	virtual ~UIText();

	void Draw() override;

	void SetText(std::string text);
	void SetTextSize(int size);

	void SetPosition(Vector2 pos);

private:
	Vector2 m_position;
	std::string m_text;
	int m_textSize;
	static Font s_font;
	static bool s_isFontLoaded;
};

class UIShape: public UIElement
{
public:
	
	enum UIShapeType
	{
		RECTANGLE,
		FILLED_RECTANGLE,
		ELLIPSE,
		FILLED_ELLIPSE,
		CIRCLE,
		FILLED_CIRCLE,
	};

	UIShape(GameObject* owner);
	virtual ~UIShape();

	void SetShape(UIShapeType shape);

	void Draw() override;

private:
	Vector2 m_size;
	std::uint8_t m_shape;

};


#endif

