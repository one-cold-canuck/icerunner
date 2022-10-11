#include "frame.hpp"

Frame::Frame(int rows, int columns, int row_0, int col_0, FrameType frame_type) {

    _has_super = FALSE;
    _super = NULL;
    _window = newwin(rows, columns, row_0, col_0);
    _height = rows;
    _width = columns;
    _y_pos = row_0,
    _x_pos = col_0;
    _frame_type = frame_type;
}

Frame::Frame(Frame * super, int rows, int columns, int row_0, int col_0, FrameType frame_type) {

    _has_super = TRUE;
    _super = super->window();
    _window = derwin(super->window(), rows, columns, row_0, col_0);
    _height = rows;
    _width = columns;
    _y_pos = row_0;
    _x_pos = col_0;
    _frame_type = frame_type;
}

Frame::~Frame(){
    delwin(_window);
}

void Frame::add(Entity * e) {
    mvwaddch(_window, e->row(), e->col(), e->symbol());
}

void Frame::erase(Entity * e) {
    mvwaddch(_window, e->row(), e->col(), ' ');
}

void Frame::add(Entity * e, int row_0, int col_0) {
    if((row_0 >= 0 && row_0 < _height) && (col_0 >= 0 && col_0 < _width)) {
            erase(e);
            mvwaddch(_window, row_0, col_0, e->symbol());
            e->pos(row_0, col_0);
        }
}


void Frame::center(Entity * e){
    if (_has_super){
        int rr = _y_pos, cc = _x_pos, hh, ww;
        int _r = e->row() - _height/2;
        int _c = e->col() - _width/2;

        getmaxyx(_super, hh, ww);

        if(_c + _width >= ww) {
            int delta = ww - (_c + _width);
            cc = _c + delta;
        }
        else {
            cc = _c;
        }

        if(_r + _height >= hh) {
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

void Frame::refresh()
{
    if(_has_super) {
        touchwin(_super);
    }
    wrefresh(_window);
}

void Frame::fill_window() {
    int max_x = _width/2;
    int max_y = _height/2;
    // Fill the first region with 0's
    for(int y = 0; y < max_y; ++y) {
        for(int x = 0; x < max_x; ++x) {
            mvwaddch(_window, y, x, '0');
        }
    }

    // Fill the second region with 1's
    for(int y = 0; y < max_y; ++y) {
        for(int x = max_x; x < _width; ++x) {
            mvwaddch(_window, y, x, '1');
        }
    }

    // Fill the third region with 2's
    for(int y = max_y; y < _height; ++y) {
        for(int x = 0; x < max_x; ++x) {
            mvwaddch(_window, y, x, '2');
        }
    }

    // Fill the fourth region with 3's
    for(int y = max_y; y < _height; ++y) {
        for(int x = max_x; x < _width; ++x) {
            mvwaddch(_window, y, x, '3');
        }
    }

    for(int y = 0; y < _height; ++y) {
        mvwaddch(_window, y, 0, '-');
        mvwaddch(_window, y, _width - 1, '-');
    }

    for(int x = 0; x < _width; ++x) {
        mvwaddch(_window, 0, x, '|');
        mvwaddch(_window, _height - 1, x, '|');
    }
}

void Frame::move(int r, int c) {
    if(_has_super) {
        mvderwin(_window, r, c);
        _y_pos = r;
        _x_pos = c;
        refresh();
    }
}

WINDOW * Frame::window(){
    return _window;
}

int Frame::height() {
    return _height;
}

int Frame::width() {
    return _width;
}

int Frame::xPos() {
    return _x_pos;
}

int Frame::yPos() {
    return _y_pos;
}











