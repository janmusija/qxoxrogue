//
// TArrays.h
// 2026-01-18
// qxoxrogue
//

#ifndef tarrays_h
#define tarrays_h

#include "../tiles/Tile.h"
#include "../tiles/Stile.h"
#include "../arrays/qxArray.h"

class TArray : public qxArray<Tile>{
};
class StArray : public qxArray<Stile>{
};

StArray loaded_stiles; // the loaded stiles
TArray loaded_tiles; // the loaded tiles

#endif // tarrays.h