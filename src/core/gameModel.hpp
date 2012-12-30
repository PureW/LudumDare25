#ifndef GAME_MODEL_H_
#define GAME_MODEL_H_

#include <list>
#include <SFML/Graphics.hpp>
#include "chipmunk.h"

#include "entity.hpp"

class Entity;
class AreaEffect;
class MotherShip;

class GameModel
{
public:
	GameModel(sf::RenderWindow* renderWindow,unsigned framesPerSecond);
	~GameModel();
	void addEntity(Entity* entity);

	void update();
	void draw();
	bool isDone();
	void setCenterViewPosition(int x, int y);
	std::list<Entity*> getEntitiesWithinRadius(float x, float y, float radius, Entity* excludeEntity=NULL);
	std::list<Entity*> getEntitiesInTeam(Team team);
	MotherShip* getMotherShip();
	bool isEntityWithinRadius(Entity* entity, float x, float y, float radius);
	
	cpSpace* getSpace() {return space;};
	double getScaleToScreen() {return scaleToScreen;};

private:
	
	MotherShip* motherShip;
	sf::RenderWindow* renderWindow;
	unsigned framesPerSecond;

	std::list<Entity*> entities;
	bool done;
	int center_x;
	int center_y;
	
	cpSpace *space;
	double scaleToScreen;
};



#endif
