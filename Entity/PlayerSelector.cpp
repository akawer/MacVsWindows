#include "PlayerSelector.h"

namespace mvw
{

PlayerSelector::PlayerSelector()
  : jr::Entity(//GraphicsComponent
               NoPhysics(0.0, 0.0))
{
               vector<int> controllerIds=getControllerIds();
               for(int i=0;i<controllerIds.size();i++)
               {
                       playerChoice.controllerId=controllerIds[i];
                       playerChoice.chosenOSId=0;
                       playerChoice.isDone=false;
               }
               
}

PlayerSelector::~PlayerSelector()
{
}

vector<int> PlayerSelector::getControllerIds()
{
  //TODO - implement this method
	  vector<int> v;
	  return v;
}

void PlayerSelector::update()
{
     bool allDone=true;
     for(int i=0;i<playerChoices.size();i++)
     {
             if(!playerChoices[i].isDone)
             {
                                         allDone=false;
                                         break;
             }
     }
     
     if(allDone==true)
     {
                      vector<int> chosenOnes;
                      for(int i=0;i<playerChoices.size();i++)
                      {
                              chosenOnes.push_back(playerChoices[i].chosenOSId);
                      }
                      Stage s(1,chosenOnes);
                      this->switchContext(s.getEntities());
     }
     else
     {
         for(int i=0;i<playerChoices.size();i++)
         {
                 int leftAnalogX=getFromController(playerChoices[i].controllerId,LEFT_ANALOG_STICK_X);
                 int aKey=getFromController(playerChoices[i].controllerId,A_KEY);
                 int bKey=getFromController(playerChoices[i].controllerId,B_KEY);
                 if(aKey) playerChoices[i].isDone=true;
                 if(bKey) playerChoices[i].isDone=false;
                 if(leftAnalogX>0) playerChoices[i].chosenOSId=(playerChoices[i].chosenOSId+1)%3;
                 if(leftAnalogX<0) playerChoices[i].chosenOSId=(playerChoices[i].chosenOSId-1)%3;
         }
     }
}


}

