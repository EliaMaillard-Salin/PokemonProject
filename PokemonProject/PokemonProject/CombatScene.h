#ifndef COMBAT_SCENE_H
#define COMBAT_SCENE_H

#include "EngineFramework.h"

#include <array>

class CombatScene : public Scene
{
public:

	CombatScene();

	void Update() override;

	void SetActivePannel(std::int8_t direction);
	void SetActiveAction(std::int8_t direction);

	void ConfirmAction();

private:
	std::array<std::shared_ptr<GameObject>, 4> m_actionPannels;
	bool m_isPlayerActive;
	// Player
	// Challenger
};


#endif

