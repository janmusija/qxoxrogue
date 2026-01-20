//
// Item_Type.cpp
// 2026-01-18
// qxoxrogue
//

#include "item/Item_Type.h"

Item_Type::Item_Type(const Material_Item_Type_Template& templ, const Material & mat, int state){
    volume = templ.volume;
    tags = templ.tags;
    symb = std::make_pair(templ.ch,mat.color);
    if (state == 1) { // liquid
        mass = (templ.volume * mat.liquid_density + 500000) / 1000000; // +500000 round
        internal_name = mat.liquid_name + " " + templ.internal_name;
    } else if (state == 2) { // gas
        mass = (templ.volume * mat.gas_density + 500000) / 1000000;
        internal_name = mat.gas_name + " " + templ.internal_name;
    } else { // 0, solid is default
        mass = (templ.volume * mat.solid_density + 500000) / 1000000;
        internal_name = mat.solid_name + " " + templ.internal_name;
    }
}