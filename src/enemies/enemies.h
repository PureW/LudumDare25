/*
 * enemies.h
 *
 *  Created on: Dec 30, 2012
 *      Author: anders
 */

#ifndef ENEMIES_H_
#define ENEMIES_H_

#include "entity.hpp"


#include "entity.hpp"

class Enemy: public Entity {
public:
	Enemy(GameModel* gameModel, sf::RenderWindow* renderWindow,std::string spriteFilename="res/sprites/ship1.png");
	virtual ~Enemy();


	void update() {};

	/** Called when destroyed. */
	virtual void onDestroy() {};


};

#endif /* ENEMIES_H_ */
