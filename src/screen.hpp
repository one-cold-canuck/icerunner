#include <ncurses.h>

#ifndef SCREEN_H
#define SCREEN_H

class Screen {
	int _height, _width;
public:
	// Initialize the ncurses library
	Screen();

	// Clear ncurses
	~Screen();

	// Print a message on the screen
	void add(const char* message);

	// Get the screen height
	int height();

	// Get the screen width
	int width();

	// Test the terminal's color output
	void test_color();
};

#endif