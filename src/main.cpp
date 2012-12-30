
#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <SFML/Graphics.hpp>
#include "chipmunk.h"

#include "common.h"
#include "config.h"
#include "res_handler.h"
#include "particle.h"
#include "event_handler.h"
#include "gameHandler.hpp"



int main(int argc, char* argv[]) 
{
	sf::RenderWindow App(sf::VideoMode(800, 600, 32), "SFML Graphics");
	
	#define MARTNO

	#ifdef MARTNO

		GameHandler gh(&App);
		while(!gh.isDone())
		{
			gh.update();
		}

	#else

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


	cpVect gravity = cpv(0,-10);
	cpSpace *space = cpSpaceNew();
	cpSpaceSetGravity(space,gravity);

	cpShape *ground = cpSegmentShapeNew(space->staticBody, cpv(-20, 5), cpv(200, -50), 0);
	cpShapeSetFriction(ground, 1);
	cpSpaceAddShape(space, ground);

	cpFloat radius = 5;
	cpFloat mass = 0.5;

	// The moment of inertia is like mass for rotation
	// Use the cpMomentFor*() functions to help you approximate it.
	cpFloat moment = cpMomentForCircle(mass, 0, radius, cpvzero);

	// The cpSpaceAdd*() functions return the thing that you are adding.
	// It's convenient to create and add an object in one line.
	cpBody *shipBody = cpSpaceAddBody(space, cpBodyNew(mass, moment));
	cpBodySetPos(shipBody, cpv(10, 15));

	cpShape *shipShape = cpSpaceAddShape(space, cpCircleShapeNew(shipBody, radius, cpvzero));
	cpShapeSetFriction(shipShape, 0.7);


	// Start game loop
	while (App.IsOpened())
	{
		UserEvents events;
		events = eventHandler.processEvents();

		if (events.pressingUp)
			//cpBodyApplyImpulse( shipBody, cpv(-1*sin(shipBody->a),1*cos(shipBody->a)),cpv(0,0));
			cpBodyApplyImpulse(
					shipBody,
					cpvrotate(cpv(0,1),shipBody->rot),
					cpv(0,0));
		if (events.pressingRight)
		{
			cpBodyApplyImpulse(
					shipBody,
					cpvrotate(cpv(0,1),shipBody->rot),
					cpvrotate(cpv(1,0),shipBody->rot));
			cpBodyApplyImpulse(
					shipBody,
					cpvrotate(cpv(0,-1),shipBody->rot),
					cpvrotate(cpv(-1,0),shipBody->rot));
		}
		if (events.pressingLeft)
		{
			cpBodyApplyImpulse(
					shipBody,
					cpvrotate(cpv(0,1),shipBody->rot),
					cpvrotate(cpv(-1,0),shipBody->rot));
			cpBodyApplyImpulse(
					shipBody,
					cpvrotate(cpv(0,-1),shipBody->rot),
					cpvrotate(cpv(1,0),shipBody->rot));
		}
		if (events.pressingF9)
			shipPart.setParticleProperties("res/config/ship_properties.yaml");

		shipPart.update();

		cpVect pos = cpBodyGetPos(shipBody);

		double scaleScreen = 10;

		shipSprite.SetX(pos.x*scaleScreen);
		shipSprite.SetY(pos.y*scaleScreen);
		shipSprite.SetRotation(-shipBody->a / PI * 180+180);

		cpSpaceStep(space,1.0/60);

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

	#endif

	return 0;
}
