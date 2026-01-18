//
// abstract_Tile.h
// 2026-01-17
// qxoxrogue
//

#ifndef abstract_Tile_h
#define abstract_Tile_h

#include <vector>
#define tlist std::vector<int> // change from vector later

class Tile {
public: 
    uint rank = 0; // this is the position within the hierarchical structure of
    int uuid;
    tlist neighb;
};

#endif // abstract_Tile.h