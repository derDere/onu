#include <ncurses.h>
#include "cScreenManager.hpp"
#include "cScreen.hpp"
#include <string>

cScreenManager::cScreenManager(cScreen *FolderScreen, cScreen *FilesScreen, cScreen *DocumentScreen) {
  this->FolderScreen = FolderScreen;
  this->FilesScreen = FilesScreen;
  this->DocumentScreen = DocumentScreen;

  int l, c;
  getmaxyx(stdscr, l, c);
  this->maxC = c;
  this->maxL = l;
}

bool cScreenManager::sizeChanged() {
  int l, c;
  getmaxyx(stdscr, l, c);
  if ((this->maxC != c) || (this->maxL != l)) {
    this->maxC = c;
    this->maxL = l;
    return true;
  }
  return false;
}

void cScreenManager::updateScreens() {

}

void cScreenManager::print() {
  addstr(std::to_string(this->maxC).c_str());
  addstr(", ");
  addstr(std::to_string(this->maxL).c_str());
}

void cScreenManager::hr() {
  addch('\n');
  for (int i = 0; i < this->maxC; i++) {
    addch('-');
  }
}
