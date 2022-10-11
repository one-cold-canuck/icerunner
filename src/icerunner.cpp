#include "game.hpp"


//void game_loop(Frame &map, Frame &viewport, Entity &main_char, int ch) {

//  if (ch == 'q' || ch == 'Q') {
//    return;
//}

//  map.add(main_char);
//  viewport.center(main_char);
//  viewport.refresh();

//  while (1) {

//    ch = getch();

//    if (ch == KEY_LEFT) {
//      map.add(main_char, main_char.row(), main_char.col() - 1);
//      viewport.center(main_char);
//      viewport.refresh();
//    }

//    else if (ch == KEY_RIGHT) {
//      map.add(main_char, main_char.row(), main_char.col() + 1);
//      viewport.center(main_char);
//      viewport.refresh();
//    }

//    else if (ch == KEY_UP) {
//      map.add(main_char, main_char.row() - 1, main_char.col());
//      viewport.center(main_char);
//      viewport.refresh();
//    }

//    else if (ch == KEY_DOWN) {
//      map.add(main_char, main_char.row() + 1, main_char.col());
//      viewport.center(main_char);
//      viewport.refresh();

//    } else if (ch == 'q' || ch == 'Q') {
//      //isRunning = false;
//      break;
//    }
//  }
//}

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
