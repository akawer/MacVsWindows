#include "mapParser.h"

namespace mvw
{

vector<SpawnPoint*>& MapParser::getSpawnPoints()
{
  return spawnPoints;
}

vector<Entity*> MapParser::getPlatforms()
{
  return platforms;
}

MapParser::MapParser(char* fileName)
{
  std::ifstream in(fileName);
  int qty;
  in >> qty;
  for(int i=0; i<qty; i++){
    float x, y, w, h;
    in >> x >> y >> w >> h;
    platforms.push_back(new Wall(w,h,x,y));
  }

  in >> qty;
  for(int i=0; i<qty; i++){
    float x, y;
    in >> x;
    in >> y;
    spawnPoints.push_back(new SpawnPoint(x, y));
  }
  in.close();
}


}

