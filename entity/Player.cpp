//
// Player.cpp
// 2026-01-17
// qxoxrogue
//

#include "../entity/Player.h"

Player::Player(const EntityTemplate & templ, uint rk, int ti, Space* sptr){
    ai = 0;
    body = templ.body;
    symb = templ.symb;
    col = templ.col;

    rank = rk;
    tile_index = ti;
    spaceptr = sptr;
}

Player::Player(EntityBody b, qx_char sym, qx_col c, uint rk, int ti, Space* sptr){
    ai = 0;
    body = b
    symb = sym;
    col = c;

    rank = rk;
    tile_index = ti;
    spaceptr = sptr;
}

#endif