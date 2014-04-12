#include "NoPhysics.h"

namespace simple
{

NoPhysics::NoPhysics(float x0, float y0)
  : pos(x0, y0)
{
}

NoPhysics::~NoPhysics()
{
}

void NoPhysics::enterWorld(b2World* world)
{
  (void)world;
}

vec<float> NoPhysics::getPosition()
{
  return pos;
}

bbox<float> NoPhysics::getBounds()
{
  bbox<float> b(pos.x, pos.x, pos.y, pos.y);
  return b;
}


}

