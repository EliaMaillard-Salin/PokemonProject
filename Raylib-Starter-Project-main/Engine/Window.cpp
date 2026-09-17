#include "Window.h"

#include "DrawableObject.h"
#include "Framework.h"
#include "Scene.h"



void Window::SetActiveScene(std::shared_ptr<Scene> pActiveScene)
{
	m_pActiveScene = pActiveScene;
}

void Window::InitWindow(std::uint8_t width, std::uint8_t height, std::string title)
{
	rl::InitWindow(width, height, title.c_str());
	rl::SetTargetFPS(60);
}

void Window::Draw()
{
	m_isClosed = rl::WindowShouldClose();
	rl::BeginDrawing();
	rl::ClearBackground(rl::DARKGREEN);

	DrawEntities();
	DrawUI();

	rl::EndDrawing();
}

bool Window::IsClosed()
{
	return m_isClosed;
}

void Window::CloseWindow()
{
	rl::CloseWindow();
}

void Window::DrawEntities()
{
	std::list<std::shared_ptr<DrawableObject>> const& listToDraw = m_pActiveScene->GetDrawableObjects();
	for (std::shared_ptr<DrawableObject> pToDraw : listToDraw)
	{
		if (pToDraw->IsUI())
			DrawUI();
		else
			pToDraw->IsSprite() ? DrawSprite(*pToDraw) : DrawShape(*pToDraw);
	}
}

void Window::DrawUI()
{
}

void Window::DrawShape(DrawableObject const& pToDraw)
{
	rl::Vector2 pos = pToDraw.GetPosition();
	rl::Vector2 size = pToDraw.GetSize();
	switch (pToDraw.GetShape())
	{
		case DrawableObject::DrawableShape::RECTANGLE :
			rl::DrawRectangleV(pos, size, pToDraw.GetColor());
		    break;
		case DrawableObject::DrawableShape::FILLED_RECTANGLE:
			rl::DrawRectangleLines(pos.x, pos.y, size.x, size.y, pToDraw.GetColor());
			break;

		case DrawableObject::DrawableShape::CIRCLE:
			rl::DrawCircleV(pos, size.x, pToDraw.GetColor());
			break;
		case DrawableObject::DrawableShape::FILLED_CIRCLE:
			rl::DrawCircleLines(pos.x, pos.y, size.x, pToDraw.GetColor());
			break;

		case DrawableObject::DrawableShape::ELLIPSE:
			rl::DrawEllipse(pos.x, pos.y, size.x, size.y, pToDraw.GetColor());
			break;
		case DrawableObject::DrawableShape::FILLED_ELLIPSE:
			rl::DrawEllipseLines(pos.x, pos.y, size.x, size.y, pToDraw.GetColor());
			break;

		case DrawableObject::DrawableShape::LINE:
			rl::DrawLine(pos.x, pos.y, size.x, size.y, pToDraw.GetColor());
			break;

		default:
			break;
	}
}

void Window::DrawSprite(DrawableObject const& pToDraw)
{
}
