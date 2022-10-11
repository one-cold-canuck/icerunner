// ICE Runner - A cyberpunk Roguelike
// SPDX-FileCopyrightText: 2022 Gerald Horula <email>
// SPDX-License-Identifier: GPL-3.0-or-later

#ifndef GAME_HPP
#define GAME_HPP

#include <ncurses.h>
#include "map.hpp"
#include "frame.hpp"
#include "entity.hpp"
#include "screen.hpp"

/**
 * @todo write docs
 */
class Game
{

public:

    Game();
    ~Game();

    void init(const char* title);

    void handleEvents();
    void update();
    void render();
    void clean();

    bool running() { return isRunning; }

private:
    Screen * scr;
    WINDOW * screen;
    bool isRunning;
    Frame * game_window;
    Frame * map;
    Frame * viewport;
    Frame * message_box;
    Frame * popup_box;
    Frame * sidebar;
    bool colorSupport;

    int height;
    int width;
    Map  * gamelevel;
    Entity * main_char;

};

#endif // GAME_H
