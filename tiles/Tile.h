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
using tlist = std::vector<int>; // change from vector later

class Tile {
public: 
    unsigned int rnk = 0; // this is the position within the hierarchical structure of
    int uuid;
    tlist neighb;
    unsigned int x_len;
    unsigned int y_len;
    Space * getSpace(int x,int y) {
        if (x < 0 || y < 0 || x >= (int)x_len || y >= (int)y_len){
            return nullptr;
        }
        return _gS(x,y);
    }
    virtual ~Tile() = default;
protected:
    virtual Space * _gS(int x,int y) =0;
};

#endif // abstract_Tile.h