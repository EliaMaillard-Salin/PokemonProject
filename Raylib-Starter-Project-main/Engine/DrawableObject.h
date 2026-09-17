#ifndef DRAWABLEOBJECT_H
#define DRAWABLEOBJECT_H

#include "GameObject.h"


class DrawableObject : public GameObject
{
public:
	enum DrawableShape
	{
		NONE = 0,
		FILLED_RECTANGLE = 1 << 0,
		RECTANGLE = 1 << 1,
		CIRCLE = 1 << 2,
		FILLED_CIRCLE = 1 << 3,
		ELLIPSE = 1 << 4,
		FILLED_ELLIPSE = 1 << 5,
		LINE = 1 << 6,
	};
	
	DrawableObject();
	virtual ~DrawableObject();
	void Update() override {}

	std::uint8_t GetShape() const;
	rl::Vector2 GetSize() const;
	rl::Vector2 GetPosition() const;
	rl::Color GetColor() const;
	bool IsSprite() const;
	bool IsUI() const;

	void SetDrawingIterator(std::list<std::shared_ptr<DrawableObject>>::iterator const& it);
	std::list<std::shared_ptr<DrawableObject>>::iterator& GetDrawingIterator();

	// str?  GetImage();

private:
	rl::Color m_color;
	// Image
	std::uint8_t m_shape;
	rl::Vector2 m_size;
	bool m_isUI;
	bool m_isSprite;
	std::list<std::shared_ptr<DrawableObject>>::iterator m_posInDrawList;
};

#endif // !DRAWABLEOBJECT_H
