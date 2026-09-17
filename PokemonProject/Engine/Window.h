#ifndef GAME_WINDOW_H
#define GAME_WINDOW_H

#include <memory>
#include <list>
#include <string>

class MeshComponent;
class GameObject;
class Scene;

class GameWindow
{

public:	
	GameWindow();
	virtual ~GameWindow();

	void SetActiveScene(std::shared_ptr<Scene> pActiveScene);

	void InitGameWindow(std::uint32_t width, std::uint32_t height, std::string title);
	void Draw();
	bool IsClosed();
	void CloseGameWindow();
	
private:

	void DrawEntities();
	void DrawUI();

	void DrawShape(MeshComponent const& pToDraw);
	void DrawSprite(MeshComponent const& pToDraw);

private:
	bool m_isClosed;
	std::shared_ptr<Scene> m_pActiveScene;
};


#endif // !PWindow_H
