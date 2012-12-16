

#include <string>
#include "yaml-cpp/yaml.h"

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
	setParticleProperties("res/config/ship_properties.yaml");
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
	

	if (events.pressingUp)
		addForce(getRotation(),1);
	if (events.pressingRight)
		addRotationalForce(-0.2);
	if (events.pressingLeft)
		addRotationalForce(0.2);

	if (events.pressingF9)
		setParticleProperties("res/config/ship_properties.yaml");

}





