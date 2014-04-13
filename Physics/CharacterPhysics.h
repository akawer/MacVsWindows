#ifndef PHYSICS_CHARACTERPHYSICS_H
#define PHYSICS_CHARACTERPHYSICS_H

#include <Box2D/Box2D.h>
#include <jr/Physics.h>

namespace mvw
{

class CharacterPhysics : public jr::PhysicsComponent
{
	public:
		CharacterPhysics(float x0, float y0);
		~CharacterPhysics();

    virtual void enterWorld(b2World* world);

	private:
    float x, y;
};

}
#endif
