#include "SpawnPoint.h"

namespace mvw
{

SpawnPoint::SpawnPoint(float x0, float y0)
  : jr::Entity(new NoGraphics(),
               new SensorRect(10.0, 10.0, x0, y0))
{
  x = x0;
  y = y0;
}

SpawnPoint::~SpawnPoint()
{
}

void SpawnPoint::update()
{
}

float SpawnPoint::getX()
{
  return x;
}

float SpawnPoint::getY()
{
  return y;
}

vec<float> SpawnPoint::getPosition()
{
  return pcomp->getPosition();
}


}

