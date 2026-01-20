//
// abstract_Stile.h
// 2026-01-17
// qxoxrogue
//

#ifndef abstract_Stile_h
#define abstract_Stile_h

#include <vector>
#include "base/macros.h"
using tlist = std::vector<int>; // change from vector later

class Stile { //these should have position in the array stored
public: 
    unsigned int rnk = 0; // this is the position within the hierarchical structure of the universe. Wait, that's not the first time I've used the term "rank" for this
    int uuid;
    tlist subtiles;
    tlist neighb;
    virtual void generate_subStile_at(int * const t) =0; // create a new Stile at this position [intended to be within the Stile]
    virtual void generate_subTile_at(int * const t) =0; // create a new Tile at this position
    void generate_sub(int * const target); // create a new Tile or Stile at this position 
    virtual ~Stile() = default;
};

#endif // abstract_Stile.h