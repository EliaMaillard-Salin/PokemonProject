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

}

void GameWindow::DrawUI()
{
}

void GameWindow::DrawShape(MeshComponent const& pToDraw)
{
}

void GameWindow::DrawSprite(MeshComponent const& pToDraw)
{
}
