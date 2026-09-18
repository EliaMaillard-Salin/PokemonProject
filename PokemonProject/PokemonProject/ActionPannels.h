#ifndef ACTION_PANEL_H
#define ACTION_PANEL_H

#include "EngineFramework.h"

#include <string>

class ActionPanel : public GameObject
{

public:
	ActionPanel();
	~ActionPanel();

	void Init(std::string panelTitle, int offset);

	void Update() override;

	void SetPanelActive(bool isActive);
	void SetActionList(std::vector<std::string> const& actions);

	void ChangeActiveAction(int newAction);

	int ActionCount();

private:
	bool m_isPannelActive;
	int m_activeAction;
	std::vector<std::shared_ptr<GameObject>> m_actionList;
	std::shared_ptr<GameObject> m_pSelectionArrow;
	std::shared_ptr<GameObject> m_pTitle;

};


#endif