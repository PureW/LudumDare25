
#include <fstream>
#include <yaml-cpp/yaml.h>


#include "entity.hpp"
#include "res_handler.h"
#include "gameModel.hpp"

Entity::Entity(GameModel* gameModel, sf::RenderWindow* renderWindow,std::string spriteFilename,
		Team team, int hp_max, int ep_max)
{
	this->gameModel = gameModel;

	if(spriteFilename.empty())
		this->sprite = NULL;
	else
		this->sprite = ResourceHandler::getInstance()->createSprite(spriteFilename);
	WARN("ENTITY");

	this->renderWindow = renderWindow;
	this->team = team;
	this->hp_max = hp_max;
	this->hp = hp_max;
	this->ep_max = ep_max;
	this->ep = ep_max;

	destroyed = false;

	cpFloat mass=1,moment=1;
	entityBody = cpSpaceAddBody(gameModel->getSpace(), cpBodyNew(mass, moment));

	double radius = sprite->GetSize().y/2.4 / gameModel->getScaleToScreen();
	cpShape *entityShape = cpSpaceAddShape(gameModel->getSpace(), cpCircleShapeNew(entityBody,radius,cpvzero));
	cpShapeSetFriction(entityShape, 1);

	turningForce=1,thrust=1;
	velocityMax = 1;
}
Entity::~Entity()
{
	if(sprite != NULL)
		delete sprite;

	cpShapeFree(entityShape);
	cpBodyFree(entityBody);
}

void Entity::update()
{

	if(hp <= 0)
		destroy();
}


void Entity::draw(float xOffset, float yOffset)
{
	if(sprite != NULL) {

		cpVect pos = cpBodyGetPos(entityBody);
		double scale = gameModel->getScaleToScreen();

		sprite->SetX(pos.x*scale);
		sprite->SetY(pos.y*scale);
		sprite->SetRotation(-entityBody->a/PI*180 + 180);
		
		renderWindow->Draw(*sprite);
	}
}


void Entity::applyDamage(int damageHP)
{
	hp -= damageHP;
	if (hp < 0 )
		destroy();
}



void Entity::destroy()
{
	destroyed = true;
	onDestroy();
}


void Entity::addRotation( double force )
{
	cpBodyApplyImpulse(
			entityBody,
			cpvrotate(cpv(0,force),entityBody->rot),
			cpvrotate(cpv(-1,0),entityBody->rot));
	cpBodyApplyImpulse(
			entityBody,
			cpvrotate(cpv(0,-force),entityBody->rot),
			cpvrotate(cpv(1,0),entityBody->rot));

}



void Entity::setBodyProperties(char *filename)
{
	std::ifstream fin(filename);
	YAML::Parser parser(fin);

	YAML::Node doc;
	parser.GetNextDocument(doc);
	fin.close();

	double tmp;
	if (const YAML::Node *pName = doc.FindValue("mass"))
	{
		*pName >> tmp;
		setMass(tmp);
	}
	if (const YAML::Node *pName = doc.FindValue("moment"))
	{
		*pName >> tmp;
		setMoment(tmp);
	}
	if (const YAML::Node *pName = doc.FindValue("velocity_max"))
	{
		*pName >> tmp;
		velocityMax = tmp;
	}
	/*if (const YAML::Node *pName = doc.FindValue("friction"))
	    *pName >> friction;
	if (const YAML::Node *pName = doc.FindValue("angular_friction"))
		   *pName >> angular_friction;

	if (const YAML::Node *pName = doc.FindValue("velocity_max"))
			*pName >> velocity_max;
	if (const YAML::Node *pName = doc.FindValue("acceleration_max"))
			*pName >> acceleration_max;
*/

}
