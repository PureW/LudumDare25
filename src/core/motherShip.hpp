#ifndef MOTHER_SHIP_H_
#define MOTHER_SHIP_H_

#include <SFML/Graphics.hpp>
#include "entity.hpp"

class EventHandler;
class GameModel;

class MotherShip : public Entity
{
public:
	MotherShip(GameModel* gameModel, sf::RenderWindow* renderWindow);
	virtual ~MotherShip();
	void update();
	
private:
	void processInput();
	
	GameModel* gameModel;
	sf::RenderWindow* renderWindow;
	EventHandler* eventHandler;
	
};


#endif
