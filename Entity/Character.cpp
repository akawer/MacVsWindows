#include "Character.h"

namespace mvw
{

Character::Character(int id,vector< vec<float> > * spawnPoints )
{
  this->spawnPoints=spawnPoints;
  this->id=id;
}

~Character::Character()
{
}

void Character::update()
{
  vec<float> pos = pcomp->getPosition();
  if(hp <= 0 || pos.y < -40.0)
    deadHandler();
}

void Character::deadHandler()
{
  if(lives > 0)
  {
    pcomp->setPosition((*spawnPosition)[(int)(rand()*(*spawnPosition.size()))]);
    vec<float> z(0.0, 0.0);
    pcomp->setVelocity(z);
    lives--;
  }
  else
  {
    keepTrack->IAmDead(playerId);
    scheduleDeletion();
  }
}

}
