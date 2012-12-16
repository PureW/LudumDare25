#include "entity.hpp"
#include "res_handler.h"


Entity::Entity(GameModel* gameModel, std::string filename, sf::RenderWindow* renderWindow, 
	Team team, int maxHP, int maxEP, bool immune, float radius)
{
	this->gameModel = gameModel;
	this->sprite = ResourceHandler::getInstance()->createSprite(filename);
	this->renderWindow = renderWindow;
	this->team = team;
	this->maxHP = maxHP;
	this->maxEP = maxEP;
	this->immune = immune;
	this->radius = radius;
}
Entity::~Entity()
{
	delete sprite;
}

void Entity::update()
{
	Particle::update();
	if(hp <= 0) {
		destroy();
	}
}



void Entity::draw()
{
	sprite->SetX(x);
	sprite->SetY(y);
	sprite->SetRotation(getRotation()-90);
	
	renderWindow->Draw(*sprite);
}



