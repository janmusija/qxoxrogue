//
// Player.h
// 2026-01-17
// qxoxrogue
//

#ifndef Player_h
#define Player_h
#include "../entity/Entity.h"

class Player : Entity {
    Player(EntityBody b, qx_char sym, qx_color c, uint rank, int tile_index, int x = -1, int y = -1, int u = 0);
    Player(const EntityTemplate & templ, uint rank, int tile_index, int x = -1, int y = -1, int u= 0);
};

#endif