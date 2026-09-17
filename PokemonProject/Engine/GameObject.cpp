#include "GameObject.h"

#include "MeshComponent.h"
#include "Collider.h"

GameObject::GameObject() : m_sceneIterator()
{}

void GameObject::AddComponent(Component & component)
{
	for (std::shared_ptr<Component> pCompIn : m_components)
		if (pCompIn->GetID() & component.GetID())
			return;
	std::shared_ptr<Component> pComp = std::make_shared<Component>(component);
	m_components.push_front(pComp);
	pComp->SetComponentIterator(m_components.begin());

	if (component.GetType() & Component::Type::DRAWABLE)
	{
		std::shared_ptr<MeshComponent> pMesh = std::dynamic_pointer_cast<MeshComponent>(pComp);
		m_drawableComponents.push_front(pMesh);
		pMesh->SetDrawingIterator(m_drawableComponents.begin());
	}
	if (component.GetType() & Component::Type::COLLIDER)
	{
		std::shared_ptr<Collider> pMesh = std::dynamic_pointer_cast<Collider>(pComp);
		m_collidableObjects.push_front(pMesh);
		//pMesh->SetColliderIterator(m_drawableComponents.begin());
	}
	if (component.GetType() & Component::Type::UI)
	{
		//std::shared_ptr<Collider> pMesh = std::dynamic_pointer_cast<Collider>(pComp);
		//m_collidableObjects.push_front(pMesh);
		//pMesh->SetColliderIterator(m_drawableComponents.begin());
	}

}

void GameObject::RemoveComponent(Component::ID componentID)
{
	for(std::shared_ptr<Component> pComp : m_components)
	{
		if (pComp->GetID() & componentID)
		{
			m_components.erase(pComp->GetComponentIterator());

			if (pComp->GetType() & Component::Type::DRAWABLE)
			{
				m_drawableComponents.erase(std::dynamic_pointer_cast<MeshComponent>(pComp)->GetDrawingIterator());
			}
			if (pComp->GetType() & Component::Type::COLLIDER)
			{
				//m_drawableComponents.erase(std::dynamic_pointer_cast<MeshComponent>(pComp)->GetDrawingIterator());
			}
			if (pComp->GetType() & Component::Type::UI)
			{
				//m_drawableComponents.erase(std::dynamic_pointer_cast<MeshComponent>(pComp)->GetDrawingIterator());
			}
		}
	}
}

Component& GameObject::GetComponent(Component::ID componentID)
{
	for (std::shared_ptr<Component> pComp : m_components)
	{
		if (pComp->GetType() & componentID)
			return *pComp;
	}
}

std::list<std::shared_ptr<GameObject>>::iterator GameObject::GetSceneIterator()
{
	return m_sceneIterator;
}

void GameObject::SetSceneIterator(std::list<std::shared_ptr<GameObject>>::iterator const& it)
{
	m_sceneIterator = it;
}
