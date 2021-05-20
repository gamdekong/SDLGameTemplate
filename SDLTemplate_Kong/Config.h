#pragma once
#ifndef __CONFIG__
#define __CONFIG__

#include <SDL_ttf.h>
#include <memory>
#include "glm/vec2.hpp"

class Config {
public:
	static const int SCREEN_WIDTH = 800;
	static const int SCREEN_HEIGHT = 600;
	static const int ROW_NUM = 15;
	static const int COL_NUM = 20;
	static const int TILE_SIZE = 40;
	static const int TILE_COST = 1;
	static const int MINE_NUM = 50;
	static const int SCORE = 0;
	static const int LIVES = 5;

};

#endif /* defined (__CONFIG__) */