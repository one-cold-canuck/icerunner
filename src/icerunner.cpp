// ICERunner.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "screen.h"
#include "character.h"
#include "frame.h"

void game_loop(Frame &game_map, Frame &viewport, Character &main_char, int ch) {

    if (ch == 'q' || ch == 'Q') return;

    game_map.add(main_char);
    viewport.center(main_char);
    viewport.refresh();

    while (1) {
        ch = getch();

        if (ch == KEY_LEFT) {
            game_map.erase(main_char);
            game_map.add(main_char, main_char.row(), main_char.col() - 1);
            viewport.center(main_char);
            viewport.refresh();
        }
        else if (ch == KEY_RIGHT) {
            game_map.erase(main_char);
            game_map.add(main_char, main_char.row(), main_char.col() + 1);
            viewport.center(main_char);
            viewport.refresh();
        }
        else if (ch == KEY_UP) {
            game_map.erase(main_char);
            game_map.add(main_char, main_char.row() - 1, main_char.col());
            viewport.center(main_char);
            viewport.refresh();
        }
        else if (ch == KEY_DOWN) {
            game_map.erase(main_char);
            game_map.add(main_char, main_char.row() + 1, main_char.col());
            viewport.center(main_char);
            viewport.refresh();
        }
        else if (ch == 'q' || ch == 'Q') {
            break;
        }
    }
}

int main()
{

    
    Screen screen;
    screen.add("Welcome to ICERunner.\nPress any key to start.\nIf you want to quit press \"q\" or \"Q\"");

    // Wait until a key is pressed
    int ch = getch();

    Frame game_map(2*screen.height(), 2*screen.width(), 0, 0);
    Frame viewport(game_map, screen.height(), screen.width(), 0, 0);

    Character main_char('@', game_map.height()/2, game_map.width()/2);

    game_map.fill_window();

    // Game loop
    game_loop(game_map, viewport, main_char, ch);

    screen.~Screen();

    return 0;
}


