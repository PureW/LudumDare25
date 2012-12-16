#ifndef DESTROYABLE_H_
#define DESTROYABLE_H_

class Destroyable
{
public:
	Destroyable();
	void destroy();
	bool isDestroyed();

protected:
	virtual void onDestroy();

private:
	bool destroyed;
};

#endif
