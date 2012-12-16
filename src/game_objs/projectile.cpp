
#include <list>
#include <cmath>
#include <iostream>

#include "gameModel.hpp"
#include "projectile.hpp"

#define RADIUS 10
#define DAMAGE 30



void Projectile::update()
{
	if (target != 0)
	{
		float diff_x = target->get_x()-x;
		float diff_y = target->get_y()-y;

		float rot = atan( diff_x, diff_y );
		setRotation(rot);

		addForce(rotation, 1);
		//std::cout << "Moving to target\n";
		//std::cout << "target->get_x()"<<target->get_x()<<" rot: "<<rot<< "diff_x: "<<diff_x<<std::endl;

		sprite->SetRotation(rot);
		
	}
	
	std::list<Entity*> entities = gameModel->getEntitiesWithinRadius(x, y, RADIUS, this);
	std::list<Entity*>::iterator entityIt;
	for(entityIt = entities.begin(); entityIt != entities.end(); entityIt++) {
		Entity* entity = *entityIt;
		if(entity->getTeam() == myEnemyTeam) {
			entity->applyDamage(DAMAGE);
			destroy();
		}
	}
	
	Entity::update();

}


Projectile::Projectile( GameModel* gameModel, sf::RenderWindow* renderWindow, Team _myEnemyTeam )
 : Entity(gameModel,std::string("res/sprites/proj1.png"), renderWindow,NEUTRAL,100, 100, false, 1)
{
	myEnemyTeam = _myEnemyTeam;
	target = 0;

}

void Projectile::onDestroy()
{
	std::cout << "Dying\n";
}


void Projectile::draw(float xOffset, float yOffset)
{
	if(sprite != NULL) {
		sprite->SetX(x - xOffset);
		sprite->SetY(y - yOffset);
		sprite->SetRotation(getRotation()-90);
		sprite->SetScale(0.5,0.5);

		renderWindow->Draw(*sprite);
	}
}
