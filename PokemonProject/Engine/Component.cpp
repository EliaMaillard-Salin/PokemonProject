#include "Component.h"

#include "GameObject.h"
#include <iostream>

Component::Component(GameObject* owner) :
	m_id(ID_NONE), m_type(TYPE_NONE), m_pGameObject(owner)
{
}

Component::~Component()
{
}

Component::Type Component::GetType()
{
	return m_type;
}


Component::ID Component::GetID()
{
	return m_id;
}

