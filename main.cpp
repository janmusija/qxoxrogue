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
    // initialize game
    setlocale(LC_ALL,"");
    initscr();
    //printw("Hello Von Neumann Universe\n");
    //printw(F_to_mK(mpz_class(-40)).get_str().c_str()); printw(" millikelvin is about -40 Fahrenheit\n");
    //addwstr(L"\u00a3 <- pound sign.\n");
    refresh();
    getch();
    endwin();
    return 0;
}