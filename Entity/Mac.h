#ifndef ENTITY_MAC_H
#define ENTITY_MAC_H

#include <vector>
#include "SpawnPoint.h"
#include "Character.h"

namespace mvw
{
using std::vector;

class Mac : public Character
{
	public:
		Mac(int playerId, vector<SpawnPoint*> spawnPoints);
		~Mac();
        virtual void update(); 
};

}
#endif
