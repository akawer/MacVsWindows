#include "PlayerSelector.h"

namespace mvw
{

PlayerSelector::PlayerSelector()
  : jr::Entity(//GraphicsComponent
               NoPhysics(0.0, 0.0))
{
   vector<int> controllerIds = XboxInput::getControllerIds();
   for(std::size_t i=0; i<controllerIds.size(); i++)
   {
      playerChoices[i].controllerId = controllerIds[i];
      playerChoices[i].chosenOSId = 0;
      playerChoices[i].isDone = false;
   } 
               
}

PlayerSelector::~PlayerSelector()
{
}

void PlayerSelector::update()
{
   if(allDone())
     startLevel();
   else
     processInput();
}

bool PlayerSelector::allDone()
{
  for(std::size_t i=0; i<playerChoices.size(); i++)
    if(!playerChoices[i].isDone)
      return false;
  return true;
}

void PlayerSelector::startLevel()
{
  vector<int> chosenOnes;
  for(int i=0;i<playerChoices.size();i++)
    chosenOnes.push_back(playerChoices[i].chosenOSId);
  Stage s(1,chosenOnes);
  switchContext(s.getEntities());
}

void PlayerSelector::processInput()
{
  for(int i=0;i<playerChoices.size();i++)
  {
    int aButton = XboxInput::getState(playerChoices[i].controllerId, XboxInput::A_BUTTON);
    int bButton = XboxInput::getState(playerChoices[i].controllerId, XboxInput::B_BUTTON);

    if(aButton)
      playerChoices[i].isDone=true;
    else if(bButton)
      playerChoices[i].isDone=false;
    
    if(!playerChoices[i].isDone){
      if(leftAnalogX > XboxInput::ANALOG_LEFT_X_THRESHOLD)
        playerChoices[i].chosenOSId = (playerChoices[i].chosenOSId + 1) % 3;
      if(leftAnalogX < -XboxInput::ANALOG_LEFT_X_THRESHOLD)
        playerChoices[i].chosenOSId = (playerChoices[i].chosenOSId - 1) % 3;
    }
  }
}



}

