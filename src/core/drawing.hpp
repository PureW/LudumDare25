#ifndef DRAWING_H_
#define DRAWING_H_

#include <SFML/Graphics.hpp>


class Drawing
{
public:
	virtual void draw() {};

protected:
	sf::Sprite* sprite;
};

#endif
