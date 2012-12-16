#include "gameHandler.hpp"
#include "gameModel.hpp"

GameHandler::GameHandler(sf::RenderWindow* renderWindow)
{
	gameModel = new GameModel(renderWindow);
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



