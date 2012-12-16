#ifndef GAME_HANDLER_H_
#define GAME_HANDLER_H_

#include <SFML/Graphics.hpp>


class GameModel;

class GameHandler
{
public:
	GameHandler(sf::RenderWindow* renderWindow);
	~GameHandler();
	bool isDone();
	void update();


private:
	GameModel* gameModel;
};


#endif
