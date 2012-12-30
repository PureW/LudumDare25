

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
: Entity(gameModel, renderWindow,std::string("res/sprites/ship1.png"), PLAYER)
{
	this->gameModel = gameModel;
	this->renderWindow = renderWindow;
	this->eventHandler = new EventHandler(renderWindow);

	setBodyProperties("res/config/ship_properties.yaml");

}

MotherShip::~MotherShip()
{
	delete eventHandler;
}

void MotherShip::update()
{
	Entity::update();
	processInput();
	cpVect pos = getPos();
	gameModel->setCenterViewPosition(pos.x, pos.y);
}


void MotherShip::processInput()
{
	UserEvents events = eventHandler->processEvents();


	if (events.pressingUp)
		applyImpulse(
				cpvrotate(cpv(0,thrust),entityBody->rot),
				cpv(0,0));
	if (events.pressingRight)
	{

		applyImpulse(
				cpvrotate(cpv(0,turningForce),entityBody->rot),
				cpvrotate(cpv(1,0),entityBody->rot));
		applyImpulse(
				cpvrotate(cpv(0,-turningForce),entityBody->rot),
				cpvrotate(cpv(-1,0),entityBody->rot));
	}
	if (events.pressingLeft)
	{
		applyImpulse(
				cpvrotate(cpv(0,turningForce),entityBody->rot),
				cpvrotate(cpv(-1,0),entityBody->rot));
		applyImpulse(
				cpvrotate(cpv(0,-turningForce),entityBody->rot),
				cpvrotate(cpv(1,0),entityBody->rot));
	}
	if (events.pressingF9)
		setBodyProperties("res/config/ship_properties.yaml");

	if (events.pressingSpace && !oldEvents.pressingSpace)
	{
/*
		std::cout << "Spawning projectile at "<<getPos().x<<"\n";
		Projectile* proj = new Projectile(gameModel, renderWindow );
		proj->setPosition( getPos() );

		/*std::list<Entity*> entities =	gameModel->getEntitiesWithinRadius(x,y,400);
		std::list<Entity*>::iterator it = entities.begin();

		for (;it != entities.end(); ++it )
		{
			Entity* entity = *entityIt;
			if(entity->getTeam() == ENEMY) {
				std::cout << "Spawning projectile at "<<x<<"\n";
				Projectile* proj = new Projectile(gameModel, renderWindow, ENEMY);
				proj->setPosition( x, y );
				proj->setTarget(entity);
				gameModel->addEntity( proj );
				
				break;
			}

		}*/
	}


	if (events.pressingF9 && !oldEvents.pressingF9)
		setBodyProperties("res/config/ship_properties.yaml");

	oldEvents = events;

}





