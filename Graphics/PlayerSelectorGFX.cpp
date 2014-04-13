#include "PlayerSelectorGFX.h"
#include <cstdio>

namespace mvw
{

PlayerSelectorGFX::PlayerSelectorGFX()
{
  canvas.create(1700, 950);
  texture.create(1700, 950);
  sprite.setOrigin(1700/2, 950/2);
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
     drawPlayerOption(choices[0],250,116);
     drawPlayerOption(choices[1],250,532);
     texture.update(canvas);
     sprite.setTexture(texture);
     sprite.setTextureRect(sf::IntRect(0,0,1700,950));
     drawPixel(0,0);
}

void PlayerSelectorGFX::drawPlayerOption(int id,int x,int y)
{
     sf::Color c;

     switch(id)
     {
               case 0:
                    c = sf::Color::Cyan;
                    break;
               case 1:
                    c = sf::Color::Green;
                    break;
               case 2:
                    c = sf::Color::Magenta;
                    break;
               default:
                    c = sf::Color::White;
                    break;
     }
     for(int i=0;i<1200;i++)
             for(int j=0;j<300;j++)
             {
                     canvas.setPixel(x+i,y+j,c);
             }
     
     //draw arrows
     sf::Color arrowColor(0,0,0);
     for(int i=0;i<50;i++)
             for(int j=-i;j<=i;j++)
             {
                     canvas.setPixel(x+i,y+j+150, arrowColor);
             }
     for(int i=0;i<50;i++)
             for(int j=-i;j<=i;j++)
             {
                     canvas.setPixel(x+(1200-i),y+j+150, arrowColor);
             }
}

}

