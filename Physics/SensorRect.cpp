#include "SensorRect.h"

namespace mvw
{

SensorRect::SensorRect(float width, float height, float x0, float y0)
  : w(width), h(height), x(x0), y(y0)
{
}

SensorRect::~SensorRect()
{
}

void SensorRect::enterWorld(b2World* world)
{
  b2BodyDef bodyDef;
  bodyDef.type = b2_staticBody;
  bodyDef.position.Set(x, y);

  b2PolygonShape shape;
  shape.SetAsBox(w/2, h/2);

  b2FixtureDef fixDef;
  fixDef.shape = &shape;
  fixDef.isSensor = true;

  body = world->CreateBody(&bodyDef);
  body->CreateFixture(&fixDef);
}

}

