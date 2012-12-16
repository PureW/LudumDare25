

#include <string>
#include <list>

#include "yaml-cpp/yaml.h"

#include "motherShip.hpp"
#include "event_handler.h"
#include "gameModel.hpp"
#include "projectile.hpp"

#define MS_HP 100
#define MS_EP 100
#define MS_RADIUS 50


MotherShip::MotherShip(GameModel* gameModel, sf::RenderWindow* renderWindow)
: Entity(gameModel, std::string("res/sprites/ship1.png"), renderWindow, PLAYER, MS_HP, MS_EP, false, MS_RADIUS)
{
	this->gameModel = gameModel;
	this->renderWindow = renderWindow;
	this->eventHandler = new EventHandler(renderWindow);
	setParticleProperties("res/config/ship_properties.yaml");
	x = 100;
	y = 100;
	
}

MotherShip::~MotherShip()
{
	delete eventHandler;
}

void MotherShip::update()
{
	Entity::update();
	processInput();
	gameModel->setCenterViewPosition(x, y);
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

	if (events.pressingSpace && !oldEvents.pressingSpace)
	{
		std::cout << "Spawning projectile at "<<x<<"\n";
		Projectile* proj = new Projectile(gameModel, renderWindow );
		proj->setPosition( x, y );

		std::list<Entity*> entities =	gameModel->getEntitiesWithinRadius(x,y,400);
		std::list<Entity*>::iterator it = entities.begin();

		for (;it != entities.end(); ++it )
		{
			if (*it != (Entity*)this)
			{
				proj->setTarget(*it);
				std::cout << "Setting target\n";
			}
		}

		gameModel->addEntity( proj );
	}


	if (events.pressingF9 && !oldEvents.pressingF9)
		setParticleProperties("res/config/ship_properties.yaml");

	oldEvents = events;

}





