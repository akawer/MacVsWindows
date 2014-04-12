#include "Stage.h"

namespace mvw
{

Stage::Stage()
{
}

Stage::Stage(int level,vector<int> chosenCharacters)
{
                 setStageEntities(level,chosenCharacters);
                 this->game=game;
}

Stage::~Stage()
{
}

void Stage::setStageEntities(int level,vector<int> chosenCharacters)
{
          char fileName[30];
          sprintf(fileName,"Level%d.txt",level);
          MapParser parser(fileName);
          entities=parser.getPlatforms();
          for(int i=0;i<chosenCharacters.size();i++)
          {
                  Character* newCharacter=new Character(i,parser.getSpawnPoints());
                  entities.push_back(newCharacter);
                  characters.push_back(newCharacter);
          }
          entities.pushBack(new CheckEnd(characters,this));
}

vector<Entity*> & const Stage::getEntities()
{
                return entities;
}

}
