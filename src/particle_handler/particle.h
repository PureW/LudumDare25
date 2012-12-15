


#ifndef PARTICLE_H_
#define PARTICLE_H_




class Particle
{
public:

	Particle();
	virtual ~Particle();

	virtual void update();

	void updateParticle();

	void addForce(float angle, float force);
	void addRotationalForce( float force );

protected:
	float x,y,rotation;
	float velocity_x,velocity_y, velocity_max;

	float mass, friction;

	float angular_speed;
	float moment_of_inertia;
	float angular_friction;

private:





};









#endif
