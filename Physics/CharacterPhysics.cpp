#include "CharacterPhysics.h"

namespace mvw
{

CharacterPhysics::CharacterPhysics(float x0, float y0)
  : x(x0), y(y0)
{
}

CharacterPhysics::~CharacterPhysics()
{
}

void CharacterPhysics::enterWorld(b2World* world)
{
  b2BodyDef bodyDef;
  bodyDef.type = b2_dynamicBody;
  bodyDef.position.Set(x, y);
  bodyDef.fixedRotation = true;

  b2PolygonShape shape;
  shape.SetAsBox(10.0/2, 10.0/2);

  b2FixtureDef fixDef;
  fixDef.shape = &shape;
  fixDef.density = 1;

  body = world->CreateBody(&bodyDef);
  body->CreateFixture(&fixDef);
}


}

