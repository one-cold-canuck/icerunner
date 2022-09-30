
#include <ncurses.h>
#include "character.h"

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
	WINDOW *win();

	WINDOW *super();
	// Initialize a main window (no parent)
	Frame(int nr_rows, int nr_cols, int row_0, int col_0);
	// Initialze a subwindow (viewport) with a parent window
	Frame(Frame &sw, int nr_rows, int nr_cols, int row_0, int col_0);
	~Frame();

	bool has_super();
	
	int height();
	int width();
	int row();
	int col();

	void fill_window();

	// Add a character to the window
	void add(Character &x);

	void add(Character &x, int row_0, int col_0);

	// Erase a character in the window
	void erase(Character &x);

	// Center the viewport around a character
	void center(Character &x);

	void refresh();

	void move(int r, int c);

};

#endif
