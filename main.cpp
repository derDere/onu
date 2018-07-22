#include <ncurses.h>
#include <stdlib.h>
#include "cScreenManager.hpp"

void quit() {
  endwin();
}

int main(int argc, char** argv) {
  initscr();
  atexit(quit);
  curs_set(0);
  noecho();

  mvaddstr(0,0,"Hallo Welt!\n\n");
  cScreenManager* sm = new cScreenManager();
  sm->print();
  sm->hr();

  addch(ACS_ULCORNER);

  getch();

  return 0;
}
