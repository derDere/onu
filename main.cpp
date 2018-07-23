#include <ncurses.h>
#include <stdlib.h>
#include "cScreenManager.hpp"
#include <string>

const int FOCUSED_CP = 1;
const int NORMAL_CP = 2;

void quit();

int main(int argc, char** argv) {
  //Init ncurses
  initscr();
  atexit(quit);
  clear();
  noecho();
  curs_set(0);
  cbreak();
  keypad(stdscr,1);

  //Init Colors
  start_color();
  init_pair(FOCUSED_CP, COLOR_BLACK, COLOR_GREEN);
  init_pair(NORMAL_CP, COLOR_WHITE, COLOR_BLACK);

  //mvaddstr(0,0,"Hallo Welt!\n\n");

  cScreen* s1 = new cScreen(1,1,0,0,FOCUSED_CP,NORMAL_CP);
  s1->name = "S1";
  s1->focus(true);
  cScreen* s2 = new cScreen(1,1,0,0,FOCUSED_CP,NORMAL_CP);
  s2->name = "S2";
  cScreen* s3 = new cScreen(1,1,0,0,FOCUSED_CP,NORMAL_CP);
  s3->name = "S3";

  cScreenManager* sm = new cScreenManager(s1, s2, s3);
  sm->updateScreens();

  refresh();
  s1->draw();
  s2->draw();
  s3->draw();

  //addch(ACS_ULCORNER);

  getch();

  return 0;//*/
}

void quit() {
  endwin();
}