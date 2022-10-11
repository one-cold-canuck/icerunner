#ifndef MAP_HPP
#define MAP_HPP


#include "tile.hpp"
#include <vector>


class Map {

public:
    Map();
    Map(int h, int w, int l);
    ~Map();

    // Flood the map with tiles - each tile has:
    //    passable: false
    //    transparent: false
    //    <items>:
    //    x,y - position in vector.
    //
    //    Store pointer to tile in Vector


    void init_map();  // Flood the map with Tiles,
    void create_room(int mapposx, int mapposy, int width, int height);  //Basic, to be replaced with a room mechanic, for special rooms etc
    void generate_map();  // To be implemented

    void height(int h);
    void width(int w);
    void level(int l);

    int height();
    int width();
    int level();
    std::vector< std::vector < Tile*>> map_grid();

private:
    int _height; // map height
    int _width;  // map width
    int _level;  // unimplemented, for future use

    std::vector<Tile *> _tile_list;
    std::vector<std::vector< Tile *>> _map_grid;
    std::vector<Tile *> init_tiles();
};
#endif
