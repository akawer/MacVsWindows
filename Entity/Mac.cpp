#include "Mac.h"

namespace mvw
{

using std::vector;

Mac::Mac(int playerId, vector<SpawnPoint*> spawnPoints) : Character(playerId, spawnPoints)
{
}

Mac::~Mac()
{
}

virtual void Mac::update()
{
}

};

}
