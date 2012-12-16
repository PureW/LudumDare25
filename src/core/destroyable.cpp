#include "destroyable.hpp"


Destroyable::Destroyable()
{
	destroyed = false;
}

void Destroyable::destroy()
{
	if(!destroyed) {
		destroyed = true;
		onDestroy();
	}
}

bool Destroyable::isDestroyed()
{
	return destroyed;
}

void Destroyable::onDestroy()
{
	// empty
}



