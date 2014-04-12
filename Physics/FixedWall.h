#ifndef PHYSICS_FIXEDWALL_H
#define PHYSICS_FIXEDWALL_H

#include <Box2D/Box2D.h>
#include <jr/Physics.h>

namespace simple
{

class FixedWall : public jr::PhysicsComponent
{
	public:
		FixedWall(float width, float height, float x0, float y0);
		~FixedWall();

    void enterWorld(b2World* world);

	private:
    float w, h, x, y;
};

}
#endif
