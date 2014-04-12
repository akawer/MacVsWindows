#include "NoGraphics.h"

namespace simple
{

NoGraphics::NoGraphics()
{
}

NoGraphics::~NoGraphics()
{
}

void NoGraphics::drawWorld(float x, float y)
{
  (void)x;
  (void)y;
}

void NoGraphics::drawPixel(int x, int y)
{
  (void)x;
  (void)y;
}

sf::Drawable* NoGraphics::getDrawable()
{
  return 0;
}

void NoGraphics::setPosition(int x, int y)
{
  (void)x;
  (void)y;
}

}

