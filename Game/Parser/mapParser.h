#ifndef PARSER_MAPPARSER_H
#define PARSER_MAPPARSER_H

#include <fstream>
#include <vector>
#include <jr/Utils.h>
#include "../../Entity/Wall.h"

namespace mvw
{

using std::vector;
using jr::Utils::vec;
using mvw::Wall;

class MapParser
{
    public:
      MapParser();
      MapParser(std::string fileName);

      vector<Wall*> getPlatforms();
      vector< vec<float> > getSpawnPoints();

    private:
      vector<Wall*> platforms;
      vector< vec<float> > spawnPoints;
};

}

#endif
