#include "Linux.h"

namespace mvw
{

using std::vector;

Linux::Linux(int playerId, vector<SpawnPoint*> spawnPoints) : Character(playerId, spawnPoints)
{
}

Linux::~Linux()
{
}

virtual void Linux::update()
{
}

};

}
