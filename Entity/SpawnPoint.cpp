#include "SpawnPoint.h"

namespace mvw
{

SpawnPoint::SpawnPoint(float x0, float y0)
  : jr::Entity(NoGraphics(),
               SensorRect(10.0, 10.0, x0, y0))
{
}

SpawnPoint::~SpawnPoint()
{
}

void SpawnPoint::update()
{
}

bool SpawnPoint::isFree()
{
  SensorRect* sensor = static_cast<SensorRect*>(gcomp);
  return sensor->isTouched();
}


}

