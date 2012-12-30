

#ifndef PROJECTILE_H_
#define PROJECTILE_H_

#include "entity.hpp"



class Projectile : public Entity
{
public:

	Projectile( GameModel* gameModel, sf::RenderWindow* renderWindow );
	~Projectile() {};

	void onDestroy();

	void setTarget( Entity* _target ) {target=_target;};

	void update();

private:
	Entity* target;

};















#endif
