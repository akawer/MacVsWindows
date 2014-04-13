#include <vector>
#include <jr/Game.h>
#include <jr/Entity.h>
#include "Entity/PlayerSelector.h"

int main()
{
  using std::vector;
  using jr::Game;
  using jr::Entity;
  using mvw::PlayerSelector;

  vector<jr::Entity*> ents;
  ents.push_back(new PlayerSelector());
  Game g(ents);
  g.play();

  return 0;
}
