//
// main.cpp
// 2026-01-17
// qxoxrogue
//

/*
    dependencies: ncurses (ncursesw), gmp.
    compile with
    g++ main.cpp -Wall -Wextra -lncursesw -lgmp -lgmpxx -o qxoxrogue
    then run
    ./qxoxrogue
*/

#include <iostream>
#include <ctime>
#include "render/render.h"
#include "documentation/units.h"
#include "entity/Player.h"
#include "arrays/EArrays.h"
#include "arrays/TArrays.h"

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
    
    // debug -- test rendering
    for (int i = 0; i<16; i++){
        for (int j = 0; j<8; j++){
            depict(i,j,'E',pair_fgbg(i,j));
        }
    }

    refresh();
    getch();
    endwin();
    return 0;
}