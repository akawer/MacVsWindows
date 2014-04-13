#include <vector>
#include <jr/Game.h>
#include <jr/Entity.h>
#include "Entity/PlayerSelector.h"
#include "Entity/Wall.h"

int main()
{
  using std::vector;
  using jr::Game;
  using jr::Entity;
  using mvw::PlayerSelector;
  using mvw::Wall;

  vector<jr::Entity*> ents;
  //ents.push_back(new Wall(10.0, 50.0, 0.0, 0.0));
  ents.push_back(new PlayerSelector());
  Game g(ents);
  g.play();

  return 0;
}
