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

  private:
          vector<Entity*> entities;
          vector<Character*> characters;
};

}
#endif
