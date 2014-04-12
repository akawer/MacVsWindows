#ifndef ENTITY_PLAYERSELECTOR_H
#define ENTITY_PLAYERSELECTOR_H

#include <vector>
#include <SFML/Window.hpp>
#include <jr/Entity.h>
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
            typedef struct _playerChoice
            {
                    int controllerId;
                    int chosenOSId;
                    bool isDone;
            } playerChoice;
            vector<int> getControllerIds();
            vector<playerChoice> playerChoices;
};

}
#endif
