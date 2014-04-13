#ifndef PARSER_MAPPARSER_H
#define PARSER_MAPPARSER_H

#include <fstream>
#include <vector>
#include <jr/Entity.h>
#include <jr/Utils.h>
#include "../../Entity/Wall.h"
#include "../../Entity/SpawnPoint.h"

namespace mvw
{

using std::vector;
using jr::Utils::vec;
using jr::Entity;
using mvw::Wall;

class MapParser
{
    public:
      MapParser(char* fileName);

      vector<Entity*> getPlatforms();
      vector<SpawnPoint*> getSpawnPoints();

    private:
      vector<Entity*> platforms;
      vector<SpawnPoint*> spawnPoints;
};

}

#endif
