#ifndef ENTITY_DAMAGEOBJECT_H
#define ENTITY_DAMAGEOBJECT_H

#include <jr/Entity.h>

namespace mvw
{

class DamageObject : public jr::Entity
{
	public:
		DamageObject();
		virtual ~DamageObject();

    virtual void update();
};

}
#endif
