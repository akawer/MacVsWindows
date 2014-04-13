#include "PlayerSelectorGFX.h"

namespace mvw
{

PlayerSelectorGFX::PlayerSelectorGFX()
{
                                      canvas.create(1700,950);
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
     sprite.setImage(canvas);
}

void drawPlayerOption(int id,int x,int y)
{
     Color c;
     switch(id)
     {
               case 0:
                    c(255,255,255);
                    break;
               case 1:
                    c(0,0,255);
                    break;
               case 2:
                    c(0,128,128);
                    break;
     }
     for(int i=0;i<1200;i++)
             for(int j=0;j<300;j++)
             {
                     canvas.setPixel(x+i,y+j,c);
             }
     
     //draw arrows
     Color arrowColor(0,0,0);
     for(int i=0;i<50;i++)
             for(int j=-i;j<=i;j++)
             {
                     canvas.setPixel(x+i,y+j+150);
             }
     for(int i=0;i<50;i++)
             for(int j=-i;j<=i;j++)
             {
                     canvas.setPixel(x+(1200-i),y+j+150);
             }
}

}

