#ifndef GAME_CHECKEND_H
#define GAME_CHECKEND_H

namespace mvw
{

class CheckEnd
{
	public:
		CheckEnd();
		CheckEnd(Character* characters);
		~CheckEnd();
		void IAmDead(int characterId);
  private:
          vector<Entity*> entities;
          vector<Character*> characters;
};

}
#endif
