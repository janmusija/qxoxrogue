//
// Camera.cpp
// 2026-01-18
// qxoxrogue
//

#include "render/Camera.h"

bool Camera::cam_to_display(){ // return 1 if successful, 0 otherwise
    if (follow != NULL && follow->tile_rnk == 0){
        if (loaded_tiles.nonnull(follow->tile_index)){
            tile = &(loaded_tiles[follow->tile_index]);
            center_x = follow->x_coord;
            center_y = follow->y_coord;
        } else {
            tile = nullptr;
        }
        // todo: implement following, by finding tile and center_space from the entity
    }
    if (tile == NULL){
        return 0;
    }
    clear();
    if (center_x == -1 || center_y == -1){
        center_x = tile->x_len/2;
        center_y = tile->y_len/2;
    }
    for (unsigned int i = 0; i < tile->x_len; i++){
        for (unsigned int j = 0; j < tile->y_len; j++){
            // logic to skip unseen tiles
            int pos_x = i+midx()-center_x;
            int pos_y = j+midy()-center_y;
            depict(pos_y,pos_x,(tile->getSpace(i,j))->display); // be WARY! ncurses puts y first and x second, because Spite.
        }
    }
    refresh();
    return 1;
}

Camera::Camera(Tile * t){
    tile = t;
}

Camera::Camera(const Entity * f){
    follow = f;
}