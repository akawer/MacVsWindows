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
               vec<float> pos=pcomp->getPosition();
               if(hp<=0 || pos.y<-10.0) deadHandler();
          }
          void Character::deadHandler()
          {
               if(lifes>0)
               {
                          pcomp->setPosition((*spawnPosition)[(int)(rand()*(*spawnPosition.size()))]);
                          vec<float> z;
                          z.x=0;
                          z.y=0;
                          pcomp->setVelocity(z);
                          lifes--;
               }else
               {
                    keepTrack->IAmDead(id);
                    scheduleDeletion();
               }
          }
}
