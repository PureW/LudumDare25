
#include <iostream>
#include <SFML/Graphics.hpp>

#include "common.h"
#include "config.h"
#include "res_handler.h"
#include "particle.h"
#include "event_handler.h"




#include "gameHandler.hpp"


int main(int argc, char* argv[]) 
{

	
	// Create the main rendering window
	sf::RenderWindow App(sf::VideoMode(800, 600, 32), "SFML Graphics");
	GameHandler gh(&App);
	gh.update();
	
	
	App.UseVerticalSync(true);
	App.SetFramerateLimit(60);

	ResourceHandler resHandler;
	resHandler.loadAllResources();

	EventHandler eventHandler(&App);

	float x=0,y=0;

	sf::Image* shipImage = resHandler.getSprite(std::string("res/sprites/ship1.png"));

	sf::Sprite shipSprite;
	shipSprite.SetImage(*shipImage);

	// Start game loop
	while (App.IsOpened())
	{
		UserEvents events;
		events = eventHandler.processEvents();
		x += (events.mouse_x-x)*0.010;
		y += (events.mouse_y-y)*0.010;
		shipSprite.SetX(x);
		shipSprite.SetY(y);



		// Clear the screen (fill it with black color)
		App.Clear();

		App.Draw(shipSprite);

		// Display window contents on screen
		App.Display();
	}

	return 0;
}
