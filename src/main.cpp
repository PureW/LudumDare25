
#include <iostream>
#include <vector>
#include <cstdlib>
#include <SFML/Graphics.hpp>

#include "common.h"
#include "config.h"
#include "res_handler.h"
#include "particle.h"
#include "event_handler.h"





int main(int argc, char* argv[]) 
{

	// Create the main rendering window
	sf::RenderWindow App(sf::VideoMode(800, 600, 32), "SFML Graphics");
	App.UseVerticalSync(true);
	App.SetFramerateLimit(60);

	ResourceHandler resHandler;
	resHandler.loadAllResources();

	EventHandler eventHandler(&App);


	sf::Image* shipImage = resHandler.getSprite(std::string("res/sprites/ship1.png"));

	sf::Sprite shipSprite;
	shipSprite.SetImage(*shipImage);
	sf::Vector2f shipSize =  shipSprite.GetSize();
	shipSprite.SetCenter(shipSize.x/2, shipSize.y/2);
	Particle shipPart;
	shipSprite.SetX(200);
	shipSprite.SetY(200);

	sf::Image* andromedaImage = resHandler.getSprite(std::string("res/sprites/m31_ware_big.jpg"));
	sf::Sprite andromedaSprite;
	andromedaSprite.SetImage(*andromedaImage);
	andromedaSprite.SetScale(0.25,0.25);

	float bgX=400,bgY=400;

	int numStars=20;
	std::vector<sf::Shape> stars;
	stars.resize(numStars);
	for (unsigned i=0; i<numStars; ++i)
	{
		stars[i] = sf::Shape::Circle(rand()%600,rand()%600,1,sf::Color(255,255,255));
	}


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

		bgX += 0.01;
		bgY += 0.005;

		andromedaSprite.SetX(bgX);
		andromedaSprite.SetY(bgY);



		// Clear the screen (fill it with black color)
		App.Clear();

		for (unsigned i=0; i<numStars; ++i)
			App.Draw(stars[i]);
		App.Draw(andromedaSprite);

		App.Draw(shipSprite);


		// Display window contents on screen
		App.Display();
	}

	return 0;
}
