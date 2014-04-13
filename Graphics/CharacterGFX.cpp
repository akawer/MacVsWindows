#include "CharacterGFX.h"

namespace mvw
{

CharacterGFX::CharacterGFX(int id)
{
  texture.loadFromFile("./Assets/Images/sprite.png");
  sf::Vector2f size(40.0/2, 100.0/2);
  sprite.setOrigin(size);
  ticker = 0.0;
}

CharacterGFX::~CharacterGFX()
{
}

sf::Drawable* CharacterGFX::getDrawable()
{
  ticker += 0.016;
  sprite.setTexture(texture);
  sprite.setTextureRect(sf::IntRect(123*(frameNumber%8),100*(frameNumber/8),123,100));
  sprite.setColor(sf::Color(255,255,255));
  return &sprite;
}

void CharacterGFX::setPosition(int x, int y)
{
  sprite.setPosition(x, y);
}

int CharacterGFX::checkFrame(int currentFrame)
{
  int rounded = jr::Utils::roundf(ticker);
  if(ticker >= 1)
    ticker = 0.0;
  return currentFrame + rounded;
}

void CharacterGFX::moveRight(bool sameState)
{
     if(!sameState) frameNumber=MOVE_RIGHT_ANIM;
     else           frameNumber = (checkFrame(frameNumber)-MOVE_RIGHT_ANIM) % MOVE_RIGHT_ANIM_LENGTH + MOVE_RIGHT_ANIM;
}

void CharacterGFX::moveLeft(bool sameState)
{
     if(!sameState) frameNumber=MOVE_LEFT_ANIM;
     else           frameNumber = (checkFrame(frameNumber)-MOVE_LEFT_ANIM) % MOVE_LEFT_ANIM_LENGTH + MOVE_LEFT_ANIM;
}
void CharacterGFX::StandByLeft(bool sameState)
{
     if(!sameState) frameNumber=STAND_BY_LEFT_ANIM;
     else           frameNumber = (checkFrame(frameNumber)-STAND_BY_LEFT_ANIM) % STAND_BY_LEFT_ANIM_LENGTH + STAND_BY_LEFT_ANIM;
}

void CharacterGFX::StandByRight(bool sameState)
{
     if(!sameState) frameNumber=STAND_BY_RIGHT_ANIM;
     else           frameNumber = (checkFrame(frameNumber)-STAND_BY_RIGHT_ANIM) % STAND_BY_RIGHT_ANIM_LENGTH + STAND_BY_RIGHT_ANIM;
}

void CharacterGFX::jump(bool sameState,bool isLeft)
{
     int prevBaseAddress;
     int baseAddress=JUMP_RIGHT_ANIM;
     if(isLeft) baseAddress=JUMP_LEFT_ANIM;
     if(!(JUMP_LEFT_ANIM<=frameNumber&&frameNumber<=JUMP_LEFT_ANIM+JUMP_ANIM_LENGTH-1))   prevBaseAddress=JUMP_LEFT_ANIM;
     else prevBaseAddress=JUMP_RIGHT_ANIM;
     if(!sameState) frameNumber=baseAddress;
     else if(frameNumber!=baseAddress+JUMP_ANIM_LENGTH-1)          frameNumber=frameNumber-prevBaseAddress+baseAddress+1;
}

bool CharacterGFX::attack(bool sameState,bool isLeft)
{
     int baseAddress=ATTACK_RIGHT_ANIM;
     if(isLeft) baseAddress=ATTACK_LEFT_ANIM;
     
     if(!sameState) frameNumber=baseAddress;
     else if(frameNumber==baseAddress+ATTACK_ANIM_LENGTH-1) return true;
     frameNumber++;
     return false;
}

}

