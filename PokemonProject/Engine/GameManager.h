#ifndef GAME_MANAGER_H
#define GAME_MANAGER_H

#include <cstdint>
#include <vector>
#include <string>

#include "Window.h"
#include "Scene.h"
#include "PhysicsManager.h"

class GameManager
{
public:
	GameManager();
	~GameManager();

	void LaunchGame(std::uint32_t width, std::uint32_t height, std::string title);
	void AddScene(Scene const& scene, bool asActive = false);
	void ChangeActiveScene(std::uint8_t sceneID);

	void CloseGame();

private:
	void GameLoop();

private:

	std::unique_ptr<PhysicsManager> m_pPhysicsManager;
	std::shared_ptr<GameWindow> m_pGameWindow;
	std::shared_ptr<Scene> m_pActiveScene;
	std::vector<std::shared_ptr<Scene>> m_loadedScenes;

};

#endif // GAMEMANAGER_H