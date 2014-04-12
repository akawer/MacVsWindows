#include "Wall.h"

namespace simple
{

Wall::Wall(float width, float height, float x0, float y0)
  : jr::Entity(new RectShape(10*width, 10*height),
               new FixedWall(width, height, x0, y0))
{
  int low_priority = 1;
  setPriority(low_priority);
}

Wall::~Wall()
{
}

void Wall::update()
{
  vec<float> pos = pcomp->getPosition();
  gcomp->drawWorld(pos.x, pos.y);
}

}

