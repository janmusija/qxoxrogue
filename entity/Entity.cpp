//
// Entity.cpp
// 2026-01-17
// qxoxrogue
//

#include "../entity/Entity.h"

Entity::Entity(const EntityTemplate & templ, uint rk, int ti, int x, int y){
    body = templ.body;
    symb = templ.symb;
    col = templ.col;

    tile_rank = rk;
    tile_index = ti;
    x_coord = x; y_coord = y;
}

Entity::Entity(EntityBody b, qx_char sym, qx_col c, uint rk, int ti, int x, int y){
    body = b
    symb = sym;
    col = c;

    tile_rank = rk;
    tile_index = ti;
    x_coord = x; y_coord = y;
}

void Entity::move(uint rk, int ti, int x, int y){
    tile_rank = rk;
    x_coord = x; y_coord = y;
    tile_index = ti;
}

void Entity::set_uuid(int u){
    uuid = u;
}