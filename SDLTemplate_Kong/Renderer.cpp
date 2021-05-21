#include "Renderer.h"

#include <utility>

//SDL_Renderer* Renderer::getRenderer() const
//{
//	return m_pRenderer;
//}

void Renderer::setRenderer(SDL_Renderer* renderer)
{
	m_pRenderer = renderer;
}

void Renderer::clean()
{
	SDL_DestroyRenderer(m_pRenderer);
}
