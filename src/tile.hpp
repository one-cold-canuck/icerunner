#ifndef TILE_H
#define TILE_H

enum tile_type : short {
    TILE_TYPE_EMPTY  = 1,
    TILE_TYPE_WALL   = 2,    
    TILE_TYPE_FLOOR = 4,
    TILE_TYPE_DOOR   = 8,
    TILE_TYPE_HALL   = 16
};

class Tile {
    int _row;
    int _col;
    tile_type _tile_type;
    bool _is_trapped;
    bool _is_blocking;
    char _character;

public:
    Tile();
    ~Tile();
    Tile(int row, int col, tile_type t, bool _is_blocking, bool _is_trapped, char c); 

    int row(); // Return the tile's y position
    int col(); // Return the tile's x position
    tile_type type(); // Return the tile's type
    char character();  // Returns the ASCII character representation of the tile
    bool is_trapped(); 
    bool is_blocking();
};

#endif