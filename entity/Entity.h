//
// Entity.h
// 2026-01-17
// qxoxrogue
//

#ifndef Entity_h
#define Entity_h

#include "render/render.h"
#include "entity/EntityBody.h"

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
    unsigned int tile_rnk; // actually rank + 1, so that 0 -> Tile, 1 -> 0-Stile, etc. 
    int tile_index; // location in array at that level of detail
    int uuid = -1; // entities with uuid -1 are not saved
    // position within a tile. Currently, for Sanity, non-squaregrid tiles are not supported (however, exotic geometries on a higher level are.)
    int x_coord = -1;
    int y_coord = -1;
    
    EntityBody body; // the entity's body
    bool Corporeal = true; // if false, does not render. can still have a body.
    qx_char symb; // associated symbol to be rendered with
    qx_color col;

    std::string name; // the entity's name. May be empty, and often is.

    // construct a new entity from a template and place within a tile, optionally at some space:
    Entity(const EntityTemplate & templ, unsigned int rnk, int tile_index, int x = -1, int y = -1);

    Entity(EntityBody b, qx_char sym, qx_color c, unsigned int rnk, int tile_index, int x = -1, int y = -1);
    
    // move to a new space. yes, you must explicitly specify the new tile even if it is the same
    void move(unsigned int rnk, int tile_index, int x = -1, int y = -1);

    void set_uuid(int u);

    // is ai (or player)
    bool ai = 1;
    virtual ~Entity() = default;
};

#endif // Entity.h