#include "CharacterGraphics.h"

namespace mvw
{

class CharacterGraphics : public jr::GraphicsComponent
{

CharacterGraphics::CharacterGraphics(int osChoiceId)
{
                                         switch(osChoiceId)
                                         {
                                                           case 0:
                                                                break;
                                                           case 1:
                                                                break;
                                                           case 2:
                                                                break;
                                         }
}

CharacterGraphics::~CharacterGraphics()
{
}

sf::Drawable* CharacterGraphics::getDrawable()
{
  return &sprite;
}

void CharacterGraphics::setPosition(int x, int y)
{
     sprite.setPosition(x, y);
}

}
#endif
