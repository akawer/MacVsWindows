#include "PlayerSelector.h"

namespace mvw
{

PlayerSelector::PlayerSelector()
  : jr::Entity(new PlayerSelectorGFX(),
               new NoPhysics(0.0, 0.0))
{
   vector<int> controllerIds = XboxInput::getControllerIds();
   for(std::size_t i=0; i<controllerIds.size(); i++)
   {
      playerChoices[i].controllerId = controllerIds[i];
      playerChoices[i].chosenOSId = 0;
      playerChoices[i].isDone = false;
   } 
   resetDelay();
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

void PlayerSelector::resetDelay()
{
  delay = 40;
}

void PlayerSelector::processInput()
{
  using jr::XboxInput;

  delay--;
  for(int i=0;i<playerChoices.size();i++)
  {

    bool a_down = XboxInput::getButton(playerChoices[i].controllerId, XboxInput::A);
    bool b_down = XboxInput::getButton(playerChoices[i].controllerId, XboxInput::B);
    bool leftAnalogX = XboxInput::getAxis(playerChoices[i].controllerId, XboxInput::LEFT_ANALOG_X);

    if(a_down)
      playerChoices[i].isDone=true;
    else if(b_down)
      playerChoices[i].isDone=false;
    
    if(!playerChoices[i].isDone && delay <= 0){
      if(leftAnalogX > 30.0)
        playerChoices[i].chosenOSId = (playerChoices[i].chosenOSId + 1) % 3;
      if(leftAnalogX < -30.0)
        playerChoices[i].chosenOSId = (playerChoices[i].chosenOSId - 1) % 3;

      resetDelay();
    }
  }
}


}

