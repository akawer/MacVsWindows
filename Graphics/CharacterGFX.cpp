#include "CharacterGFX.h"

namespace mvw
{

CharacterGFX::CharacterGFX(int id)
{
  playerType = id;

  //TODO - Use sf::Sprite here
  float x = 10.0;
  float y = 10.0;
  sf::Vector2f size(x, y);
  image.setSize(size);
  sf::Color c(40,0,255);
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

}

