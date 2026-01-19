//
// Test_Stile.h
// 2026-01-17
// qxoxrogue
//

#ifndef Test_Stile_h
#define Test_Stile_h

#include "../tiles/Stile.h"

// test_Stile is a 4x4 stile.

class Test_Stile : Stile {
public:
    int[4][4] subt = {{-1,-1,-1,-1},{-1,-1,-1,-1},{-1,-1,-1,-1},{-1,-1,-1,-1}}; // uninitialized
    Test_Stile(uint rk);
    void generate_subStile_at(int * const t) override; // create a new Stile at this position [intended to be within the Stile]
    void generate_subTile_at(int * const t) override; // create a new Tile at this position
};

#endif // Test_Stile.h