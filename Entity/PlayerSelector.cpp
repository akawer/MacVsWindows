#include "PlayerSelector.h"

namespace mvw
{

PlayerSelector::PlayerSelector()
  : jr::Entity(//GraphicsComponent
               NoPhysics(0.0, 0.0))
{
}

PlayerSelector::~PlayerSelector()
{
}

vector<int> PlayerSelector::getControllerIds()
{
  //TODO - Implement XBox Controller API class
  //TODO - implement this method
  vector<int> v;
  return v;
}

void PlayerSelector::update()
{
  //TODO - Put logic here!
}


}

