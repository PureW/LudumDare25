#include <string>
#include "motherShip.hpp"
#include "event_handler.h"

#define MS_HP 100
#define MS_EP 100
#define MS_RADIUS 50


using namespace std;




MotherShip::MotherShip(GameModel* gameModel, sf::RenderWindow* renderWindow)
: Entity(gameModel, std::string("res/sprites/ship1.png"), renderWindow, PLAYER, MS_HP, MS_EP, false, MS_RADIUS)
{
	this->gameModel = gameModel;
	this->renderWindow = renderWindow;
	this->eventHandler = new EventHandler(renderWindow);
}

MotherShip::~MotherShip()
{
	delete eventHandler;
}

void MotherShip::update()
{
	Entity::update();
	
	processInput();
}


void MotherShip::processInput()
{
	UserEvents events = eventHandler->processEvents();
	if(events.pressingUp) {
		velocity_x = 0;
		velocity_y = -1;
	}
	else if(events.pressingDown) {
		velocity_x = 0;
		velocity_y = 1;
	}
	else if(events.pressingLeft) {
		velocity_x = -1;
		velocity_y = 0;
	}
	else if(events.pressingRight) {
		velocity_x = 1;
		velocity_y = 0;
	}
	
}





