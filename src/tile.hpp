#ifndef TILE_H
#define TILE_H
enum class TileType{
    empty,
    wall,
    floor,
    door,
    hall
};

class Tile {

public:
    Tile();
    ~Tile();
    Tile(int row, int col, TileType t, bool _is_blocking, bool _is_trapped, char c);

    int row(); // Return the tile's y position
    int col(); // Return the tile's x position
    TileType type(); // Return the tile's type
    char character();  // Returns the ASCII character representation of the tile
    bool is_trapped();
    bool is_blocking();

    void setTileType(TileType t);
    void setTrapped(bool t);
    void setBlocking(bool b);
    void setCharacter(char c);

private:
    int _row;
    int _col;
    TileType _tile_type;
    bool _is_trapped;
    bool _is_blocking;
    char _character;
};

#endif
