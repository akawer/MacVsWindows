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
		Character(int id,vector< vec<float> > * spawnPoints);
		~Character();
        virtual void update();

  private:
    float x, y;
    int hp,lifes;
    vector< vec<float> > * spawnPoints;
    void deadHandler();
    CheckEnd* keepTrack;
    int controllerId;
    int id;
};

}
#endif
