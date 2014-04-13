#include "WinnerEntity.h"

namespace mvw
{

WinnerEntity::WinnerEntity(int winnerId)
  : jr::Entity(new WinnerGFX(winnerId),
               new NoPhysicsRect(170.0, 95.0, 0.0, 0.0))
{
	delay = 666;
}

WinnerEntity::~WinnerEntity()
{
}

void WinnerEntity::update()
{
  gcomp->drawWorld(0.0, 0.0);
	delay--;
  if(delay > 0) return;

  if(fork())
    exit(0);
  else
    execlp("./out", "./out", 0);
}



}

