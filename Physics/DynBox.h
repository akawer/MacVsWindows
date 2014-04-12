#ifndef PHYSICS_DYNBOX_H
#define PHYSICS_DYNBOX_H

#include <Box2D/Box2D.h>
#include <jr/Physics.h>

namespace simple
{

class DynBox : public jr::PhysicsComponent
{
	public:
		DynBox(float length, float x0, float y0);
		~DynBox();

    void enterWorld(b2World* world);

	private:
    float l, x, y;
};

}
#endif
