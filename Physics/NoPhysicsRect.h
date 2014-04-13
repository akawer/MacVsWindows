#ifndef PHYSICS_NOPHYSICSRECT_H
#define PHYSICS_NOPHYSICSRECT_H

#include <jr/Utils.h>
#include "NoPhysics.h"

namespace mvw
{

using jr::Utils::bbox;

class NoPhysicsRect : public NoPhysics
{
	public:
		NoPhysicsRect(float width, float height, float x0, float y0);
		~NoPhysicsRect();

    virtual bbox<float> getBounds();

	private:
    float w, h;
};

}
#endif
