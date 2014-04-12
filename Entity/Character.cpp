#include "Character.h"

namespace mvw
{

Character::Character(int id, vector<SpawnPoint*> spawnPoints)
//  : jr::Entity(CharacterGraphicsComponent(id),
//               CharacterPhysics(A, B,
//                                getIth(id, spawnPoints[id]).x,
//                                getIth(id, spawnPoints[id]).y))
{
  this->spawnPoints = spawnPoints;
  this->playerId = id;
}

Character::~Character()
{
}

void Character::update()
{
  vec<float> pos = pcomp->getPosition();
  if(hp <= 0 || pos.y < -40.0)
    die();
}

void Character::die()
{
  if(lives > 0)
  {
    vec<float> spawn = getOpenSpawn();
    vec<float> motionless(0.0, 0.0);
    pcomp->setPosition(spawn.x, spawn.y);
    pcomp->setVelocity(motionless);
    lives--;
  }
  else
  {
    keepTrack->IAmDead(playerId);
    scheduleDeletion();
  }
}

vec<float> Character::getOpenSpawn()
{
  std::size_t curr = playerId;
  for(int i=0; i<spawnPoints.size(); i++){
    SpawnPoint* s = spawnPoints[i]; 
    if(s->isFree())
      return s->getPosition();
    curr = (curr + 1) % spawnPoints.size();
  }
}

}
