#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include <cstdint>
#include <vector>
#include <string>
#include "Framework.h"

class Scene;
class PhysicsManager;
class Window;

class GameManager
{
public:
	void LaunchGame(std::uint8_t width, std::uint8_t height, std::string title);
	void AddScene(Scene const& scene, bool asActive = false);
	void ChangeActiveScene(std::uint8_t sceneID);
	
	void CloseGame();

private:
	void GameLoop();

private:

	std::unique_ptr<PhysicsManager> m_pPhysicsManager;
	std::unique_ptr<Window> m_pWindow;
	std::shared_ptr<Scene> m_pActiveScene;
	std::vector<std::shared_ptr<Scene>> m_loadedScenes;

};

#endif // GAMEMANAGER_H