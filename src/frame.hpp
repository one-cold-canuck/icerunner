#ifndef FRAME_HPP
#define FRAME_HPP

//#include <curses.h>
#include <ncurses.h>
#include <vector>
//#include "entity.hpp"

enum class FrameType { stdscr, mapGrid, viewport, messageBox, popupBox, sideBar };

class Frame {
public:

  Frame(int rows, int columns, int row_0, int col_0, FrameType frame_type);
  Frame(Frame *super, int rows, int columns, int row_0, int col_0, FrameType frame_type);
  ~Frame();

  WINDOW *window();
  WINDOW *super();
  int height();
  int width();
  int xPos();
  int yPos();

  bool add(char c, char tc, int row, int col, int dest_row, int dest_col);
  bool add(char c, int dest_row, int dest_col);
  void move(int r, int c);
  void erase(int row, int col, char tc);
  void center (int row, int col);

  void draw(std::vector< std::vector< char >> c);

  void refresh();
  void fill_window();

private:
  WINDOW *_window; //TODO rename members with leading _
  WINDOW *_super;
  bool _has_super;
  int _height;
  int _width;
  int _y_pos;
  int _x_pos;
  FrameType _frame_type;
};

#endif // FRAME_HPP
