#include <ncurses.h>
#include "cScreen.hpp"
#include "cFolderScreen.hpp"
#include <string>

cFolderScreen::cFolderScreen(int focused_color, int normal_color) : cScreen(1,1,0,0,focused_color,normal_color) {
  this->Title = "Folders";
}

void cFolderScreen::draw(bool force) {
  mvwaddstr(this->win,2,2,"test");
  cScreen::draw();
}
