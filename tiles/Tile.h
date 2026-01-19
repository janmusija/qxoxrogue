//
// abstract_Tile.h
// 2026-01-17
// qxoxrogue
//

#ifndef abstract_Tile_h
#define abstract_Tile_h

#include <vector>
#include "base/macros.h"
#include "space/Space.h"
#ifndef tlist
#define tlist std::vector<int> // change from vector later
#endif

class Tile {
public: 
    unsigned int rnk = 0; // this is the position within the hierarchical structure of
    int uuid;
    tlist neighb;
    unsigned int x_len;
    unsigned int y_len;
    virtual Space * getSpace(int x,int y) =0;
    virtual ~Tile() = default;
};

#endif // abstract_Tile.h