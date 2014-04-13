#include "CheckEnd.h"

namespace mvw
{

CheckEnd::CheckEnd(int numChars)
  : jr::Entity(new NoGraphics(),
               new NoPhysicsRect(180.0, 105.0, 0.0, 0.0))
{
  for(int i=0; i<numChars; i++)
    alive.push_back(1);
}

CheckEnd::~CheckEnd()
{
}

void CheckEnd::setDead(int characterId)
{
  alive[characterId]=0;
}

void CheckEnd::update()
{
  int total=0;
  int winner=0;
  for(std::size_t i=0; i<alive.size(); i++)
  {
    total += alive[i];
    if(alive[i])
      winner=i;
  }
  if(total <= 1)
  {
    vector<jr::Entity*> ents;
    ents.push_back(new WinnerEntity(winner));
    switchContext(ents);
  }
}

}
