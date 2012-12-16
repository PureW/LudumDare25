
#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
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
	App.UseVerticalSync(true);
	App.SetFramerateLimit(60);
	
	GameHandler gh(&App);
	while(!gh.isDone()) {
		gh.update();
	}
	
	

/*

	EventHandler eventHandler(&App);


	sf::Image* shipImage = ResourceHandler::getInstance()->getImage(std::string("res/sprites/ship1.png"));

	sf::Sprite shipSprite;
	shipSprite.SetImage(*shipImage);
	sf::Vector2f shipSize =  shipSprite.GetSize();
	shipSprite.SetCenter(shipSize.x/2, shipSize.y/2);
	Particle shipPart;
	shipPart.setParticleProperties("res/config/ship_properties.yaml");
	shipSprite.SetX(200);
	shipSprite.SetY(200);

	sf::Image* andromedaImage = ResourceHandler::getInstance()->getImage(std::string("res/sprites/m31_ware_big.jpg"));
	sf::Sprite andromedaSprite;
	andromedaSprite.SetImage(*andromedaImage);
	andromedaSprite.SetScale(0.25,0.25);

	float bgX=400,bgY=400;

	unsigned numStars=20;
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

		if (events.pressingUp)
			shipPart.addForce(shipPart.getRotation(),100);
		if (events.pressingRight)
			shipPart.addRotationalForce(-0.2);
		if (events.pressingLeft)
				shipPart.addRotationalForce(0.2);

		if (events.pressingF9)
			shipPart.setParticleProperties("res/config/ship_properties.yaml");

		shipPart.update();
		shipSprite.SetX(shipPart.getX());
		shipSprite.SetY(shipPart.getY());
		shipSprite.SetRotation(shipPart.getRotation()-90);

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
	* */

	return 0;
}
