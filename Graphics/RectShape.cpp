#include "RectShape.h"

namespace simple
{

RectShape::RectShape(float x, float y)
{
  sf::Vector2f size(x, y);
  image.setSize(size);
  sf::Color c(x, y, 255);
  image.setFillColor(c);
  image.setOrigin(x/2, y/2);
}

RectShape::~RectShape()
{
}

sf::Drawable* RectShape::getDrawable()
{
  return &image;
}

void RectShape::setPosition(int x, int y)
{
  image.setPosition(x, y);
}

void RectShape::setAngle(float rad)
{
  image.setRotation(-rad * 180 / 3.14159265358);
}


}

