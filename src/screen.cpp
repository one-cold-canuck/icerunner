#include "screen.hpp"
#include "frame.hpp"
#include <string>

Screen::Screen() {
	_stdscr = initscr();

	clear();
	noecho();
	cbreak();
	nonl();
	intrflush(_stdscr, FALSE);
	keypad(_stdscr, TRUE);
	curs_set(0);
	initColor();
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

WINDOW* Screen::getStdScr(){
	return _stdscr;
}

void Screen::initColor() {

	start_color();
	
	for(int i = 1; i < COLORS; i++){
		init_pair(i, i-1, -1);
	}
}