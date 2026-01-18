//
// main.cpp
// 2026-01-17
// qxoxrogue
//

/*
    compile with
    g++ main.cpp -Wall -Wextra -lncurses -lgmpxx -o qxoxrogue
    then run
    ./qxoxrogue
*/

#include "render/render.h"

int main(int argc, char *argv[]){
    initscr();
    printw("Hello Von Neumann Universe");
    refresh();
    getch();
    endwin();
    return 0;
}