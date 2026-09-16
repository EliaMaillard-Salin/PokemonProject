#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include <cstdint>

class Scene;
class PhysicSystem;
class Window;

class GameManager
{
public:
	void LaunchActiveScene();
	void AddScene(Scene const* pScene);
	void ChangeActiveScene(std::uint8_t sceneID);
	
	void Closegame();

	PhysicSystem* GetPhysicsSystem();
	Window* GetWindow();

private:
	void GameLoop();

private:
	// PhysicsManager
	// Window
	// LoadedScenes

};

#endif // GAMEMANAGER_H