#ifndef SCREEN_HPP
#define SCREEN_HPP
#include <ncurses.h>

class Screen
{
public:
    Screen();
    ~Screen();
    void add(const char *message);
    int height();
    int width();

private:
    int _height;
    int _width;
};



#endif // SCREEN_HPP
