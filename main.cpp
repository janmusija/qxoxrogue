//
// main.cpp
// 2026-01-17
// qxoxrogue
//

/*
    dependencies: ncurses (ncursesw), gmp.
    compile with
    make
    then run
    ./qxoxrogue
*/

#include <iostream>
#include <ctime>
#include "render/render.h"
#include "render/Camera.h"
#include "documentation/units.h"
#include "entity/Player.h"
#include "arrays/EArrays.h"
#include "arrays/TArrays.h"
#include "tiles/tile/Med_Tile.h"
#include "data/process_raws.h"

int main(int argc, char *argv[]){
    // determine whether to initialize a fresh game or something else
    std::cout << "Type \"load\" to load a new game, and \"new\" to create a new game: ";
    {
        std::string choice;
        std::cin >> choice;
        // this would be a good place for a goto labyrinth I think.
        if (choice == "load" || choice == "l") {
            throw "unimplemented";
            // ho ho TK
        } else if (choice == "new" || choice == "n" || choice == "r" || choice == "random" || choice == "seed" || choice == "seeded" || choice == "s"){
            unsigned long seed;
            // create a new world
            if (choice == "new" || choice == "n"){
                std::cout << "Type \"random\" to use a random seed, or \"seed\" followed by the seed to use a specific seed: ";
                std::cin >> choice;
            }
            if (choice == "random" || choice == "r"){
                seed = (int)time(nullptr);
            }
            if  (choice == "seed" || choice == "seeded" || choice == "s"){
                std::cin >> seed;
            }
            // generate fresh world TK
        }
    }
    // initialize nscurses
    setlocale(LC_ALL,"");
    initscr();
    register_color_pairs();
    curs_set(0);
    //noecho();
    


    Med_Tile m;
    loaded_tiles.insert<Med_Tile>(std::move(m));
    Camera cam(&(loaded_tiles[0]));
    EntityBody testb; // entirely empty body for now
    //std::cout << loaded_tiles[0].
    char_col charac = std::make_pair(L'\u0040',pair_fgbg(COLOR_BLACK+LIGHT_FG,COLOR_BLACK));
    registerentity(Entity(testb,charac,0,0,4,4,&next_E_uuid));
    Entity * pl = &loaded_entities[0];
    pl->link_space();
    pl->noai();

    //std::cout << loaded_entities[0].x_coord << std::endl;
    //mvprintw(midy(),midx(),(std::to_string(midx()) + "," + std::to_string(midy())).c_str());
    
    bool goon = 1;
    while (goon){
        cam.cam_to_display();
        int ch = getch();
        pl->step(ch);
    }



    endwin();
    return 0;
}