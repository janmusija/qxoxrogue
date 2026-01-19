//
// Player.cpp
// 2026-01-17
// qxoxrogue
//

#include "../entity/Player.h"

Player::Player(const EntityTemplate & templ, uint rk, int ti, int x, int y, int u){
    ai = 0;
    body = templ.body;
    symb = templ.symb;
    col = templ.col;

    tile_rank = rk;
    tile_index = ti;
    x_coord = x; y_coord = y;
    set_uuid(u);
}

Player::Player(EntityBody b, qx_char sym, qx_col c, uint rk, int ti, int x, int y, int u){
    ai = 0;
    body = b
    symb = sym;
    col = c;

    tile_rank = rk;
    tile_index = ti;
    x_coord = x; y_coord = y;
    set_uuid(u);
}

#endif