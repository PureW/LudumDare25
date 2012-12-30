

#include <cmath>
#include <iostream>
#include "chipmunk.h"
#include "projectile.hpp"



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



