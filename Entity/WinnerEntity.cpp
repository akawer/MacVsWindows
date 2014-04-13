#include "WinnerEntity.h"

namespace mvw
{

WinnerEntity::WinnerEntity(int winnerId)
  : jr::Entity(new WinnerGFX(winnerId),
               new NoPhysics(0.0, 0.0))
{
	delay = 150;
}

WinnerEntity::~WinnerEntity()
{
}

void WinnerEntity::update()
{
	delay--;
	if(delay > 0){
		gcomp->drawPixel(0.0, -100.0);
		return;
	}
	//get ready to switch context (back to title screen)
}



}

