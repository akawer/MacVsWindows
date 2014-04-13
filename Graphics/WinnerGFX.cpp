#include "WinnerGFX.h"

namespace mvw
{

WinnerGFX::WinnerGFX(int winId)
{
  winnerId = winId;

  	sf::Font MyFont;
	

	text("WINNER!!!", MyFont, 50);
	text.setColor(sf::Color(128, 128, 0));
	sf::FloatRect bounds = text.getLocalBounds();
	text.setOrigin(bounds.width/2, bounds.height/2);

	setPriority(-1);

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

