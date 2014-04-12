#include "mapParser.h"
#include<fstream>
namespace mvw
{
	vec<float>[4] MapParser::getSpawnPoints()
	{
				  return spawnPoints;
	}
	Wall* MapParser::getPlatforms
	{
			   return platforms;
	}
	MapParser::Map()
	{
					this->platformsQuantity=0;
					this->platforms=new Wall[1];
	}
	MapParser::Map(string fileName)
	{
			   std::ifstream in(fileName);
			   in>>this->platformsQuantity;
			   this->platforms=malloc(sizeof(Wall)*this->platformsQuantity);
			   for(int i=0;i<this->platformsQuantity;i++)
			   {
					   float x,y,w,h;
					   in>>x,y,w,h;
					   this->platforms[i]=new Wall(w,h,x,y);
			   }
			   for(int i=0;i<4;i++)
			   {
					   in>>this->spawnPoints[i].x;
					   in>>this->spawnPoints[i].y;
			   }
			   in.close();
	}
	int MapParser::getPlatformsQuantity()
	{
	}
}
