

#ifndef PARTICLE_H_
#define PARTICLE_H_

#define PI 3.14159265


class Particle
{
public:

	Particle();
	virtual ~Particle();

	virtual void update();


	void addForce(float angle, float force);
	void addRotationalForce( float force );

	float getX() {return x;};
	float getY() {return y;};
	float getRotation() {return rotation;};


	void setParticleProperties(char *filename);


protected:
	void updateParticle();

	float x,y,rotation;
	float velocity_x,velocity_y, velocity_max,acceleration_max;

	float mass, friction;

	float angular_speed;
	float moment_of_inertia;
	float angular_friction;

private:





};



float atan(float x,float y);




#endif
