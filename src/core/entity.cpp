#include "entity.hpp"
#include "res_handler.h"
#include "gameModel.hpp"

Entity::Entity(GameModel* gameModel, std::string filename, sf::RenderWindow* renderWindow, 
	Team team, int maxHP, int maxEP, bool immune, float radius)
{
	this->gameModel = gameModel;
	if(filename.empty()) {
		this->sprite = NULL;
	}
	else {
		this->sprite = ResourceHandler::getInstance()->createSprite(filename);
	}
	this->renderWindow = renderWindow;
	this->team = team;
	this->maxHP = maxHP;
	this->hp = maxHP;
	this->maxEP = maxEP;
	this->ep = maxEP;
	this->immune = immune;
	this->radius = radius;
	
	this->deathObject = NULL;
}
Entity::~Entity()
{
	if(sprite != NULL) {
		delete sprite;
	}
}

void Entity::update()
{
	Particle::update();
	if(hp <= 0) {
		destroy();
	}
}



void Entity::draw(float xOffset, float yOffset)
{
	if(sprite != NULL) {
		sprite->SetX(x - xOffset);
		sprite->SetY(y - yOffset);
		
		renderWindow->Draw(*sprite);
	}
}

void Entity::setDeathObject(Entity* entity)
{
	this->deathObject = entity;
}
	
void Entity::onDestroy()
{
	if(deathObject != NULL) {
		deathObject->setPosition(x, y);
		gameModel->addEntity(deathObject);
	}
}
	
void Entity::setPosition(float new_x, float new_y)
{
	x = new_x;
	y = new_y;
}

Team Entity::getTeam()
{
	return team;
}



void Entity::applyDamage(int damageHP)
{
	hp -= damageHP;
}

float Entity::get_x()
{
	return x;
}

float Entity::get_y()
{
	return y;
}








