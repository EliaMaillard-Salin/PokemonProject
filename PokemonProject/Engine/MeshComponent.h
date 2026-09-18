#ifndef MESH_COMPONENT_H
#define MESH_COMPONENT_H

#include "Component.h"

class MeshComponent : public Component
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
	
	MeshComponent(GameObject* owner);
	virtual ~MeshComponent();

	std::uint8_t GetShape() const;
	Color GetColor() const;
	bool IsSprite() const;
	bool IsUI() const;

	void SetColor(Color color);
	void SetShape(DrawableShape shape);

	void Draw() override;

	// str?  GetImage();

protected:
	Color m_color;
	// Image
	std::uint8_t m_shape;
	bool m_isUI;
	bool m_isSprite;

private:
	void DrawShape();
	void DrawSprite();

};

#endif // !DRAWABLEOBJECT_H
