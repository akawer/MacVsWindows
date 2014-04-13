#include "Character.h"

namespace mvw
{

static int numChars=0;
static vector<SpawnPoint*> spawnPoints;
static CheckEnd* checkEnd;

Character::Character(int typ)
  : jr::Entity(new CharacterGFX(typ),
               new CharacterPhysics(spawnPoints[numChars]->getX(),
                                    spawnPoints[numChars]->getY()))
{
  playerId = numChars++;
  lives = 3;
  resetHealth();
}

void Character::setSpawns(vector<SpawnPoint*> spawns)
{
  spawnPoints = spawns;
}

void Character::setCheckEnd(CheckEnd* chkEnd)
{
  checkEnd = chkEnd;
}

int Character::getControllerId()
{
  return XboxInput::getControllerIds()[playerId];
}

Character::~Character()
{
}

void Character::resetHealth()
{
  hp = 100;
}

void Character::update()
{
  vec<float> pos = pcomp->getPosition();
  if(hp <= 0 || pos.y < -40.0){
    resetHealth();
    die();
  }
  gcomp->drawWorld(pos.x, pos.y);
}

void Character::die()
{
  if(lives > 0)
  {
    pcomp->setPosition(getOpenSpawn(this));
    vec<float> motionless(0.0, 0.0);
    pcomp->setVelocity(motionless);
    lives--;
  }
  else
  {
    checkEnd->setDead(playerId);
    scheduleDeletion();
  }
}

vec<float> Character::getOpenSpawn(Character* c)
{
  std::size_t curr = c->playerId;
  for(std::size_t i=0; i<spawnPoints.size(); i++){
    SpawnPoint* s = spawnPoints[i]; 
    if(!s->isTouching())
      return s->getPosition();
    curr = (curr + 1) % spawnPoints.size();
  }
  return spawnPoints[curr]->getPosition();
}

}
