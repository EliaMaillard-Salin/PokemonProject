#include "GameObject.h"


GameObject::GameObject() : m_position({0.0f,0.0f}),m_type(Type::NONE),m_positionInScene()
{}

std::list<GameObject*>::iterator GameObject::GetSceneIterator()
{
	return m_positionInScene;
}
