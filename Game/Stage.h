#ifndef GAME_STAGE_H
#define GAME_STAGE_H

#include <cstdio>
#include <vector>
#include <jr/Entity.h>
#include "Parser/mapParser.h"
#include "../Entity/Character.h"
#include "../Entity/Mac.h"
#include "../Entity/Windows.h"
#include "../Entity/Linux.h"
#include "../Entity/CheckEnd.h"
#include "../Entity/SpawnPoint.h"

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
		vector<Entity*> & getEntities();

  private:
    vector<Entity*> entities;
    vector<Character*> characters;
};


}
#endif
