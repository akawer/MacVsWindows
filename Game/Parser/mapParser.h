#ifndef PARSER_MAPPARSER_H
#define PARSER_MAPPARSER_H

#include <fstream>
#include <vector>
#include <jr/Utils.h>
#include "../../Entity/Wall.h"
#include "../../Entity/Entity.h"

namespace mvw
{

using std::vector;
using jr::Utils::vec;
using mvw::Wall;
using mvw::Entity;

class MapParser
{
    public:
      MapParser();
      MapParser(char* fileName);

      vector<Entity*> getPlatforms();
      vector< vec<float> > getSpawnPoints();

    private:
      vector<Entity*> platforms;
      vector< vec<float> > spawnPoints;
};

}

#endif
