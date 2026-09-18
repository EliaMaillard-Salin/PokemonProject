#include "CombatScene.h"

#include <algorithm>

CombatScene::CombatScene():
	m_activePannel(0),m_activeAction(0)
{
	m_actionPannels[0] = AddGameObject<ActionPanel>();
	m_actionPannels[0]->SetPosition({ 960.0f,750.0f });
	m_actionPannels[0]->Init("Attacks", 0);
	// m_pPlayer->GetPokemonTeam();
	m_actionPannels[0]->SetActionList({ "AAAAA", "ATTTAACCK", "BOOOOO","LANCEEER"});

	m_actionPannels[1] = AddGameObject<ActionPanel>();
	m_actionPannels[1]->SetPosition({ 960.0f,750.0f });
	m_actionPannels[1]->Init("Pokemon", 1);
	// m_pPlayer->GetPokemonTeam();
	m_actionPannels[1]->SetActionList({ "Pleurayon", "Shitanobi", "Vesselec","Morrillon", "Trompolune", "Truffador" }); 
	m_actionPannels[1]->SetPanelActive(false);


}

void CombatScene::OpenScene()
{
	//m_pPlayer->GetEnemy();
	//m_pPlayer->GetInventory();
}

void CombatScene::Update()
{
	bool hasPanelChanged = false;
	bool hasActionChanged = false;
	int newActivePanel = m_activePannel;
	int newActiveAction = m_activeAction;
	if (IsKeyPressed(KEY_Q))
	{
		hasPanelChanged = true;
		newActivePanel -= 1;
	}
	if (IsKeyPressed(KEY_E))
	{
		hasPanelChanged = true;
		newActivePanel += 1;
	}
	if (IsKeyPressed(KEY_UP))
	{
		hasActionChanged = true;
		newActiveAction -= 1;
	}
	if (IsKeyPressed(KEY_DOWN))
	{
		hasActionChanged = true;
		newActiveAction += 1;
	}
	if (IsKeyPressed(KEY_LEFT))
	{
		hasActionChanged = true;
		newActiveAction -= 2;
	}
	if (IsKeyPressed(KEY_RIGHT))
	{
		hasActionChanged = true;
		newActiveAction += 2;
	}

	if (IsKeyPressed(KEY_ENTER))
		ConfirmAction();

	if (hasPanelChanged)
	{
		newActivePanel = std::clamp(newActivePanel,0,4);
		SetActivePannel(newActivePanel);
	}

	if (hasActionChanged)
	{
		newActiveAction = std::clamp(newActiveAction, 0, m_actionPannels[m_activePannel]->ActionCount() - 1);
		SetActiveAction(newActiveAction);
	}
}

void CombatScene::SetActivePannel(std::int8_t direction)
{
	m_actionPannels[m_activePannel]->SetPanelActive(false);
	m_activePannel = direction;
	m_actionPannels[m_activePannel]->SetPanelActive(true);
}

void CombatScene::SetActiveAction(std::int8_t direction)
{
	m_activeAction = direction;
	m_actionPannels[m_activePannel]->ChangeActiveAction(direction);
}

void CombatScene::ConfirmAction()
{
}
