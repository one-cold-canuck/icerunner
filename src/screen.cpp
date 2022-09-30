#include "screen.h"

Screen::Screen() {
	initscr();
	clear();
	noecho();
	cbreak();
	keypad(stdscr, TRUE);
	curs_set(0);
	// Acquire the screen dimensions
	getmaxyx(stdscr, _height, _width);
}

Screen::~Screen() {
	endwin();
}

void Screen::add(const char* message) {
	printw(message);
}

int Screen::height() {
	return _height;
}

int Screen::width() {
	return _width;
}


