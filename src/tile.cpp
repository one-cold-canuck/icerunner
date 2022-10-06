#include "tile.hpp"

// Default constructor - creates a default tile - blocking, no character, non transparent
Tile::Tile() {
    _tile_type = TILE_TYPE_EMPTY;
    _is_blocking = true;
    _is_trapped = false;
    _character = ' ';
} 

Tile::Tile(int row, int col, tile_type t, bool is_blocking, bool is_trapped, char c) {

    _row = row; 
    _col = col;
    _tile_type = t;
    _is_blocking = is_blocking;
    _is_trapped = is_trapped;
    _character = c;
}

Tile::~Tile() {

}

int Tile::row() {
    return _row;
}

int Tile::col(){
    return _col;
}

tile_type Tile::type() {
    return _tile_type;
}

char Tile::character() {
    return _character;
}

bool Tile::is_trapped() {
    return _is_trapped;
}

bool Tile::is_blocking() {
    return _is_blocking;
}
