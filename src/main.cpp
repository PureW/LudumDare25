
#include <iostream>
#include <SFML/Graphics.hpp>

#include "common.h"
#include "config.h"
#include "res_handler.h"
#include "particle.h"


int main(int argc, char* argv[]) 
{

	// Create the main rendering window
	sf::RenderWindow App(sf::VideoMode(800, 600, 32), "SFML Graphics");


	ResourceHandler resHandler;

	resHandler.loadAllResources();

	sf::Image* shipImage = resHandler.getSprite(std::string("res/sprites/ship1.png"));

	sf::Sprite shipSprite;
	shipSprite.SetImage(*shipImage);

	// Start game loop
	while (App.IsOpened())
	{
		// Process events
		sf::Event Event;
		while (App.GetEvent(Event))
		{
			// Close window : exit
			if (Event.Type == sf::Event::Closed)
				App.Close();
		}

		// Clear the screen (fill it with black color)
		App.Clear();

		App.Draw(shipSprite);

		// Display window contents on screen
		App.Display();
	}

	return 0;
}
