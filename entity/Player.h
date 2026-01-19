//
// Player.h
// 2026-01-17
// qxoxrogue
//

#ifndef Player_h
#define Player_h
#include "entity/Entity.h"

class Player : public Entity {
    Player(EntityBody b, char_col sym, unsigned int rnk, int tile_index, int x = -1, int y = -1, int u = 0):
        Entity(b, sym, rnk, tile_index, x,y) {
        ai = 0;
        set_uuid(u);
    };
    Player(const EntityTemplate & templ, unsigned int rnk, int tile_index, int x = -1, int y = -1, int u= 0) :
        Entity(templ, rnk, tile_index, x, y){
        ai = 0;
        set_uuid(u);
    };
};

#endif