#include "CheckEnd.h"

namespace mvw
{
CheckEnd::CheckEnd()
{
}

CheckEnd::CheckEnd(vector<Character*> characters,Stage* stage)
{
                              for(int i=0;i<characters.size();i++)
                              {
                                      alive[i]=1;
                              }
                              this->stage=stage;
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
     for(int i=0;i<alive.size();i++)
     {
             total+=alive[i];
             if(alive[i]==1) winner=i;
     }
     if(total<=1)
     {
                 vector<int> chosenOnes;
                 chosenOnes[0]=(int)(3*rand());
                 chosenOnes[1]=(int)(3*rand());
                 stage->setStageEntities(1,chosenOnes);
                 switchContext(stage->getEntities());
     }
}

}
#endif
