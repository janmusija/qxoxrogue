//
// Material.h
// 2026-01-17
// qxoxrogue
//

#ifndef Material_h
#define Material_h

#include <ncurses.h>
#include <locale.h>
#include <gmpxx.h>
#include "render/render.h"
#include "documentation/units.h" // useful for converting between different units
#include <unordered_set>

class Material {
    public:
    std::string internal_name;
    std::string solid_name; // e.g. "ice"
    std::string liquid_name; // e.g. "water"
    std::string gas_name; // e.g. "steam"
    std::unordered_set<std::string> tags;
    qx_color color;
    mpz_class melt_point; // temp in millikelvin
    mpz_class boil_point; // also in mK
    mpz_class solid_density; // in g/m^3
    mpz_class liquid_density; // in g/m^3
    mpz_class gas_density; // in g/m^3
    /* implement further properties e.g. specific heat, brittleness later ... but for now this is probably scope creep */
    virtual ~Material() = default;
};

#endif // Material.h