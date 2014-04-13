#ifndef ENTITY_PLAYERSELECTOR_H
#define ENTITY_PLAYERSELECTOR_H

//#include <cstdlib>
#include <vector>
#include <SFML/Window.hpp>
#include <jr/Entity.h>
#include <jr/Utils.h>
#include "../Physics/NoPhysicsRect.h"
#include "../Graphics/PlayerSelectorGFX.h"
#include "../Game/Stage.h"

namespace mvw
{

using std::vector;
using jr::XboxInput;

class PlayerSelector : public jr::Entity
{
	public:
		PlayerSelector();
		~PlayerSelector();
    
    virtual void update();

	private:
    class PlayerChoice {
      public:
        PlayerChoice(int contId);
        int controllerId;
        int chosenOSId;
        bool isDone;
    };

    vector<PlayerChoice> playerChoices;
    vector<int> delays;

    void resetDelay(int i);
    bool allDone();
    void startLevel();
    void processInput();
    vector<int> getChoices();
};

}
#endif
