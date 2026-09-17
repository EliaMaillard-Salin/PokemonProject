#include "GameManager.h"

#include <raylib.h>

GameManager::GameManager() :
    m_pGameWindow(std::make_unique<GameWindow>()), m_pPhysicsManager(std::make_unique<PhysicsManager>()),
    m_pActiveScene(nullptr), m_loadedScenes({})
{}


GameManager::~GameManager()
{}

void GameManager::LaunchGame(std::uint32_t width, std::uint32_t height, std::string title)
{
    m_pGameWindow->InitGameWindow(width, height, title);
    GameLoop();
}

void GameManager::AddScene(Scene const& scene, bool asActive)
{
    std::shared_ptr<Scene> sptrScene = std::make_shared<Scene>(scene);
    if (asActive || m_loadedScenes.empty())
    {
        m_pActiveScene = sptrScene;
        m_pGameWindow->SetActiveScene(m_pActiveScene);
        m_pPhysicsManager->SetActiveScene(m_pActiveScene);
    }

    m_loadedScenes.push_back(sptrScene);
}

void GameManager::ChangeActiveScene(std::uint8_t sceneID)
{
    m_pActiveScene = m_loadedScenes[sceneID];
    m_pGameWindow->SetActiveScene(m_pActiveScene);
    m_pPhysicsManager->SetActiveScene(m_pActiveScene);
}

void GameManager::CloseGame()
{
    m_pGameWindow->CloseGameWindow();
}


void GameManager::GameLoop()
{

    while (!WindowShouldClose())
    {
        m_pActiveScene->StartFrame();

        m_pActiveScene->Update();

        m_pActiveScene->FixedUpdate();

        BeginDrawing();
        ClearBackground(DARKGREEN);

        m_pActiveScene->Draw();

        EndDrawing();


        m_pActiveScene->EndFrame();
    }

    CloseGame();
}
