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
	joystick=getXboxControllerIds();
	for (unsigned int j = 0; j < joystick.size(); ++j)
		{
			int i=joystick[j];
		    if (sf::Joystick::isConnected(i))
		    {

		        float x    = sf::Joystick::getAxisPosition(i, sf::Joystick::X);		//TO DOOO!! make sure which button is what
		        float y    = sf::Joystick::getAxisPosition(i, sf::Joystick::Y)    : 0;
		    }
		 }

  //TODO - implement this method
	  vector<int> v;
	  return v;
}

void PlayerSelector::update()
{
  //TODO - Put logic here!
	vector<int> a;
	  a[0]=player1Choice;
	  a[1]=player2Choice;
	  Stage s(1,a);
	  this->switchContext(s.getEntities());
}


}

