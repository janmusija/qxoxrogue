//
// abstract_Stile.h
// 2026-01-17
// qxoxrogue
//

#ifndef abstract_Stile_h
#define abstract_Stile_h

#include <vector>
#ifndef tlist
#define tlist std::vector<int> // change from vector later
#endif

class Stile {
public: 
    uint rank = 0; // this is the position within the hierarchical structure of
    int uuid;
    tlist subtiles;
    tlist neighb;
    virtual void generate_subStile_at(int * const t) =0; // create a new Stile at this position [intended to be within the Stile]
    virtual void generate_subTile_at(int * const t) =0; // create a new Tile at this position
    void generate_sub(int * const target); // create a new Tile or Stile at this position 
};

#endif // abstract_Stile.h