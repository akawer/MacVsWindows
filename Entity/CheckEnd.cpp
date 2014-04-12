#include "CheckEnd.h"

namespace mvw
{

CheckEnd::CheckEnd()
{
}

CheckEnd::CheckEnd(vector<Character*> characters)
{
  for(std::size_t i=0;i<characters.size();i++)
    alive[i]=1;
}

CheckEnd::~CheckEnd()
{
}

void CheckEnd::IAmDead(int characterId)
{
     alive[characterId]=0;
}

void update()
{
  int total=0;
  int winner;
  for(std::size_t i=0; i<alive.size(); i++)
  {
    total+=alive[i];
    if(alive[i]==1) winner=i;
  }
  if(total<=1)
  {
    //TODO - Spawn "WINNER" entity that will later switch context
    //       to a Player Selection Menu
    vector<int> chosenOnes;
    chosenOnes[0]=(int)(3*rand());
    chosenOnes[1]=(int)(3*rand());
    Stage s(1, chosenOnes);
    switchContext(s.getEntities());
  }
}

}
#endif
