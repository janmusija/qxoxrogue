//
// Stile.cpp
// 2026-01-17
// qxoxrogue
//

#include "tiles/Stile.h"

void Stile::generate_sub(int * const target){
    if (rank > 0){
        generate_subStile_at(target);
    } else {
        generate_subTile_at(target);
    }
}