

#include <cmath>
#include <iostream>

#include "projectile.hpp"



void Projectile::update()
{
	if (target != 0)
	{
		float diff_x = target->get_x()-x;
		float diff_y = target->get_y()-y;

		float rot = atan( diff_x, diff_y );

		addForce(rot, 1);
		//std::cout << "Moving to target\n";
		std::cout << "target->get_x()"<<target->get_x()<<" rot: "<<rot<< "diff_x: "<<diff_x<<std::endl;
	}
	Entity::update();

}


Projectile::Projectile( GameModel* gameModel, sf::RenderWindow* renderWindow )
 : Entity(gameModel,std::string("res/sprites/ship1.png"), renderWindow,NEUTRAL,100, 100, false, 1)
{
	target = 0;

}

void Projectile::onDestroy()
{
	std::cout << "Dying\n";
}


