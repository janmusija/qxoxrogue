//
// Space.h
// 2026-01-17
// qxoxrogue
//

#ifndef Space_h
#define Space_h

#ifndef eilist
#include <vector>
#include "../render/render.h"
#include "../tiles/Tile.h"
#define eilist std::vector<int> // change from vector later?
#endif

class Space {
public:
    eilist entities; //positions of entities in array
    eilist items; // similarly
    char_col display = std::make_pair(L'\u002e',8); // grey .
};

#endif // Space.h