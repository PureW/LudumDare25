
#include <cmath>
#include <iostream>

#include "particle.h"



Particle::Particle()
{
	x=200,y=200;

	mass = 100;
	friction = 0.05;

	angular_speed = 0.0;
	angular_friction = 0.05;
	moment_of_inertia = 1.0;

	velocity_max = 10;
	acceleration_max = 0.1;
}

Particle::~Particle()
{

}





void Particle::addForce(float angle, float force)
{
	float accel_x = (cos(angle/180*PI) * force) / mass;
	float accel_y = -(sin(angle/180*PI) * force) / mass;

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



void Particle::update()
{

	velocity_x *= (1-friction);
	velocity_y *= (1-friction);
	angular_speed *= (1-angular_friction);

	while (velocity_x*velocity_x + velocity_y*velocity_y > velocity_max*velocity_max)
	{
		float brake_const = 0.99;
		velocity_x *= brake_const;
		velocity_y *= brake_const;
	}

	rotation += angular_speed;
	//atan( -velocity_y/velocity_x ) * 180 / PI - 90;
	/*if (velocity_x<0 && velocity_y<0)
		rotation += 180;
	if (velocity_x<0 && velocity_y>0)
		rotation += 180;*/
	rotation = fmod(rotation,360);

	//std::cout << "rot: "<<rotation<<"\tvel_x: "<<velocity_x<<"\tvel_y: "<<velocity_y
	//		<<"\tatan: "<<atan(velocity_x/velocity_y)/PI*180<<std::endl;


	x += velocity_x;
	y += velocity_y;




}
