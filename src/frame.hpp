#ifndef FRAME_HPP
#define FRAME_HPP

//#include <curses.h>
#include <ncurses.h>
#include "entity.hpp"

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
  void add(Entity * e);
  void add(Entity * e, int row_0, int col_0);
  void center(Entity * e);
  void refresh();

  void fill_window();
  void move(int r, int c);
  void erase(Entity * e);

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
