#include "StartScene.h"
#include <algorithm>
#include "Game.h"
#include "glm/gtx/string_cast.hpp"
#include "EventManager.h"
#include "Renderer.h"

StartScene::StartScene()
{
	StartScene::start();
}

StartScene::~StartScene()
= default;

void StartScene::draw()
{
	SDL_SetRenderDrawColor(Renderer::Instance().getRenderer(), 0, 0, 255, 255);
	SDL_RenderDrawRect(Renderer::Instance().getRenderer(), &m_rect);
	Scene::drawDisplayList();
}

void StartScene::update()
{
	Scene::updateDisplayList();
}

void StartScene::clean()
{
	Scene::removeAllChildren();
}

void StartScene::handleEvents()
{
	EventManager::Instance().update();

	// Keyboard Events
	if (EventManager::Instance().isKeyDown(SDL_SCANCODE_ESCAPE))
	{
		TheGame::Instance().quit();
	}

}

void StartScene::start()
{
	//const SDL_Color blue = { 0, 0, 255, 255 };
	m_rect = {100, 100, 200, 300};

}

