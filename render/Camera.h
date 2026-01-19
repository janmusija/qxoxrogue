//
// Camera.h
// 2026-01-17
// qxoxrogue
//

#ifndef Camera_h
#define Camera_h

#include "../render/render.h"
#include "../entity/Entity.h"
#include "../space/Space.h"
#include "../tiles/Tile.h"
#include "../arrays/TArrays.h"

class Camera {
    public:
    const Entity * follow = nullptr; // can be null without issue
    Tile * tile = nullptr; // this should really be const but I'm unsure the best way to do so
    int center_x = -1;
    int center_y = -1;
    bool cam_to_display();
    Camera(Tile * t);
    Camera(const Entity * f);
};

#endif // Camera.h