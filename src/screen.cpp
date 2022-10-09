#include "screen.hpp"
#include "frame.hpp"
#include <string>

Screen::Screen()
{
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

Screen::~Screen()
{
	endwin();
}

void Screen::add(const char *message)
{
	printw(message);
}

int Screen::height()
{
	return _height;
}

int Screen::width()
{
	return _width;
}

WINDOW *Screen::getStdScr()
{
	return _stdscr;
}

void Screen::initColor()
{

	start_color();

	for (int i = 1; i < COLORS; i++)
	{
		init_pair(i, i - 1, -1);
	}
}

void Screen::init_play_window()
{

	_c_map_window.nr_rows = 2 * height();
	_c_map_window.nr_cols = 2 * width();
	_c_map_window.row_0 = 0;
	_c_map_window.col_0 = 0;

	_c_viewport.nr_rows = height();
	_c_viewport.nr_cols = width();
	_c_viewport.row_0 = 0;
	_c_viewport.col_0 = 0;

	_c_stat_window.nr_rows = _c_viewport.nr_rows;
	_c_stat_window.nr_cols = 20;
	_c_stat_window.row_0 = 0;
	_c_stat_window.col_0 = _c_viewport.nr_cols - 20;

	_c_message_block.nr_rows = 6;
	_c_message_block.nr_cols = _c_viewport.nr_cols - _c_stat_window.nr_cols;
	_c_message_block.row_0 = _c_viewport.nr_rows - 6;
	_c_message_block.col_0 = 0;

	_f_game_map = new Frame(_c_map_window.nr_rows, _c_map_window.nr_cols, _c_map_window.row_0, _c_map_window.col_0, "Map Window");
	_f_viewport = new Frame(_f_game_map, _c_viewport.nr_rows, _c_viewport.nr_cols, _c_viewport.row_0, _c_viewport.col_0, "Viewport");
	_f_message_block = new Frame(_c_message_block.nr_rows, _c_message_block.nr_cols, _c_message_block.row_0, _c_message_block.col_0, "Message Block");
	_f_stat_window = new Frame(_c_stat_window.nr_rows, _c_stat_window.nr_cols, _c_stat_window.row_0, _c_stat_window.col_0, "Stat Window");

	_f_message_block->frame_window();
	_f_stat_window->frame_window();
	_f_viewport->frame_window();
}

void Screen::draw_map(std::vector<std::vector<Tile *>> game_board, Frame * target_frame)
{
	// For now, call to frame.  Might be right, might not be
	target_frame = _f_game_map;
	target_frame->fill_window(_c_map_window.nr_cols, _c_map_window.nr_rows);
	// target_frame->draw_map(game_board);
  	
}

Frame * Screen::game_map()
{
	return _f_game_map;
}

Frame * Screen::viewport()
{
	return _f_viewport;
}

Frame * Screen::message_box()
{
	return _f_message_block;
}

Frame * Screen::stat_window()
{
	return _f_stat_window;
}
