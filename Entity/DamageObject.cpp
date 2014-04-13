#include "DamageObject.h"

namespace mvw
{

DamageObject::DamageObject(int dmg, float x0, float y0, bool moveLeft)
  : jr::Entity(new NoGraphics(),
               new DynBox(0.3, moveLeft ? (x0-0.3) : (x0+0.3), y0))
{
  vec<float> velocity(10.0 * (moveLeft ? -1.0 : 1.0), 0);
  pcomp->setVelocity(velocity);
}

DamageObject::~DamageObject()
{
}

void DamageObject::update()
{
}


}

