#ifndef GAME_MODEL_H_
#define GAME_MODEL_H_

#include <list>
#include <SFML/Graphics.hpp>
#include "entity.hpp"

class Entity;
class AreaEffect;
class MotherShip;

class GameModel
{
public:
	GameModel(sf::RenderWindow* renderWindow);
	~GameModel();
	void addEntity(Entity* entity);
	void addAreaEffect(AreaEffect* areaEffect);
	void update();
	void draw();
	bool isDone();
	void setCenterViewPosition(int x, int y);
	std::list<Entity*> getEntitiesWithinRadius(float x, float y, float radius, Entity* excludeEntity=NULL);
	std::list<Entity*> getEntitiesInTeam(Team team);
	MotherShip* getMotherShip();
	bool isEntityWithinRadius(Entity* entity, float x, float y, float radius);
	
private:
	
	MotherShip* motherShip;
	sf::RenderWindow* renderWindow;
	std::list<Entity*> entities;
	std::list<AreaEffect*> areaEffects;
	bool done;
	int center_x;
	int center_y;
	
};



#endif
