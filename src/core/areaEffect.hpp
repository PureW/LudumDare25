#ifndef AREA_EFFECT_H_
#define AREA_EFFECT_H_

class AreaEffect : public Drawing, public Destroyable
{
public:
	virtual ~AreaEffect() {};
	void update() {};
};


#endif
