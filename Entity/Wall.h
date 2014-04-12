#ifndef ENTITY_WALL_H
#define ENTITY_WALL_H

#include <jr/Entity.h>
#include <jr/Utils.h>
#include "../Graphics/RectShape.h"
#include "../Physics/FixedWall.h"

namespace simple
{

using jr::Utils::vec;

class Wall : public jr::Entity
{
	public:
		Wall(float width, float height, float x0, float y0);
		~Wall();

    virtual void update();
};

}
#endif
