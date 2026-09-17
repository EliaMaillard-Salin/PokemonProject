#include "GameManager.h"
#include "Window.h"
#include "PhysicsManager.h"
#include "Scene.h"


void GameManager::LaunchGame(std::uint8_t width, std::uint8_t height, std::string title)
{
    m_pWindow->InitWindow(width, height, title);
    GameLoop();
}

void GameManager::AddScene(Scene const& scene, bool asActive)
{
    std::shared_ptr<Scene> sptrScene = std::make_shared<Scene>(scene);
    m_loadedScenes.push_back(sptrScene);
    if (asActive || m_loadedScenes.empty())
        m_pActiveScene = sptrScene;
}

void GameManager::ChangeActiveScene(std::uint8_t sceneID)
{
    m_pActiveScene = m_loadedScenes[sceneID];
    m_pWindow->SetActiveScene(m_pActiveScene);
    m_pPhysicsManager->SetActiveScene(m_pActiveScene);
}

void GameManager::CloseGame()
{
    m_pWindow->CloseWindow();
}


void GameManager::GameLoop()
{

    while (!m_pWindow->IsClosed())
    {
        m_pActiveScene->StartFrame();

        m_pActiveScene->Update();

        m_pPhysicsManager->FixedUpdate();

        m_pWindow->Draw();

        m_pActiveScene->EndFrame();
    }

    m_pWindow->CloseWindow();
}
