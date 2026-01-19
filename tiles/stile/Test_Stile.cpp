//
// Test_Stile.cpp
// 2026-01-17
// qxoxrogue
//

#include "Test_Stile.h"
#include "tiles/tile/Med_Tile.h"
#include "arrays/TArrays.h"

void Test_Stile::generate_subStile_at (int * const t) override{
    Test_Stile nt;
    loaded_tiles.insert(std::move(nt))
}  

void Test_Stile::generate_subTile_at (int * const t) override {
    Med_Tile nt;
    loaded_tiles.insert(std::move(nt))
}