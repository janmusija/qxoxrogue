//
// Camera.h
// 2026-01-17
// qxoxrogue
//

#ifndef Camera_h
#define Camera_h

#include "../render/render.h"
#include "../entity/Entity.h"
#include "../space/Space.h"
#include "../tiles/Tile.h"
#include "../arrays/TArrays.h"

class Camera {
    Entity * follow = nullptr; // can be null without issue
    Tile * tile = nullptr;
    int center_x = -1;
    int center_y = -1;
    bool push_to_display(){ // return 1 if successful, 0 otherwise
        if (follow != NULL || follow.tile_rank == 0){
            if (loaded_tiles.in_use(follow.tile_index)){
                tile = &(loaded_tiles[follow.tile_index]);
                center_x = follow.x_coord;
                center_y = follow.y_coord;
            } else {
                tile = nullptr;
            }
            // todo: implement following, by finding tile and center_space from the entity
        }
        if (tile == NULL){
            return 0;
        }
        else
    }
};

#endif // Camera.h