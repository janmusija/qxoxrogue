//
// EArrays.cpp
// 2026-01-18
// qxoxrogue
//

#include "arrays/EArrays.h"

EArray loaded_entities;
int next_E_uuid = 0;

void loadentity(Entity&& en, EArray *  arr){
    int ap = arr->insert<Entity>(std::move(en)); // I don't know if this will inadvertently cast things in a way that causes Bad. perhaps it is necessary to override this for other more specific entities
    // did I implement this properly?
    (*arr)[ap].array_position = ap;
}

