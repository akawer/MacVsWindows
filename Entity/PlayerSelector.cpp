#include "PlayerSelector.h"

namespace mvw
{

PlayerSelector::PlayerChoice::PlayerChoice(int contId)
{
  controllerId = contId;
  chosenOSId = 0;
  isDone = false;
}

PlayerSelector::PlayerSelector()
  : jr::Entity(new PlayerSelectorGFX(),
               new NoPhysicsRect(170.0, 95.0, 0.0, 0.0))
{
   vector<int> controllerIds = XboxInput::getControllerIds();
   for(std::size_t i=0; i<controllerIds.size(); i++){
     PlayerChoice p(controllerIds[i]);
     playerChoices.push_back(p);
     delays.push_back(7);
   }
}

PlayerSelector::~PlayerSelector()
{
}

vector<int> PlayerSelector::getChoices()
{
  vector<int> chosenOnes;
  for(std::size_t i=0; i<playerChoices.size(); i++)
    chosenOnes.push_back(playerChoices[i].chosenOSId);
  return chosenOnes;
}

void PlayerSelector::update()
{
   if(allDone()){
     startLevel();
     return;
   }
   processInput();
   PlayerSelectorGFX* gfx = dynamic_cast<PlayerSelectorGFX*>(gcomp);
   gfx->drawUsing(getChoices());
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
  Stage s(1,getChoices());
  switchContext(s.getEntities());
}

void PlayerSelector::resetDelay(int i)
{
  delays[i] = 7;
}

void PlayerSelector::processInput()
{
  using jr::XboxInput;

  for(std::size_t i=0;i<playerChoices.size();i++){
    bool a_down = XboxInput::getButton(playerChoices[i].controllerId, XboxInput::A);
    bool b_down = XboxInput::getButton(playerChoices[i].controllerId, XboxInput::B);
    float leftAnalogX = XboxInput::getAxis(playerChoices[i].controllerId, XboxInput::LEFT_ANALOG_X);

    if(a_down)
      playerChoices[i].isDone=true;
    else if(b_down)
      playerChoices[i].isDone=false;
    
    delays[i]--;
    if(!(playerChoices[i].isDone) && delays[i] <= 0){
      if(leftAnalogX > 60.0)
        playerChoices[i].chosenOSId = (playerChoices[i].chosenOSId + 1) % 3;
      if(leftAnalogX < -60.0)
        playerChoices[i].chosenOSId = (playerChoices[i].chosenOSId - 1 + 3) % 3;
      resetDelay(i);
    }
  }
}


}

