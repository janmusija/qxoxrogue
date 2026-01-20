//
// Space.h
// 2026-01-17
// qxoxrogue
//

#ifndef Space_h
#define Space_h

#include "render/render.h"

#include <unordered_set> // this should probably be a set or something.
using eilist = std::unordered_set<int>; // change from vector later

class Space {
public:
    eilist entities; //positions of entities in array. for rendering
    eilist items; // similarly
    char_col display(int n);
    char_col defaultdisplay = std::make_pair(L'\u00b7',pair_fgbg(COLOR_BLACK + LIGHT_FG,COLOR_BLACK)); // grey .
};

#endif // Space.h