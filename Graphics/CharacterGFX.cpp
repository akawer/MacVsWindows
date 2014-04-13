#include "CharacterGFX.h"

namespace mvw
{

CharacterGFX::CharacterGFX(int id)
{
  //TODO - Use sf::Sprite here
  float x = 10.0;
  float y = 10.0;
  sf::Vector2f size(x, y);
  image.setSize(size);
  sf::Color c(id,0,255);
  image.setFillColor(c);
  image.setOrigin(x/2, y/2);
}

CharacterGFX::~CharacterGFX()
{
}

sf::Drawable* CharacterGFX::getDrawable()
{
  return &image;
}

void CharacterGFX::setPosition(int x, int y)
{
  image.setPosition(x, y);
}

void CharacterGFX::moveRight(bool sameState)
{
     if(!sameState) frameNumber=MOVE_RIGHT_ANIM;
     else           frameNumber = (frameNumber+1-MOVE_RIGHT_ANIM) % MOVE_RIGHT_ANIM_LENGTH + MOVE_RIGHT_ANIM;
}

void CharacterGFX::moveLeft(bool sameState)
{
     if(!sameState) frameNumber=MOVE_LEFT_ANIM;
     else           frameNumber = (frameNumber+1-MOVE_LEFT_ANIM) % MOVE_LEFT_ANIM_LENGTH + MOVE_LEFT_ANIM;
}
void CharacterGFX::StandByLeft(bool sameState)
{
     if(!sameState) frameNumber=STAND_BY_LEFT_ANIM;
     else           frameNumber = (frameNumber+1-STAND_BY_LEFT_ANIM) % STAND_BY_LEFT_ANIM_LENGTH + STAND_BY_LEFT_ANIM;
}

void CharacterGFX::StandByRight(bool sameState)
{
     if(!sameState) frameNumber=STAND_BY_RIGHT_ANIM;
     else           frameNumber = (frameNumber+1-STAND_BY_RIGHT_ANIM) % STAND_BY_RIGHT_ANIM_LENGTH + STAND_BY_RIGHT_ANIM;
}

}

