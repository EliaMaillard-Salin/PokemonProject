#ifndef DRAWABLEOBJECT_H
#define DRAWABLEOBJECT_H

#include "GameObject.h"

#include "raylib.h"

class DrawableObject : public GameObject
{
public:
	enum DrawableShape
	{
		NONE = 0,
		FILLED_RECTANGLE = 1 << 0,
		RECTANGLE = 1 << 1,
		ELLIPSE = 1 << 2,
		FILLED_ELLIPSE = 1 << 3,
		LINE = 1 << 4,
	};
	
	DrawableObject();
	virtual ~DrawableObject();
	void Update() override {}

	std::uint8_t GetShape();
	Vector2 GetPosition();
	Color GetColor();


	// str?  GetImage();

private:
	Color m_color;
	// Image
	std::uint8_t m_shape;
	bool m_isUI;
};

#endif // !DRAWABLEOBJECT_H
