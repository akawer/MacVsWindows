#include "FixedWall.h"

namespace simple
{

FixedWall::FixedWall(float width, float height, float x0, float y0)
  : w(width), h(height), x(x0), y(y0)
{
}

FixedWall::~FixedWall()
{
}

void FixedWall::enterWorld(b2World* world)
{
  b2BodyDef bodyDef;
  bodyDef.type = b2_staticBody;
  bodyDef.position.Set(x, y);

  b2PolygonShape shape;
  shape.SetAsBox(w/2, h/2);

  b2FixtureDef fixDef;
  fixDef.shape = &shape;
  fixDef.restitution = 0.01;

  body = world->CreateBody(&bodyDef);
  body->CreateFixture(&fixDef);
}


}

