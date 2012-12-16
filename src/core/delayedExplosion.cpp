#include <list>
#include <iostream>
#include "delayedExplosion.hpp"
#include "gameModel.hpp"

#define EXPLOSION_TIME_IN_FPS 50 
#define EXPLOSION_RADIUS 100
#define EXPLOSION_DAMAGE 100

using namespace std;

DelayedExplosion::DelayedExplosion(GameModel* gameModel, sf::RenderWindow* renderWindow)
: Entity(gameModel, string(""), renderWindow, NEUTRAL, 1, 0, true, 1.0)
{
	timeLeft = EXPLOSION_TIME_IN_FPS;
}

void DelayedExplosion::update()
{
	timeLeft--;
	if(timeLeft <= 0) {
		destroy();
	}
}

void DelayedExplosion::onDestroy()
{
	list<Entity*> entities = gameModel->getEntitiesWithinRadius(x, y, EXPLOSION_RADIUS);
	list<Entity*>::iterator entityIt;
	for(entityIt = entities.begin(); entityIt != entities.end(); entityIt++) {
		Entity* entity = *entityIt;
		if(entity->getTeam() == PLAYER || entity->getTeam() == ENEMY) {
			entity->applyDamage(EXPLOSION_DAMAGE);
		}
	}
	
}











