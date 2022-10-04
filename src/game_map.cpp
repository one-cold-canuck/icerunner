#include "game_map.hpp"


    GameMap::GameMap(){

    }

    GameMap::GameMap(int h, int w, int l) {
        _height = h;
        _width = w;
        _level = l;

    }

    GameMap::GameMap(){
        // Iterate vector, destroy tiles?
    }

    // Flood the map with tiles - each tile has:
    //    passable: false
    //    transparent: false
    //    <items>: 
    //    x,y - position in vector.
    //
    //    Store pointer to tile in Vector


    std::vector<Tile> GameMap::init_tiles(){
        for(int j = 0; j < _height; j++) {
            for(int k = 0; k < _width; k++) {
                Tile tile(j, k, tile_type::TILE_TYPE_EMPTY, true, false, '.', this);    
                _tile_list.push_back(tile);
            }
        }
    }

    void GameMap::init_map(){  // Flood the map with Tile pointers, 
        int i = 0;
        for (int r = 0; r < _height; r++) {
            std::vector<Tile *> tile_tmp;
            for (int c = 0; c < _width; c++) {
                std::vector<Tile *> tile_col;
                tile_col.push_back(&_tile_list.at(i));
                tile_tmp = tile_col;
            }
            _game_board.push_back(tile_tmp);
        }
    }

    void GameMap::create_room(int x, int y) {  //Basic, to be replaced with a room mechanic, for special rooms etc

    }

    void GameMap::generate_map() {  // To be implemented

    }

    void GameMap::setHeight(int h) {
        _height = h;
    }

    void GameMap::setWidth(int w){
        _width = w;
    }

    void GameMap::setLevel(int l) {
        _level = l;
    }

    int GameMap::height() {
        return _height;
    }

    int GameMap::width() {
        return _width;
    }

    int GameMap::level() {
        return _level;
    }

    std::vector< std::vector < Tile *>> GameMap::game_board() {
        return _game_board;
    }