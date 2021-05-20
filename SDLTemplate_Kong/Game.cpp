#include "Game.h"
#include <algorithm>
#include <ctime>
#include <iomanip>
#include <SDL_ttf.h>

#include "glm/gtx/string_cast.hpp"
#include "EventManager.h"
#include "SceneState.h"
#include "FontManager.h"
#include "Renderer.h"
#include "StartScene.h"
#include "TextureManager.h"


//Game* Game::s_pInstance = nullptr;

// Game functions - DO NOT REMOVE ***********************************************

Game::Game() :
	m_bRunning(true),
	m_frames(0),
	m_deltaTime(0),
	m_mousePosition(glm::vec2()),
	m_currentScene(nullptr),
	m_currentSceneState(SceneState::NO_SCENE),
	m_pWindow(nullptr)
{
	srand(unsigned(time(nullptr)));  // random seed
}


void Game::init()
{
	m_bRunning = true;
}

bool Game::init(const char* title, const int x, const int y, const int width, const int height, const bool fullscreen)
{
	auto flags = 0;

	if (fullscreen)
	{
		flags = SDL_WINDOW_FULLSCREEN;
	}

	// initialize SDL
	if (SDL_Init(SDL_INIT_EVERYTHING) >= 0)
	{
		std::cout << "SDL Init success" << std::endl;

		// if succeeded create our window
		m_pWindow = (SDL_CreateWindow(title, x, y, width, height, flags));

		// if window creation successful create our renderer
		if (m_pWindow != nullptr)
		{
			std::cout << "window creation success" << std::endl;

			// create a new SDL Renderer and store it in the Singleton
			SDL_Renderer* renderer = SDL_CreateRenderer(m_pWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
			Renderer::Instance().setRenderer(renderer);

			if (Renderer::Instance().getRenderer() != nullptr) // render init success
			{
				std::cout << "renderer creation success" << std::endl;
				SDL_SetRenderDrawColor(Renderer::Instance().getRenderer(), 255, 255, 255, 255);
			}
			else
			{
				std::cout << "renderer init failure" << std::endl;
				return false; // render int fail
			}

			// IMGUI
			//ImGuiWindowFrame::Instance().Init();

			// Initialize Font Support
			if (TTF_Init() == -1)
			{
				printf("SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError());
				return false;
			}

			start();

		}
		else
		{
			std::cout << "window init failure" << std::endl;
			return false; // window init fail
		}
	}
	else
	{
		std::cout << "SDL init failure" << std::endl;
		return false; //SDL could not intialize
	}

	std::cout << "init success" << std::endl;
	m_bRunning = true; // everything initialized successfully - start the main loop

	return true;
}

void Game::start()
{
	m_currentSceneState = SceneState::NO_SCENE;

	changeSceneState(SceneState::START_SCENE);
}

bool Game::isRunning() const
{
	return m_bRunning;
}


glm::vec2 Game::getMousePosition() const
{
	return m_mousePosition;
}

void Game::setFrames(const Uint32 frames)
{
	m_frames = frames;
}

Uint32 Game::getFrames() const
{
	return m_frames;
}

float Game::getDeltaTime() const
{
	return m_deltaTime;
}

void Game::setDeltaTime(const float time)
{
	m_deltaTime = time;
}

void Game::changeSceneState(const SceneState new_state)
{
	if (new_state != m_currentSceneState) {

		// scene clean up
		if (m_currentSceneState != SceneState::NO_SCENE)
		{
			m_currentScene->clean();
			std::cout << "cleaning previous scene" << std::endl;
			FontManager::Instance().clean();
			std::cout << "cleaning FontManager" << std::endl;
			TextureManager::Instance().clean();
			std::cout << "cleaning TextureManager" << std::endl;
		}

		delete m_currentScene;
		m_currentScene = nullptr;

		m_currentSceneState = new_state;

		EventManager::Instance().reset();

		switch (m_currentSceneState)
		{
			case SceneState::START_SCENE:
				m_currentScene = new StartScene();
				std::cout << "start scene activated" << std::endl;
				break;
			default:
				std::cout << "default case activated" << std::endl;
				break;
		}
	}

}

void Game::quit()
{
	m_bRunning = false;
}

void Game::render() const
{
	SDL_SetRenderDrawColor(Renderer::Instance().getRenderer(), 255, 255, 255, 255);
	SDL_RenderClear(Renderer::Instance().getRenderer()); // clear the renderer to the draw colour

	m_currentScene->draw();



	SDL_RenderPresent(Renderer::Instance().getRenderer()); // draw to the screen

	//ImGuiWindowFrame::Instance().Render();
}

void Game::update() const
{
	m_currentScene->update();
}

void Game::clean() const
{
	std::cout << "cleaning game" << std::endl;

	// Clean Up for IMGUI
	//ImGui::DestroyContext();
	//ImGuiWindowFrame::Instance().Clean();

	Renderer::Instance().clean();
	SDL_DestroyWindow(m_pWindow);

	TTF_Quit();
	SDL_Quit();
}

void Game::handleEvents() const
{
	m_currentScene->handleEvents();
}
