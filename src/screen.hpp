#ifndef SCREEN_H
#define SCREEN_H

#include <ncurses.h>
#include "frame.hpp"

class Screen
{

	int _height, _width;	 // The screen's height and width
	WINDOW * _stdscr;		 // Pointer to the screen created by a call to initscr()
	Frame * _f_game_map;		 // Pointer to the game map draw frame
	Frame * _f_viewport;		 // Pointer to the play area viewport
	Frame * _f_message_block; // Pointer to the message viewport
	Frame * _f_stat_window;	 // Pointer to the status viewport,
	Frame * _f_popup_box;	 // Pointer to a popup box frame

	struct WINDOW_CONFIGURATION
	{
		int nr_rows;
		int nr_cols;
		int row_0;
		int col_0;
		bool has_parent;
	};

	WINDOW_CONFIGURATION _c_map_window;
	WINDOW_CONFIGURATION _c_viewport;
	WINDOW_CONFIGURATION _c_message_block;
	WINDOW_CONFIGURATION _c_stat_window;

public:
	// Initialize the ncurses library
	Screen();

	// Clear ncurses
	~Screen();

	// Print a message on the screen
	void add(const char *message);

	// Get the screen height
	int height();

	// Get the screen width
	int width();

	// Initialize color pairs
	void initColor();

	void colorTest();

	WINDOW *getStdScr();

	void set_game_map(Frame *game_map);
	void set_viewport(Frame *viewport);
	void set_message_box(Frame *message_box);
	void set_stat_window(Frame *stat_window);
	void popup_box(Frame *popup_box);

	void init_play_window();

	Frame *game_map();
	Frame *viewport();
	Frame *message_box();
	Frame *stat_window();
	// Frame* popup_box();

	void draw_map(std::vector<std::vector<Tile *>> game_board, Frame * target_frame);

	WINDOW_CONFIGURATION game_map_config()
	{
		return _c_map_window;
	}
};

#endif
