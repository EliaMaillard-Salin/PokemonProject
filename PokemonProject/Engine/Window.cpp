#include "Window.h"

#include "MeshComponent.h"
#include "GameObject.h"
#include "Scene.h"



GameWindow::GameWindow() : m_pActiveScene(nullptr), m_isClosed(false)
{
}

GameWindow::~GameWindow()
{
}

void GameWindow::SetActiveScene(std::shared_ptr<Scene> pActiveScene)
{
	m_pActiveScene = pActiveScene;
}

void GameWindow::InitGameWindow(std::uint32_t width, std::uint32_t height, std::string title)
{
	InitWindow(width, height, title.c_str());
	SetTargetFPS(60);
}

void GameWindow::Draw()
{

}

bool GameWindow::IsClosed()
{
	return m_isClosed;
}

void GameWindow::CloseGameWindow()
{
	CloseWindow();
}

void GameWindow::DrawEntities()
{
	std::list<std::shared_ptr<MeshComponent>> const& listToDraw = m_pActiveScene->GetDrawableObjects();
	for (std::shared_ptr<MeshComponent> pToDraw : listToDraw)
	{
		if (pToDraw->IsUI())
			DrawUI();
		else
			pToDraw->IsSprite() ? DrawSprite(*pToDraw) : DrawShape(*pToDraw);
	}
}

void GameWindow::DrawUI()
{
}

void GameWindow::DrawShape(MeshComponent const& pToDraw)
{
	Vector2 pos = pToDraw.GetPosition();
	Vector2 size = pToDraw.GetSize();
	switch (pToDraw.GetShape())
	{
		case MeshComponent::DrawableShape::RECTANGLE :
			DrawRectangleLines(pos.x, pos.y, size.x, size.y, pToDraw.GetColor());
		    break;
		case MeshComponent::DrawableShape::FILLED_RECTANGLE:
			DrawRectangleV(pos, size, pToDraw.GetColor());
			break;

		case MeshComponent::DrawableShape::CIRCLE:
			DrawCircleLines(pos.x, pos.y, size.x, pToDraw.GetColor());
			break;
		case MeshComponent::DrawableShape::FILLED_CIRCLE:
			DrawCircleV(pos, size.x, pToDraw.GetColor());
			break;

		case MeshComponent::DrawableShape::ELLIPSE:
			DrawEllipseLines(pos.x, pos.y, size.x, size.y, pToDraw.GetColor());
			break;
		case MeshComponent::DrawableShape::FILLED_ELLIPSE:
			DrawEllipse(pos.x, pos.y, size.x, size.y, pToDraw.GetColor());
			break;

		case MeshComponent::DrawableShape::LINE:
			DrawLine(pos.x, pos.y, size.x, size.y, pToDraw.GetColor());
			break;

		default:
			break;
	}
}

void GameWindow::DrawSprite(MeshComponent const& pToDraw)
{
}
