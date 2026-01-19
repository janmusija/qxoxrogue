//
// render.h
// 2026-01-17
// qxoxrogue
//

#ifndef render_h
#define render_h

#include <ncurses.h>
#include <locale.h>
#define qx_char wchar_t // for now, or maybe for ever
#define qx_color int // for now

/*
// curses defines 3 bit colors, blue least sig:
COLOR_BLACK	0
COLOR_RED	1
COLOR_GREEN	2
COLOR_YELLOW	3
COLOR_BLUE	4
COLOR_MAGENTA	5
COLOR_CYAN	6
COLOR_WHITE	7
*/
#define LIGHT_FG 8

#define char_col std::pair<qx_char,qx_color>

int midx(const WINDOW * w =stdscr) {return getmaxx(w)/2;}
int midy(const WINDOW * w =stdscr) {return getmaxy(w)/2;}

int unpair_fg(int fgbg){return fgbg/8;}
int unpair_bg(int fgbg){return fgbg%8;}
int pair_fgbg(int fg, int bg){return fg*8 + bg;} 

void register_color_pairs(){
    start_color();
    for (int i = 0; i<16*8; i++){
        init_pair(i,unpair_fg(i),unpair_bg(i));
    }
}

void depict(int x, int y, const qx_char & symb, const qx_color & col){
    attron(COLOR_PAIR(col));
    mvaddwstr(x,y,std::wstring({symb}).c_str()); // there is a better way to do this and I don't know what it is.
    attroff(COLOR_PAIR(col));
}

void depict(int x, int y, const char_col & symb){
    depict(x,y,symb.first,symb.second);
}


#endif // render.h