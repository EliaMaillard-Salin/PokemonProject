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
	GameManager(std::uint32_t width, std::uint32_t height, std::string title);
	~GameManager();

	void LaunchGame();
	Scene& CreateNewScene(bool asActive = false);
	void ChangeActiveScene(std::uint8_t sceneID);

	void CloseGame();

	std::shared_ptr<Scene> m_pActiveScene;
private:
	void GameLoop();

private:

	std::unique_ptr<PhysicsManager> m_pPhysicsManager;
	std::shared_ptr<GameWindow> m_pGameWindow;
	std::vector<std::shared_ptr<Scene>> m_loadedScenes;

};

#endif // GAMEMANAGER_H