//
// Space.h
// 2026-01-17
// qxoxrogue
//

#ifndef Space_h
#define Space_h

#include "render/render.h"

#ifndef eilist
#include <vector>
#define eilist std::vector<int> // change from vector later?
#endif

class Space {
public:
    eilist entities; //positions of entities in array
    eilist items; // similarly
    char_col display = std::make_pair(L'\u00b7',pair_fgbg(COLOR_BLACK + LIGHT_FG,COLOR_BLACK)); // grey .
};

#endif // Space.h