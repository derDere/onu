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
  s1->title("S1")->focus(true);
  cScreen* s2 = new cScreen(1,1,0,0,FOCUSED_CP,NORMAL_CP);
  s2->title("S2");
  cScreen* s3 = new cScreen(1,1,0,0,FOCUSED_CP,NORMAL_CP);
  s3->title("S3");

  cScreenManager* sm = new cScreenManager(s1, s2, s3);

  //addch(ACS_ULCORNER);

  char input;
  do {
    if(sm->sizeChanged())
      sm->updateScreens();
    sm->draw();

    input = getch();

    switch (input) {
      case 'a':
        sm->focus(s1);
        break;
      case 's':
        sm->focus(s2);
        break;
      case 'd':
        sm->focus(s3);
        break;
    }
  } while(input != 'q');

  return 0;//*/
}

void quit() {
  endwin();
}
