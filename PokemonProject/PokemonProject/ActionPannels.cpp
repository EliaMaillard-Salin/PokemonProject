#include "ActionPannels.h"

ActionPanel::ActionPanel() :
	m_actionList({}), m_isPannelActive(false), m_pSelectionArrow(nullptr), m_pTitle(nullptr)
{
	SetSize({ 960.0f,300.0f });
}

ActionPanel::~ActionPanel()
{
}

void ActionPanel::Update()
{
	GameObject::Update();
}

void ActionPanel::Init(std::string panelTitle, int offset)
{
	MeshComponent& bg = AddComponent<MeshComponent>(Component::ID::MESH);
	bg.SetColor(LIGHTGRAY);
	bg.SetShape(MeshComponent::FILLED_RECTANGLE);

	m_pSelectionArrow = m_pScene->AddGameObject<GameObject>();
	UIShape& shape = m_pSelectionArrow->AddComponent<UIShape>(Component::ID::UI_SHAPE);
	shape.SetShape(UIShape::UIShapeType::FILLED_ELLIPSE);
	shape.SetColor(BLACK);
	m_pSelectionArrow->SetSize({ 10.0f,5.0f });
	m_pSelectionArrow->SetPosition({ this->m_position.x + 30.0f, this->m_position.y + 60.0f + 20.0f});

	m_pTitle = m_pScene->AddGameObject<GameObject>();
	m_pTitle->SetSize({ 240.0f,50.0f });
	m_pTitle->SetPosition({ this->m_position.x + 240 * offset, this->m_position.y - 50.0f });

	MeshComponent& tShape = m_pTitle->AddComponent<MeshComponent>(Component::ID::MESH);
	tShape.SetShape(MeshComponent::FILLED_RECTANGLE);
	tShape.SetColor(LIGHTGRAY);
	UIText& txt = m_pTitle->AddComponent<UIText>(Component::ID::UI_TEXT);
	txt.SetText(panelTitle);
	txt.SetColor(BLACK);
	txt.SetTextSize(40);
	txt.SetPosition({ this->m_position.x + 10.0f + 240 * offset, this->m_position.y - 45.0f });

}

void ActionPanel::SetPanelActive(bool active)
{
	m_pSelectionArrow->SetActive(active);
	for (int i = 0; i < m_actionList.size(); i++)
	{
		m_actionList[i]->SetActive(active);
	}
}


void ActionPanel::SetActionList(std::vector<std::string> const& actions)
{
	int xOffset = 0;
	int yOffset = 0;
	for (int i = 0; i < actions.size(); i++)
	{
		yOffset = i % 2;
		std::shared_ptr<GameObject> obj = m_pScene->AddGameObject<GameObject>();
		UIText& txt = obj->AddComponent<UIText>(Component::ID::UI_TEXT);
		txt.SetText(actions[i]);
		txt.SetColor(BLACK);
		txt.SetTextSize(35);

		txt.SetPosition({ this->m_position.x + 60.0f + (xOffset * 300.0f), this->m_position.y + 60.0f + (yOffset * 100.0f)});
		xOffset += i % 2;
		m_actionList.push_back(obj);
	}
}

void ActionPanel::ChangeActiveAction(int newAction)
{
	m_pSelectionArrow->SetPosition({ this->m_position.x + 30 + (300 * (newAction / 2)), this->m_position.y + 60.0f + 20.0f + (100.0f * (newAction % 2)) });
}

int ActionPanel::ActionCount()
{
	return m_actionList.size();
}
