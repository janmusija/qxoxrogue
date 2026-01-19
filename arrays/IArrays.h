//
// EArrays.h
// 2026-01-18
// qxoxrogue
//

#ifndef iarrays_h
#define iarrays_h

#include "item/Item.h"
#include "arrays/qxArray.h"

class IArray : public qxArray<Item>{
};

extern IArray loaded_items;
extern int next_I_uuid;

#endif // iarrays_h