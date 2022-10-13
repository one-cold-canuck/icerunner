#include "entity.hpp"

Entity::Entity(){}

Entity::Entity(char symbol, int row_0, int col_0) {
    _row = row_0;
    _col = col_0;
    _symbol = symbol;
}

void Entity::pos(int row_0, int col_0) {
    _row = row_0;
    _col = col_0;
}

char Entity::symbol(){
    return _symbol;
}

int Entity::row(){
    return _row;
}

int Entity::col(){
    return _col;
}
