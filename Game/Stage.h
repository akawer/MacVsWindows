#ifndef GAME_STAGE_H
#define GAME_STAGE_H

#include <vector>
#include <jr/Entity.h>
#include "../Entity/Character.h"
#include "../Entity/Mac.h"
#include "../Entity/Windows.h"
#include "../Entity/Linux.h"

namespace mvw
{

using std::vector;
using jr::Entity;

class Stage
{
	public:
		Stage(int level, vector<int> chosenCharacters);
		~Stage();

    void setStageEntities(int level, vector<int> chosenCharacters);
		vector<Entity*> & const getEntities();

  private:
    vector<Entity*> entities;
    vector<Character*> characters;
};

}
#endif
