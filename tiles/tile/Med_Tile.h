//
// Med_Tile.h
// 2026-01-17
// qxoxrogue
//

#ifndef Med_Tile_h
#define Med_Tile_h

#include "tiles/Tile.h"

// med_tile is a 16x16 grid of spaces.

class Med_Tile : public Tile {
public:
    Space spaces[16][16];
    Med_Tile() {x_len = 16; y_len = 16;};
    Space * getSpace(int x,int y) override{
        return &(spaces[x][y]);
    }
    Med_Tile(Med_Tile&&) = default;
};

#endif // Med_Tile.h