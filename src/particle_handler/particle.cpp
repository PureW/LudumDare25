
#include <cmath>
#include <iostream>
#include <fstream>
#include <yaml-cpp/yaml.h>

#include "particle.h"

float atan(float x,float y)
{
	float rot;
	if (x==0)
		rot = 0;
	else
		rot = atan( -y/x ) * 180 / PI;
	if (x<0 && y<0)
		rot += 180;
	if (x<0 && y>0)
		rot += 180;

	return rot;
}

Particle::Particle()
{
	x=200,y=200;
	velocity_x = velocity_y = 0;

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

	while (accel_x*accel_x + accel_y*accel_y > acceleration_max*acceleration_max)
	{
		accel_x *= 0.98;
		accel_y *= 0.98;
	}

	velocity_x += accel_x;
	velocity_y += accel_y;
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



void Particle::setParticleProperties(char *filename)
{
	std::ifstream fin(filename);
	YAML::Parser parser(fin);

	YAML::Node doc;
	parser.GetNextDocument(doc);
	fin.close();

	if (const YAML::Node *pName = doc.FindValue("mass"))
	    *pName >> mass;
	if (const YAML::Node *pName = doc.FindValue("friction"))
	    *pName >> friction;
	if (const YAML::Node *pName = doc.FindValue("angular_friction"))
		   *pName >> angular_friction;
	if (const YAML::Node *pName = doc.FindValue("moment_of_inertia"))
		    *pName >> moment_of_inertia;
	if (const YAML::Node *pName = doc.FindValue("velocity_max"))
			*pName >> velocity_max;
	if (const YAML::Node *pName = doc.FindValue("acceleration_max"))
			*pName >> acceleration_max;


}
