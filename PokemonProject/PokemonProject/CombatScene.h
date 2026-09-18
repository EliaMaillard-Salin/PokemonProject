#ifndef COMBAT_SCENE_H
#define COMBAT_SCENE_H

#include "EngineFramework.h"

#include <array>
#include "Player.h"
#include "ActionPannels.h"

class CombatScene : public Scene
{
public:

	CombatScene();

	void OpenScene() override;

	void Update() override;

	void SetActivePannel(std::int8_t direction);
	void SetActiveAction(std::int8_t direction);

	void ConfirmAction();

private:
	int m_activePannel;
	int m_activeAction;
	std::array<std::shared_ptr<ActionPanel>, 4> m_actionPannels;
	bool m_isPlayerActive;
	std::shared_ptr<Player> m_pPlayer;
	// Challenger
};


#endif

