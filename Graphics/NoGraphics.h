#ifndef GRAPHICS_NOGRAPHICS_H
#define GRAPHICS_NOGRAPHICS_H

#include <SFML/Graphics.hpp>
#include <jr/Graphics.h>

namespace simple
{

class NoGraphics : public jr::GraphicsComponent
{
	public:
		NoGraphics();
		~NoGraphics();

    void drawWorld(float x, float y);
    void drawPixel(int x, int y);

  protected:
    sf::Drawable* getDrawable();
    void setPosition(int x, int y);
};

}
#endif
