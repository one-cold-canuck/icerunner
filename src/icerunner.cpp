// ICERunner.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include "entity.hpp"
#include "frame.hpp"
#include "screen.hpp"
#include <string>

void game_loop(Frame &game_map, Frame &viewport, Frame &message_block, Frame &stat_window, Entity &main_char, int ch) {

    if (ch == 'q' || ch == 'Q') return;
    main_char.setColor(COLOR_PAIR(25));

    game_map.add(main_char);

    viewport.center(main_char);
    viewport.refresh();

    message_block.frame_window();
    message_block.refresh();

    stat_window.frame_window();
    stat_window.refresh();

    while (1) {
        ch = getch();

        if (ch == KEY_LEFT) {
            game_map.erase(main_char);
            game_map.add(main_char, main_char.row(), main_char.col() - 1);

            viewport.center(main_char);
            viewport.refresh();

            message_block.append_message(("At coordinates " + std::to_string(main_char.row()) + ", " + std::to_string(main_char.col())).c_str());
            message_block.refresh();
            stat_window.refresh();
            
        }
        else if (ch == KEY_RIGHT) {
            game_map.erase(main_char);
            game_map.add(main_char, main_char.row(), main_char.col() + 1);

            viewport.center(main_char);
            viewport.refresh();

            message_block.append_message(("At coordinates " + std::to_string(main_char.row()) + ", "+ std::to_string(main_char.col())).c_str());
            message_block.redraw();
            message_block.refresh();
            stat_window.refresh();
            
        }
        else if (ch == KEY_UP) {
            game_map.erase(main_char);
            game_map.add(main_char, main_char.row() - 1, main_char.col());

            viewport.center(main_char);
            viewport.refresh();

            message_block.append_message(("At coordinates " + std::to_string(main_char.row()) + ", "+ std::to_string(main_char.col())).c_str());
            message_block.redraw();
            message_block.refresh();

            stat_window.refresh();

        }
        else if (ch == KEY_DOWN) {
            game_map.erase(main_char);
            game_map.add(main_char, main_char.row() + 1, main_char.col());

            viewport.center(main_char);
            viewport.refresh();

            message_block.append_message(("At coordinates " + std::to_string(main_char.row()) + ", "+ std::to_string(main_char.col())).c_str());
            message_block.redraw();
            message_block.refresh();
            stat_window.refresh();
            
        }
        else if (ch == 'q' || ch == 'Q') {
            break;
        }
        
        message_block.append_message(("At coordinates " + std::to_string(main_char.row()) + ", " + std::to_string(main_char.col()) +": color set: " + std::to_string(main_char.color())).c_str());
        message_block.redraw();
        message_block.refresh();
        stat_window.redraw();
        stat_window.refresh();
    }
}

int main()
{

    struct WINDOW_CONFIGURATION {
		int nr_rows;
		int nr_cols;
		int row_0;
		int col_0;
		bool has_parent;
	};

    WINDOW_CONFIGURATION map_window;
	WINDOW_CONFIGURATION viewport;
	WINDOW_CONFIGURATION message_block;
	WINDOW_CONFIGURATION stat_window;

    

    Screen screen;

    map_window.nr_rows = 2*screen.height();
	map_window.nr_cols = 2*screen.width();
	map_window.row_0 = 0;
	map_window.col_0 = 0;

	viewport.nr_rows = screen.height();
	viewport.nr_cols = screen.width();
	viewport.row_0 = 0;
	viewport.col_0 = 0;

	message_block.nr_rows = 5;
	message_block.nr_cols = viewport.nr_cols;
	message_block.row_0 = viewport.nr_rows - 5;
	message_block.col_0 = 0;

	stat_window.nr_rows = viewport.nr_rows;
	stat_window.nr_cols = 20;
	stat_window.row_0 = 0;
	stat_window.col_0 = viewport.nr_cols - 20;

    screen.add("Welcome to ICERunner.\nPress any key to start.\nIf you want to quit press \"q\" or \"Q\"");
  
    // Wait until a key is pressed
    int ch = getch();
    
    GameMap game_map(map_window.nr_rows, map_window.nr_cols, 1);
    
    Frame mapw(map_window.nr_rows, map_window.nr_cols, map_window.row_0, map_window.col_0);
    Frame vport(mapw, viewport.nr_rows-message_block.nr_rows, viewport.nr_cols-stat_window.nr_cols, viewport.row_0, viewport.col_0);
    Frame mblock(message_block.nr_rows, message_block.nr_cols, message_block.row_0, message_block.col_0);
    Frame statw(stat_window.nr_rows, stat_window.nr_cols, stat_window.row_0, stat_window.col_0);

    game_map.init_tiles();
    game_map.init_map();

    mapw.draw_map(&game_map);
    Entity main_char('@', mapw.height()/2, mapw.width()/2);

    
    mblock.clear_window();
    statw.clear_window();

    // Game loop
    game_loop(mapw, vport, mblock, statw, main_char, ch);

    screen.~Screen();

    return 0;
}


