
#include <cmath>

#include "particle.h"





void Particle::update()
{
	updateLogic();
	updateParticle();
}



void Particle::addForce(float angle, float force)
{
	velocity_x += cos(angle) * force;
	velocity_y += sin(angle) * force;


}


void Particle::updateParticle()
{




	while (velocity_x*velocity_x + velocity_y*velocity_y > velocity_max*velocity_max)
	{
		float brake_const = 0.99;
		velocity_x *= brake_const;
		velocity_y *= brake_const;
	}

	x += velocity_x;
	y += velocity_y;




}
