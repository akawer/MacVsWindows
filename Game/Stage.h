#ifndef GAME_STAGE_H
#define GAME_STAGE_H

namespace mvw
{

class Stage
{
	public:
		Stage();
		Stage(int level,vector<int> chosenCharacters);
		~Stage();
        void setStageEntities(int level, vector<int> chosenCharacters);
		vector<Entity*> & const getEntities();

  private:
          vector<Entity*> entities;
          vector<Character*> characters;
          Game* game;
};

}
#endif
