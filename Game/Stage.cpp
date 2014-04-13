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
  sprintf(fileName, "Level%d.txt", level);
  MapParser parser(fileName);
  entities = parser.getPlatforms();

  vector<SpawnPoint*> spawns = parser.getSpawnPoints();
  Character::setSpawns(spawns);
  for(std::size_t i=0; i<spawns.size(); i++)
    entities.push_back(spawns[i]);

  for(std::size_t i=0; i<chosenCharacters.size(); i++){
    Character* newCharacter;
    switch(chosenCharacters[i]){
      case 0:
        newCharacter = new Mac();
        break;
      case 1:
        newCharacter = new Windows();
        break;
      case 2:
        newCharacter = new Linux();
        break;
    }
    entities.push_back(newCharacter);
    characters.push_back(newCharacter);
  }

  CheckEnd* chkEnd = new CheckEnd(characters.size());
  entities.push_back(chkEnd);
  Character::setCheckEnd(chkEnd);
}

vector<Entity*>& Stage::getEntities()
{
  return entities;
}

}
