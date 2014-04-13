#include "WinnerGFX.h"

namespace mvw
{

WinnerGFX::WinnerGFX(int winId)
  : winnerId(winId), text()
{
  text.setString("HEARTBLEED WINS!!!");
	text.setCharacterSize(50);
	text.setColor(sf::Color(128, 128, 0));
	sf::FloatRect bounds = text.getLocalBounds();
	text.setOrigin(bounds.width/2, bounds.height/2);

	setPriority(-1);
}

WinnerGFX::~WinnerGFX()
{
}

sf::Drawable* WinnerGFX::getDrawable()
{
  return &text;
}

void WinnerGFX::setPosition(int x, int y)
{
	text.setPosition(x, y);
}


}

