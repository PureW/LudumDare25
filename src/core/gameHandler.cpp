

#include <iostream>

#include "gameHandler.hpp"
#include "gameModel.hpp"

GameHandler::GameHandler(sf::RenderWindow* renderWindow)
{
	framesPerSecond = 60;
	renderWindow->UseVerticalSync(true);
	renderWindow->SetFramerateLimit(framesPerSecond);

	gameModel = new GameModel(renderWindow,framesPerSecond);
}

GameHandler::~GameHandler()
{
	delete gameModel;
}


bool GameHandler::isDone()
{
	return gameModel->isDone();
}

void GameHandler::update(){
	gameModel->update();
	gameModel->draw();
}



