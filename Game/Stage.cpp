#include "Stage.h"

namespace mvw
{

Stage::Stage(int level, vector<int> chosenCharacters)
{
   setStageEntities(level, chosenCharacters);
}

Stage::~Stage()
{
}

void Stage::setStageEntities(int level, vector<int> chosenCharacters)
{
  char fileName[30];
  sprintf(fileName,"Level%d.txt",level);
  MapParser parser(fileName);
  entities = parser.getPlatforms();
  for(std::size_t i=0; i<chosenCharacters.size(); i++)
  {
    Character* newCharacter;
    switch(chosenCharacters[i])
    {
            case 0:
                 newCharacter=new Mac(i,parser.getSpawnPoints());
                 break;
            case 1:
                 newCharacter=new Windows(i,parser.getSpawnPoints());
                 break;
            case 2:
                 newCharacter=new Linux(i,parser.getSpawnPoints());
                 break;
    }
    entities.push_back(newCharacter);
    characters.push_back(newCharacter);
  }
  entities.push_back(new CheckEnd(characters));
}

vector<Entity*> & const Stage::getEntities()
{
                return entities;
}

}
