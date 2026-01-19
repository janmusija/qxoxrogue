//
// Entity.cpp
// 2026-01-17
// qxoxrogue
//

#include "entity/Entity.h"
#include "arrays/EArrays.h"

Entity::Entity(const EntityBody & b, const char_col & sym, unsigned int rk, int ti, int x=-1, int y=-1,int * uuidctr = &next_E_uuid){
    body = b;
    symb = sym;
    uuid = *uuidctr;
    ++uuidctr;

    tile_rnk = rk;
    tile_index = ti;
    x_coord = x; y_coord = y;
}

void Entity::mov(unsigned int rk, int ti, int x, int y){
    tile_rnk = rk;
    x_coord = x; y_coord = y;
    tile_index = ti;
}