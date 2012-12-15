
#include <cmath>

#include "particle.h"



Particle::Particle()
{
	mass = 1.0;
	friction = 0.1;

	angular_speed = 0.0;
	moment_of_inertia = 1.0;
}

Particle::~Particle()
{

}



void Particle::update()
{
	updateParticle();
}



void Particle::addForce(float angle, float force)
{

	velocity_x += cos(angle) * force;
	velocity_y += sin(angle) * force;

}

void Particle::addRotationalForce( float force )
{
	angular_speed += force * moment_of_inertia;
}


void Particle::updateParticle()
{
	velocity_x *= friction;
	velocity_y *= friction;
	angular_speed *= angular_friction;



	while (velocity_x*velocity_x + velocity_y*velocity_y > velocity_max*velocity_max)
	{
		float brake_const = 0.99;
		velocity_x *= brake_const;
		velocity_y *= brake_const;
	}

	x += velocity_x;
	y += velocity_y;




}
