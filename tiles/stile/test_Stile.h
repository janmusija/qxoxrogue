//
// test_Stile.h
// 2026-01-17
// qxoxrogue
//

#ifndef test_Stile.h
#define test_Stile.h

#include "tile/abstract_Stile.h"

// test_Stile is a 4x4 stile with a position in the world.

class test_Stile : abstract_Stile {
public:
    int pos_x = 0;
    int pos_y = 0;
    int[4][4] subt = {{-1,-1,-1,-1},{-1,-1,-1,-1},{-1,-1,-1,-1},{-1,-1,-1,-1}}; // uninitialized
};

#endif // test_Stile.h