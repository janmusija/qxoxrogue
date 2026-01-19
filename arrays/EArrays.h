//
// EArrays.h
// 2026-01-18
// qxoxrogue
//

#ifndef earrays_h
#define earrays_h

#include "entity/Entity.h"
#include "arrays/qxArray.h"

class EArray : public qxArray<Entity>{
};

extern EArray loaded_entities;
extern int next_E_uuid;

#endif // earrays_h