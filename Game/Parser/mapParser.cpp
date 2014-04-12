#include "mapParser.h"

namespace mvw
{

vector< vec<float> > MapParser::getSpawnPoints()
{
  return spawnPoints;
}

vector< Entity* > MapParser::getPlatforms()
{
  return platforms;
}

MapParser::MapParser()
{
}

MapParser::MapParser(char* fileName)
{
       std::ifstream in(fileName);
       int qty;
       in>>qty;
       for(int i=0;i<qty;i++)
       {
           float x,y,w,h;
             in>>x>>y>>w>>h;
           this->platforms.push_back(new Wall(w,h,x,y));
       }
       in>>qty;
       for(int i=0;i<qty;i++)
       {
         vec<float> temp;
         in>>temp.x;
         in>>temp.y;
         this->spawnPoints.push_back(temp);
       }
       in.close();
}


}

