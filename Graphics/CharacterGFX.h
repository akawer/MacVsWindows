#ifndef GRAPHICS_CHARACTERGFX_H
#define GRAPHICS_CHARACTERGFX_H

#include <SFML/Graphics.hpp>
#include <jr/Graphics.h>

#define MOVE_RIGHT_ANIM 0
#define MOVE_RIGHT_ANIM_LENGTH 8
#define MOVE_LEFT_ANIM 16
#define MOVE_LEFT_ANIM_LENGTH 8
#define STAND_BY_RIGHT_ANIM 8
#define STAND_BY_RIGHT_ANIM_LENGTH 1
#define STAND_BY_LEFT_ANIM 12
#define STAND_BY_LEFT_ANIM_LENGTH 1

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
            sf::Texture texture;
            sf::Sprite sprite;
            int frameNumber;
};

}
#endif
