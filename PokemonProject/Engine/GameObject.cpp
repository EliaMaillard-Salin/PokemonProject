#include "GameObject.h"

#include "MeshComponent.h"
#include "Collider.h"

GameObject::GameObject() : m_sceneIterator(), m_position({0.0f,0.0f}), m_size({0.0f,0.0f})
{
}


void GameObject::RemoveComponent(Component::ID componentID, Component::Type componentType)
{
	for(std::shared_ptr<Component> pComp : m_components[componentType])
	{
		if (pComp->GetID() & componentID)
		{
			m_components[componentType].erase(pComp->m_compIterator);
		}
	}
}


void GameObject::UpdateComponent(Component::Type componentType)
{
	for (std::shared_ptr<Component> comp : m_components[componentType])
	{
		switch (componentType)
		{
		case Component::DRAW:
			comp->Draw();
			break;
		case Component::DRAW_UI:
			comp->Draw();
			break;
		case Component::UPDATE:
			comp->Update();
			break;
		case Component::FIXED_UPDATE:
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
