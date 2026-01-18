//
// Entity.h
// 2026-01-17
// qxoxrogue
//

#ifndef Entity_h
#define Entity_h

#include "../space/Space.h"
#include "../render/render.h"
#include "../entity/EntityBody.h"

class EntityTemplate { // these are basically "species"
    public:
    std::string name; // the name of this template
    EntityBody body;
    qx_char symb;
    qx_color col;
};

class Entity { // these are individual creatures, etc
    public:
    // location:
    uint rank; // actually rank + 1, so that 0 -> Tile, 1 -> 0-Stile, etc. 
    int tile_index; // location in array at that level of detail
    int uuid = -1; // entities with uuid -1 are not saved
    Space* spaceptr; // if not null, points to current position. Nulled when tile unloaded.
    
    EntityBody body; // the entity's body
    bool Corporeal = true; // if false, does not render. can still have a body.
    qx_char symb; // associated symbol to be rendered with
    qx_color col;

    std::string name; // the entity's name. May be empty, and often is.

    // construct a new entity from a template and place within a tile, optionally at some space:
    Entity(const EntityTemplate & templ, uint rank, int tile_index, const Space* sptr=nullptr);

    Entity(EntityBody b, qx_char sym, qx_color c, uint rank, int tile_index, const Space* sptr=nullptr);
    
    // move to a new space. yes, you must explicitly specify the new tile even if it is the same
    void move(uint rank, int tile_index, const Space* sptr=nullptr);

    void set_uuid(int u);

    // is ai (or player)
    bool ai = 1;
};

#endif // Entity.h