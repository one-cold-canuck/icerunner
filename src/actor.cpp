#include "actor.hpp"
#include "entity.hpp"

Actor::Actor(){}

Actor::Actor(char symbol, int row_0, int col_0)  : Entity(symbol, row_0, col_0) {

}

bool Actor::move( std::vector < std::vector< Tile * >> t, int row, int col) {
    if ( t.at(row).at(col)->is_blocking()) {
        return false;
    } else {

        _prev_row = _row;
        _prev_col = _col;
        pos(row, col);
    }
    return true;
}

int Actor::prev_row(){
    return _prev_row;
}

int Actor::prev_col(){
    return _prev_col;
}
