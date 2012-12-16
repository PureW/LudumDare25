
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
	//gh.update();
	
	
	App.UseVerticalSync(true);
	App.SetFramerateLimit(60);

	ResourceHandler resHandler;
	resHandler.loadAllResources();

	EventHandler eventHandler(&App);


	sf::Image* shipImage = resHandler.getImage(std::string("res/sprites/ship1.png"));

	sf::Sprite shipSprite;
	shipSprite.SetImage(*shipImage);
	sf::Vector2f shipSize =  shipSprite.GetSize();
	shipSprite.SetCenter(shipSize.x/2, shipSize.y/2);
	Particle shipPart;
	shipSprite.SetX(200);
	shipSprite.SetY(200);

	// Start game loop
	while (App.IsOpened())
	{
		UserEvents events;
		events = eventHandler.processEvents();
		shipPart.addForce(0,((float)events.mouse_x-shipPart.getX()));
		shipPart.addForce(90, ((float)events.mouse_y-shipPart.getY()));

		shipPart.update();
		shipSprite.SetX(shipPart.getX());
		shipSprite.SetY(shipPart.getY());
		shipSprite.SetRotation(shipPart.getRotation());


		// Clear the screen (fill it with black color)
		App.Clear();

		App.Draw(shipSprite);

		// Display window contents on screen
		App.Display();
	}

	return 0;
}
