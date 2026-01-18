//
// Entity.cpp
// 2026-01-17
// qxoxrogue
//

#include "../entity/Entity.h"

Entity::Entity(const EntityTemplate & templ, uint rk, int ti, const Space* sptr){
    body = templ.body;
    symb = templ.symb;
    col = templ.col;

    rank = rk;
    tile_index = ti;
    spaceptr = sptr;
}

Entity::Entity(EntityBody b, qx_char sym, qx_col c, uint rk, int ti, const Space* sptr){
    body = b
    symb = sym;
    col = c;

    rank = rk;
    tile_index = ti;
    spaceptr = sptr;
}

void Entity::move(uint rk, int ti, const Space* sptr){
    rank = rk;
    spaceptr = sptr;
    tile_index = ti;
}

void Entity::set_uuid(int u){
    uuid = u;
}