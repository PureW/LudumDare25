#ifndef DELAYED_EXPLOSION_H_
#define DELAYED_EXPLOSION_H_

#include "entity.hpp"

class DelayedExplosion : public Entity
{
public:
	DelayedExplosion(GameModel* gameModel, sf::RenderWindow* renderWindow);
	//virtual ~DelayedExplosion();
	virtual void update();
	virtual void onDestroy();
	
private:
	int timeLeft;
	
	
};



#endif
