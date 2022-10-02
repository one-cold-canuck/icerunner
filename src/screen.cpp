#include "screen.h"
#include <string>

Screen::Screen() {
	stdscr = initscr();
	start_color();
	
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

void Screen::test_color(){
	printw("Colours supported: %d\n", COLORS);

	for (int i = 1; i < COLORS; ++i){
		// init_pair(i-1, i, -1);
		attron(COLOR_PAIR(i));
		printw("COLOR PAIR: %d\t", COLOR_PAIR(i));
	}
}
