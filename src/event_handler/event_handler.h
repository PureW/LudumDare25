

#ifndef EVENT_HANDLER_H_
#define EVENT_HANDLER_H_

#include <SFML/Graphics.hpp>



struct UserEvents
{
	bool pressingUp;
	bool pressingDown;
	bool pressingLeft;
	bool pressingRight;
	bool pressingSpace;

	bool pressingLMB;
	bool pressingRMB;
	unsigned int mouse_x;
	unsigned int mouse_y;


};


class EventHandler
{

public:
	EventHandler( sf::RenderWindow *App );
	~EventHandler() {};

	const UserEvents processEvents();




private:


	sf::RenderWindow *App;

	UserEvents events;

};














#endif
