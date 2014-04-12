#include "Windows.h"

namespace mvw
{

using std::vector;

Windows::Windows(int playerId, vector<SpawnPoint*> spawnPoints) : Character(playerId, spawnPoints)
{
}

Windows::~Windows()
{
}

virtual void Windows::update()
{
}

};

}
