#ifndef WINDOW_H
#define WINDOW_H

#include <list>
#include <string>
#include "Framework.h"

class DrawableObject;
class Scene;

class Window
{

public:	

	void SetActiveScene(std::shared_ptr<Scene> pActiveScene);

	void InitWindow(std::uint8_t width, std::uint8_t height, std::string title);
	void Draw();
	bool IsClosed();
	void CloseWindow();
	
private:

	void DrawEntities();
	void DrawUI();

	void DrawShape(DrawableObject const& pToDraw);
	void DrawSprite(DrawableObject const& pToDraw);

private:
	bool m_isClosed;
	std::shared_ptr<Scene> m_pActiveScene;
};


#endif // !WINDOW_H
