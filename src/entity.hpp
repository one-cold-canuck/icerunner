#ifndef ENTITY_HPP
#define ENTITY_HPP
#include <vector>
#include "tile.hpp"

class Entity {

public:
    Entity();
    Entity(char symbol, int row_0, int col_0);
    void pos(int row_0, int col_0);  // Change the character's position

    virtual bool move(std::vector< std::vector< Tile * >> t, int row, int col) = 0;
    virtual int prev_row() = 0;
    virtual int prev_col() = 0;
    char symbol();
    int row();
    int col();

protected:
  int _row;     // Current y position
  int _col;     // Current x position
  char _symbol; // ASCII representation of the Entity
};

#endif // ENTITY_HPP
