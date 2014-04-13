#ifndef ENTITY_CHARACTER_H
#define ENTITY_CHARACTER_H

#include <vector>
#include <jr/Entity.h>
#include <jr/Utils.h>
#include "CheckEnd.h"
#include "SpawnPoint.h"
#include "../Graphics/CharacterGFX.h"
#include "../Physics/CharacterPhysics.h"

namespace mvw
{

using std::vector;
using jr::Utils::vec;
using jr::XboxInput;

class Character : public jr::Entity
{
	public:
		Character(int playerType);
		~Character();

    virtual void update();

    static void setSpawns(vector<SpawnPoint*> spawns);
    static void setCheckEnd(CheckEnd* chkEnd);

  protected:
    int hp, lives, playerId;

    void resetHealth();
    void die();
    int getControllerId();
    static vec<float> getOpenSpawn(Character* c);

  
};

}
#endif
