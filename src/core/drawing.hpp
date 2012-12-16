#ifndef DRAWING_H_
#define DRAWING_H_

#include <SFML/Graphics.hpp>


class Drawing
{
public:
	virtual void draw(float xOffset, float yOffset) {};

protected:
	sf::Sprite* sprite;
};

#endif
