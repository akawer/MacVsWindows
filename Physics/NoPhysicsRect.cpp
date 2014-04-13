#include "NoPhysicsRect.h"

namespace mvw
{

NoPhysicsRect::NoPhysicsRect(float width, float height, float x0, float y0)
  : NoPhysics(x0, y0), w(width), h(height)
{
}

NoPhysicsRect::~NoPhysicsRect()
{
}

bbox<float> NoPhysicsRect::getBounds()
{
  bbox<float> b(pos.x - w/2, pos.x + w/2, pos.y - w/2, pos.y + w/2);
  return b;
}


}

