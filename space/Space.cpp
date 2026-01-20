//
// Space.cpp
// 2026-01-17
// qxoxrogue
//

#include "space/Space.h"
#include "arrays/EArrays.h"
#include "arrays/IArrays.h"

#define SPACE_DISPLAY_ITERATION_LIMIT 10

char_col Space::display(int n){ // probably cacheing something would be more efficient
    // blink through entities and items stacked on top
    unsigned int lsize = entities.size()+items.size();
    if (lsize == 0){
        return defaultdisplay;
    }
    n %= lsize;
    if (n >= (int)entities.size()){
        n-= entities.size();
        eilist::iterator it = items.begin();
        for (int i = 0; i<n; ++i){
        it++;
        }
        return loaded_items[*it].symb;
    } else{
        eilist::iterator it = entities.begin();
        for (int i = 0; i<n; ++i){
        it++;
        }
        return loaded_entities[*it].symb;
    }
    return defaultdisplay;
}