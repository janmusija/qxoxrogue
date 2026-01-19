//
// Camera.h
// 2026-01-17
// qxoxrogue
//

#ifndef Camera_h
#define Camera_h

#include "render/render.h"
#include "entity/Entity.h"
#include "space/Space.h"
#include "tiles/Tile.h"
#include "arrays/TArrays.h"

#define CAMERA_LINGER_TIME 12 // number of frames (maybe later just make this actual literal time) to linger on a given item within a number of stacked entities/items
#define CAMERA_LOOP_PERIOD 50 // number of distinct items to cycle through in this situation

class Camera {
    public:
    const Entity * follow = nullptr; // can be null without issue
    Tile * tile = nullptr; // this should really be const but I'm unsure the best way to do so
    int center_x = -1;
    int center_y = -1;
    bool cam_to_display();
    Camera(Tile * t);
    Camera(const Entity * f);

    unsigned int cameratick = 0;
};

#endif // Camera.h