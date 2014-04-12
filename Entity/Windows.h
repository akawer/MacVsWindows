#ifndef ENTITY_WINDOWS_H
#define ENTITY_WINDOWS_H

#include <vector>
#include "SpawnPoint.h"
#include "Character.h"

namespace mvw
{
using std::vector;

class Windows : public Character
{
	public:
		Windows(int playerId, vector<SpawnPoint*> spawnPoints);
		~Windows();
        virtual void update(); 
};

}
#endif
