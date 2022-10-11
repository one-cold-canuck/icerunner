// <one line to give the program's name and a brief idea of what it does.>
// SPDX-FileCopyrightText: 2022 Gerald Horula <email>
// SPDX-License-Identifier: GPL-3.0-or-later

#include "game.hpp"

Game::Game() {}

Game::~Game() {
  echo();
  curs_set(1);
  printw("Thank you for playing!\n");
  endwin();
}

void Game::init(const char *title) {

  scr = new Screen();

  scr->add("Welcome to ICERunner.\n\nPress any key to start.\nIf you want to quit press \"q\" or \"Q\"");

  int ch = getch();

  map = new Frame(2*scr->height(), 2*scr->width(), 0, 0, FrameType::mapGrid);
  viewport = new Frame(map, scr->height(), scr->width(), 0, 0, FrameType::viewport);
  main_char = new Entity('@', map->height() / 2, map->width() / 2);

  map->fill_window();

  if(ch == 'q' || ch == 'Q') return;

  map->add(main_char);
  viewport->center(main_char);
  viewport->refresh();

  isRunning = true;

}

void Game::handleEvents() {

  int ch = getch();

  if (ch == KEY_LEFT) {
    map->add(main_char, main_char->row(), main_char->col() - 1);
//    viewport->center(main_char);
//    viewport->refresh();
  }

  else if (ch == KEY_RIGHT) {
    map->add(main_char, main_char->row(), main_char->col() + 1);
//    viewport->center(main_char);
//    viewport->refresh();
  }

  else if (ch == KEY_UP) {
    map->add(main_char, main_char->row() - 1, main_char->col());
//    viewport->center(main_char);
//    viewport->refresh();
  }

  else if (ch == KEY_DOWN) {
    map->add(main_char, main_char->row() + 1, main_char->col());
//    viewport->center(main_char);
//    viewport->refresh();

  }
  else if (ch == 'q' || ch == 'Q') {
    isRunning = false;

  }
}

void Game::update() {
    // Process enemy/npc turns
    // Update counters
    // etc
}

void Game::render() {
    viewport->center(main_char);
    viewport->refresh();
}

void Game::clean() {
  echo();
  curs_set(1);
  printw("Thank you for playing!\n");
  endwin();
}