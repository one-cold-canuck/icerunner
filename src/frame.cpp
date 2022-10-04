#include "frame.hpp"
#include "entity.hpp"

// #include <ncurses.h>
Frame::Frame(){

}

Frame::Frame(int nr_rows, int nr_cols, int row_0, int col_0)
{
	_has_super = FALSE;
	_super = NULL;
	_w = newwin(nr_rows, nr_cols, row_0, col_0);

	_height = nr_rows;
	_width = nr_cols;

	_row = row_0;
	_col = col_0;
}

Frame::Frame(Frame &sw, int nr_rows, int nr_cols, int row_0, int col_0)
{
	_has_super = TRUE;
	_super = sw.win();
	_w = derwin(sw.win(), nr_rows, nr_cols, row_0, col_0);

	_height = nr_rows;
	_width = nr_cols;

	_row = row_0;
	_col = col_0;
}

Frame::~Frame()
{
	delwin(_w);
}

bool Frame::has_super()
{
	return _has_super;
}

WINDOW* Frame::win()
{
	return _w;
}

WINDOW* Frame::super()
{
	return _super;
}

int Frame::height()
{
	return _height;
}

int Frame::width()
{
	return _width;
}

int Frame::row()
{
	return _row;
}

int Frame::col()
{
	return _col;
}


// Add a character to the window
// Change this to symbol - Frame and Screen should not care about entities
void Frame::add(Entity &x)
{
	wattron(win(), COLOR_PAIR(x.color()));
	mvwaddch(_w, x.row(), x.col(), x.symbol());
}

// Add a character to the window at a specific position
void Frame::add(Entity &x, int row_0, int col_0) {
	if ((row_0 >= 0 && row_0 < _height) && (col_0 >= 0 && col_0 < _width)) {
		erase(x);

		wattron(_w, COLOR_PAIR(x.color()));
		mvwaddch(_w, row_0, col_0, x.symbol());
		x.pos(row_0, col_0);
	}
}

// Define the "erase" character, use an empty character for cleaning a cell or
// a visible character for showing the trace of a game character
void Frame::erase(Entity &x)
{
	mvwaddch(_w, x.row(), x.col(), ' ');
}

// Center the viewport around a character
void Frame::center(Entity &x)
{
	if (_has_super) {
		int rr = _row, cc = _col, hh, ww;
		int _r = x.row() - _height / 2;
		int _c = x.col() - _width / 2;

		getmaxyx(_super, hh, ww);

		if (_c + _width >= ww) {
				int delta = ww - (_c + _width);
				cc = _c + delta;
		}
		else {
			cc = _c;
		}

		if (_r + _height >= hh) {
			int delta = hh - (_r + _height);
			rr = _r + delta;
		}
		else {
			rr = _r;
		}

		if (_r < 0) {
			rr = 0;
		}

		if (_c < 0) {
			cc = 0;
		}
			
		move(rr, cc);
	}
}

void Frame::redraw() {
	redrawwin(_w);
}
// Refresh the window
void Frame::refresh() {
	if (_has_super) {
		touchwin(_super);
	}
	wrefresh(_w);
}

void Frame::move(int r, int c) {
	if (_has_super) {
		mvderwin(_w, r, c);
		_row = r;
		_col = c;
		touchwin(_super);
		refresh();
	}
}

void Frame::frame_window() {

	for (int x = _col; x < _width; x++) {
		if (x == _col) {
			mvwaddch(_w, _row, _col, '*');
			for(int y = _col + 1; y < _width; y++){
				mvwaddch(_w, _row, y, '-' );
			}
			mvwaddch(_w, _row, _width, '*');
		} else {
			for(int z = _row + 1; z < _height; z++){
				mvwaddch(_w, z, _col, '|');
				mvwaddch(_w, z, _width, '|');	
			}
		}
	}
}
// Fill a window with numbers - the window is split in four equal regions, 
// each region is filled with a single number, so 4 regions and 4 numbers.
//
//							1|2
//						   -----
//							3|4
// This is for debugging purposes
void Frame::fill_window() {
	int max_x = _width / 2;
	int max_y = _height / 2;

	//Fill the first region
	for (int y = 0; y < max_y; ++y) {
		for (int x = 0; x < max_x; ++x) {
			mvwaddch(_w, y, x, '1');
		}
	}

	//Fill the second region
	for (int y = 0; y < max_y; ++y) {
		for (int x = max_x; x < _width; ++x) {
			mvwaddch(_w, y, x, '2');
		}
	}

	//Fill the third region
	for (int y = max_y; y < _height; ++y) {
		for (int x = 0; x < max_x; ++x) {
			mvwaddch(_w, y, x, '3');
		}
	}

	//Fill the last region
	for (int y = max_y; y < _height; ++y) {
		for (int x = max_x; x < _width; ++x) {
			mvwaddch(_w, y, x, '4');
		}
	}

	for (int y = 0; y < _height; ++y) {
		mvwaddch(_w, y, 0, '|');
		mvwaddch(_w, y, _width - 1, '|');
	}

	for (int x = 0; x < _width; ++x) {
		mvwaddch(_w, 0, x, '-');
		mvwaddch(_w, _height - 1, x, '-');
	}
}

void Frame::clear_window(){
	werase(_w);

}

void Frame::append_message(const char* message){
	mvaddstr(_row + 1, _col + 1, message);
}
