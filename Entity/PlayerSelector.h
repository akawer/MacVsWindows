#ifndef ENTITY_PLAYERSELECTOR_H
#define ENTITY_PLAYERSELECTOR_H

#include <vector>
#include <SFML/Window.hpp>
#include <jr/Entity.h>
#include <jr/Utils.h>
#include "../Physics/NoPhysics.h"

namespace mvw
{

using std::vector;

class PlayerSelector : public jr::Entity
{
	public:
		PlayerSelector();
		~PlayerSelector();
    
    virtual void update();

	private:
    class PlayerChoice {
      public:
        int controllerId;
        int chosenOSId;
        bool isDone;
    };

    vector<PlayerChoice> playerChoices;
    int delay;

    void resetDelay();
};

}
#endif
