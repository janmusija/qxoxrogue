//
// Entity.cpp
// 2026-01-17
// qxoxrogue
//

#include "entity/Entity.h"

Entity::Entity(const EntityTemplate & templ, unsigned int rk, int ti, int x, int y){
    body = templ.body;
    symb = templ.symb;

    tile_rnk = rk;
    tile_index = ti;
    x_coord = x; y_coord = y;
}

Entity::Entity(EntityBody b, char_col sym, unsigned int rk, int ti, int x, int y){
    body = b;
    symb = sym;

    tile_rnk = rk;
    tile_index = ti;
    x_coord = x; y_coord = y;
}

void Entity::mov(unsigned int rk, int ti, int x, int y){
    tile_rnk = rk;
    x_coord = x; y_coord = y;
    tile_index = ti;
}

void Entity::set_uuid(int u){
    uuid = u;
}