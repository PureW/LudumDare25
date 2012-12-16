#include <iostream>
#include <cmath>

#include "gameModel.hpp"
#include "motherShip.hpp"
#include "entity.hpp"
#include "areaEffect.hpp"
#include "delayedExplosion.hpp"

using namespace std;



GameModel::GameModel(sf::RenderWindow* renderWindow)
{
	this->renderWindow = renderWindow;
	done = false;
	
	Entity* entity = new Entity(this, std::string("res/sprites/ship1.png"), renderWindow, 
		ENEMY, 100, 100, false, 20);
	addEntity(entity);
	
	motherShip = new MotherShip(this, renderWindow);
	motherShip->setDeathObject(new DelayedExplosion(this, renderWindow));
	addEntity(motherShip);
}


GameModel::~GameModel()
{
	list<Entity*>::iterator entityIt;
	for(entityIt = entities.begin(); entityIt != entities.end(); entityIt++) {
		delete *entityIt;
	}
	
	list<AreaEffect*>::iterator areaEffectIt;
	for(areaEffectIt = areaEffects.begin(); areaEffectIt != areaEffects.end(); areaEffectIt++) {
		delete *areaEffectIt;
	}
}

void GameModel::addEntity(Entity* entity)
{
	entities.push_back(entity);
}


void GameModel::addAreaEffect(AreaEffect* areaEffect)
{
	areaEffects.push_back(areaEffect);
}



void GameModel::update()
{
	list<Entity*>::iterator entityIt;
	for(entityIt = entities.begin(); entityIt != entities.end(); entityIt++) {
		(*entityIt)->update();
	}
	
	list<AreaEffect*>::iterator areaEffectIt;
	for(areaEffectIt = areaEffects.begin(); areaEffectIt != areaEffects.end(); areaEffectIt++) {
		(*areaEffectIt)->update();
	}
	
	
	
	entityIt = entities.begin();
	while (entityIt != entities.end())
	{
		if((*entityIt)->isDestroyed()) {
			delete *entityIt;
			entities.erase(entityIt++);	// ugly code...
		}
		else {
			entityIt++;
		}
	}
	
	areaEffectIt = areaEffects.begin();
	while (areaEffectIt != areaEffects.end())
	{
		if((*areaEffectIt)->isDestroyed()) {
			delete *areaEffectIt;
			areaEffects.erase(areaEffectIt++);	// ugly code...
		}
		else {
			areaEffectIt++;
		}
	}


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
	
	list<AreaEffect*>::iterator areaEffectIt;
	for(areaEffectIt=areaEffects.begin(); areaEffectIt != areaEffects.end(); areaEffectIt++) {
		(*areaEffectIt)->draw(screenOrigin_x, screenOrigin_y);
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


list<Entity*> GameModel::getEntitiesWithinRadius(float x, float y, float radius, Entity* excludeEntity)
{
	list<Entity*> entitiesWithinRadius = list<Entity*>();
	list<Entity*>::iterator entityIt;
	for(entityIt = entities.begin(); entityIt != entities.end(); entityIt++) {
		Entity* entity = *entityIt;
		if(isEntityWithinRadius(entity, x, y, radius) && entity != excludeEntity) {
			entitiesWithinRadius.push_back(entity);
		}
	}
	
	return entitiesWithinRadius;
}

MotherShip* GameModel::getMotherShip()
{
	return motherShip;
}

std::list<Entity*> GameModel::getEntitiesInTeam(Team team)
{
	list<Entity*> entitiesInTeam = list<Entity*>();
	list<Entity*>::iterator entityIt;
	for(entityIt = entities.begin(); entityIt != entities.end(); entityIt++) {
		Entity* entity = *entityIt;
		if(entity->getTeam() == team) {
			entitiesInTeam.push_back(entity);
		}
	}
	return entitiesInTeam;
}

bool GameModel::isEntityWithinRadius(Entity* entity, float x, float y, float radius)
{
	float distance = sqrt( pow(entity->get_x()-x, 2) + pow(entity->get_y()-y, 2) );
	return distance <= radius;
}







