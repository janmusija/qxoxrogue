//
// EntityBody.h
// 2026-01-17
// qxoxrogue
//

#ifndef EntityBody_h
#define EntityBody_h
#include "material/Material.h"
#include <vector>

class BodySegment {
    public:
    std::string name;
    int parent = -1; // -1 -> no parent body part
    mpz_class volume;
    std::vector<std::pair<Material,float>> layers; // material, thickness
    bool embedded; // true -> does not contribute to body size in general, and some other things
};

class EntityBody {
    public:
    std::vector<BodySegment> segments;

    // not sure what the best way to implement this. It should be a tree of different components, I guess, with some Traits or another.
    // at the very least, materials.
    // at this stage something DFine is probably excessive so I won't do that

    void prepend_to_seg_names(std::string s); // add to strings
    void append_to_seg_names(std::string s); 

    EntityBody(const BodySegment & seg);
    EntityBody(); // empty body

    // manipulate body parts
    void contract(unsigned int X); // delete body part at X and contract attached edges
    void attach_seg(unsigned int X, const BodySegment & seg); // attach segment at X
    void attach_EB(unsigned int X, const EntityBody & EB); // attach body part at X
    void repeat_seg_series(unsigned int X, unsigned int n, const BodySegment & seg); // attach a chain of n copies of a segment at X
    void repeat_EB_series(unsigned int X, unsigned int n, const EntityBody & EB); // attach a chain of n copies of a body part at X
    void repeat_seg_star(unsigned int X, unsigned int n, const BodySegment & seg); // attach n copies of a segment directly at X
    void repeat_EB_star(unsigned int X, unsigned int n, const EntityBody & EB); // attach n copies of a body part directly at X

};

#endif // EntityBody.h