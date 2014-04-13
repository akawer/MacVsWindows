#ifndef GRAPHICS_PLAYERSELECTORGFX_H
#define GRAPHICS_PLAYERSELECTORGFX_H

#include <vector>
#include <jr/Graphics.h>

namespace mvw
{

using std::vector;

class PlayerSelectorGFX : public jr::GraphicsComponent
{
	public:
		PlayerSelectorGFX();
		~PlayerSelectorGFX();

    void drawUsing(vector<int> choices);

  protected:
    sf::Drawable* getDrawable();
    void setPosition(int x, int y);

	private:
    sf::Image canvas;
    sf::Sprite sprite;
};

}

#endif
