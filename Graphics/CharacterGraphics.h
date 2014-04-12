#ifndef GRAPHICS_CHARACTERGRAPHICS_H
#define GRAPHICS_CHARACTERGRAPHICS_H

#include <SFML/Graphics.hpp>
#include <jr/Graphics.h>

namespace mvw
{

class CharacterGraphics : public jr::GraphicsComponent
{
	public:
		CharacterGraphics(int osChoiceId);
		~CharacterGraphics();

  protected:
    sf::Drawable* getDrawable();
    void setPosition(int x, int y);

	private:
    sf::Sprite sprite;
};

}
#endif
