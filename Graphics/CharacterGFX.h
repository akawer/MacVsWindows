#ifndef GRAPHICS_CHARACTERGFX_H
#define GRAPHICS_CHARACTERGFX_H

#include <SFML/Graphics.hpp>
#include <jr/Graphics.h>

namespace mvw
{

class CharacterGFX : public jr::GraphicsComponent
{
	public:
		CharacterGFX(int id);
		~CharacterGFX();
		void moveRight(bool sameState);
		void moveLeft(bool sameState);
		void StandByLeft(bool sameState);
		void StandByRight(bool sameState);

  protected:
    sf::Drawable* getDrawable();
    void setPosition(int x, int y);

	private:
            sf::RectangleShape image;
            int frameNumber;
};

}
#endif
