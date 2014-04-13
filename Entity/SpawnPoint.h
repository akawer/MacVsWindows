#ifndef ENTITY_SPAWNPOINT_H
#define ENTITY_SPAWNPOINT_H

#include <jr/Entity.h>
#include <jr/Utils.h>
#include "../Graphics/NoGraphics.h"
#include "../Physics/SensorRect.h"

namespace mvw
{

using jr::Utils::vec;

class SpawnPoint : public jr::Entity
{
	public:
		SpawnPoint(float x0, float y0);
		~SpawnPoint();

    virtual void update();

    float getX();
    float getY();
    vec<float> getPosition();
    
    private:
      float x, y;
};

}
#endif
