
#include <list>
#include <cmath>
#include <iostream>

#include "chipmunk.h"

#include "gameModel.hpp"
#include "projectile.hpp"

#define RADIUS 10
#define DAMAGE 30



void Projectile::update()
{
	if (target != 0)
	{
		cpVect diff_pos = cpvsub(target->getPos(),getPos());

		float rot = cpvtoangle( diff_pos ) - getA();

		addRotation(rot);

		applyImpulse(
				cpvrotate(cpv(0,1),getRot()),
				cpv(0,0)
				);
		//std::cout << "Moving to target\n";
		//std::cout << "target->get_x()"<<target->get_x()<<" rot: "<<rot<< "diff_x: "<<diff_x<<std::endl;

		sprite->SetRotation(rot);
		
	}
	
	/*
	std::list<Entity*> entities = gameModel->getEntitiesWithinRadius(x, y, RADIUS, this);
	std::list<Entity*>::iterator entityIt;
	for(entityIt = entities.begin(); entityIt != entities.end(); entityIt++) {
		Entity* entity = *entityIt;
		if(entity->getTeam() == myEnemyTeam) {
			entity->applyDamage(DAMAGE);
			destroy();
		}
	}
	*/
	
	Entity::update();

}



Projectile::Projectile( GameModel* gameModel, sf::RenderWindow* renderWindow )
 : Entity(gameModel, renderWindow,std::string("res/sprites/proj1.png"),NEUTRAL,100, 100)
{
	target = 0;
}

void Projectile::onDestroy()
{
	std::cout << "Dying\n";
}



