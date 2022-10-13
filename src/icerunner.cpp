#include "game.hpp"

int main(int argc, const char *argv[]) {

  Game * game = new Game(); // TODO: object needs deletion

  game->init("ICERunner");

  while(game->running()) {
      game->handleEvents();
      game->update();
      game->render();
  }

  game->clean();

  return 0;
}
