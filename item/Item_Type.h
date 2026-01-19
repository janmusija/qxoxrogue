//
// Item_Type.h
// 2026-01-18
// qxoxrogue
//

#ifndef Item_Type_h
#define Item_Type_h

#include "render/render.h"
#include "material/Material.h"
#include <gmpxx.h>


class Material_Item_Type_Template { // e.g. "ingot", "plate", ""
    public:
    std::string internal_name;
    qx_char ch;
    mpz_class volume;
};

class Item_Type { // most items are instances of item types.
    public:
    std::string internal_name;
    char_col symb;
    mpz_class volume;
    mpz_class mass;
    Item_Type(const Material_Item_Type_Template&, const Material & mat,int state = 0);
    // TK contents -- figure out material, components, etc
};

#endif // Item_Type.h