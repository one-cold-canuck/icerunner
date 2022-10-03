#ifndef SCREEN_H
#define SCREEN_H

#include <ncurses.h>
#include "frame.hpp"

class Screen {

	int _height, _width;
	WINDOW * _stdscr;
	
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

	// Initialize color pairs
	void initColor();

	void colorTest();

	WINDOW* getStdScr();

};

#endif
