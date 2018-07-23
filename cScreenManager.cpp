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
  int w3 = (int)(this->maxC*0.3);
  int w4 = (int)(this->maxC*0.4);
  this->FolderScreen->update(0,0,w3,this->maxL);
  this->FilesScreen->update(w3,0,w3,this->maxL);
  this->DocumentScreen->update(w3+w3,0,w4,this->maxL);
}
