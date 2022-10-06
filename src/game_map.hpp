#ifndef GAME_MAP_H
#define GAME_MAP_H

#include "tile.hpp"
#include <vector>


class GameMap {
    
    int _height; // map height
    int _width;  // map width
    int _level;  // unimplemented, for future use

    std::vector<Tile> _tile_list;
    std::vector<std::vector< Tile *>> _game_board;

public:
    GameMap();
    GameMap(int h, int w, int l);
    ~GameMap();

    // Flood the map with tiles - each tile has:
    //    passable: false
    //    transparent: false
    //    <items>: 
    //    x,y - position in vector.
    //
    //    Store pointer to tile in Vector
    
 
    void init_map();  // Flood the map with Tiles, 
    void create_room(int x, int y);  //Basic, to be replaced with a room mechanic, for special rooms etc
    void generate_map();  // To be implemented
    void setHeight(int h);
    void setWidth(int w);
    void setLevel(int l);
    std::vector<Tile> init_tiles();
    int height();
    int width();
    int level();
    std::vector< std::vector < Tile*>> game_board();  

};
#endif