#include "DynBox.h"

namespace simple
{

DynBox::DynBox(float length, float x0, float y0)
  : l(length), x(x0), y(y0)
{
}

DynBox::~DynBox()
{
}

void DynBox::enterWorld(b2World* world)
{
  b2BodyDef bodyDef;
  bodyDef.type = b2_dynamicBody;
  bodyDef.position.Set(x, y);

  b2PolygonShape shape;
  shape.SetAsBox(l/2, l/2);

  b2FixtureDef fixDef;
  fixDef.shape = &shape;
  fixDef.density = 1;


  body = world->CreateBody(&bodyDef);
  body->CreateFixture(&fixDef);
}


}

