//
// Item.h
// 2026-01-17
// qxoxrogue
//

#ifndef Item_h
#define Item_h

#include "render/render.h"
#include "item/Item_Type.h"
#include <gmpxx.h>

class Item { // these may be complicated-- I don't want to limit them to consisting of only one material.
    public:
    std::string internal_name;
    int uuid = -1;
    char_col symb;
    virtual ~Item() = default;
    Item(Item&&) = default;
    mpz_class mass;
    mpz_class volume;
    // TK
    Item(const Item_Type & typ, int u=-1);
    Item(const Material_Item_Type_Template & templ, const Material & mat, int state = 0, int u =-1) : Item (Item_Type(templ,mat,state), u){};
};

#endif // Item.h