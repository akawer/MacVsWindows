#ifndef PHYSICS_SENSORRECT_H
#define PHYSICS_SENSORRECT_H

#include <Box2D/Box2D.h>
#include <jr/Physics.h>

namespace mvw
{

class SensorRect : public jr::PhysicsComponent
{
	public:
		SensorRect(float width, float height, float x0, float y0);
		~SensorRect();

    virtual void enterWorld(b2World* world);

	private:
    float w,h,x,y;
};

}
#endif
