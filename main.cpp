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

  cScreen* s1 = new cScreen(0,0,0,0);
  cScreen* s2 = new cScreen(0,0,0,0);
  cScreen* s3 = new cScreen(0,0,0,0);

  cScreenManager* sm = new cScreenManager(s1, s2, s3);
  sm->print();
  sm->hr();

  addstr("\n\n");
  s1->draw();
  s2->draw();
  s3->draw();

  addch(ACS_ULCORNER);

  getch();

  return 0;
}
