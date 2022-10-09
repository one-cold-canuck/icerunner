#ifndef FRAME_H
#define FRAME_H

#include <ncurses.h>
#include "entity.hpp"
#include <vector>
#include "tile.hpp"
#include "game_map.hpp"
#include <string>

// A Frame defines the game map, and a viewport
class Frame
{

	// Frame dimensions
	int _height, _width;
	// Frame position
	int _row, _col;
	// Boolean - FALSE for a window and TRUE for a subwindow (viewport)
	bool _has_super;

	std::string _id;
	// Pointer to a curses WINDOW
	WINDOW *_w;
	// Pointer to a curses WINDOW, this will be NULL for a window and will point to the parent
	// for a subwindow
	WINDOW *_super;

	GameMap *_game_map;

public:
	// Get this frame's WINDOW
	WINDOW *win();

	// Get this frame's parent WINDOW
	WINDOW *super();

	// Default initializer
	Frame();

	// Initialize a main window (no parent)
	Frame(int nr_rows, int nr_cols, int row_0, int col_0, std::string id);

	// Initialze a subwindow (viewport) with a parent window
	Frame(Frame * sw, int nr_rows, int nr_cols, int row_0, int col_0, std::string);

	~Frame();

	// Flag for viewports.  Returns FALSE for a top-level window, TRUE otherwise
	bool has_super();
	void has_super(bool s);	
	// Return the window height
	int height();
	void height(int h);

	// Return the window width
	int width();
	void width(int w);

	// Return the frame position row
	int row();
	void row(int r);
	
	// Return the frame position column
	int col();
	void col(int c);

	std::string id();
	void id(std::string id);
	
	//draw a frame around a window
	void frame_window();

	// Fill the window with a test pattern
	void fill_window(int w, int h);

	void draw_map(std::vector< std::vector< Tile *>>);

	GameMap * game_map();

	// Add a character to the window
	void add(Entity &x);

	// Add a character to a specific position in the window
	void add(Entity &x, int row_0, int col_0);

	void add(Tile * t, int row_0, int col_0);

	// Erase a character in the window
	void erase(Entity &x);

	// Center the viewport around a character
	void center(Entity &x);

	// Refresh the window
	void refresh();
	
	void redraw();

	// Move the window to the specified row and column
	void move(int r, int c);

	void append_message(const char* message);

	void clear_window();

	void move_entity(GameMap &game_map, Entity &entity, int col, int row);

	void init_frame(WINDOW * sw);
};

#endif
