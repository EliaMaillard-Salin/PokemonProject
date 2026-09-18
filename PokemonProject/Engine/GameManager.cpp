#include "GameManager.h"

#include <raylib.h>

GameManager::GameManager() :
    m_pGameWindow(std::make_unique<GameWindow>()), m_pPhysicsManager(std::make_unique<PhysicsManager>()),
    m_pActiveScene(nullptr), m_loadedScenes({})
{
}


GameManager::~GameManager()
{}

void GameManager::LaunchGame(std::uint32_t width, std::uint32_t height, std::string title)
{
    InitWindow(width, height, title.c_str());
    SetTargetFPS(60);
    GameLoop();
}

Scene& GameManager::CreateNewScene(bool asActive)
{
    std::shared_ptr<Scene> pScene = std::make_shared<Scene>();
    if (asActive || m_loadedScenes.empty())
    {
        m_pActiveScene = pScene;
    }
    m_loadedScenes.push_back(pScene);
    return *pScene;
}

void GameManager::ChangeActiveScene(std::uint8_t sceneID)
{
    m_pActiveScene = m_loadedScenes[sceneID];
}

void GameManager::CloseGame()
{
    CloseWindow();
}


void GameManager::GameLoop()
{

    while (!WindowShouldClose())
    {
       // m_pActiveScene->StartFrame();

        m_pActiveScene->Update();

        m_pActiveScene->FixedUpdate();

        BeginDrawing();
        ClearBackground(DARKGREEN);

        m_pActiveScene->Draw();

        EndDrawing();


      //  m_pActiveScene->EndFrame();
    }

    CloseGame();
}
