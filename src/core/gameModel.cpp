#include <iostream>

#include "gameModel.hpp"
#include "motherShip.hpp"
#include "entity.hpp"
#include "areaEffect.hpp"

using namespace std;



GameModel::GameModel(sf::RenderWindow* renderWindow)
{
	this->renderWindow = renderWindow;
	done = false;
	
	Entity* motherShip = new MotherShip(this, renderWindow);
	addEntity(motherShip);
	std::cout <<"Adding mothership\n";
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
	
	list<Entity*>::iterator entityIt;
	for(entityIt=entities.begin(); entityIt != entities.end(); entityIt++) {
		(*entityIt)->draw();
	}
	
	list<AreaEffect*>::iterator areaEffectIt;
	for(areaEffectIt=areaEffects.begin(); areaEffectIt != areaEffects.end(); areaEffectIt++) {
		(*areaEffectIt)->draw();
	}
	
	renderWindow->Display();
}


bool GameModel::isDone()
{
	return !renderWindow->IsOpened();
}












