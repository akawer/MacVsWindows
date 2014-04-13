#include "CharacterGFX.h"

namespace mvw
{

CharacterGFX::CharacterGFX(int id)
{
  texture.loadFromFile("./Assets/Images/sprite.png");
}

CharacterGFX::~CharacterGFX()
{
}

sf::Drawable* CharacterGFX::getDrawable()
{
              sprite.setTexture(texture);
              sprite.setTextureRect(sf::IntRect(123*(frameNumber%8),100*(frameNumber/8),123,100));
              sprite.setColor(sf::Color(255,255,255,255));
              return &sprite;
}

void CharacterGFX::setPosition(int x, int y)
{
  sprite.setPosition(x, y);
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

