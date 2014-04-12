#ifndef ENTITY_SPAWNPOINT_H
#define ENTITY_SPAWNPOINT_H

#include <jr/Entity.h>
#include "../Graphics/NoGraphics.h"
#include "../Physics/SensorRect.h"

namespace mvw
{

class SpawnPoint : public jr::Entity
{
	public:
		SpawnPoint(float x0, float y0);
		~SpawnPoint();

    virtual void update();
    bool isFree();
};

}
#endif
