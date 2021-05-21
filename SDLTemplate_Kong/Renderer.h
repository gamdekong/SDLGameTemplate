#pragma once
#ifndef __RENDERER__
#define __RENDERER__
#include <SDL.h>
#include "Config.h"

/* Singleton */
class Renderer
{
public:
	static Renderer& Instance()
	{
		static Renderer instance;
		return instance;
	}

	// getters and setters
	//SDL_Renderer* getRenderer() const;
	void setRenderer(SDL_Renderer* renderer);

	void clean();

private:
	Renderer() = default;
	~Renderer() = default;

	SDL_Renderer* m_pRenderer;
};

#endif /* defined (__RENDERER__) */