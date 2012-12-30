#ifndef ENTITY_H_
#define ENTITY_H_

#include <string>
#include <SFML/Graphics.hpp>
#include "chipmunk.h"

#include "common.h"
#include "drawing.hpp"


enum Team { NEUTRAL, PLAYER, ENEMY };

class GameModel;

class Entity
{
public:
	Entity(GameModel* gameModel, sf::RenderWindow* renderWindow,std::string spriteFilename="",
		Team team=NEUTRAL, int hp_max=100, int ep_max=100);
	virtual ~Entity();

	virtual void update();
	virtual void draw(float xOffset, float yOffset);
	void destroy();
	/** Called when destroyed. */
	virtual void onDestroy() {};

	cpVect getPos() {return cpBodyGetPos(entityBody);};
	cpFloat getA() {return entityBody->a;};
	cpVect getRot() {return entityBody->rot;};
	/** Applies two opposite forces on each side, resulting in rotation on the spot. */
	void addRotation( double force );
	/** Apply an impulse (in world coordinates) to the body at a point relative to the center of gravity (also in world coordinates).
	 *  See cpBodyApplyImpulse. */
	void applyImpulse( cpVect j, cpVect r ) { cpBodyApplyImpulse(entityBody,j,r);};

	void applyDamage(int damageHP);
	bool isDestroyed() {return destroyed;};

	void setPosition(cpVect pos) {cpBodySetPos(entityBody, pos);};
	void setMass(cpFloat mass) {cpBodySetMass(entityBody,mass);};
	void setMoment(cpFloat moment) {cpBodySetMoment(entityBody,moment);};
	void setBodyProperties(char *filename);


protected:

	GameModel* gameModel;
	sf::Sprite* sprite;
	sf::RenderWindow* renderWindow;

	double turningForce,thrust;
	double velocityMax;

	int hp_max;
	int hp;
	int ep_max;
	int ep;
	Team team;

	bool destroyed;

	cpBody* entityBody;
	cpShape* entityShape;

};


#endif
