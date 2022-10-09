// ICERunner.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include "entity.hpp"
#include "frame.hpp"
#include "screen.hpp"
#include <string>


void game_loop(GameMap &game_map, Frame * game_board, Frame * viewport, Frame * message_block, Frame * stat_window, Entity &main_char, int ch) {

    if (ch == 'q' || ch == 'Q') return;

   // main_char.setColor(COLOR_PAIR(25));

 
    game_board->add(main_char);
    viewport->center(main_char);
    viewport->refresh();

    message_block->frame_window();
    message_block->refresh();

    stat_window->frame_window();
    stat_window->refresh();

    while (1) {
        ch = getch();

        if (ch == KEY_LEFT) {
            
            game_board->move_entity(game_map, main_char, main_char.row(), main_char.col() - 1);  // Move the main character on the map
            viewport->center(main_char);
            viewport->refresh();

            message_block->append_message(("At coordinates " + std::to_string(main_char.row()) + ", " + std::to_string(main_char.col())).c_str());
            message_block->refresh();
            stat_window->refresh();
            
        }
        else if (ch == KEY_RIGHT) {
            
            game_board->move_entity(game_map, main_char, main_char.row(), main_char.col() + 1);
            viewport->center(main_char);
            viewport->refresh();

            message_block->append_message(("At coordinates " + std::to_string(main_char.row()) + ", "+ std::to_string(main_char.col())).c_str());
            message_block->redraw();
            message_block->refresh();
            stat_window->refresh();
            
        }
        else if (ch == KEY_UP) {
            game_board->move_entity(game_map, main_char, main_char.row() - 1, main_char.col());
            viewport->center(main_char);
            viewport->refresh();

            message_block->append_message(("At coordinates " + std::to_string(main_char.row()) + ", "+ std::to_string(main_char.col())).c_str());
            message_block->redraw();
            message_block->refresh();

            stat_window->refresh();

        }
        else if (ch == KEY_DOWN) {
            game_board->move_entity(game_map, main_char, main_char.row()+1, main_char.col());
            viewport->center(main_char);
            viewport->refresh();

            message_block->append_message(("At coordinates " + std::to_string(main_char.row()) + ", "+ std::to_string(main_char.col())).c_str());
            message_block->redraw();
            message_block->refresh();
            stat_window->refresh();
            
        }
        else if (ch == 'q' || ch == 'Q') {
            break;
        }
        
        message_block->append_message(("At coordinates " + std::to_string(main_char.row()) + ", " + std::to_string(main_char.col()) +": color set: " + std::to_string(main_char.color())).c_str());
        message_block->redraw();
        message_block->refresh();
        stat_window->redraw();
        stat_window->refresh();
    }
}

int main()
{

    Screen * screen = new Screen();

    screen->add("Welcome to ICERunner.\nPress any key to start.\nIf you want to quit press \"q\" or \"Q\"");
    
    // Wait until a key is pressed
    int ch = getch();

    screen->init_play_window();

    GameMap game_map(screen->game_map_config().nr_rows, screen->game_map_config().nr_cols, 1);

    game_map.init_tiles();
    game_map.init_map();

    Frame * target_frame = screen->game_map();
    screen->draw_map(game_map.game_board(), target_frame);
  
    Entity main_char('@', screen->game_map()->width()/2, screen->game_map()->height()/2);

    game_loop(game_map, screen->game_map(), screen->viewport(), screen->message_box(), screen->stat_window(), main_char, ch);

    screen->~Screen();

    return 0;
    
}


