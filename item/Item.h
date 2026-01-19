//
// Item.h
// 2026-01-17
// qxoxrogue
//

#ifndef Item_h
#define Item_h

#include "render/render.h"

class Item { // these may be complicated-- I don't want to limit them to consisting of only one material.
    public:
    std::string internal_name;
    int uuid = -1;
    char_col symb;
    virtual ~Item() = default;
    Item(Item&&) = default;
    // TK
};

#endif // Item.h