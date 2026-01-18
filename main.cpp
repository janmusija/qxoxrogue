//
// main.cpp
// 2026-01-17
// qxoxrogue
//

/*
    dependencies: ncurses, gmp.
    compile with
    g++ main.cpp -Wall -Wextra -lncurses -lgmpxx -o qxoxrogue
    then run
    ./qxoxrogue
*/

#include "render/render.h"

int main(int argc, char *argv[]){
    initscr();
    printw("Hello Von Neumann Universe");
    addwstr(L"\u00E7test");
    refresh();
    getch();
    endwin();
    return 0;
}