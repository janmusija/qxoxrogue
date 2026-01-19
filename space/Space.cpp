//
// Space.cpp
// 2026-01-17
// qxoxrogue
//

#include "space/Space.h"
#include "arrays/EArrays.h"
#include "arrays/IArrays.h"

char_col Space::display(int n){
    // blink through entities and items stacked on top
    unsigned int lsize = entities.size()+items.size();
    if (lsize == 0){
        return defaultdisplay;
    }
    n %= lsize;
    if (n >= entities.size()){
        n-=entities.size();
        return loaded_items[items[n]].symb;
    } else {
        return loaded_entities[entities[n]].symb;
    }
}