/*
 * enemies.cpp
 *
 *  Created on: Dec 30, 2012
 *      Author: anders
 */

#include "enemies.h"

Enemy::Enemy(GameModel* gameModel, sf::RenderWindow* renderWindow, std::string spriteFilename)
	: Entity(gameModel, renderWindow,spriteFilename)
{


}

Enemy::~Enemy() {
	// TODO Auto-generated destructor stub
}

