#include "frame.hpp"


// #include <ncurses.h>
Frame::Frame(){
	
}

Frame::Frame(int nr_rows, int nr_cols, int row_0, int col_0, std::string id)
{
	_has_super = FALSE;
	_super = NULL;
	_w = newwin(nr_rows, nr_cols, row_0, col_0);

	_height = nr_rows;
	_width = nr_cols;

	_row = row_0;
	_col = col_0;
	_id = id;
}

Frame::Frame(Frame * sw, int nr_rows, int nr_cols, int row_0, int col_0, std::string id)
{
	_has_super = TRUE;
	_super = sw->win();
	_w = derwin(_super, nr_rows, nr_cols, row_0, col_0);

	_height = nr_rows;
	_width = nr_cols;

	_row = row_0;
	_col = col_0;
	_id = id;
}

Frame::~Frame()
{
	delwin(_w);
}

void Frame::init_frame(WINDOW * sw){
	_has_super = TRUE;
	_super = sw;
	_w = derwin(sw, height(), width(), row(), col());
}

bool Frame::has_super()
{
	return _has_super;
}

void Frame::has_super(bool s) {
	_has_super = s;
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

void Frame::height(int h) {
	_height = h;
}

int Frame::width()
{
	return _width;
}

int Frame::row()
{
	return _row;
}

void Frame::row(int r) {
	_row = r;
}

int Frame::col()
{
	return _col;
}

void Frame::col(int c) {
	_col = c;
}

std::string Frame::id(){
	return _id;
}

void Frame::id(std::string id) {
	_id = id;
}
// Add a character to the window
// Change this to symbol - Frame and Screen should not care about entities
// TODO:  Add a base class who's objects can be placed
void Frame::add(Entity &x)
{
	wattron(win(), COLOR_PAIR(x.color()));
	mvwaddch(_w, x.row(), x.col(), x.symbol());
}

// Add a character to the window at a specific position
void Frame::add(Entity &x, int row_0, int col_0) {
	if ((row_0 >= 0 && row_0 < _height) && (col_0 >= 0 && col_0 < _width)) {
		erase(x);

		//wattron(_w, COLOR_PAIR(x.color()));
		mvwaddch(_w, row_0, col_0, x.symbol());
		x.pos(row_0, col_0);
	}
}

void Frame::add(Tile * t, int row_0, int col_0) {
	if ((row_0 >= 0 && row_0 < _height) && (col_0 >= 0 && col_0 < _width)) {
		//wattron(_w, COLOR_PAIR(x.color()));
		mvwaddch(_w, t->col(), t->row(), t->character());
	}
}

void Frame::draw_map(std::vector< std::vector< Tile *>> game_board) {
	
	for(int r = 0; r < _height - 1; r++ ) {
		for (int c = 0; c < _width - 1; c++){
			Tile * t = game_board.at(r).at(c);
			mvwaddch(_w, t->col(), t->row(), t->character());
		}
	}

}

// Define the "erase" character, use an empty character for cleaning a cell or
// a visible character for showing the trace of a game character
void Frame::erase(Entity &x)
{
	mvwaddch(_w, x.row(), x.col(), ' ');
}

void Frame::move_entity(GameMap &game_map, Entity &entity, int col, int row) {
	int curr_col = entity.col();
	int curr_row = entity.row();
	if (game_map.game_board()[col][row]->is_blocking()) {
			return;
	} 
	add(entity, col, row);
	add(game_map.game_board()[curr_col][curr_row], curr_col, curr_row);
	
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
	if(_has_super){
		touchwin(_super);
	}
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
		refresh();
	}
}

void Frame::frame_window() {

	for (int y = 0; y < _height; ++y) {
		mvwaddch(_w, y, 0, '|');
		mvwaddch(_w, y, _width - 1, '|');
	}

	for (int x = 0; x < _width; ++x) {
		mvwaddch(_w, 0, x, '-');
		mvwaddch(_w, _height - 1, x, '-');
	}
}
// Fill a window with numbers - the window is split in four equal regions, 
// each region is filled with a single number, so 4 regions and 4 numbers.
//
//							1|2
//						   -----
//							3|4
// This is for debugging purposes
void Frame::fill_window(int w, int h) {
	int max_x = w / 2;
	int max_y = h / 2;

	//Fill the first region
	for (int y = 0; y < max_y; ++y) {
		for (int x = 0; x < max_x; ++x) {
			mvwaddch(_w, y, x, '1');
		}
	}

	//Fill the second region
	for (int y = 0; y < max_y; ++y) {
		for (int x = max_x; x < w; ++x) {
			mvwaddch(_w, y, x, '2');
		}
	}

	//Fill the third region
	for (int y = max_y; y < h; ++y) {
		for (int x = 0; x < max_x; ++x) {
			mvwaddch(_w, y, x, '3');
		}
	}

	//Fill the last region
	for (int y = max_y; y < h; ++y) {
		for (int x = max_x; x < w; ++x) {
			mvwaddch(_w, y, x, '4');
		}
	}

	for (int y = 0; y < h; ++y) {
		mvwaddch(_w, y, 0, '|');
		mvwaddch(_w, y, w - 1, '|');
	}

	for (int x = 0; x < w; ++x) {
		mvwaddch(_w, 0, x, '-');
		mvwaddch(_w, h - 1, x, '-');
	}
}

void Frame::clear_window(){
	if(_has_super){
		touchwin(_super);
	}
	werase(_w);
}

void Frame::append_message(const char* message){
	mvaddstr(_row + 1, _col + 1, message);
}
