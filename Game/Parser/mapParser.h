#ifndef PARSER_MAPPARSER_H
#define PARSER_MAPPARSER_H

#include "mapParser.h"
#include <jr/Utils.h>
using jr::Utils::vec;
namespace mvw
{
	class MapParser
	{
          private:
		          Wall* platforms;
                  vec<float>[4] spawnPoints;
                  int platformsQuantity;
		  public:
				 vec<float>[4] getSpawnPoints();
				 Rectangle* getPlatforms();
				 Map();
				 Map(string fileName);
				 int getPlatformsQuantity();
	};
}

#endif
