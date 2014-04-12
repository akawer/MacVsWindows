#ifndef ENTITY_CHARACTER_H
#define ENTITY_CHARACTER_H

#include <vector.h>
#include <jr/Entity.h>
#include <jr/Utils.h>
#include "../Graphics/RectShape.h"
#include "../Physics/DynBox.h"

namespace mvw
{

using jr::Utils::vec;
using std::vector;

class Character : public jr::Entity
{
	public:
		Character(int playerId, vector< vec<float> >& spawnPoints);
		~Character();

    virtual void update();

  private:
    int hp, lives;
    int playerId, controllerId;
    vector< vec<float> > spawnPoints;
    CheckEnd* keepTrack;

    void deadHandler();
};

}
#endif
