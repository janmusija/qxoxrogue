//
// Test_Stile.cpp
// 2026-01-17
// qxoxrogue
//

#include "Test_Stile.h"
#include "tiles/tile/Med_Tile.h"
#include "arrays/TArrays.h"

void Test_Stile::generate_subStile_at (int * const t){
    Test_Stile nt(rnk-1);
    loaded_stiles.insert<Test_Stile>(std::move(nt));
}  

void Test_Stile::generate_subTile_at (int * const t) {
    Med_Tile nt;
    loaded_tiles.insert<Med_Tile>(std::move(nt));
}