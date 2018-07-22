#include <ncurses.h>
#include <stdlib.h>
#include "test.hpp"

void quit() {
  endwin();
}

int main(int argc, char** argv) {
  initscr();
  atexit(quit);
  curs_set(0);
  noecho();
  
  mvaddstr(0,0,test());
  
  addch(ACS_ULCORNER);
  
  getch();
  
  return 0;
}
