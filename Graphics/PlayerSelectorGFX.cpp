#include "PlayerSelectorGFX.h"

namespace mvw
{

PlayerSelectorGFX::PlayerSelectorGFX()
{

}

PlayerSelectorGFX::~PlayerSelectorGFX()
{
}

sf::Drawable* PlayerSelectorGFX::getDrawable()
{
  return &sprite;
}

void PlayerSelectorGFX::setPosition(int x, int y)
{
  sprite.setPosition(x, y);
}

void PlayerSelectorGFX::drawUsing(vector<int> choices)
{

}


}

