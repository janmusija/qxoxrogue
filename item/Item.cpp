//
// Item.cpp
// 2026-01-18
// qxoxrogue
//

#include "item/Item.h"
Item::Item(const Item_Type & typ, int u){
    uuid = u;
    symb = typ.symb;
    volume = typ.volume;
    mass = typ.mass;
    tags = typ.tags;
}