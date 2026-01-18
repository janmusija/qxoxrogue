//
// Space.h
// 2026-01-17
// qxoxrogue
//

#ifndef Space_h
#define Space_h

#ifndef eilist
#include <vector>
#define eilist std::vector<int> // change from vector later
#endif

class Space {
public:

    eilist entities; //positions of entities in array
    eilist items; // similarly
};

#endif // Space.h