#ifndef ENTITY_CHECKEND_H
#define ENTITY_CHECKEND_H

#include "Character.h"
#include <vector.h>

using namespace std::vector;

namespace mvw
{

class CheckEnd::Entity
{
	public:
		CheckEnd();
		CheckEnd(vector<Character*> characters, Stage* stage);
		~CheckEnd();
		void IAmDead(int characterId);
		virtual void update();
  private:
          vector<int> alive;
          Stage* stage;
};

}
#endif
