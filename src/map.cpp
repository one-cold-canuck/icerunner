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
        for(int j = 0; j < _height; j++) {
            for(int k = 0; k < _width; k++) {
                Tile * tile = new Tile(j, k, Tile::TileType::empty, true, false, ' '); //TODO object cleanup for tiles - should not outlive mapgrid
                _tile_list.push_back(tile);
            }
        }
        return _tile_list;
    }

    void Map::init_map(){  // Flood the map with Tile pointers
        _tile_list = init_tiles();
        std::vector<Tile *> tile_col;
        int i = 0;
        for (int r = 0; r < _height; r++) {
            for (int c = 0; c < _width; c++) {
                tile_col.push_back(_tile_list.at(i));
                i++;
            }
            _map_grid.push_back(tile_col);
            tile_col.clear();
        }
        _is_dirty = true;
    }

    void Map::create_room(int mapposx, int mapposy, int width, int height) {  //Basic, to be replaced with a room mechanic, for special rooms etc
        if(mapposx >= 0 && mapposx < _height && mapposy >= 0 && mapposy < _width) {
            for(int x = 0; x <= height; x++){
                for(int y = 0; y <= width; y++) {
                    if (x == 0 || x == height || y == 0 || y == width) {
                        if ((x == 0 && y == 0) || (x == 0 && y == height) || (x == width && y == 0) || (x == width && y == height)){
                            _map_grid.at(x+mapposx).at(y+mapposy)->setCharacter('-');
                        } else if ( x == 0 || x == height) {
                            _map_grid.at(x+mapposx).at(y+mapposy)->setCharacter('-');
                        } else if (y == 0 || y == width) {
                            _map_grid.at(x+mapposx).at(y+mapposy)->setCharacter('|');
                        }
                        _map_grid.at(x+mapposx).at(y+mapposy)->setBlocking(true);
                        _map_grid.at(x+mapposx).at(y+mapposy)->setTrapped(false);
                        _map_grid.at(x+mapposx).at(y+mapposy)->setTileType(Tile::TileType::wall);
                    } else {
                        _map_grid.at(x+mapposx).at(y+mapposy)->setCharacter('.');
                        _map_grid.at(x+mapposx).at(y+mapposy)->setBlocking(false);
                        _map_grid.at(x+mapposx).at(y+mapposy)->setTrapped(false);
                        _map_grid.at(x+mapposx).at(y+mapposy)->setTileType(Tile::TileType::wall);
                    }
                }
            }
            _is_dirty = true;
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

    std::vector< Tile *> Map::tile_list() {
        return _tile_list;
    }

    bool Map::is_dirty(){
        return _is_dirty;
    }

    void Map::is_dirty(bool dirty) {
        _is_dirty = dirty;
    }
