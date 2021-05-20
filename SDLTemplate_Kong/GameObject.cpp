#include "GameObject.h"

GameObject::GameObject() :
	m_transform{glm::vec2(0, 0), glm::vec2(0, 0), glm::vec2(0, 0)},
	m_rigidBody{0, glm::vec2(0, 0), glm::vec2(0, 0), false},
	m_width(0),
	m_height(0),
	m_type(GameObjectType::NONE),
	m_enabled(true),
	m_visible(true)
{
}

Transform GameObject::getTransform() const
{
	return m_transform;
}

void GameObject::setTransform(Transform transform)
{
	m_transform = transform;
}

RigidBody GameObject::getRigidBody() const
{
	return m_rigidBody;
}

void GameObject::setRigidBody(RigidBody rigidBody)
{
	m_rigidBody = rigidBody;
}

int GameObject::getWidth() const
{
	return m_width;
}

int GameObject::getHeight() const
{
	return m_height;
}

GameObjectType GameObject::getType() const
{
	return m_type;
}

void GameObject::setWidth(const int new_width)
{
	m_width = new_width;
}

void GameObject::setHeight(const int new_height)
{
	m_height = new_height;
}

void GameObject::setType(const GameObjectType new_type)
{
	m_type = new_type;
}

void GameObject::setEnabled(const bool state)
{
	m_enabled = state;
}

bool GameObject::isEnabled() const
{
	return m_enabled;
}

void GameObject::setVisible(const bool state)
{
	m_visible = state;
}

bool GameObject::isVisible() const
{
	return m_visible;
}
