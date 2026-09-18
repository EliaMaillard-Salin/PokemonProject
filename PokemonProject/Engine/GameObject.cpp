#include "GameObject.h"

#include "MeshComponent.h"
#include "Collider.h"

GameObject::GameObject() : 
	m_sceneIterator(), m_position({0.0f,0.0f}), m_size({0.0f,0.0f}),
	m_components({})
{
	std::uint8_t offset = 1 << 0;
	for (std::uint8_t c = 0; c < ComponentType::componentTypeCount; c++)
	{
		m_components.insert(std::pair<std::uint8_t, std::list<std::shared_ptr<Component>>>(offset, {}));
		offset <<= 1;
	}
}


void GameObject::RemoveComponent(Component::ID componentID)
{
	for (auto copsInList : m_components)
	{
		for(auto it = copsInList.second.begin(); it != copsInList.second.end(); it++)
		{
			if (it->get()->GetID() & componentID)
			{
				copsInList.second.erase(it);
			}
		}
	}
}


void GameObject::UpdateComponent(std::uint8_t componentType)
{
	for (std::shared_ptr<Component> comp : m_components[componentType])
	{
		switch (componentType)
		{
		case ComponentType::DRAW:
			comp->Draw();
			break;
		case ComponentType::DRAW_UI:
			comp->Draw();
			break;
		case ComponentType::UPDATE:
			comp->Update();
			break;
		case ComponentType::FIXED_UPDATE:
			comp->FixedUpdate();
			break;
		default:
			break;
		}
	}
}

Vector2 GameObject::GetPosition() const
{
	return m_position;
}
Vector2 GameObject::GetSize() const
{
	return m_size;
}

void GameObject::SetPosition(Vector2 const& pos)
{
	m_position = pos;
}
void GameObject::SetSize(Vector2 const& size)
{
	m_size = size;
}

void GameObject::SetActive(bool isActive)
{
	m_isActive = isActive;
}

bool GameObject::GetActive()
{
	return m_isActive;
}
