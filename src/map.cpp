#include "map.hpp"


    Map::Map(){

    }

    Map::Map(int h, int w, int l) {
        _height = h;
        _width = w;
        _level = l;

    }

    Map::~Map(){

    }

    std::vector<Tile *> Map::init_tiles(){
        for(int j = 0; j < _height-1; j++) {
            for(int k = 0; k < _width-1; k++) {
                Tile * tile = new Tile(j, k, TileType::empty, false, false, '.'); //TODO object cleanup for tiles - should not outlive mapgrid
                _tile_list.push_back(tile);
            }
        }
        return _tile_list;
    }

    void Map::init_map(){  // Flood the map with Tile pointers
        init_tiles();
        int i = 0;
        for (int r = 0; r < _height - 1; r++) {
            std::vector<Tile *> tile_col;
            for (int c = 0; c < _width -1; c++) {
                tile_col.push_back(_tile_list.at(i));
                i++;
            }
            _map_grid.push_back(tile_col);
        }

    }

    void Map::create_room(int mapposx, int mapposy, int width, int height) {  //Basic, to be replaced with a room mechanic, for special rooms etc

        for (int x = 0; x < width; x++) {
            for (int y = 0; y < height; y++) {
                Tile * t = _map_grid[mapposy+y][mapposx+x];
                t->setCharacter('.');
                t->setTileType(TileType::floor);
                t->setBlocking(false);
                t->setTrapped(false); // ...or is it?
            }
        }
    }

    void Map::generate_map() {  // To be implemented

        _tile_list = init_tiles();
        init_map();
    }

    void Map::height(int h) {
        _height = h;
    }

    void Map::width(int w){
        _width = w;
    }

    void Map::level(int l) {
        _level = l;
    }

    int Map::height() {
        return _height;
    }

    int Map::width() {
        return _width;
    }

    int Map::level() {
        return _level;
    }

    std::vector< std::vector < Tile *>> Map::map_grid() {
        return _map_grid;
    }
