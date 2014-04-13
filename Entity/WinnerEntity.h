#ifndef ENTITY_WINNERENTITY_H
#define ENTITY_WINNERENTITY_H

#include <jr/Entity.h>
#include "../Physics/NoPhysics.h"
#include "../Graphics/WinnerGFX.h"

namespace mvw
{

class WinnerEntity : public jr::Entity
{
	public:
		WinnerEntity(int winnerId);
		virtual ~WinnerEntity();

    virtual void update();
};

}
#endif
