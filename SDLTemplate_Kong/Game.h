#pragma once
#ifndef __GAME__
#define __GAME__

// Core Libraries
#include <iostream>
#include <string>
#include <vector>
#include "SceneState.h"
#include "Scene.h"

#include <SDL.h>

#include <glm/vec2.hpp>

class Game
{
public:
	static Game& Instance()
	{
		static Game instance;
		return instance;
	}

	// simply set the isRunning variable to true
	void init();
	bool init(const char* title, int x, int y, int width, int height, bool fullscreen);

	// public life cycle functions
	void render() const;
	void update() const;
	void handleEvents() const;
	void clean() const;
	void start();
	void quit();

	// getter and setter functions
	glm::vec2 getMousePosition() const;

	void setFrames(Uint32 frames);
	Uint32 getFrames() const;

	float getDeltaTime() const;
	void setDeltaTime(float time);

	bool isRunning() const;
	void changeSceneState(SceneState new_state);

private:
	Game();
	~Game() = default;

	// game properties
	bool m_bRunning;
	Uint32 m_frames;
	float m_deltaTime;
	glm::vec2 m_mousePosition;

	// scene variables
	Scene* m_currentScene;
	SceneState m_currentSceneState;

	SDL_Window* m_pWindow;
};

typedef Game TheGame;

#endif /* defined (__GAME__) */

