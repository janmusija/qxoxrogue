//
// Entity.h
// 2026-01-17
// qxoxrogue
//

#ifndef Entity_h
#define Entity_h

#include "render/render.h"
#include "entity/EntityBody.h"
#include <unordered_set>

class EntityType { // these are basically "species"
    public:
    std::string name; // the name of this template
    EntityBody body;
    char_col symb;
};

class Entity { // these are individual creatures, etc
    public:
    // location:
    unsigned int tile_rnk; // actually rank + 1, so that 0 -> Tile, 1 -> 0-Stile, etc. 
    int tile_index; // location in array at that level of detail
    int uuid;
    int array_position = -1;
    // position within a tile. Currently, for Sanity, non-squaregrid tiles are not supported (however, exotic geometries on a higher level are.)
    int x_coord = -1;
    int y_coord = -1;
    
    EntityBody body; // the entity's body
    std::unordered_set<std::string> tags;
    char_col symb; // associated symbol to be rendered with

    std::string name; // the entity's name. May be empty, and often is.

    // construct a new entity from a template and place within a tile, optionally at some space:
    Entity(const EntityType & templ, unsigned int rnk, int tile_index, int x, int y, int * uuidctr) : Entity(templ.body, templ.symb, rnk, tile_index, x, y, uuidctr) {};

    Entity(const EntityBody & b, const char_col & sym, unsigned int rnk, int tile_index, int x, int y, int * uuidctr);
    
    // move to a new space. yes, you must explicitly specify the new tile even if it is the same
    void mov(unsigned int rnk, int tile_index, int x = -1, int y = -1);
    void unlink_space(int ti, int x, int y);
    void unlink_space() {unlink_space(tile_index,x_coord, y_coord);};
    void link_space(int ti, int x, int y);
    void link_space() {link_space(tile_index,x_coord, y_coord);};

    void step(char dir);

    // is ai (or player)
    bool ai = 1;   
    void noai(){ai = 0;};


    virtual ~Entity() = default;
    Entity(Entity&&) = default;
};

#endif // Entity.h