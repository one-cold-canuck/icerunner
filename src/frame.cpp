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

void Frame::erase(int row, int col, char tc) {
    mvwaddch(_window, row, col, tc);
}

bool Frame::add(char c, int dest_row, int dest_col) {
    bool is_successful = false;
    if((dest_row >= 0 && dest_row < _height) && (dest_col >= 0 && dest_col < _width)) {
            mvwaddch(_window, dest_row, dest_col, c);
            is_successful = true;
        }
    return is_successful;
}

bool Frame::add(char c, char tc, int row, int col, int dest_row, int dest_col) {
    bool is_successful = false;
    if((dest_row >= 0 && dest_row < _height) && (dest_col >= 0 && dest_col < _width)) {
            erase(row, col, tc);
            mvwaddch(_window, dest_row, dest_col, c);
            is_successful = true;
        }
    return is_successful;
}


void Frame::center(int row, int col){
    if (_has_super){
        int rr = _y_pos, cc = _x_pos, hh, ww;
        int _r = row - _height/2;
        int _c = col - _width/2;

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

void Frame::draw(std::vector< std::vector< char >> c) {
    for (int i = 0; i < c.size(); i++) {
        std::vector<char> v = c.at(i);
        for (int j = 0; j < v.size(); j++) {
            mvwaddch(_window, c.at(i).at(j), i, j);
        }
        //refresh();
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











