#ifndef GRAPHICS_WINNERGFX_H
#define GRAPHICS_WINNERGFX_H

#include <SFML/Graphics.hpp>
#include <jr/Graphics.h>

namespace mvw
{

class WinnerGFX : public jr::GraphicsComponent
{
	public:
		WinnerGFX(int winnerId);
		virtual ~WinnerGFX();

  	protected:
    	sf::Drawable* getDrawable();
    	void setPosition(int x, int y);

	private:
    	int winnerId;
    	sf::Text text;
};

}
#endif
