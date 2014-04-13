#include "Character.h"

namespace mvw
{

Character::Character(int id, vector<SpawnPoint*> spawnPoints)
  : jr::Entity(new CharacterGFX(id),
               new CharacterPhysics(spawnPoints[numChars]).x,
                                    spawnPoints[numChars]).y))
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
  gcomp->drawWorld(pos.x, pos.y);
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
    if(!s->isTouching())
      return s->getPosition();
    curr = (curr + 1) % spawnPoints.size();
  }
}

vec<float> Character::getIth(int id, vector<SpawnPoint*>

}
