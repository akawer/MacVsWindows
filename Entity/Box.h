#ifndef ENTITY_BOX_H
#define ENTITY_BOX_H

#include <jr/Entity.h>
#include <jr/Utils.h>
#include "../Graphics/RectShape.h"
#include "../Physics/DynBox.h"

namespace simple
{

using jr::Utils::vec;

class Box : public jr::Entity
{
	public:
		Box(float length, float x0, float y0);
		~Box();

    virtual void update();

  private:
    float size, x, y;
};

}
#endif
