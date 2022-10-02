
#include <ncurses.h>
#include "entity.h"

#ifndef FRAME_H
#define FRAME_H

// A Frame defines the game map, and a viewport
class Frame
{
	// Frame dimensions
	int _height, _width;
	// Frame position
	int _row, _col;
	// Boolean - FALSE for a window and TRUE for a subwindow (viewport)
	bool _has_super;

	// Pointer to a curses WINDOW
	WINDOW *_w;
	// Pointer to a curses WINDOW, this will be NULL for a window and will point to the parent
	// for a subwindow
	WINDOW *_super;

public:
	// Get this frame's WINDOW
	WINDOW *win();

	// Get this frame's parent WINDOW
	WINDOW *super();

	// Initialize a main window (no parent)
	Frame(int nr_rows, int nr_cols, int row_0, int col_0);

	// Initialze a subwindow (viewport) with a parent window
	Frame(Frame &sw, int nr_rows, int nr_cols, int row_0, int col_0);

	~Frame();

	// Flag for viewports.  Returns FALSE for a top-level window, TRUE otherwise
	bool has_super();
	
	// Return the window height
	int height();

	// Return the window width
	int width();

	// Return the frame position row
	int row();
	
	// Return the frame position column
	int col();

	// Fill the window with a test pattern
	void fill_window();

	// Add a character to the window
	void add(Entity &x);

	// Add a character to a specific position in the window
	void add(Entity &x, int row_0, int col_0);

	// Erase a character in the window
	void erase(Entity &x);

	// Center the viewport around a character
	void center(Entity &x);

	// Refresh the window
	void refresh();

	// Move the window to the specified row and column
	void move(int r, int c);

};

#endif
