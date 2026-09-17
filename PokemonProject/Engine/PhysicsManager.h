#ifndef PHYSICSMANAGER_H
#define PHYSICSMANAGER_H

#include <memory>

class Scene;


class PhysicsManager
{
public:
	PhysicsManager();
	virtual ~PhysicsManager();

	void FixedUpdate();
	void SetActiveScene(std::shared_ptr<Scene> pActiveScene);

private:
	void MoveObjects();
	void CheckCollisions();

private:
	std::shared_ptr<Scene> m_pActiveScene;
};

#endif // !PHYSICSMANAGER_H
