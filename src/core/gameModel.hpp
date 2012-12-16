#ifndef GAME_MODEL_H_
#define GAME_MODEL_H_

#include <list>
#include <SFML/Graphics.hpp>

class Entity;
class AreaEffect;

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
	
private:
	sf::RenderWindow* renderWindow;
	std::list<Entity*> entities;
	std::list<AreaEffect*> areaEffects;
	bool done;
	
};



#endif
