#ifndef ENTITY_LINUX_H
#define ENTITY_LINUX_H

#include <vector.h>
#include "SpawnPoint.h"
#include "Character.h"

namespace mvw
{
using std::vector;

class Linux : public Character
{
	public:
		Linux(int playerId, vector<SpawnPoint*> spawnPoints);
		~Linux();
        virtual void update(); 
};

}
#endif
