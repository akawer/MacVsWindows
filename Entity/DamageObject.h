#ifndef ENTITY_DAMAGEOBJECT_H
#define ENTITY_DAMAGEOBJECT_H

#include <jr/Entity.h>
#include <jr/Utils.h>
#include "../Graphics/NoGraphics.h"
#include "../Physics/DynBox.h"

namespace mvw
{

using jr::Utils::vec;

class DamageObject : public jr::Entity
{
	public:
		DamageObject(int dmg, float x0, float y0, bool moveLeft);
		virtual ~DamageObject();

    virtual void update();
    virtual int getDmg();
    
    private:
      int dmg;
};

}
#endif
