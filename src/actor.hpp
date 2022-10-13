#ifndef ACTOR_HPP
#define ACTOR_HPP

#include "entity.hpp"
#include "tile.hpp"
#include <vector>

class Actor : public Entity
{
public:
    Actor();
    Actor(char symbol, int row_0, int col_0);
    bool move( std::vector < std::vector< Tile * >> t, int row_0, int col_0) override;
    int prev_row();
    int prev_col();

private:
    int _prev_row;
    int _prev_col;
};



#endif // ACTOR_HPP
