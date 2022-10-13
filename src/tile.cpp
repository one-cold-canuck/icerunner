#include "tile.hpp"

// Default constructor - creates a default tile - blocking, no character, non transparent
Tile::Tile() {
    _tile_type = TileType::empty;
    _is_blocking = true;
    _is_trapped = false;
    _character = ' ';
}

Tile::Tile(int row, int col, TileType t, bool is_blocking, bool is_trapped, char c) {

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

Tile::TileType Tile::type() {
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

void Tile::setTileType(TileType t)
{
    _tile_type = t;
}

void Tile::setTrapped(bool t)
{
    _is_trapped = t;
}

void Tile::setBlocking(bool b)
{
    _is_blocking = b;
}

void Tile::setCharacter(char c)
{
    _character = c;
}
