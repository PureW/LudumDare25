
#include <cmath>
#include <iostream>

#include "particle.h"



Particle::Particle()
{
	x=200,y=200;

	mass = 100;
	friction = 0.001;

	angular_speed = 0.0;
	moment_of_inertia = 1.0;

	velocity_max = 10;
	acceleration_max = 0.1;
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
	float accel_x = (cos(angle) * force) / mass;
	float accel_y = (sin(angle) * force) / mass;

	if (fabs(accel_x) < acceleration_max)
		velocity_x += accel_x;
	else
		velocity_x += accel_x/fabs(accel_x)*fabs(acceleration_max);

	if (fabs(accel_y) < acceleration_max)
		velocity_y += accel_y;
	else
		velocity_y += accel_y/fabs(accel_y)*fabs(acceleration_max);
}

void Particle::addRotationalForce( float force )
{
	angular_speed += force * moment_of_inertia;
}


void Particle::updateParticle()
{
	velocity_x *= (1-friction);
	velocity_y *= (1-friction);
	angular_speed *= angular_friction;



	while (velocity_x*velocity_x + velocity_y*velocity_y > velocity_max*velocity_max)
	{
		float brake_const = 0.99;
		velocity_x *= brake_const;
		velocity_y *= brake_const;
	}

	rotation = atan( -velocity_y/velocity_x ) * 180 / PI - 90;
	if (velocity_x<0 && velocity_y<0)
		rotation += 180;
	if (velocity_x<0 && velocity_y>0)
		rotation += 180;
	rotation = fmod(rotation,180);

	std::cout << "rotation is "<<rotation<<std::endl;


	x += velocity_x;
	y += velocity_y;




}
