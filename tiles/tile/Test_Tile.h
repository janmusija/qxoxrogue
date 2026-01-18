//
// Test_Tile.h
// 2026-01-17
// qxoxrogue
//

#ifndef Test_Tile_h
#define Test_Tile_h

#include "tile/abstract_Stile.h"

// test_tile is a 16x16 grid of spaces.

class Test_Tile : abstract_Tile {
public:
    int pos_x;
    int pos_y;

    Space[16][16]; spaces;
};

#endif // Test_Tile.h