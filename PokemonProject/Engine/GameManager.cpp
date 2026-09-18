#include "GameManager.h"

#include <raylib.h>

GameManager::GameManager(std::uint32_t width, std::uint32_t height, std::string title) :
    m_pGameWindow(std::make_unique<GameWindow>()), m_pPhysicsManager(std::make_unique<PhysicsManager>()),
    m_pActiveScene(nullptr), m_loadedScenes({})
{
    InitWindow(width, height, title.c_str());
    SetTargetFPS(60);
}


GameManager::~GameManager()
{}

void GameManager::LaunchGame()
{
    GameLoop();
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
