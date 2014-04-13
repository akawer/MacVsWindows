#ifndef ENTITY_CHECKEND_H
#define ENTITY_CHECKEND_H

#include <vector>
#include <jr/Entity.h>
#include "WinnerEntity.h"
#include "../Graphics/NoGraphics.h"
#include "../Physics/NoPhysicsRect.h"

using std::vector;

namespace mvw
{

class CheckEnd : public jr::Entity
{
	public:
		CheckEnd(int numChars);
		~CheckEnd();
		void setDead(int characterId);
		virtual void update();

  private:
    vector<int> alive;
};

}
#endif
