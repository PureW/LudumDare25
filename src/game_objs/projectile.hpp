

#ifndef PROJECTILE_H_
#define PROJECTILE_H_

#include "entity.hpp"



class Projectile : public Entity
{
public:

	Projectile( GameModel* gameModel, sf::RenderWindow* renderWindow );
	~Projectile() {};

	void setTarget( Entity* _target ) {target=_target;};

	void update();
	void draw(float xOffset, float yOffset);
	void onDestroy();
private:
	Entity* target;

};















#endif
