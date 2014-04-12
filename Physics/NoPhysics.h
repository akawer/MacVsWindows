#ifndef PHYSICS_NOPHYSICS_H
#define PHYSICS_NOPHYSICS_H

#include <Box2D/Box2D.h>
#include <jr/Physics.h>
#include <jr/Utils.h>

namespace simple
{

using jr::Utils::vec;
using jr::Utils::bbox;

class NoPhysics : public jr::PhysicsComponent
{
	public:
		NoPhysics(float x0, float y0);
		~NoPhysics();

    void enterWorld(b2World* world);
    bbox<float> getBounds();
    vec<float> getPosition();
    void setUserData(void* data);

    private:
      vec<float> pos;
};

}
#endif
