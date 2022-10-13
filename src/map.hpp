#ifndef MAP_HPP
#define MAP_HPP


#include "tile.hpp"
#include <vector>


class Map {

public:
    Map();
    Map(int h, int w, int l);
    ~Map();

    void init_map();  // Flood the map with Tiles,
    void create_room(int mapposx, int mapposy, int width, int height);  //Basic, to be replaced with a room mechanic, for special rooms etc
    void generate_map();  // To be implemented

    void height(int h);
    void width(int w);
    void level(int l);

    int height();
    int width();
    int level();
    bool is_dirty();
    void is_dirty(bool dirty);
    std::vector<Tile *> init_tiles();
    std::vector< std::vector < Tile*>> map_grid();
    std::vector<Tile *> tile_list();
private:
    int _height; // map height
    int _width;  // map width
    int _level;  // unimplemented, for future use
    bool _is_dirty; // Does the map need to be redrawn?
    std::vector<Tile *> _tile_list;
    std::vector<std::vector< Tile *>> _map_grid;

};
#endif
