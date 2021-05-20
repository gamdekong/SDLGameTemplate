#pragma once
#ifndef __TRANSFORM__
#define __TRANSFORM__
#include <glm/vec2.hpp>

class Transform
{
public:
	Transform(const glm::vec2& position, const glm::vec2& rotation, const glm::vec2& scale)
		: m_position(position),
		  m_rotation(rotation),
		  m_scale(scale)
	{
	}


	glm::vec2 getPosition() const
	{
		return m_position;
	}

	void setPosition(const glm::vec2& mPosition)
	{
		m_position = mPosition;
	}

	glm::vec2 getRotation() const
	{
		return m_rotation;
	}

	void setRotation(const glm::vec2& mRotation)
	{
		m_rotation = mRotation;
	}

	glm::vec2 getScale() const
	{
		return m_scale;
	}

	void setScale(const glm::vec2& mScale)
	{
		m_scale = mScale;
	}

private:
	glm::vec2 m_position;
	glm::vec2 m_rotation;
	glm::vec2 m_scale;
};
#endif // !__TRANSFORM__
