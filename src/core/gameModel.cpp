#include <iostream>
#include <cmath>

#include "chipmunk.h"

#include "common.h"
#include "gameModel.hpp"
#include "motherShip.hpp"
#include "entity.hpp"
#include "enemies.h"

using namespace std;



GameModel::GameModel(sf::RenderWindow* renderWindow,unsigned framesPerSecond)
{
	this->renderWindow = renderWindow;
	this->framesPerSecond = framesPerSecond;
	done = false;



	scaleToScreen = 10;
	space = cpSpaceNew();
	space->damping = 0.5;

	Entity* motherShip = new MotherShip(this, renderWindow);
	motherShip->setPosition(cpv(10,10));
	addEntity(motherShip);

	for (int x=20; x<70; x+=7)
		for (int y=20; y<70; y+=7)
		{
			Entity* enemy = new Enemy(this,renderWindow);
			enemy->setPosition(cpv(x,y));
			addEntity(enemy);
		}

}


GameModel::~GameModel()
{
	list<Entity*>::iterator entityIt;
	for(entityIt = entities.begin(); entityIt != entities.end(); entityIt++) {
		delete *entityIt;
	}
	
	cpSpaceFree( space );
}

void GameModel::addEntity(Entity* entity)
{
	entities.push_back(entity);
}

void GameModel::update()
{
	list<Entity*>::iterator entityIt;
	for(entityIt = entities.begin(); entityIt != entities.end(); entityIt++) {
		(*entityIt)->update();
	}
	
	entityIt = entities.begin();
	while (entityIt != entities.end())
	{
		if((*entityIt)->isDestroyed())
		{
			delete *entityIt;
			entities.erase(entityIt);	// ugly code...
		}

		entityIt++;
	}

	cpSpaceStep(space,1.0/framesPerSecond);
}

void GameModel::draw()
{
	renderWindow->Clear();
	
	int screenOrigin_x = center_x - renderWindow->GetWidth() / 2;
	int screenOrigin_y = center_y - renderWindow->GetHeight() / 2;
	
	
	list<Entity*>::iterator entityIt;
	for(entityIt=entities.begin(); entityIt != entities.end(); entityIt++) {
		(*entityIt)->draw(screenOrigin_x, screenOrigin_y);
	}
	
	renderWindow->Display();
}

void GameModel::setCenterViewPosition(int x, int y)
{
	center_x = x;
	center_y = y;
}



bool GameModel::isDone()
{
	return !renderWindow->IsOpened();
}


list<Entity*> GameModel::getEntitiesWithinRadius(float x, float y, float radius)
{
	list<Entity*> entitiesWithinRadius = list<Entity*>();
	list<Entity*>::iterator entityIt;
	for(entityIt = entities.begin(); entityIt != entities.end(); entityIt++) {
		Entity* entity = *entityIt;
		if(isEntityWithinRadius(entity, x, y, radius)) {
			entitiesWithinRadius.push_back(entity);
		}
	}
	return entitiesWithinRadius;
}

bool GameModel::isEntityWithinRadius(Entity* entity, float x, float y, float radius)
{
	//float distance = sqrt( pow(entity->get()-x, 2) + pow(entity->get_y()-y, 2) );
	WARN("isEntityWithinRadius not workning");
	return 0 <= radius;
}







