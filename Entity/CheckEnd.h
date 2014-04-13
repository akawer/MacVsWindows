#ifndef ENTITY_CHECKEND_H
#define ENTITY_CHECKEND_H

#include <vector.h>
#include <jr/Entity.h>
#include "Character.h"
#include "PlayerSelector.h"
#include "../Game/Stage.h"

using std::vector;

namespace mvw
{

class CheckEnd : public jr::Entity
{
	public:
		CheckEnd();
		CheckEnd(vector<Character*> characters);
		~CheckEnd();
		void IAmDead(int characterId);
		virtual void update();

  private:
    vector<int> alive;
};

}
#endif
