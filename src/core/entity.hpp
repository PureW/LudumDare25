#ifndef ENTITY_H_
#define ENTITY_H_

#include <string>
#include <SFML/Graphics.hpp>
#include "particle.h"
#include "destroyable.hpp"
#include "drawing.hpp"


enum Team { NEUTRAL, PLAYER, ENEMY };

class GameModel;

class Entity : public Particle, public Destroyable, public Drawing
{
public:
	Entity(GameModel* gameModel, std::string filename, sf::RenderWindow* renderWindow, 
		Team team, int maxHP, int maxEP, bool immune, float radius);
	virtual ~Entity();
	virtual void update();
	virtual void draw();
	
protected:
	GameModel* gameModel;
	sf::Sprite* sprite;
	sf::RenderWindow* renderWindow;
	int maxHP;
	int hp;
	int maxEP;
	int ep;
	Team team;
	bool immune;
	float radius;
	
};


#endif
