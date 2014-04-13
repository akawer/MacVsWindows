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
  shape.SetAsBox(2.0, 5.0);
  //10 pixels per meter
  //100 pixels tall -> 10 meters
  //20 pixels as half width
  //40 pixels as width

  b2FixtureDef fixDef;
  fixDef.shape = &shape;
  fixDef.density = 1;

  body = world->CreateBody(&bodyDef);
  body->CreateFixture(&fixDef);
}


}

