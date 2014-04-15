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
  falconPunch = 0;
  lives = 3;
  resetHealth();
  animationStateBitMask=FACING_LEFT;
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
  if(hp <= 0 || pos.y < -50.0){
    resetHealth();
    die();
  }
  controllerHandler();
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

void Character::collideWith(Entity* ent)
{
  Entity::collideWith(ent);
  DamageObject* pichazo = dynamic_cast<DamageObject*>(ent);
  if(pichazo){
    hp -= pichazo->getDmg();
  }
}

void Character::controllerHandler()
{
     int controllerId=getControllerId();
     float leftAnalogX = XboxInput::getAxis(controllerId, XboxInput::LEFT_ANALOG_X);
     float leftAnalogY = XboxInput::getAxis(controllerId, XboxInput::LEFT_ANALOG_Y);
     bool attack=XboxInput::getButton(controllerId,XboxInput::A);
     bool jump=(leftAnalogY<-60);
     bool moveToRight=(leftAnalogX>60);
     bool moveToLeft=(leftAnalogX<-60);

     if(moveToRight){ animationStateBitMask&=(0x1F & ~FACING_LEFT); animationStateBitMask|=FACING_RIGHT; }
     if(moveToLeft){ animationStateBitMask&=(0x1F & ~FACING_RIGHT); animationStateBitMask|=FACING_LEFT; }

    int filteredBitMask=animationStateBitMask&~FACING_LEFT&~FACING_RIGHT;

     vec<float> vel; 
     if(moveToRight &&
        (filteredBitMask==0 || filteredBitMask==MOVING) )
     {
                    ((CharacterGFX*)gcomp)->moveRight( (animationStateBitMask&~FACING_LEFT-FACING_RIGHT)==MOVING | FACING_RIGHT);
                    animationStateBitMask |= MOVING;
                    vel=pcomp->getVelocity();
                    vel.x=30;
                    pcomp->setVelocity(vel);
     }
     else if(moveToLeft
        && (filteredBitMask==0 || filteredBitMask==MOVING) )
     {
                    ((CharacterGFX*)gcomp)->moveLeft(animationStateBitMask==MOVING | FACING_LEFT);
                    animationStateBitMask |= MOVING;
                    vel=pcomp->getVelocity();
                    vel.x=-30;
                    pcomp->setVelocity(vel);
     }
     
     else if(!moveToRight && filteredBitMask==MOVING)
     {
                    ((CharacterGFX*)gcomp)->StandByRight(false);
                     animationStateBitMask &= ~MOVING;
                    vel=pcomp->getVelocity();
                    vel.x=0;
                    pcomp->setVelocity(vel);
     }
     
     else if(!moveToLeft && filteredBitMask==MOVING)
     {
                    ((CharacterGFX*)gcomp)->StandByLeft(false);
                     animationStateBitMask &= ~MOVING;
                    vel=pcomp->getVelocity();
                    vel.x=0;
                    pcomp->setVelocity(vel);
     }
     else if(jump&& (filteredBitMask==MOVING || filteredBitMask==0))
     {
           ((CharacterGFX*)gcomp)->jump(false,animationStateBitMask&FACING_LEFT!=0);
           animationStateBitMask |= JUMPING;
           vel=pcomp->getVelocity();
           vel.y=30;
           pcomp->setVelocity(vel);
     }else if(filteredBitMask==JUMPING)
     {
           ((CharacterGFX*)gcomp)->jump(true,animationStateBitMask&FACING_LEFT!=0);
           vel=pcomp->getVelocity();
           if(vel.y==0) animationStateBitMask &= ~JUMPING;
     }else if(filteredBitMask==0&&attack)
     {
           ((CharacterGFX*)gcomp)->attack(false,animationStateBitMask&FACING_LEFT!=0);
           animationStateBitMask |= ATTACKING;
           vel = pcomp->getPosition();
           //falconPunch = new DamageObject(15,vel.x, vel.y, moveToLeft);
     }else if(filteredBitMask==ATTACKING)
     {
           if( ((CharacterGFX*)gcomp)->attack(true,animationStateBitMask&FACING_LEFT!=0) )
           {
               animationStateBitMask &= ~ATTACKING;
               if(falconPunch){
                 falconPunch->scheduleDeletion();
                 falconPunch = 0;
               }
           }
     }else if(filteredBitMask==JUMPING&&moveToRight)
     {
                    vel=pcomp->getVelocity();
                    vel.x=15;
                    pcomp->setVelocity(vel);
     }else if(filteredBitMask==JUMPING&&moveToLeft)
     {
                    vel=pcomp->getVelocity();
                    vel.x=-15;
                    pcomp->setVelocity(vel);
     }
     
}

}
