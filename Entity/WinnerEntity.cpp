#include "WinnerEntity.h"

namespace mvw
{

WinnerEntity::WinnerEntity(int winnerId)
  : jr::Entity(new WinnerGFX(winnerId),
               new NoPhysics(0.0, 0.0))
{
}

WinnerEntity::~WinnerEntity()
{
}

void WinnerEntity::update()
{
}


}

